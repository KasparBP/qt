/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativecontext.h"
#include "qdeclarativecontext_p.h"

#include "qdeclarativeexpression_p.h"
#include "qdeclarativeengine_p.h"
#include "qdeclarativeengine.h"
#include "qdeclarativecompiledbindings_p.h"
#include "qdeclarativeinfo.h"
#include "qdeclarativeglobalscriptclass_p.h"

#include <qscriptengine.h>
#include <QtCore/qvarlengtharray.h>
#include <QtCore/qdebug.h>

#include <private/qscriptdeclarativeclass_p.h>

QT_BEGIN_NAMESPACE

QDeclarativeContextPrivate::QDeclarativeContextPrivate()
: data(0), notifyIndex(-1)
{
}

/*!
    \class QDeclarativeContext
    \since 4.7
    \brief The QDeclarativeContext class defines a context within a QML engine.
    \mainclass

    Contexts allow data to be exposed to the QML components instantiated by the
    QML engine.

    Each QDeclarativeContext contains a set of properties, distinct from
    its QObject properties, that allow data to be
    explicitly bound to a context by name.  The context properties are defined or
    updated by calling QDeclarativeContext::setContextProperty().  The following example shows
    a Qt model being bound to a context and then accessed from a QML file.

    \code
    QDeclarativeEngine engine;
    QDeclarativeContext context(engine.rootContext());
    context.setContextProperty("myModel", modelData);

    QDeclarativeComponent component(&engine, "ListView { model=myModel }");
    component.create(&context);
    \endcode

    To simplify binding and maintaining larger data sets, QObject's can be
    added to a QDeclarativeContext.  These objects are known as the context's default
    objects.  In this case all the properties of the QObject are
    made available by name in the context, as though they were all individually
    added by calling QDeclarativeContext::setContextProperty().  Changes to the property's
    values are detected through the property's notify signal.  This method is
    also slightly more faster than manually adding property values.

    The following example has the same effect as the one above, but it is
    achieved using a default object.

    \code
    class MyDataSet : ... {
        ...
        Q_PROPERTY(QAbstractItemModel *myModel READ model NOTIFY modelChanged)
        ...
    };

    MyDataSet myDataSet;
    QDeclarativeEngine engine;
    QDeclarativeContext context(engine.rootContext());
    context.setContextObject(&myDataSet);

    QDeclarativeComponent component(&engine, "ListView { model=myModel }");
    component.create(&context);
    \endcode

    Default objects added first take precedence over those added later.  All properties 
    added explicitly by QDeclarativeContext::setContextProperty() take precedence over default 
    object properties.

    Contexts are hierarchal, with the \l {QDeclarativeEngine::rootContext()}{root context}
    being created by the QDeclarativeEngine.  A component instantiated in a given context
    has access to that context's data, as well as the data defined by its
    ancestor contexts.  Data values (including those added implicitly by the
    default objects) in a context override those in ancestor contexts.  Data
    that should be available to all components instantiated by the QDeclarativeEngine
    should be added to the \l {QDeclarativeEngine::rootContext()}{root context}.

    In the following example,

    \code
    QDeclarativeEngine engine;
    QDeclarativeContext context1(engine.rootContext());
    QDeclarativeContext context2(&context1);
    QDeclarativeContext context3(&context2);

    context1.setContextProperty("a", 12);
    context2.setContextProperty("b", 13);
    context3.setContextProperty("a", 14);
    context3.setContextProperty("c", 14);
    \endcode

    a QML component instantiated in context1 would have access to the "a" data,
    a QML component instantiated in context2 would have access to the "a" and
    "b" data, and a QML component instantiated in context3 would have access to
    the "a", "b" and "c" data - although its "a" data would return 14, unlike
    that in context1 or context2.
*/

/*! \internal */
QDeclarativeContext::QDeclarativeContext(QDeclarativeEngine *e, bool)
: QObject(*(new QDeclarativeContextPrivate))
{
    Q_D(QDeclarativeContext);
    d->data = new QDeclarativeContextData(this);

    d->data->engine = e;
}

/*!
    Create a new QDeclarativeContext as a child of \a engine's root context, and the
    QObject \a parent.
*/
QDeclarativeContext::QDeclarativeContext(QDeclarativeEngine *engine, QObject *parent)
: QObject(*(new QDeclarativeContextPrivate), parent)
{
    Q_D(QDeclarativeContext);
    d->data = new QDeclarativeContextData(this);

    d->data->setParent(engine?QDeclarativeContextData::get(engine->rootContext()):0);
}

/*!
    Create a new QDeclarativeContext with the given \a parentContext, and the
    QObject \a parent.
*/
QDeclarativeContext::QDeclarativeContext(QDeclarativeContext *parentContext, QObject *parent)
: QObject(*(new QDeclarativeContextPrivate), parent)
{
    Q_D(QDeclarativeContext);
    d->data = new QDeclarativeContextData(this);

    d->data->setParent(parentContext?QDeclarativeContextData::get(parentContext):0);
}

/*!
    \internal
*/
QDeclarativeContext::QDeclarativeContext(QDeclarativeContextData *data)
: QObject(*(new QDeclarativeContextPrivate), 0)
{
    Q_D(QDeclarativeContext);
    d->data = data;
}

/*!
    Destroys the QDeclarativeContext.

    Any expressions, or sub-contexts dependent on this context will be
    invalidated, but not destroyed (unless they are parented to the QDeclarativeContext
    object).
 */
QDeclarativeContext::~QDeclarativeContext()
{
    Q_D(QDeclarativeContext);

    if (!d->data->isInternal)
        d->data->destroy();
}

/*!
    Return the context's QDeclarativeEngine, or 0 if the context has no QDeclarativeEngine or the
    QDeclarativeEngine was destroyed.
*/
QDeclarativeEngine *QDeclarativeContext::engine() const
{
    Q_D(const QDeclarativeContext);
    return d->data->engine;
}

/*!
    Return the context's parent QDeclarativeContext, or 0 if this context has no
    parent or if the parent has been destroyed.
*/
QDeclarativeContext *QDeclarativeContext::parentContext() const
{
    Q_D(const QDeclarativeContext);
    return d->data->parent?d->data->parent->asQDeclarativeContext():0;
}

/*!
    Return the context object, or 0 if there is no context object.
*/
QObject *QDeclarativeContext::contextObject() const
{
    Q_D(const QDeclarativeContext);
    return d->data->contextObject;
}

/*!
    Set the context \a object.
*/
void QDeclarativeContext::setContextObject(QObject *object)
{
    Q_D(QDeclarativeContext);

    QDeclarativeContextData *data = d->data;

    if (data->isInternal) {
        qWarning("QDeclarativeContext: Cannot set context object for internal context.");
        return;
    }

    data->contextObject = object;
}

/*!
    Set a the \a value of the \a name property on this context.
*/
void QDeclarativeContext::setContextProperty(const QString &name, const QVariant &value)
{
    Q_D(QDeclarativeContext);
    if (d->notifyIndex == -1)
        d->notifyIndex = this->metaObject()->methodCount();

    QDeclarativeContextData *data = d->data;

    if (data->isInternal) {
        qWarning("QDeclarativeContext: Cannot set property on internal context.");
        return;
    }

    if (data->engine) {
        bool ok;
        QObject *o = QDeclarativeEnginePrivate::get(data->engine)->toQObject(value, &ok);
        if (ok) {
            setContextProperty(name, o);
            return;
        }
    }

    if (!data->propertyNames) data->propertyNames = new QDeclarativeIntegerCache(data->engine);

    int idx = data->propertyNames->value(name);
    if (idx == -1) {
        data->propertyNames->add(name, data->idValueCount + d->propertyValues.count());
        d->propertyValues.append(value);

        data->refreshExpressions();
    } else {
        d->propertyValues[idx] = value;
        QMetaObject::activate(this, idx + d->notifyIndex, 0);
    }
}

/*!
    Set the \a value of the \a name property on this context.

    QDeclarativeContext does \bold not take ownership of \a value.
*/
void QDeclarativeContext::setContextProperty(const QString &name, QObject *value)
{
    Q_D(QDeclarativeContext);
    if (d->notifyIndex == -1)
        d->notifyIndex = this->metaObject()->methodCount();

    QDeclarativeContextData *data = d->data;

    if (data->isInternal) {
        qWarning("QDeclarativeContext: Cannot set property on internal context.");
        return;
    }

    if (!data->propertyNames) data->propertyNames = new QDeclarativeIntegerCache(data->engine);
    int idx = data->propertyNames->value(name);

    if (idx == -1) {
        data->propertyNames->add(name, data->idValueCount + d->propertyValues.count());
        d->propertyValues.append(QVariant::fromValue(value));

        data->refreshExpressions();
    } else {
        d->propertyValues[idx] = QVariant::fromValue(value);
        QMetaObject::activate(this, idx + d->notifyIndex, 0);
    }
}

/*!
  Returns the value of the \a name property for this context
  as a QVariant.
 */
QVariant QDeclarativeContext::contextProperty(const QString &name) const
{
    Q_D(const QDeclarativeContext);
    QVariant value;
    int idx = -1;

    QDeclarativeContextData *data = d->data;

    if (data->propertyNames)
        idx = data->propertyNames->value(name);

    if (idx == -1) {
        QByteArray utf8Name = name.toUtf8();
        if (data->contextObject) {
            QObject *obj = data->contextObject;
            QDeclarativePropertyCache::Data local;
            QDeclarativePropertyCache::Data *property = 
                QDeclarativePropertyCache::property(data->engine, obj, name, local);

            if (property) value = obj->metaObject()->property(property->coreIndex).read(obj);
        }
        if (!value.isValid() && parentContext())
            value = parentContext()->contextProperty(name);
    } else {
        if (idx >= d->propertyValues.count())
            value = QVariant::fromValue(data->idValues[idx - d->propertyValues.count()].data());
        else
            value = d->propertyValues[idx];
    }

    return value;
}

/*!
    Resolves the URL \a src relative to the URL of the
    containing component.

    \sa QDeclarativeEngine::baseUrl(), setBaseUrl()
*/
QUrl QDeclarativeContext::resolvedUrl(const QUrl &src)
{
    Q_D(QDeclarativeContext);
    return d->data->resolvedUrl(src);
}

QUrl QDeclarativeContextData::resolvedUrl(const QUrl &src)
{
    QDeclarativeContextData *ctxt = this;

    if (src.isRelative() && !src.isEmpty()) {
        if (ctxt) {
            while(ctxt) {
                if(ctxt->url.isValid())
                    break;
                else
                    ctxt = ctxt->parent;
            }

            if (ctxt)
                return ctxt->url.resolved(src);
            else if (engine)
                return engine->baseUrl().resolved(src);
        }
        return QUrl();
    } else {
        return src;
    }
}


/*!
    Explicitly sets the url resolvedUrl() will use for relative references to \a baseUrl.

    Calling this function will override the url of the containing
    component used by default.

    \sa resolvedUrl()
*/
void QDeclarativeContext::setBaseUrl(const QUrl &baseUrl)
{
    Q_D(QDeclarativeContext);

    d->data->url = baseUrl;
}

/*!
    Returns the base url of the component, or the containing component
    if none is set.
*/
QUrl QDeclarativeContext::baseUrl() const
{
    Q_D(const QDeclarativeContext);
    const QDeclarativeContextData* data = d->data;
    while (data && data->url.isEmpty()) 
        data = data->parent;

    if (data)
        return data->url;
    else
        return QUrl();
}

int QDeclarativeContextPrivate::context_count(QDeclarativeListProperty<QObject> *prop)
{
    QDeclarativeContext *context = static_cast<QDeclarativeContext*>(prop->object);
    QDeclarativeContextPrivate *d = QDeclarativeContextPrivate::get(context);
    int contextProperty = (int)(intptr_t)prop->data;

    if (d->propertyValues.at(contextProperty).userType() != qMetaTypeId<QList<QObject*> >()) {
        return 0;
    } else {
        return ((const QList<QObject> *)d->propertyValues.at(contextProperty).constData())->count();
    }
}

QObject *QDeclarativeContextPrivate::context_at(QDeclarativeListProperty<QObject> *prop, int index)
{
    QDeclarativeContext *context = static_cast<QDeclarativeContext*>(prop->object);
    QDeclarativeContextPrivate *d = QDeclarativeContextPrivate::get(context);
    int contextProperty = (int)(intptr_t)prop->data;

    if (d->propertyValues.at(contextProperty).userType() != qMetaTypeId<QList<QObject*> >()) {
        return 0;
    } else {
        return ((const QList<QObject*> *)d->propertyValues.at(contextProperty).constData())->at(index);
    }
}


QDeclarativeContextData::QDeclarativeContextData()
: parent(0), engine(0), isInternal(false), publicContext(0), propertyNames(0), contextObject(0),
  imports(0), childContexts(0), nextChild(0), prevChild(0), expressions(0), contextObjects(0),
  contextGuards(0), idValues(0), idValueCount(0), optimizedBindings(0), linkedContext(0)
{
}

QDeclarativeContextData::QDeclarativeContextData(QDeclarativeContext *ctxt)
: parent(0), engine(0), isInternal(false), publicContext(ctxt), propertyNames(0), contextObject(0),
  imports(0), childContexts(0), nextChild(0), prevChild(0), expressions(0), contextObjects(0),
  contextGuards(0), idValues(0), idValueCount(0), optimizedBindings(0), linkedContext(0)
{
}

void QDeclarativeContextData::destroy()
{
    if (linkedContext) 
        linkedContext->destroy();

    if (prevChild) {
        *prevChild = nextChild;
        if (nextChild) nextChild->prevChild = prevChild;
        nextChild = 0;
        prevChild = 0;
    }
    
    QDeclarativeContextData *child = childContexts;
    while (child) {
        QDeclarativeContextData *next = child->nextChild;

        child->invalidateEngines();
        child->parent = 0;
        child->nextChild = 0;
        child->prevChild = 0;

        child = next;
    }
    childContexts = 0;

    QDeclarativeAbstractExpression *expression = expressions;
    while (expression) {
        QDeclarativeAbstractExpression *nextExpression = expression->m_nextExpression;

        expression->m_context = 0;
        expression->m_prevExpression = 0;
        expression->m_nextExpression = 0;

        expression = nextExpression;
    }
    expressions = 0;

    while (contextObjects) {
        QDeclarativeDeclarativeData *co = contextObjects;
        contextObjects = contextObjects->nextContextObject;

        co->context = 0;
        co->outerContext = 0;
        co->nextContextObject = 0;
        co->prevContextObject = 0;
    }

    QDeclarativeGuardedContextData *contextGuard = contextGuards;
    while (contextGuard) {
        QDeclarativeGuardedContextData *next = contextGuard->m_next;
        contextGuard->m_next = 0;
        contextGuard->m_prev = 0;
        contextGuard->m_contextData = 0;
        contextGuard = next;
    }
    contextGuards = 0;

    if (propertyNames)
        propertyNames->release();

    if (imports)
        imports->release();

    if (optimizedBindings)
        optimizedBindings->release();

    delete [] idValues;

    if (isInternal)
        delete publicContext;

    delete this;
}

void QDeclarativeContextData::setParent(QDeclarativeContextData *p)
{
    if (p) {
        parent = p;
        engine = p->engine;
        nextChild = p->childContexts;
        if (nextChild) nextChild->prevChild = &nextChild;
        prevChild = &p->childContexts;
        p->childContexts = this;
    }
}

void QDeclarativeContextData::invalidateEngines()
{
    if (!engine)
        return;
    engine = 0;

    QDeclarativeContextData *child = childContexts;
    while (child) {
        child->invalidateEngines();
        child = child->nextChild;
    }
}

/* 
Refreshes all expressions that could possibly depend on this context.  Refreshing flushes all 
context-tree dependent caches in the expressions, and should occur every time the context tree 
 *structure* (not values) changes.
*/
void QDeclarativeContextData::refreshExpressions()
{
    QDeclarativeContextData *child = childContexts;
    while (child) {
        child->refreshExpressions();
        child = child->nextChild;
    }

    QDeclarativeAbstractExpression *expression = expressions;
    while (expression) {
        expression->refresh();
        expression = expression->m_nextExpression;
    }
}

void QDeclarativeContextData::addObject(QObject *o)
{
    QDeclarativeDeclarativeData *data = QDeclarativeDeclarativeData::get(o, true);

    Q_ASSERT(data->context == 0);

    data->context = this;
    data->outerContext = this;

    data->nextContextObject = contextObjects;
    if (data->nextContextObject) 
        data->nextContextObject->prevContextObject = &data->nextContextObject;
    data->prevContextObject = &contextObjects;
    contextObjects = data;
}

void QDeclarativeContextData::addScript(const QDeclarativeParser::Object::ScriptBlock &script, 
                                        QObject *scopeObject)
{
    if (!engine) 
        return;

    QDeclarativeEnginePrivate *enginePriv = QDeclarativeEnginePrivate::get(engine);
    QScriptEngine *scriptEngine = QDeclarativeEnginePrivate::getScriptEngine(engine);

    QScriptContext *scriptContext = QScriptDeclarativeClass::pushCleanContext(scriptEngine);

    scriptContext->pushScope(enginePriv->contextClass->newContext(this, scopeObject));
    scriptContext->pushScope(enginePriv->globalClass->globalObject());
    
    QScriptValue scope = scriptEngine->newObject();
    scriptContext->setActivationObject(scope);
    scriptContext->pushScope(scope);

    for (int ii = 0; ii < script.codes.count(); ++ii) {
        scriptEngine->evaluate(script.codes.at(ii), script.files.at(ii), script.lineNumbers.at(ii));

        if (scriptEngine->hasUncaughtException()) {
            QDeclarativeError error;
            QDeclarativeExpressionPrivate::exceptionToError(scriptEngine, error);
            qWarning().nospace() << qPrintable(error.toString());
        }
    }

    scriptEngine->popContext();

    scripts.append(scope);
}

void QDeclarativeContextData::setIdProperty(int idx, QObject *obj)
{
    idValues[idx] = obj;
    idValues[idx].context = this;
}

void QDeclarativeContextData::setIdPropertyData(QDeclarativeIntegerCache *data)
{
    Q_ASSERT(!propertyNames);
    propertyNames = data;
    propertyNames->addref();

    idValueCount = data->count();
    idValues = new ContextGuard[idValueCount];
}

QDeclarativeContext *QDeclarativeContextData::asQDeclarativeContext()
{
    if (!publicContext) 
        publicContext = new QDeclarativeContext(this);
    return publicContext;
}

QDeclarativeContextPrivate *QDeclarativeContextData::asQDeclarativeContextPrivate()
{
    return QDeclarativeContextPrivate::get(asQDeclarativeContext());
}

QT_END_NAMESPACE
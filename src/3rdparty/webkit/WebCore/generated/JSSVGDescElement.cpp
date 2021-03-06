/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(SVG)

#include "JSSVGDescElement.h"

#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "CSSValue.h"
#include "JSCSSStyleDeclaration.h"
#include "JSCSSValue.h"
#include "JSSVGAnimatedString.h"
#include "KURL.h"
#include "SVGDescElement.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGDescElement);

/* Hash table */

static const HashTableValue JSSVGDescElementTableValues[5] =
{
    { "xmllang", DontDelete, (intptr_t)jsSVGDescElementXmllang, (intptr_t)setJSSVGDescElementXmllang },
    { "xmlspace", DontDelete, (intptr_t)jsSVGDescElementXmlspace, (intptr_t)setJSSVGDescElementXmlspace },
    { "className", DontDelete|ReadOnly, (intptr_t)jsSVGDescElementClassName, (intptr_t)0 },
    { "style", DontDelete|ReadOnly, (intptr_t)jsSVGDescElementStyle, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGDescElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSSVGDescElementTableValues, 0 };
#else
    { 9, 7, JSSVGDescElementTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSSVGDescElementPrototypeTableValues[2] =
{
    { "getPresentationAttribute", DontDelete|Function, (intptr_t)jsSVGDescElementPrototypeFunctionGetPresentationAttribute, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGDescElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGDescElementPrototypeTableValues, 0 };
#else
    { 2, 1, JSSVGDescElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGDescElementPrototype::s_info = { "SVGDescElementPrototype", 0, &JSSVGDescElementPrototypeTable, 0 };

JSObject* JSSVGDescElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGDescElement>(exec, globalObject);
}

bool JSSVGDescElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSVGDescElementPrototypeTable, this, propertyName, slot);
}

bool JSSVGDescElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSVGDescElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGDescElement::s_info = { "SVGDescElement", &JSSVGElement::s_info, &JSSVGDescElementTable, 0 };

JSSVGDescElement::JSSVGDescElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGDescElement> impl)
    : JSSVGElement(structure, globalObject, impl)
{
}

JSObject* JSSVGDescElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGDescElementPrototype(JSSVGDescElementPrototype::createStructure(JSSVGElementPrototype::self(exec, globalObject)));
}

bool JSSVGDescElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGDescElement, Base>(exec, &JSSVGDescElementTable, this, propertyName, slot);
}

bool JSSVGDescElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGDescElement, Base>(exec, &JSSVGDescElementTable, this, propertyName, descriptor);
}

JSValue jsSVGDescElementXmllang(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGDescElement* castedThis = static_cast<JSSVGDescElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGDescElement* imp = static_cast<SVGDescElement*>(castedThis->impl());
    return jsString(exec, imp->xmllang());
}

JSValue jsSVGDescElementXmlspace(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGDescElement* castedThis = static_cast<JSSVGDescElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGDescElement* imp = static_cast<SVGDescElement*>(castedThis->impl());
    return jsString(exec, imp->xmlspace());
}

JSValue jsSVGDescElementClassName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGDescElement* castedThis = static_cast<JSSVGDescElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGDescElement* imp = static_cast<SVGDescElement*>(castedThis->impl());
    RefPtr<SVGAnimatedString> obj = imp->classNameAnimated();
    return toJS(exec, castedThis->globalObject(), obj.get(), imp);
}

JSValue jsSVGDescElementStyle(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSSVGDescElement* castedThis = static_cast<JSSVGDescElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    SVGDescElement* imp = static_cast<SVGDescElement*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->style()));
}

void JSSVGDescElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGDescElement, Base>(exec, propertyName, value, &JSSVGDescElementTable, this, slot);
}

void setJSSVGDescElementXmllang(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGDescElement* imp = static_cast<SVGDescElement*>(static_cast<JSSVGDescElement*>(thisObject)->impl());
    imp->setXmllang(value.toString(exec));
}

void setJSSVGDescElementXmlspace(ExecState* exec, JSObject* thisObject, JSValue value)
{
    SVGDescElement* imp = static_cast<SVGDescElement*>(static_cast<JSSVGDescElement*>(thisObject)->impl());
    imp->setXmlspace(value.toString(exec));
}

JSValue JSC_HOST_CALL jsSVGDescElementPrototypeFunctionGetPresentationAttribute(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGDescElement::s_info))
        return throwError(exec, TypeError);
    JSSVGDescElement* castedThisObj = static_cast<JSSVGDescElement*>(asObject(thisValue));
    SVGDescElement* imp = static_cast<SVGDescElement*>(castedThisObj->impl());
    const UString& name = args.at(0).toString(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->getPresentationAttribute(name)));
    return result;
}


}

#endif // ENABLE(SVG)

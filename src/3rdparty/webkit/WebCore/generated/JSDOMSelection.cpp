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
#include "JSDOMSelection.h"

#include "DOMSelection.h"
#include "JSNode.h"
#include "JSRange.h"
#include "KURL.h"
#include "Node.h"
#include "Range.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSDOMSelection);

/* Hash table */

static const HashTableValue JSDOMSelectionTableValues[12] =
{
    { "anchorNode", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionAnchorNode, (intptr_t)0 },
    { "anchorOffset", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionAnchorOffset, (intptr_t)0 },
    { "focusNode", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionFocusNode, (intptr_t)0 },
    { "focusOffset", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionFocusOffset, (intptr_t)0 },
    { "isCollapsed", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionIsCollapsed, (intptr_t)0 },
    { "rangeCount", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionRangeCount, (intptr_t)0 },
    { "baseNode", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionBaseNode, (intptr_t)0 },
    { "baseOffset", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionBaseOffset, (intptr_t)0 },
    { "extentNode", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionExtentNode, (intptr_t)0 },
    { "extentOffset", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionExtentOffset, (intptr_t)0 },
    { "type", DontDelete|ReadOnly, (intptr_t)jsDOMSelectionType, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSDOMSelectionTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 63, JSDOMSelectionTableValues, 0 };
#else
    { 34, 31, JSDOMSelectionTableValues, 0 };
#endif

/* Hash table for prototype */

static const HashTableValue JSDOMSelectionPrototypeTableValues[16] =
{
    { "collapse", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionCollapse, (intptr_t)2 },
    { "collapseToEnd", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionCollapseToEnd, (intptr_t)0 },
    { "collapseToStart", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionCollapseToStart, (intptr_t)0 },
    { "deleteFromDocument", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionDeleteFromDocument, (intptr_t)0 },
    { "containsNode", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionContainsNode, (intptr_t)2 },
    { "selectAllChildren", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionSelectAllChildren, (intptr_t)1 },
    { "extend", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionExtend, (intptr_t)2 },
    { "getRangeAt", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionGetRangeAt, (intptr_t)1 },
    { "removeAllRanges", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionRemoveAllRanges, (intptr_t)0 },
    { "addRange", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionAddRange, (intptr_t)1 },
    { "toString", DontDelete|DontEnum|Function, (intptr_t)jsDOMSelectionPrototypeFunctionToString, (intptr_t)0 },
    { "modify", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionModify, (intptr_t)3 },
    { "setBaseAndExtent", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionSetBaseAndExtent, (intptr_t)4 },
    { "setPosition", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionSetPosition, (intptr_t)2 },
    { "empty", DontDelete|Function, (intptr_t)jsDOMSelectionPrototypeFunctionEmpty, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSDOMSelectionPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 2047, JSDOMSelectionPrototypeTableValues, 0 };
#else
    { 34, 31, JSDOMSelectionPrototypeTableValues, 0 };
#endif

const ClassInfo JSDOMSelectionPrototype::s_info = { "DOMSelectionPrototype", 0, &JSDOMSelectionPrototypeTable, 0 };

JSObject* JSDOMSelectionPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSDOMSelection>(exec, globalObject);
}

bool JSDOMSelectionPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSDOMSelectionPrototypeTable, this, propertyName, slot);
}

bool JSDOMSelectionPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSDOMSelectionPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSDOMSelection::s_info = { "DOMSelection", 0, &JSDOMSelectionTable, 0 };

JSDOMSelection::JSDOMSelection(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<DOMSelection> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSDOMSelection::~JSDOMSelection()
{
    forgetDOMObject(this, impl());
}

JSObject* JSDOMSelection::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSDOMSelectionPrototype(JSDOMSelectionPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSDOMSelection::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDOMSelection, Base>(exec, &JSDOMSelectionTable, this, propertyName, slot);
}

bool JSDOMSelection::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDOMSelection, Base>(exec, &JSDOMSelectionTable, this, propertyName, descriptor);
}

JSValue jsDOMSelectionAnchorNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->anchorNode()));
}

JSValue jsDOMSelectionAnchorOffset(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsNumber(exec, imp->anchorOffset());
}

JSValue jsDOMSelectionFocusNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->focusNode()));
}

JSValue jsDOMSelectionFocusOffset(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsNumber(exec, imp->focusOffset());
}

JSValue jsDOMSelectionIsCollapsed(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsBoolean(imp->isCollapsed());
}

JSValue jsDOMSelectionRangeCount(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsNumber(exec, imp->rangeCount());
}

JSValue jsDOMSelectionBaseNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->baseNode()));
}

JSValue jsDOMSelectionBaseOffset(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsNumber(exec, imp->baseOffset());
}

JSValue jsDOMSelectionExtentNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->extentNode()));
}

JSValue jsDOMSelectionExtentOffset(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsNumber(exec, imp->extentOffset());
}

JSValue jsDOMSelectionType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSDOMSelection* castedThis = static_cast<JSDOMSelection*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    DOMSelection* imp = static_cast<DOMSelection*>(castedThis->impl());
    return jsString(exec, imp->type());
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionCollapse(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Node* node = toNode(args.at(0));
    int index = args.at(1).toInt32(exec);

    imp->collapse(node, index, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionCollapseToEnd(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());

    imp->collapseToEnd();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionCollapseToStart(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());

    imp->collapseToStart();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionDeleteFromDocument(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());

    imp->deleteFromDocument();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionContainsNode(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    Node* node = toNode(args.at(0));
    bool allowPartial = args.at(1).toBoolean(exec);


    JSC::JSValue result = jsBoolean(imp->containsNode(node, allowPartial));
    return result;
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionSelectAllChildren(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Node* node = toNode(args.at(0));

    imp->selectAllChildren(node, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionExtend(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Node* node = toNode(args.at(0));
    int offset = args.at(1).toInt32(exec);

    imp->extend(node, offset, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionGetRangeAt(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int index = args.at(0).toInt32(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->getRangeAt(index, ec)));
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionRemoveAllRanges(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());

    imp->removeAllRanges();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionAddRange(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    Range* range = toRange(args.at(0));

    imp->addRange(range);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionToString(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());


    JSC::JSValue result = jsString(exec, imp->toString());
    return result;
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionModify(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    const UString& alter = args.at(0).toString(exec);
    const UString& direction = args.at(1).toString(exec);
    const UString& granularity = args.at(2).toString(exec);

    imp->modify(alter, direction, granularity);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionSetBaseAndExtent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Node* baseNode = toNode(args.at(0));
    int baseOffset = args.at(1).toInt32(exec);
    Node* extentNode = toNode(args.at(2));
    int extentOffset = args.at(3).toInt32(exec);

    imp->setBaseAndExtent(baseNode, baseOffset, extentNode, extentOffset, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionSetPosition(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Node* node = toNode(args.at(0));
    int offset = args.at(1).toInt32(exec);

    imp->setPosition(node, offset, ec);
    setDOMException(exec, ec);
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsDOMSelectionPrototypeFunctionEmpty(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSDOMSelection::s_info))
        return throwError(exec, TypeError);
    JSDOMSelection* castedThisObj = static_cast<JSDOMSelection*>(asObject(thisValue));
    DOMSelection* imp = static_cast<DOMSelection*>(castedThisObj->impl());

    imp->empty();
    return jsUndefined();
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, DOMSelection* object)
{
    return getDOMObjectWrapper<JSDOMSelection>(exec, globalObject, object);
}
DOMSelection* toDOMSelection(JSC::JSValue value)
{
    return value.inherits(&JSDOMSelection::s_info) ? static_cast<JSDOMSelection*>(asObject(value))->impl() : 0;
}

}

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

#if ENABLE(VIDEO_TRACK)

#include "JSTrackEvent.h"

#include "JSDictionary.h"
#include "TrackEvent.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table */

static const HashTableValue JSTrackEventTableValues[] =
{
    { "track", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTrackEventTrack), (intptr_t)0 },
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTrackEventConstructor), (intptr_t)0 },
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSTrackEventTable = { 4, 3, JSTrackEventTableValues, 0 };
/* Hash table for constructor */

static const HashTableValue JSTrackEventConstructorTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSTrackEventConstructorTable = { 1, 0, JSTrackEventConstructorTableValues, 0 };
EncodedJSValue JSC_HOST_CALL JSTrackEventConstructor::constructJSTrackEvent(ExecState* exec)
{
    JSTrackEventConstructor* jsConstructor = jsCast<JSTrackEventConstructor*>(exec->callee());

    ScriptExecutionContext* executionContext = jsConstructor->scriptExecutionContext();
    if (!executionContext)
        return throwVMError(exec, createReferenceError(exec, "Constructor associated execution context is unavailable"));

    AtomicString eventType = exec->argument(0).toString(exec)->value(exec);
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    TrackEventInit eventInit;

    JSValue initializerValue = exec->argument(1);
    if (!initializerValue.isUndefinedOrNull()) {
        // Given the above test, this will always yield an object.
        JSObject* initializerObject = initializerValue.toObject(exec);

        // Create the dictionary wrapper from the initializer object.
        JSDictionary dictionary(exec, initializerObject);

        // Attempt to fill in the EventInit.
        if (!fillTrackEventInit(eventInit, dictionary))
            return JSValue::encode(jsUndefined());
    }

    RefPtr<TrackEvent> event = TrackEvent::create(eventType, eventInit);
    return JSValue::encode(toJS(exec, jsConstructor->globalObject(), event.get()));
}

bool fillTrackEventInit(TrackEventInit& eventInit, JSDictionary& dictionary)
{
    if (!fillEventInit(eventInit, dictionary))
        return false;

    if (!dictionary.tryGetProperty("track", eventInit.track))
        return false;
    return true;
}

const ClassInfo JSTrackEventConstructor::s_info = { "TrackEventConstructor", &Base::s_info, &JSTrackEventConstructorTable, 0, CREATE_METHOD_TABLE(JSTrackEventConstructor) };

JSTrackEventConstructor::JSTrackEventConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTrackEventConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSTrackEventPrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(1), ReadOnly | DontDelete | DontEnum);
}

bool JSTrackEventConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTrackEventConstructor, JSDOMWrapper>(exec, JSTrackEventConstructorTable, jsCast<JSTrackEventConstructor*>(object), propertyName, slot);
}

ConstructType JSTrackEventConstructor::getConstructData(JSCell*, ConstructData& constructData)
{
    constructData.native.function = constructJSTrackEvent;
    return ConstructTypeHost;
}

/* Hash table for prototype */

static const HashTableValue JSTrackEventPrototypeTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSTrackEventPrototypeTable = { 1, 0, JSTrackEventPrototypeTableValues, 0 };
const ClassInfo JSTrackEventPrototype::s_info = { "TrackEventPrototype", &Base::s_info, &JSTrackEventPrototypeTable, 0, CREATE_METHOD_TABLE(JSTrackEventPrototype) };

JSObject* JSTrackEventPrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTrackEvent>(vm, globalObject);
}

const ClassInfo JSTrackEvent::s_info = { "TrackEvent", &Base::s_info, &JSTrackEventTable, 0 , CREATE_METHOD_TABLE(JSTrackEvent) };

JSTrackEvent::JSTrackEvent(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TrackEvent> impl)
    : JSEvent(structure, globalObject, impl)
{
}

void JSTrackEvent::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSTrackEvent::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSTrackEventPrototype::create(vm, globalObject, JSTrackEventPrototype::createStructure(vm, globalObject, JSEventPrototype::self(vm, globalObject)));
}

bool JSTrackEvent::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTrackEvent* thisObject = jsCast<JSTrackEvent*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    return getStaticValueSlot<JSTrackEvent, Base>(exec, JSTrackEventTable, thisObject, propertyName, slot);
}

EncodedJSValue jsTrackEventTrack(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSTrackEvent* castedThis = jsDynamicCast<JSTrackEvent*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    return JSValue::encode(castedThis->track(exec));
}


EncodedJSValue jsTrackEventConstructor(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue, PropertyName)
{
    JSTrackEvent* domObject = jsDynamicCast<JSTrackEvent*>(JSValue::decode(thisValue));
    if (!domObject)
        return throwVMTypeError(exec);
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSTrackEvent::getConstructor(exec->vm(), domObject->globalObject()));
}

JSValue JSTrackEvent::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTrackEventConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}


}

#endif // ENABLE(VIDEO_TRACK)

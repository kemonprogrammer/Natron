
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <pysidesignal.h>
#include <shiboken.h> // produces many warnings
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <pysideqenum.h>
#include <feature_select.h>
#include <qapp_macro.h>

QT_WARNING_DISABLE_DEPRECATED

#include <typeinfo>
#include <iterator>

// module include
#include "natronengine_python.h"

// main header
#include "double3dparam_wrapper.h"

// inner classes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING

#include <cctype>
#include <cstring>



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}

// Native ---------------------------------------------------------

void Double3DParamWrapper::pysideInitQtMetaTypes()
{
}

void Double3DParamWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

Double3DParamWrapper::~Double3DParamWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Double3DParamFunc_get(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Double3DParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "get", 0, 1, &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: DoubleParam::get()const
    // 1: DoubleParam::get(double)const
    if (numArgs == 0) {
        overloadId = 0; // get()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        overloadId = 1; // get(double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Double3DParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                Double3DTuple* cppResult = new Double3DTuple(const_cast<const ::Double3DParam *>(cppSelf)->get());
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX]), cppResult, true, true);
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                Double3DTuple* cppResult = new Double3DTuple(const_cast<const ::Double3DParam *>(cppSelf)->get(cppArg0));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX]), cppResult, true, true);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Double3DParamFunc_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Double3DParam.get");
        return {};
}

static PyObject *Sbk_Double3DParamFunc_set(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Double3DParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    const Py_ssize_t numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "set", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: Double2DParam::set(double,double,double)
    // 1: DoubleParam::set(double,double)
    // 2: DoubleParam::set(double)
    // 3: Double3DParam::set(double,double,double,double)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // set(double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // set(double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // set(double,double,double)
                } else if (numArgs == 4
                    && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 3; // set(double,double,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Double3DParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(double x, double y, double z)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // set(double,double,double)
                // Begin code injection
                cppSelf->set(cppArg0,cppArg1,cppArg2);

                // End of code injection

            }
            break;
        }
        case 1: // set(double x, double y)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(double,double)
                reinterpret_cast<Double2DParam *>(cppSelf)->set(cppArg0, cppArg1);
            }
            break;
        }
        case 2: // set(double x)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(double)
                reinterpret_cast<DoubleParam *>(cppSelf)->set(cppArg0);
            }
            break;
        }
        case 3: // set(double x, double y, double z, double frame)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // set(double,double,double,double)
                // Begin code injection
                cppSelf->set(cppArg0,cppArg1,cppArg2,cppArg3);

                // End of code injection

            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Double3DParamFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Double3DParam.set");
        return {};
}


static const char *Sbk_Double3DParam_PropertyStrings[] = {
    nullptr // Sentinel
};

static PyMethodDef Sbk_Double3DParam_methods[] = {
    {"get", reinterpret_cast<PyCFunction>(Sbk_Double3DParamFunc_get), METH_VARARGS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Double3DParamFunc_set), METH_VARARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Double3DParam_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    PySide::Feature::Select(self);
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Double3DParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_DOUBLE3DPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<Double3DParamWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Double3DParam_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Double3DParam_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Double3DParam_Type = nullptr;
static SbkObjectType *Sbk_Double3DParam_TypeF(void)
{
    return _Sbk_Double3DParam_Type;
}

static PyType_Slot Sbk_Double3DParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Double3DParam_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Double3DParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Double3DParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Double3DParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Double3DParam_spec = {
    "1:NatronEngine.Double3DParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Double3DParam_slots
};

} //extern "C"

static void *Sbk_Double3DParam_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Param >()))
        return dynamic_cast< ::Double3DParam *>(reinterpret_cast< ::Param *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Double3DParam_PythonToCpp_Double3DParam_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Double3DParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_Double3DParam_PythonToCpp_Double3DParam_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Double3DParam_TypeF())))
        return Double3DParam_PythonToCpp_Double3DParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *Double3DParam_PTR_CppToPython_Double3DParam(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Double3DParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
    }
    PyObject *result = Shiboken::Object::newObject(Sbk_Double3DParam_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Double3DParam_SignatureStrings[] = {
    "1:NatronEngine.Double3DParam.get(self)->NatronEngine.Double3DTuple",
    "0:NatronEngine.Double3DParam.get(self,frame:double)->NatronEngine.Double3DTuple",
    "3:NatronEngine.Double3DParam.set(self,x:double,y:double,z:double)",
    "2:NatronEngine.Double3DParam.set(self,x:double,y:double)",
    "1:NatronEngine.Double3DParam.set(self,x:double)",
    "0:NatronEngine.Double3DParam.set(self,x:double,y:double,z:double,frame:double)",
    nullptr}; // Sentinel

void init_Double3DParam(PyObject *module)
{
    _Sbk_Double3DParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Double3DParam",
        "Double3DParam*",
        &Sbk_Double3DParam_spec,
        &Shiboken::callCppDestructor< ::Double3DParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX]),
        0,
        0    );
    
    auto pyType = reinterpret_cast<PyTypeObject *>(_Sbk_Double3DParam_Type);
    InitSignatureStrings(pyType, Double3DParam_SignatureStrings);
    SbkObjectType_SetPropertyStrings(reinterpret_cast<PyTypeObject *>(_Sbk_Double3DParam_Type), Sbk_Double3DParam_PropertyStrings);
    SbkNatronEngineTypes[SBK_DOUBLE3DPARAM_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Double3DParam_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Double3DParam_TypeF(),
        Double3DParam_PythonToCpp_Double3DParam_PTR,
        is_Double3DParam_PythonToCpp_Double3DParam_PTR_Convertible,
        Double3DParam_PTR_CppToPython_Double3DParam);

    Shiboken::Conversions::registerConverterName(converter, "Double3DParam");
    Shiboken::Conversions::registerConverterName(converter, "Double3DParam*");
    Shiboken::Conversions::registerConverterName(converter, "Double3DParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Double3DParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::Double3DParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Double3DParam_TypeF(), &Sbk_Double3DParam_typeDiscovery);


    Double3DParamWrapper::pysideInitQtMetaTypes();
}

#include <Python.h>
#include <stdint.h>

static inline uint64_t _rdtscp(void)
{
    unsigned long _hi, _lo;
    asm volatile("rdtscp" : "=a"(_lo), "=d"(_hi));
    uint64_t val = (((uint64_t)_hi) << 32 | ((uint64_t)_lo));
    return val;
}

static PyObject* do_rdtscp(PyObject *self, PyObject *args)
{
    uint64_t res;
    res = _rdtscp();

    return Py_BuildValue("l", res);
}

static PyMethodDef rdtscp_module_methods[] = { 
    {   
        "rdtscp",
        do_rdtscp,
        METH_NOARGS,
        "C Extension for Python3 to call RDTSCP()"
    },  
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef rdtscp_module_definition = { 
    PyModuleDef_HEAD_INIT,
    "rdtscp_module",
    "C Extension for Python3 to call RDTSCP()",
    -1, 
    rdtscp_module_methods
};

PyMODINIT_FUNC PyInit_rdtscp_module(void)
{
    Py_Initialize();

    return PyModule_Create(&rdtscp_module_definition);
}

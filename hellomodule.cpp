#include <Python.h>
#include "hello.h"

static PyObject * hello_wrapper(PyObject *self, PyObject *args) {
    const char *command;
    const char * sts;

    if(!PyArg_ParseTuple(args, "s", &command))
        return NULL;

    sts = hello(command);

    return PyBytes_FromString(sts);
}

static PyObject * hello_robot_wrapper(PyObject *self, PyObject *args) {
    const char *name;
    char result[100];

    if(!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    hello_robot(name, result, 100);

    return PyBytes_FromString(result);
}

static PyMethodDef HelloMethods[] = {
    {"hello", hello_wrapper, METH_VARARGS, "Returns what you write"},
    {"hello_robot", hello_robot_wrapper, METH_VARARGS, "Hello robot func"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",
    NULL,
    -1,
    HelloMethods
};

PyMODINIT_FUNC PyInit_hello(void){
    return PyModule_Create(&hellomodule);
}

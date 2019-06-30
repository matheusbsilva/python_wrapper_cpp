#include <Python.h>

const char * hello(const char * what) {
    return what;
}

static PyObject * hello_wrapper(PyObject *self, PyObject *args) {
    const char *command;
    const char * sts;

    if(!PyArg_ParseTuple(args, "s", &command))
        return NULL;

    sts = hello(command);

    return PyBytes_FromString(sts);
}

static PyMethodDef HelloMethods[] = {
    {"hello", hello_wrapper, METH_VARARGS, "Return String"},
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

#include <Python.h>

int main() {
    Py_Initialize(); // 初始化 Python 解釋器

    PyObject* pName = PyUnicode_DecodeFSDefault("your_python_module");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        PyObject* pFunc = PyObject_GetAttrString(pModule, "your_function");
        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject* pArgs = PyTuple_Pack(1, PyLong_FromLong(42)); // 傳遞參數
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != nullptr) {
                printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                Py_DECREF(pValue);
            } else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
                return 1;
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"your_python_module\"\n");
        return 1;
    }

    Py_Finalize(); // 結束 Python 解釋器
    return 0;
}

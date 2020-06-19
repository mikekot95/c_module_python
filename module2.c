#include <Python.h>
#include <stdbool.h>

PyObject* TestModule_TestMethod(PyObject* self, PyObject* args) {
	bool flag;
	int value;
	if (PyTuple_Size(args) != 2) {
		return NULL;
	}
	if (!PyArg_ParseTuple(args, "pi", &flag, &value)) {
		return NULL;
	}
	if (flag) {
		return Py_BuildValue("i", value++);
	}else {
		return Py_BuildValue("i", value--);
	}
}

static PyMethodDef TestModule_funcs[] = {
	{"TestMethod", (PyCFunction)TestModule_TestMethod, METH_VARARGS, "TestMethod"},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC PyInit_TestModule(void) {
	PyObject *module;
	static struct PyModuleDef moduledef = {
		PyModuleDef_HEAD_INIT,
		"TestModule",
		"TestModule",
		-1,
		TestModule_funcs,
		NULL,
		NULL,
		NULL,
		NULL
	};
	module = PyModule_Create(&moduledef);
	if (!module) return NULL;
	return module;
}

/*PyMODINIT_FUNC PyInit_TestModule(void) {
	Py_InitModule3("TestModule", TestModule_funcs, "TestModule");
}*/


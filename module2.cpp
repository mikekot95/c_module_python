#include <Python.h>
#include <stdbool.h>

PyObject* TestModule_TestMethod(PyObject* self, PyObject* args) {
	struct TestClass {
		bool flag;
		int value;
		int TestMethod() {
			if (flag) return value+1;
			return value-1;
		}
	} TestObject;
	if (PyTuple_Size(args) != 2) {
		return NULL;
	}
	if (!PyArg_ParseTuple(args, "pi", &TestObject.flag, &TestObject.value)) {
		return NULL;
	}
	return Py_BuildValue("i", TestObject.TestMethod());
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
from distutils.core import setup, Extension

setup(name='TestModule', version='1.0',\
      ext_modules=[Extension('TestModule', ['module.cpp'])])

from distutils.core import setup, Extension

extension_mod = Extension("hello", sources=["hellomodule.cpp"])

setup(name = "hello", ext_modules=[extension_mod])

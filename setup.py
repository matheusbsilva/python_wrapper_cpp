from distutils.core import setup, Extension

extension_mod = Extension("hello", include_dirs=['./include/'],
                          sources=["hellomodule.cpp", "hello.cpp"])

setup(name = "hello", ext_modules=[extension_mod])

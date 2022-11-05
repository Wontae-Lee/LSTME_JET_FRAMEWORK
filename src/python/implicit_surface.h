#ifndef SRC_PYTHON_IMPLICIT_SURFACE_H_
#define SRC_PYTHON_IMPLICIT_SURFACE_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addImplicitSurface2(pybind11::module& m);
void
addImplicitSurface3(pybind11::module& m);

#endif // SRC_PYTHON_IMPLICIT_SURFACE_H_

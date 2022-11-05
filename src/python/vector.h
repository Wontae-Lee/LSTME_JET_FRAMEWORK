#ifndef SRC_PYTHON_VECTOR_H_
#define SRC_PYTHON_VECTOR_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addVector2F(pybind11::module& m);
void
addVector2D(pybind11::module& m);
void
addVector3F(pybind11::module& m);
void
addVector3D(pybind11::module& m);

#endif // SRC_PYTHON_VECTOR_H_

#ifndef SRC_PYTHON_RAY_H_
#define SRC_PYTHON_RAY_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addRay2F(pybind11::module& m);
void
addRay2D(pybind11::module& m);
void
addRay3F(pybind11::module& m);
void
addRay3D(pybind11::module& m);

#endif // SRC_PYTHON_RAY_H_

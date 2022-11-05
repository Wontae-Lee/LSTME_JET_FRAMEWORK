#ifndef SRC_PYTHON_BOUNDING_BOX_H_
#define SRC_PYTHON_BOUNDING_BOX_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addBoundingBox2F(pybind11::module& m);
void
addBoundingBox2D(pybind11::module& m);
void
addBoundingBox3F(pybind11::module& m);
void
addBoundingBox3D(pybind11::module& m);

#endif // SRC_PYTHON_BOUNDING_BOX_H_

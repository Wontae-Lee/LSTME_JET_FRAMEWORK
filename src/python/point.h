#ifndef SRC_PYTHON_POINT_H_
#define SRC_PYTHON_POINT_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addPoint2UI(pybind11::module& m);
void
addPoint3UI(pybind11::module& m);

#endif // SRC_PYTHON_POINT_H_

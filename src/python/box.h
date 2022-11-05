#ifndef SRC_PYTHON_BOX_H_
#define SRC_PYTHON_BOX_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addBox2(pybind11::module& m);
void
addBox3(pybind11::module& m);

#endif // SRC_PYTHON_BOX_H_

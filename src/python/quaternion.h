#ifndef SRC_PYTHON_QUATERNION_H_
#define SRC_PYTHON_QUATERNION_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addQuaternionF(pybind11::module& m);
void
addQuaternionD(pybind11::module& m);

#endif // SRC_PYTHON_QUATERNION_H_

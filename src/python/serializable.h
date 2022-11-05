#ifndef SRC_PYTHON_SERIALIZABLE_H_
#define SRC_PYTHON_SERIALIZABLE_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addSerializable(pybind11::module& m);

#endif // SRC_PYTHON_SERIALIZABLE_H_

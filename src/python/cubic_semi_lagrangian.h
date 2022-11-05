#ifndef SRC_PYTHON_CUBIC_SEMI_LAGRANGIAN_H_
#define SRC_PYTHON_CUBIC_SEMI_LAGRANGIAN_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addCubicSemiLagrangian2(pybind11::module& m);
void
addCubicSemiLagrangian3(pybind11::module& m);

#endif // SRC_PYTHON_CUBIC_SEMI_LAGRANGIAN_H_

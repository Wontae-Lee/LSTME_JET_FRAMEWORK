#ifndef SRC_PYTHON_FMM_LEVEL_SET_SOLVER_H_
#define SRC_PYTHON_FMM_LEVEL_SET_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addFmmLevelSetSolver2(pybind11::module& m);
void
addFmmLevelSetSolver3(pybind11::module& m);

#endif // SRC_PYTHON_FMM_LEVEL_SET_SOLVER_H_

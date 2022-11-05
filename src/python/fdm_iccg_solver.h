#ifndef SRC_PYTHON_FDM_ICCG_SOLVER_SOLVER_H_
#define SRC_PYTHON_FDM_ICCG_SOLVER_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addFdmIccgSolver2(pybind11::module& m);
void
addFdmIccgSolver3(pybind11::module& m);

#endif // SRC_PYTHON_FDM_ICCG_SOLVER_SOLVER_H_

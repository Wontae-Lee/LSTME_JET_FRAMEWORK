#ifndef SRC_PYTHON_FDM_GAUSS_SEIDEL_SOLVER_SOLVER_H_
#define SRC_PYTHON_FDM_GAUSS_SEIDEL_SOLVER_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addFdmGaussSeidelSolver2(pybind11::module& m);
void
addFdmGaussSeidelSolver3(pybind11::module& m);

#endif // SRC_PYTHON_FDM_GAUSS_SEIDEL_SOLVER_SOLVER_H_

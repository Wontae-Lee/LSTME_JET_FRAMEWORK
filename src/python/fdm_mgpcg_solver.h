#ifndef SRC_PYTHON_FDM_MGPCG_SOLVER2_H_
#define SRC_PYTHON_FDM_MGPCG_SOLVER2_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addFdmMgpcgSolver2(pybind11::module& m);
void
addFdmMgpcgSolver3(pybind11::module& m);

#endif // SRC_PYTHON_FDM_MGPCG_SOLVER2_H_

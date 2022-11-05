#ifndef SRC_PYTHON_PCI_SPH_SOLVER_H_
#define SRC_PYTHON_PCI_SPH_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addPciSphSolver2(pybind11::module& m);
void
addPciSphSolver3(pybind11::module& m);

#endif // SRC_PYTHON_PCI_SPH_SOLVER_H_

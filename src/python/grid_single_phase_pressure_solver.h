#ifndef SRC_PYTHON_GRID_SINGLE_PHASE_PRESSURE_SOLVER_H_
#define SRC_PYTHON_GRID_SINGLE_PHASE_PRESSURE_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addGridSinglePhasePressureSolver2(pybind11::module& m);
void
addGridSinglePhasePressureSolver3(pybind11::module& m);

#endif // SRC_PYTHON_GRID_SINGLE_PHASE_PRESSURE_SOLVER_H_

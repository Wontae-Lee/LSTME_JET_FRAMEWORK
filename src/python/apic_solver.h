#ifndef SRC_PYTHON_APIC_SOLVER_H_
#define SRC_PYTHON_APIC_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addApicSolver2(pybind11::module& m);
void
addApicSolver3(pybind11::module& m);

#endif // SRC_PYTHON_APIC_SOLVER_H_

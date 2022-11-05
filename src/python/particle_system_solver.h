#ifndef SRC_PYTHON_PARTICLE_SYSTEM_SOLVER_H_
#define SRC_PYTHON_PARTICLE_SYSTEM_SOLVER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addParticleSystemSolver2(pybind11::module& m);
void
addParticleSystemSolver3(pybind11::module& m);

#endif // SRC_PYTHON_PARTICLE_SYSTEM_SOLVER_H_

#ifndef SRC_PYTHON_POINT_PARTICLE_EMITTER_H_
#define SRC_PYTHON_POINT_PARTICLE_EMITTER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addPointParticleEmitter2(pybind11::module& m);
void
addPointParticleEmitter3(pybind11::module& m);

#endif // SRC_PYTHON_POINT_PARTICLE_EMITTER_H_

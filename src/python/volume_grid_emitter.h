#ifndef SRC_PYTHON_VOLUME_GRID_EMITTER_H_
#define SRC_PYTHON_VOLUME_GRID_EMITTER_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addVolumeGridEmitter2(pybind11::module& m);
void
addVolumeGridEmitter3(pybind11::module& m);

#endif // SRC_PYTHON_VOLUME_GRID_EMITTER_H_

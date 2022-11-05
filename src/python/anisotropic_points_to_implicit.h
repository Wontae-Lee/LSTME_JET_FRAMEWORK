#ifndef SRC_PYTHON_ANISOTROPIC_POINTS_TO_IMPLICIT_H_
#define SRC_PYTHON_ANISOTROPIC_POINTS_TO_IMPLICIT_H_
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void
addAnisotropicPointsToImplicit2(pybind11::module& m);
void
addAnisotropicPointsToImplicit3(pybind11::module& m);

#endif // SRC_PYTHON_ANISOTROPIC_POINTS_TO_IMPLICIT_H_

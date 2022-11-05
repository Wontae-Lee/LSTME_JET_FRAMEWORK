#include "implicit_surface.h"
#include "pybind11_utils.h"
#include <jet/implicit_surface2.h>
#include <jet/implicit_surface3.h>
namespace py = pybind11;
using namespace jet;
void
addImplicitSurface2(py::module& m)
{
    py::class_<ImplicitSurface2, ImplicitSurface2Ptr, Surface2>(
        m,
        "ImplicitSurface2",
        R"pbdoc(
         Abstract base class for 2-D implicit surface.
         )pbdoc")
        .def(
            "signedDistance",
            [](const ImplicitSurface2& instance, py::object otherPoint) {
                return instance.signedDistance(objectToVector2D(otherPoint));
            },
            R"pbdoc(
             Returns signed distance from the given point otherPoint.
             )pbdoc",
            py::arg("otherPoint"));
}

void
addImplicitSurface3(py::module& m)
{
    py::class_<ImplicitSurface3, ImplicitSurface3Ptr, Surface3>(
        m,
        "ImplicitSurface3",
        R"pbdoc(
         Abstract base class for 3-D implicit surface.
         )pbdoc")
        .def(
            "signedDistance",
            [](const ImplicitSurface3& instance, py::object otherPoint) {
                return instance.signedDistance(objectToVector3D(otherPoint));
            },
            R"pbdoc(
             Returns signed distance from the given point otherPoint.
             )pbdoc",
            py::arg("otherPoint"));
}

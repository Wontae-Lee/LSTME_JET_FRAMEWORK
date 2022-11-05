#include "advection_solver.h"
#include "pybind11_utils.h"
#include <jet/advection_solver2.h>
#include <jet/advection_solver3.h>
namespace py = pybind11;
using namespace jet;
void
addAdvectionSolver2(py::module& m)
{
    py::class_<AdvectionSolver2, AdvectionSolver2Ptr>(m,
                                                      "AdvectionSolver2",
                                                      R"pbdoc(
        Abstract based class for 2-D grid-based advection solver.
        The implementation of this abstract base class should solve 2-D advection
        equation for scalar and vector fields.
        )pbdoc");
}

void
addAdvectionSolver3(py::module& m)
{
    py::class_<AdvectionSolver3, AdvectionSolver3Ptr>(m,
                                                      "AdvectionSolver3",
                                                      R"pbdoc(
        Abstract based class for 3-D grid-based advection solver.

        The implementation of this abstract base class should solve 3-D advection
        equation for scalar and vector fields.
        )pbdoc");
}

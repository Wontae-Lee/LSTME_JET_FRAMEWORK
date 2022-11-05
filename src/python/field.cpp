#include "field.h"
#include "pybind11_utils.h"
#include <jet/field2.h>
#include <jet/field3.h>
namespace py = pybind11;
using namespace jet;
void
addField2(py::module& m)
{
    py::class_<Field2, Field2Ptr>(
        m, "Field2", R"pbdoc(Abstract base class for 2-D fields.)pbdoc");
}

void
addField3(py::module& m)
{
    py::class_<Field3, Field3Ptr>(
        m, "Field3", R"pbdoc(Abstract base class for 3-D fields.)pbdoc");
}

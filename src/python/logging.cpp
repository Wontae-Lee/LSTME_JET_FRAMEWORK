#include "logging.h"
#include "pybind11_utils.h"
#include <jet/logging.h>
namespace py = pybind11;
using namespace jet;
void
addLogging(pybind11::module& m)
{
    py::enum_<LoggingLevel>(m, "LoggingLevel")
        .value("ALL", LoggingLevel::All)
        .value("DEBUG", LoggingLevel::Debug)
        .value("INFO", LoggingLevel::Info)
        .value("WARN", LoggingLevel::Warn)
        .value("ERROR", LoggingLevel::Error)
        .value("OFF", LoggingLevel::Off)
        .export_values();

    py::class_<Logging>(m, "Logging")
        .def_static("setLevel", &Logging::setLevel)
        .def_static("mute", &Logging::mute)
        .def_static("unmute", &Logging::unmute);
}

#include <benchmark/benchmark.h>
#include <fstream>
#include <jet/logging.h>
int
main(int argc, char** argv)
{
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) {
        return 1;
    }
    std::ofstream logFile("mem_perf_tests.log");
    if (logFile) {
        jet::Logging::setAllStream(&logFile);
    }

    ::benchmark::RunSpecifiedBenchmarks();
}

#include <fstream>
#include <gtest/gtest.h>
#include <jet/jet.h>
using namespace jet;
int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::ofstream logFile("mem_perf_tests.log");
    if (logFile) {
        Logging::setAllStream(&logFile);
    }
    int ret = RUN_ALL_TESTS();

    return ret;
}

#include <fstream>
#include <gtest/gtest.h>
#include <jet/jet.h>
#include <manual_tests.h>
using namespace jet;
int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    createDirectory(JET_TESTS_OUTPUT_DIR);
    std::ofstream logFile("manual_tests.log");
    if (logFile) {
        Logging::setAllStream(&logFile);
    }
    int ret = RUN_ALL_TESTS();

    return ret;
}

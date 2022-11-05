#include "mem_perf_tests.h"
#include <gtest/gtest.h>
#include <jet/fdm_iccg_solver3.h>
#include <jet/timer.h>
using namespace jet;
TEST(FdmIccgSolver3, Memory)
{
    const size_t n = 300;
    const size_t mem0 = getCurrentRSS();
    FdmLinearSystem3 system;
    system.A.resize(n, n, n);
    system.x.resize(n, n, n);
    system.b.resize(n, n, n);
    FdmIccgSolver3 solver(1, 0.0);
    solver.solve(&system);
    const size_t mem1 = getCurrentRSS();
    const auto msg = makeReadableByteSize(mem1 - mem0);

    printMemReport(msg.first, msg.second);
}

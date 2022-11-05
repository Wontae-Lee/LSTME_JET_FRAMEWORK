#include <gtest/gtest.h>
#include <jet/apic_solver3.h>
using namespace jet;
TEST(ApicSolver3, UpdateEmpty)
{
    ApicSolver3 solver;

    for (Frame frame; frame.index < 2; ++frame) {
        solver.update(frame);
    }
}

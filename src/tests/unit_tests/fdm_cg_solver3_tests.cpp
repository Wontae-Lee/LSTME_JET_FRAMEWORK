#include "fdm_linear_system_solver_test_helper3.h"
#include <jet/fdm_cg_solver3.h>
#include <gtest/gtest.h>
using namespace jet;
TEST(FdmCgSolver3, Solve)
{
    FdmLinearSystem3 system;
    FdmLinearSystemSolverTestHelper3::buildTestLinearSystem(&system,
                                                            { 3, 3, 3 });
    FdmCgSolver3 solver(100, 1e-9);
    solver.solve(&system);
    EXPECT_GT(solver.tolerance(), solver.lastResidual());
}
TEST(FdmCgSolver3, SolveCompressed)
{
    FdmCompressedLinearSystem3 system;
    FdmLinearSystemSolverTestHelper3::buildTestCompressedLinearSystem(
        &system, { 3, 3, 3 });
    FdmCgSolver3 solver(100, 1e-9);
    solver.solveCompressed(&system);

    EXPECT_GT(solver.tolerance(), solver.lastResidual());
}

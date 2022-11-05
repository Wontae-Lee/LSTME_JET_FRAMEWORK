#include "my_physics_solver.h"
using namespace jet;
MyPhysicsSolver::MyPhysicsSolver() {}
MyPhysicsSolver::~MyPhysicsSolver() {}
void
MyPhysicsSolver::onInitialize()
{
    // This function is called at frame 0
    // TODO: Perform initialization here
}
void
MyPhysicsSolver::onAdvanceTimeStep(double timeIntervalInSeconds)
{
    // This function is called at frames greater than 0
    (void)timeIntervalInSeconds;

    // TODO: Perform simulation update here
}

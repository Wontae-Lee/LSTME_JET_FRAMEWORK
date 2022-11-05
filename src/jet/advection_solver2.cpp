#include <jet/advection_solver2.h>
#include <limits>
#include <pch.h>
using namespace jet;
AdvectionSolver2::AdvectionSolver2() {}
AdvectionSolver2::~AdvectionSolver2() {}
void AdvectionSolver2::advect(const CollocatedVectorGrid2 &source,
                              const VectorField2 &flow, double dt,
                              CollocatedVectorGrid2 *target,
                              const ScalarField2 &boundarySdf) {
  UNUSED_VARIABLE(source);
  UNUSED_VARIABLE(flow);
  UNUSED_VARIABLE(dt);
  UNUSED_VARIABLE(target);
  UNUSED_VARIABLE(boundarySdf);
}

void AdvectionSolver2::advect(const FaceCenteredGrid2 &source,
                              const VectorField2 &flow, double dt,
                              FaceCenteredGrid2 *target,
                              const ScalarField2 &boundarySdf) {
  UNUSED_VARIABLE(source);
  UNUSED_VARIABLE(flow);
  UNUSED_VARIABLE(dt);
  UNUSED_VARIABLE(target);
  UNUSED_VARIABLE(boundarySdf);
}

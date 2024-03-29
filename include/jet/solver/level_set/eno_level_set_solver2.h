// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_ENO_LEVEL_SET_SOLVER2_H_
#define INCLUDE_JET_ENO_LEVEL_SET_SOLVER2_H_

#include "iterative_level_set_solver2.h"

namespace jet {

//! Two-dimensional third-order ENO-based iterative level set solver.
class EnoLevelSetSolver2 final : public IterativeLevelSetSolver2
{
public:
  //! Default constructor.
  EnoLevelSetSolver2();

protected:
  //! Computes the derivatives for given grid point.
  void getDerivatives(ConstArrayAccessor2<double> grid,
                      const Vector2D& gridSpacing,
                      size_t i,
                      size_t j,
                      std::array<double, 2>* dx,
                      std::array<double, 2>* dy) const override;
};

typedef std::shared_ptr<EnoLevelSetSolver2> EnoLevelSetSolver2Ptr;

} // namespace jet

#endif // INCLUDE_JET_ENO_LEVEL_SET_SOLVER2_H_

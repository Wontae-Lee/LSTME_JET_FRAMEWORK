// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.hpp>

#include <fmm_level_set_solver2.hpp>
#include <particle_system_data2.hpp>
#include <spherical_points_to_implicit2.hpp>

using namespace lstme;

SphericalPointsToImplicit2::SphericalPointsToImplicit2(double radius,
                                                       bool isOutputSdf)
  : _radius(radius)
  , _isOutputSdf(isOutputSdf)
{
}

void
SphericalPointsToImplicit2::convert(const ConstArrayAccessor1<Vector2D>& points,
                                    ScalarGrid2* output) const
{
  if (output == nullptr) {
    LSTME_WARN << "Null scalar grid output pointer provided.";
    return;
  }

  const auto res = output->resolution();
  if (res.x * res.y == 0) {
    LSTME_WARN << "Empty grid is provided.";
    return;
  }

  const auto bbox = output->boundingBox();
  if (bbox.isEmpty()) {
    LSTME_WARN << "Empty domain is provided.";
    return;
  }

  ParticleSystemData2 particles;
  particles.addParticles(points);
  particles.buildNeighborSearcher(2.0 * _radius);

  const auto neighborSearcher = particles.neighborSearcher();

  auto temp = output->clone();
  temp->fill([&](const Vector2D& x) {
    double minDist = 2.0 * _radius;
    neighborSearcher->forEachNearbyPoint(
      x, 2.0 * _radius, [&](size_t, const Vector2D& xj) {
        minDist = std::min(minDist, (x - xj).length());
      });

    return minDist - _radius;
  });

  if (_isOutputSdf) {
    FmmLevelSetSolver2 solver;
    solver.reinitialize(*temp, kMaxD, output);
  } else {
    temp->swap(output);
  }
}

// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_SPHERICAL_POINTS_TO_IMPLICIT2_H_
#define INCLUDE_LSTME_SPHERICAL_POINTS_TO_IMPLICIT2_H_

#include <points_to_implicit2.hpp>

namespace lstme {

//!
//! \brief 2-D points-to-implicit converter based on simple sphere model.
//!
class SphericalPointsToImplicit2 final : public PointsToImplicit2 {
 public:
    //! Constructs the converter with given sphere radius.
    SphericalPointsToImplicit2(double radius = 1.0, bool isOutputSdf = true);

    //! Converts the given points to implicit surface scalar field.
    void convert(const ConstArrayAccessor1<Vector2D>& points,
                 ScalarGrid2* output) const override;

 private:
    double _radius = 1.0;
    bool _isOutputSdf = true;
};

//! Shared pointer type for SphericalPointsToImplicit2.
typedef std::shared_ptr<SphericalPointsToImplicit2>
    SphericalPointsToImplicit2Ptr;

}  // namespace lstme

#endif  // INCLUDE_LSTME_SPHERICAL_POINTS_TO_IMPLICIT2_H_

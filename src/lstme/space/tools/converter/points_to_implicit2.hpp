//
// Created by LSTME on 2022-09-22.
//

#ifndef LSTME_POINTS_TO_IMPLICIT2_HPP
#define LSTME_POINTS_TO_IMPLICIT2_HPP

#include <array_accessor1.hpp>
#include <scalar_grid2.hpp>
#include <vector2.hpp>

#include <memory>

namespace lstme {

//! Abstract base class for 2-D points-to-implicit converters.
class PointsToImplicit2
{
public:
  //! Default constructor.
  PointsToImplicit2();

  //! Default destructor.
  virtual ~PointsToImplicit2();

  //! Converts the given points to implicit surface scalar field.
  virtual void convert(const ConstArrayAccessor1<Vector2D>& points,
                       ScalarGrid2* output) const = 0;
};
//! Shared pointer for the PointsToImplicit2 type.
typedef std::shared_ptr<PointsToImplicit2> PointsToImplicit2Ptr;
}

#endif // LSTME_POINTS_TO_IMPLICIT2_HPP

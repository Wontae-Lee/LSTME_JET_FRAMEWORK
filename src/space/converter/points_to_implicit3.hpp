//
// Created by LSTME on 2022-09-22.
//

#ifndef LSTME_POINTS_TO_IMPLICIT3_HPP
#define LSTME_POINTS_TO_IMPLICIT3_HPP


#include <array_accessor1.hpp>
#include <scalar_grid3.hpp>
#include <vector3.hpp>

#include <memory>

namespace lstme {

//! Abstract base class for 3-D points-to-implicit converters.
class PointsToImplicit3 {
public:
  //! Default constructor.
  PointsToImplicit3();

  //! Default destructor.
  virtual ~PointsToImplicit3();

  //! Converts the given points to implicit surface scalar field.
  virtual void convert(const ConstArrayAccessor1<Vector3D>& points,
                       ScalarGrid3* output) const = 0;
};

//! Shared pointer for the PointsToImplicit3 type.
typedef std::shared_ptr<PointsToImplicit3> PointsToImplicit3Ptr;

}  // namespace lstme


#endif // LSTME_POINTS_TO_IMPLICIT3_HPP

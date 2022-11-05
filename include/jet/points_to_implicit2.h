#pragma once
#include <jet/array_accessor1.h>
#include <jet/scalar_grid2.h>
#include <jet/vector2.h>
#include <memory>
namespace jet {
//! Abstract base class for 2-D points-to-implicit converters.
class PointsToImplicit2 {
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
}  // namespace jet

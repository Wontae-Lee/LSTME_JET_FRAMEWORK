// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_NEAREST_NEIGHBOR_QUERY_ENGINE2_H_
#define INCLUDE_LSTME_NEAREST_NEIGHBOR_QUERY_ENGINE2_H_

#include <constants.hpp>
#include <vector2.hpp>

#include <functional>

namespace lstme {

//! Nearest neighbor query result.
template<typename T>
struct NearestNeighborQueryResult2
{
  const T* item = nullptr;
  double distance = kMaxD;
};

//! Nearest neighbor distance measure function.
template<typename T>
using NearestNeighborDistanceFunc2 =
  std::function<double(const T&, const Vector2D&)>;

//! Abstract base class for 2-D nearest neigbor query engine.
template<typename T>
class NearestNeighborQueryEngine2
{
public:
  //! Returns the nearest neighbor for given point and distance measure
  //! function.
  virtual NearestNeighborQueryResult2<T> nearest(
    const Vector2D& pt,
    const NearestNeighborDistanceFunc2<T>& distanceFunc) const = 0;
};

} // namespace lstme

#endif // INCLUDE_LSTME_NEAREST_NEIGHBOR_QUERY_ENGINE2_H_

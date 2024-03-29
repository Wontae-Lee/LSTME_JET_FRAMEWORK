// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_OCTREE_H_
#define INCLUDE_JET_OCTREE_H_

#include "jet/engine/intersection_query_engine3.h"
#include "jet/engine/nearest_neighbor_query_engine3.h"
#include <vector>

namespace jet {

//!
//! \brief      Generic octree data structure.
//!
//! This class is a generic octree representation to store arbitrary spatial
//! data. The octree supports closest neighbor search, overlapping test, and
//! ray intersection test.
//!
//! \tparam     T     Value type.
//!
template<typename T>
class Octree final
  : public IntersectionQueryEngine3<T>
  , public NearestNeighborQueryEngine3<T>
{
public:
  typedef std::vector<T> ContainerType;
  typedef typename ContainerType::iterator Iterator;
  typedef typename ContainerType::const_iterator ConstIterator;

  //! Default constructor.
  Octree();

  //! Builds an octree with given list of items, bounding box of the items,
  //! overlapping test function, and max depth of the tree.
  void build(const std::vector<T>& items, const BoundingBox3D& bound, const BoxIntersectionTestFunc3<T>& testFunc, size_t maxDepth);

  //! Clears all the contents of this instance.
  void clear();

  //! Returns the nearest neighbor for given point and distance measure
  //! function.
  NearestNeighborQueryResult3<T> nearest(const Vector3D& pt, const NearestNeighborDistanceFunc3<T>& distanceFunc) const override;

  //! Returns true if given \p box intersects with any of the stored items.
  bool intersects(const BoundingBox3D& box, const BoxIntersectionTestFunc3<T>& testFunc) const override;

  //! Returns true if given \p ray intersects with any of the stored items.
  bool intersects(const Ray3D& ray, const RayIntersectionTestFunc3<T>& testFunc) const override;

  //! Invokes \p visitorFunc for every intersecting items.
  void forEachIntersectingItem(const BoundingBox3D& box,
                               const BoxIntersectionTestFunc3<T>& testFunc,
                               const IntersectionVisitorFunc3<T>& visitorFunc) const override;

  //! Invokes \p visitorFunc for every intersecting items.
  void forEachIntersectingItem(const Ray3D& ray,
                               const RayIntersectionTestFunc3<T>& testFunc,
                               const IntersectionVisitorFunc3<T>& visitorFunc) const override;

  //! Returns the closest intersection for given \p ray.
  ClosestIntersectionQueryResult3<T> closestIntersection(const Ray3D& ray, const GetRayIntersectionFunc3<T>& testFunc) const override;

  //! Returns the begin iterator of the item.
  Iterator begin();

  //! Returns the end iterator of the item.
  Iterator end();

  //! Returns the immutable begin iterator of the item.
  ConstIterator begin() const;

  //! Returns the immutable end iterator of the item.
  ConstIterator end() const;

  //! Returns the number of items.
  size_t numberOfItems() const;

  //! Returns the item at \p i.
  const T& item(size_t i) const;

  //! Returns the number of octree nodes.
  size_t numberOfNodes() const;

  //! Returns the list of the items for given noide index.
  const std::vector<size_t>& itemsAtNode(size_t nodeIdx) const;

  //!
  //! \brief      Returns a child's index for given node.
  //!
  //! For a given node, its children is stored continuously, such that if the
  //! node's first child's index is i, then i + 1, i + 2, ... , i + 7 are the
  //! indices for its children. The order of octant is x-major.
  //!
  //! \param[in]  nodeIdx The node index.
  //! \param[in]  childIdx The child index (0 to 7).
  //!
  //! \return     Index of the selected child.
  //!
  size_t childIndex(size_t nodeIdx, size_t childIdx) const;

  //! Returns the bounding box of this octree.
  const BoundingBox3D& boundingBox() const;

  //! Returns the maximum depth of the tree.
  size_t maxDepth() const;

private:
  struct Node
  {
    size_t firstChild = kMaxSize;
    std::vector<size_t> items;

    bool isLeaf() const;
  };

  size_t _maxDepth = 1;
  BoundingBox3D _bbox;
  std::vector<T> _items;
  std::vector<Node> _nodes;

  void build(size_t nodeIdx, size_t currentDepth, const BoundingBox3D& currentBound, const BoxIntersectionTestFunc3<T>& overlapsFunc);

  bool intersects(const BoundingBox3D& box, const BoxIntersectionTestFunc3<T>& testFunc, size_t nodeIdx, const BoundingBox3D& currentBound) const;

  bool intersects(const Ray3D& ray, const RayIntersectionTestFunc3<T>& testFunc, size_t nodeIdx, const BoundingBox3D& currentBound) const;

  void forEachIntersectingItem(const BoundingBox3D& box,
                               const BoxIntersectionTestFunc3<T>& testFunc,
                               const IntersectionVisitorFunc3<T>& visitorFunc,
                               size_t nodeIdx,
                               const BoundingBox3D& currentBound) const;

  void forEachIntersectingItem(const Ray3D& ray,
                               const RayIntersectionTestFunc3<T>& testFunc,
                               const IntersectionVisitorFunc3<T>& visitorFunc,
                               size_t nodeIdx,
                               const BoundingBox3D& currentBound) const;

  ClosestIntersectionQueryResult3<T> closestIntersection(const Ray3D& ray,
                                                         const GetRayIntersectionFunc3<T>& testFunc,
                                                         size_t nodeIdx,
                                                         const BoundingBox3D& currentBound,
                                                         ClosestIntersectionQueryResult3<T> best) const;
};

} // namespace jet

#include "octree.inl"

#endif // INCLUDE_JET_OCTREE_H_

//
// Created by LSTME on 2022-09-26.
//

#ifndef LSTME_COLLIDER_SET3_HPP
#define LSTME_COLLIDER_SET3_HPP



#include <collider3.hpp>
#include <surface_set3.hpp>
#include <vector>

namespace lstme {

//! Collection of 3-D colliders
class ColliderSet3 final : public Collider3 {
public:
  class Builder;

  //! Default constructor.
  ColliderSet3();

  //! Constructs with other colliders.
  explicit ColliderSet3(const std::vector<Collider3Ptr>& others);

  //! Returns the velocity of the collider at given \p point.
  Vector3D velocityAt(const Vector3D& point) const override;

  //! Adds a collider to the set.
  void addCollider(const Collider3Ptr& collider);

  //! Returns number of colliders.
  size_t numberOfColliders() const;

  //! Returns collider at index \p i.
  Collider3Ptr collider(size_t i) const;

  //! Returns builder fox ColliderSet3.
  static Builder builder();

private:
  std::vector<Collider3Ptr> _colliders;
};

//! Shared pointer for the ColliderSet3 type.
typedef std::shared_ptr<ColliderSet3> ColliderSet3Ptr;
 

//!
//! \brief Front-end to create ColliderSet3 objects step by step.
//!
class ColliderSet3::Builder final {
public:
  //! Returns builder with other colliders.
  Builder& withColliders(const std::vector<Collider3Ptr>& others);

  //! Builds ColliderSet3.
  ColliderSet3 build() const;

  //! Builds shared pointer of ColliderSet3 instance.
  ColliderSet3Ptr makeShared() const;

private:
  std::vector<Collider3Ptr> _colliders;
};

}  // namespace lstme


#endif // LSTME_COLLIDER_SET3_HPP

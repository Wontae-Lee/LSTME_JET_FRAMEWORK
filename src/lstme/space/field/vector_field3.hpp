// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_VECTOR_FIELD3_H_
#define INCLUDE_LSTME_VECTOR_FIELD3_H_

#include <field3.hpp>
#include <functional>
#include <memory>
#include <vector3.hpp>

namespace lstme {

//! Abstract base class for 3-D vector field.
class VectorField3 : public Field3
{
public:
  //! Default constructor.
  VectorField3();

  //! Default destructor.
  virtual ~VectorField3();

  //! Returns sampled value at given position \p x.
  virtual Vector3D sample(const Vector3D& x) const = 0;

  //! Returns divergence at given position \p x.
  virtual double divergence(const Vector3D& x) const;

  //! Returns curl at given position \p x.
  virtual Vector3D curl(const Vector3D& x) const;

  //! Returns sampler function object.
  virtual std::function<Vector3D(const Vector3D&)> sampler() const;
};

//! Shared pointer for the VectorField3 type.
typedef std::shared_ptr<VectorField3> VectorField3Ptr;

} // namespace lstme

#endif // INCLUDE_LSTME_VECTOR_FIELD3_H_

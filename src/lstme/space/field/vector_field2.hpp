// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_VECTOR_FIELD2_H_
#define INCLUDE_LSTME_VECTOR_FIELD2_H_

#include <field2.hpp>
#include <functional>
#include <memory>
#include <vector2.hpp>

namespace lstme {

//! Abstract base class for 2-D vector field.
class VectorField2 : public Field2
{
public:
  //! Default constructor.
  VectorField2();

  //! Default destructor.
  virtual ~VectorField2();

  //! Returns sampled value at given position \p x.
  virtual Vector2D sample(const Vector2D& x) const = 0;

  //! Returns divergence at given position \p x.
  virtual double divergence(const Vector2D& x) const;

  //! Returns curl at given position \p x.
  virtual double curl(const Vector2D& x) const;

  //! Returns sampler function object.
  virtual std::function<Vector2D(const Vector2D&)> sampler() const;
};

//! Shared pointer for the VectorField2 type.
typedef std::shared_ptr<VectorField2> VectorField2Ptr;

} // namespace lstme

#endif // INCLUDE_LSTME_VECTOR_FIELD2_H_

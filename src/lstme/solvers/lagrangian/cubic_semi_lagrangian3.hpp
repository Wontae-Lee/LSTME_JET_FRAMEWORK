//
// Created by LSTME on 2022-09-26.
//

#ifndef LSTME_CUBIC_SEMI_LAGRANGIAN3_HPP
#define LSTME_CUBIC_SEMI_LAGRANGIAN3_HPP

#include <semi_lagrangian3.hpp>

namespace lstme {

//!
//! \brief Implementation of 3-D cubic semi-Lagrangian advection solver.
//!
//! This class implements 3rd-order cubic 3-D semi-Lagrangian advection solver.
//!
class CubicSemiLagrangian3 final : public SemiLagrangian3
{
public:
  CubicSemiLagrangian3();

protected:
  //!
  //! \brief Returns spatial interpolation function object for given scalar
  //! grid.
  //!
  //! This function overrides the original function with cubic interpolation.
  //!
  std::function<double(const Vector3D&)> getScalarSamplerFunc(
    const ScalarGrid3& source) const override;

  //!
  //! \brief Returns spatial interpolation function object for given
  //! collocated vector grid.
  //!
  //! This function overrides the original function with cubic interpolation.
  //!
  std::function<Vector3D(const Vector3D&)> getVectorSamplerFunc(
    const CollocatedVectorGrid3& source) const override;

  //!
  //! \brief Returns spatial interpolation function object for given
  //! face-centered vector grid.
  //!
  //! This function overrides the original function with cubic interpolation.
  //!
  std::function<Vector3D(const Vector3D&)> getVectorSamplerFunc(
    const FaceCenteredGrid3& source) const override;
};

typedef std::shared_ptr<CubicSemiLagrangian3> CubicSemiLagrangian3Ptr;

} // namespace lstme

#endif // LSTME_CUBIC_SEMI_LAGRANGIAN3_HPP

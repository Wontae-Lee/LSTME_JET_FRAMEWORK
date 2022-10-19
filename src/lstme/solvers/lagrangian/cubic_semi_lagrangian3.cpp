//
// Created by LSTME on 2022-10-15.
//

#include <array_samplers3.hpp>
#include <cubic_semi_lagrangian3.hpp>
#include <pch.hpp>


using namespace lstme;

CubicSemiLagrangian3::CubicSemiLagrangian3() {}

std::function<double(const Vector3D&)>
CubicSemiLagrangian3::getScalarSamplerFunc(const ScalarGrid3& source) const
{
  auto sourceSampler = CubicArraySampler3<double, double>(
    source.constDataAccessor(), source.gridSpacing(), source.dataOrigin());
  return sourceSampler.functor();
}

std::function<Vector3D(const Vector3D&)>
CubicSemiLagrangian3::getVectorSamplerFunc(
  const CollocatedVectorGrid3& source) const
{
  auto sourceSampler = CubicArraySampler3<Vector3D, double>(
    source.constDataAccessor(), source.gridSpacing(), source.dataOrigin());
  return sourceSampler.functor();
}

std::function<Vector3D(const Vector3D&)>
CubicSemiLagrangian3::getVectorSamplerFunc(
  const FaceCenteredGrid3& source) const
{
  auto uSourceSampler = CubicArraySampler3<double, double>(
    source.uConstAccessor(), source.gridSpacing(), source.uOrigin());
  auto vSourceSampler = CubicArraySampler3<double, double>(
    source.vConstAccessor(), source.gridSpacing(), source.vOrigin());
  auto wSourceSampler = CubicArraySampler3<double, double>(
    source.wConstAccessor(), source.gridSpacing(), source.wOrigin());
  return [uSourceSampler, vSourceSampler, wSourceSampler](const Vector3D& x) {
    return Vector3D(uSourceSampler(x), vSourceSampler(x), wSourceSampler(x));
  };
}

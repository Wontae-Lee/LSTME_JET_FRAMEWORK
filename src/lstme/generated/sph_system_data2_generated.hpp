// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_SPHSYSTEMDATA2_LSTME_FBS_H_
#define FLATBUFFERS_GENERATED_SPHSYSTEMDATA2_LSTME_FBS_H_

#include <flatbuffers.hpp>

#include "basic_types_generated.hpp"
#include "particle_system_data2_generated.hpp"

namespace lstme {
namespace fbs {

struct SphSystemData2;

struct SphSystemData2 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
{
  enum
  {
    VT_BASE = 4,
    VT_TARGETDENSITY = 6,
    VT_TARGETSPACING = 8,
    VT_KERNELRADIUSOVERTARGETSPACING = 10,
    VT_KERNELRADIUS = 12,
    VT_PRESSUREIDX = 14,
    VT_DENSITYIDX = 16
  };
  const lstme::fbs::ParticleSystemData2* base() const
  {
    return GetPointer<const lstme::fbs::ParticleSystemData2*>(VT_BASE);
  }
  double targetDensity() const
  {
    return GetField<double>(VT_TARGETDENSITY, 0.0);
  }
  double targetSpacing() const
  {
    return GetField<double>(VT_TARGETSPACING, 0.0);
  }
  double kernelRadiusOverTargetSpacing() const
  {
    return GetField<double>(VT_KERNELRADIUSOVERTARGETSPACING, 0.0);
  }
  double kernelRadius() const { return GetField<double>(VT_KERNELRADIUS, 0.0); }
  uint64_t pressureIdx() const { return GetField<uint64_t>(VT_PRESSUREIDX, 0); }
  uint64_t densityIdx() const { return GetField<uint64_t>(VT_DENSITYIDX, 0); }
  bool Verify(flatbuffers::Verifier& verifier) const
  {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_BASE) &&
           verifier.VerifyTable(base()) &&
           VerifyField<double>(verifier, VT_TARGETDENSITY) &&
           VerifyField<double>(verifier, VT_TARGETSPACING) &&
           VerifyField<double>(verifier, VT_KERNELRADIUSOVERTARGETSPACING) &&
           VerifyField<double>(verifier, VT_KERNELRADIUS) &&
           VerifyField<uint64_t>(verifier, VT_PRESSUREIDX) &&
           VerifyField<uint64_t>(verifier, VT_DENSITYIDX) &&
           verifier.EndTable();
  }
};

struct SphSystemData2Builder
{
  flatbuffers::FlatBufferBuilder& fbb_;
  flatbuffers::uoffset_t start_;
  void add_base(flatbuffers::Offset<lstme::fbs::ParticleSystemData2> base)
  {
    fbb_.AddOffset(SphSystemData2::VT_BASE, base);
  }
  void add_targetDensity(double targetDensity)
  {
    fbb_.AddElement<double>(
      SphSystemData2::VT_TARGETDENSITY, targetDensity, 0.0);
  }
  void add_targetSpacing(double targetSpacing)
  {
    fbb_.AddElement<double>(
      SphSystemData2::VT_TARGETSPACING, targetSpacing, 0.0);
  }
  void add_kernelRadiusOverTargetSpacing(double kernelRadiusOverTargetSpacing)
  {
    fbb_.AddElement<double>(SphSystemData2::VT_KERNELRADIUSOVERTARGETSPACING,
                            kernelRadiusOverTargetSpacing,
                            0.0);
  }
  void add_kernelRadius(double kernelRadius)
  {
    fbb_.AddElement<double>(SphSystemData2::VT_KERNELRADIUS, kernelRadius, 0.0);
  }
  void add_pressureIdx(uint64_t pressureIdx)
  {
    fbb_.AddElement<uint64_t>(SphSystemData2::VT_PRESSUREIDX, pressureIdx, 0);
  }
  void add_densityIdx(uint64_t densityIdx)
  {
    fbb_.AddElement<uint64_t>(SphSystemData2::VT_DENSITYIDX, densityIdx, 0);
  }
  SphSystemData2Builder(flatbuffers::FlatBufferBuilder& _fbb)
    : fbb_(_fbb)
  {
    start_ = fbb_.StartTable();
  }
  SphSystemData2Builder& operator=(const SphSystemData2Builder&);
  flatbuffers::Offset<SphSystemData2> Finish()
  {
    const auto end = fbb_.EndTable(start_, 7);
    auto o = flatbuffers::Offset<SphSystemData2>(end);
    return o;
  }
};

inline flatbuffers::Offset<SphSystemData2>
CreateSphSystemData2(
  flatbuffers::FlatBufferBuilder& _fbb,
  flatbuffers::Offset<lstme::fbs::ParticleSystemData2> base = 0,
  double targetDensity = 0.0,
  double targetSpacing = 0.0,
  double kernelRadiusOverTargetSpacing = 0.0,
  double kernelRadius = 0.0,
  uint64_t pressureIdx = 0,
  uint64_t densityIdx = 0)
{
  SphSystemData2Builder builder_(_fbb);
  builder_.add_densityIdx(densityIdx);
  builder_.add_pressureIdx(pressureIdx);
  builder_.add_kernelRadius(kernelRadius);
  builder_.add_kernelRadiusOverTargetSpacing(kernelRadiusOverTargetSpacing);
  builder_.add_targetSpacing(targetSpacing);
  builder_.add_targetDensity(targetDensity);
  builder_.add_base(base);
  return builder_.Finish();
}

inline const lstme::fbs::SphSystemData2*
GetSphSystemData2(const void* buf)
{
  return flatbuffers::GetRoot<lstme::fbs::SphSystemData2>(buf);
}

inline bool
VerifySphSystemData2Buffer(flatbuffers::Verifier& verifier)
{
  return verifier.VerifyBuffer<lstme::fbs::SphSystemData2>(nullptr);
}

inline void
FinishSphSystemData2Buffer(flatbuffers::FlatBufferBuilder& fbb,
                           flatbuffers::Offset<lstme::fbs::SphSystemData2> root)
{
  fbb.Finish(root);
}

} // namespace fbs
} // namespace lstme

#endif // FLATBUFFERS_GENERATED_SPHSYSTEMDATA2_LSTME_FBS_H_
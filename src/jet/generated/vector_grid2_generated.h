// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_VECTORGRID2_JET_FBS_H_
#define FLATBUFFERS_GENERATED_VECTORGRID2_JET_FBS_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

#include "basic_types_generated.h"

namespace jet {
namespace fbs {

struct VectorGrid2;
struct VectorGrid2Builder;

struct VectorGrid2 FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef VectorGrid2Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_RESOLUTION = 4,
    VT_GRIDSPACING = 6,
    VT_ORIGIN = 8,
    VT_DATA = 10
  };
  const jet::fbs::Size2 *resolution() const {
    return GetStruct<const jet::fbs::Size2 *>(VT_RESOLUTION);
  }
  const jet::fbs::Vector2D *gridSpacing() const {
    return GetStruct<const jet::fbs::Vector2D *>(VT_GRIDSPACING);
  }
  const jet::fbs::Vector2D *origin() const {
    return GetStruct<const jet::fbs::Vector2D *>(VT_ORIGIN);
  }
  const ::flatbuffers::Vector<double> *data() const {
    return GetPointer<const ::flatbuffers::Vector<double> *>(VT_DATA);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<jet::fbs::Size2>(verifier, VT_RESOLUTION, 8) &&
           VerifyField<jet::fbs::Vector2D>(verifier, VT_GRIDSPACING, 8) &&
           VerifyField<jet::fbs::Vector2D>(verifier, VT_ORIGIN, 8) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           verifier.EndTable();
  }
};

struct VectorGrid2Builder {
  typedef VectorGrid2 Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_resolution(const jet::fbs::Size2 *resolution) {
    fbb_.AddStruct(VectorGrid2::VT_RESOLUTION, resolution);
  }
  void add_gridSpacing(const jet::fbs::Vector2D *gridSpacing) {
    fbb_.AddStruct(VectorGrid2::VT_GRIDSPACING, gridSpacing);
  }
  void add_origin(const jet::fbs::Vector2D *origin) {
    fbb_.AddStruct(VectorGrid2::VT_ORIGIN, origin);
  }
  void add_data(::flatbuffers::Offset<::flatbuffers::Vector<double>> data) {
    fbb_.AddOffset(VectorGrid2::VT_DATA, data);
  }
  explicit VectorGrid2Builder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<VectorGrid2> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<VectorGrid2>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<VectorGrid2> CreateVectorGrid2(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const jet::fbs::Size2 *resolution = nullptr,
    const jet::fbs::Vector2D *gridSpacing = nullptr,
    const jet::fbs::Vector2D *origin = nullptr,
    ::flatbuffers::Offset<::flatbuffers::Vector<double>> data = 0) {
  VectorGrid2Builder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_origin(origin);
  builder_.add_gridSpacing(gridSpacing);
  builder_.add_resolution(resolution);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<VectorGrid2> CreateVectorGrid2Direct(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const jet::fbs::Size2 *resolution = nullptr,
    const jet::fbs::Vector2D *gridSpacing = nullptr,
    const jet::fbs::Vector2D *origin = nullptr,
    const std::vector<double> *data = nullptr) {
  auto data__ = data ? _fbb.CreateVector<double>(*data) : 0;
  return jet::fbs::CreateVectorGrid2(
      _fbb,
      resolution,
      gridSpacing,
      origin,
      data__);
}

inline const jet::fbs::VectorGrid2 *GetVectorGrid2(const void *buf) {
  return ::flatbuffers::GetRoot<jet::fbs::VectorGrid2>(buf);
}

inline const jet::fbs::VectorGrid2 *GetSizePrefixedVectorGrid2(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<jet::fbs::VectorGrid2>(buf);
}

inline bool VerifyVectorGrid2Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<jet::fbs::VectorGrid2>(nullptr);
}

inline bool VerifySizePrefixedVectorGrid2Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<jet::fbs::VectorGrid2>(nullptr);
}

inline void FinishVectorGrid2Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<jet::fbs::VectorGrid2> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedVectorGrid2Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<jet::fbs::VectorGrid2> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace fbs
}  // namespace jet

#endif  // FLATBUFFERS_GENERATED_VECTORGRID2_JET_FBS_H_

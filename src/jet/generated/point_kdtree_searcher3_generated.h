// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_POINTKDTREESEARCHER3_JET_FBS_H_
#define FLATBUFFERS_GENERATED_POINTKDTREESEARCHER3_JET_FBS_H_

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

struct PointKdTreeSearcherNode3;

struct PointKdTreeSearcher3;
struct PointKdTreeSearcher3Builder;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(8) PointKdTreeSearcherNode3 FLATBUFFERS_FINAL_CLASS {
 private:
  uint64_t flags_;
  uint64_t child_;
  uint64_t item_;

 public:
  PointKdTreeSearcherNode3()
      : flags_(0),
        child_(0),
        item_(0) {
  }
  PointKdTreeSearcherNode3(uint64_t _flags, uint64_t _child, uint64_t _item)
      : flags_(::flatbuffers::EndianScalar(_flags)),
        child_(::flatbuffers::EndianScalar(_child)),
        item_(::flatbuffers::EndianScalar(_item)) {
  }
  uint64_t flags() const {
    return ::flatbuffers::EndianScalar(flags_);
  }
  uint64_t child() const {
    return ::flatbuffers::EndianScalar(child_);
  }
  uint64_t item() const {
    return ::flatbuffers::EndianScalar(item_);
  }
};
FLATBUFFERS_STRUCT_END(PointKdTreeSearcherNode3, 24);

struct PointKdTreeSearcher3 FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PointKdTreeSearcher3Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_POINTS = 4,
    VT_NODES = 6
  };
  const ::flatbuffers::Vector<const jet::fbs::Vector3D *> *points() const {
    return GetPointer<const ::flatbuffers::Vector<const jet::fbs::Vector3D *> *>(VT_POINTS);
  }
  const ::flatbuffers::Vector<const jet::fbs::PointKdTreeSearcherNode3 *> *nodes() const {
    return GetPointer<const ::flatbuffers::Vector<const jet::fbs::PointKdTreeSearcherNode3 *> *>(VT_NODES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_POINTS) &&
           verifier.VerifyVector(points()) &&
           VerifyOffset(verifier, VT_NODES) &&
           verifier.VerifyVector(nodes()) &&
           verifier.EndTable();
  }
};

struct PointKdTreeSearcher3Builder {
  typedef PointKdTreeSearcher3 Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_points(::flatbuffers::Offset<::flatbuffers::Vector<const jet::fbs::Vector3D *>> points) {
    fbb_.AddOffset(PointKdTreeSearcher3::VT_POINTS, points);
  }
  void add_nodes(::flatbuffers::Offset<::flatbuffers::Vector<const jet::fbs::PointKdTreeSearcherNode3 *>> nodes) {
    fbb_.AddOffset(PointKdTreeSearcher3::VT_NODES, nodes);
  }
  explicit PointKdTreeSearcher3Builder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<PointKdTreeSearcher3> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<PointKdTreeSearcher3>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<PointKdTreeSearcher3> CreatePointKdTreeSearcher3(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<const jet::fbs::Vector3D *>> points = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<const jet::fbs::PointKdTreeSearcherNode3 *>> nodes = 0) {
  PointKdTreeSearcher3Builder builder_(_fbb);
  builder_.add_nodes(nodes);
  builder_.add_points(points);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<PointKdTreeSearcher3> CreatePointKdTreeSearcher3Direct(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<jet::fbs::Vector3D> *points = nullptr,
    const std::vector<jet::fbs::PointKdTreeSearcherNode3> *nodes = nullptr) {
  auto points__ = points ? _fbb.CreateVectorOfStructs<jet::fbs::Vector3D>(*points) : 0;
  auto nodes__ = nodes ? _fbb.CreateVectorOfStructs<jet::fbs::PointKdTreeSearcherNode3>(*nodes) : 0;
  return jet::fbs::CreatePointKdTreeSearcher3(
      _fbb,
      points__,
      nodes__);
}

inline const jet::fbs::PointKdTreeSearcher3 *GetPointKdTreeSearcher3(const void *buf) {
  return ::flatbuffers::GetRoot<jet::fbs::PointKdTreeSearcher3>(buf);
}

inline const jet::fbs::PointKdTreeSearcher3 *GetSizePrefixedPointKdTreeSearcher3(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<jet::fbs::PointKdTreeSearcher3>(buf);
}

inline bool VerifyPointKdTreeSearcher3Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<jet::fbs::PointKdTreeSearcher3>(nullptr);
}

inline bool VerifySizePrefixedPointKdTreeSearcher3Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<jet::fbs::PointKdTreeSearcher3>(nullptr);
}

inline void FinishPointKdTreeSearcher3Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<jet::fbs::PointKdTreeSearcher3> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedPointKdTreeSearcher3Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<jet::fbs::PointKdTreeSearcher3> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace fbs
}  // namespace jet

#endif  // FLATBUFFERS_GENERATED_POINTKDTREESEARCHER3_JET_FBS_H_

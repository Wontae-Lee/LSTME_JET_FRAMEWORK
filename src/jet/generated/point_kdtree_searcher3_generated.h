// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_POINTKDTREESEARCHER3_JET_FBS_H_
#define FLATBUFFERS_GENERATED_POINTKDTREESEARCHER3_JET_FBS_H_

#include "../3rdparty/flatbuffers/flatbuffers.h"

#include "basic_types_generated.h"

namespace jet {
namespace fbs {

struct PointKdTreeSearcherNode3;

struct PointKdTreeSearcher3;

MANUALLY_ALIGNED_STRUCT(8) PointKdTreeSearcherNode3 FLATBUFFERS_FINAL_CLASS {
 private:
    uint64_t flags_;
    uint64_t child_;
    uint64_t item_;

 public:
    PointKdTreeSearcherNode3() { memset(this, 0, sizeof(PointKdTreeSearcherNode3)); }
    PointKdTreeSearcherNode3(const PointKdTreeSearcherNode3 &_o) { memcpy(this, &_o, sizeof(PointKdTreeSearcherNode3)); }
    PointKdTreeSearcherNode3(uint64_t _flags, uint64_t _child, uint64_t _item)
        : flags_(flatbuffers::EndianScalar(_flags)), child_(flatbuffers::EndianScalar(_child)), item_(flatbuffers::EndianScalar(_item)) {}
    uint64_t flags() const { return flatbuffers::EndianScalar(flags_); }
    uint64_t child() const { return flatbuffers::EndianScalar(child_); }
    uint64_t item() const { return flatbuffers::EndianScalar(item_); }
};
STRUCT_END(PointKdTreeSearcherNode3, 24);

struct PointKdTreeSearcher3 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
    enum { VT_POINTS = 4, VT_NODES = 6 };
    const flatbuffers::Vector<const jet::fbs::Vector3D *> *points() const { return GetPointer<const flatbuffers::Vector<const jet::fbs::Vector3D *> *>(VT_POINTS); }
    const flatbuffers::Vector<const PointKdTreeSearcherNode3 *> *nodes() const { return GetPointer<const flatbuffers::Vector<const PointKdTreeSearcherNode3 *> *>(VT_NODES); }
    bool Verify(flatbuffers::Verifier &verifier) const {
        return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_POINTS) && verifier.Verify(points()) && VerifyOffset(verifier, VT_NODES) && verifier.Verify(nodes()) && verifier.EndTable();
    }
};

struct PointKdTreeSearcher3Builder {
    flatbuffers::FlatBufferBuilder &fbb_;
    flatbuffers::uoffset_t start_;
    void add_points(flatbuffers::Offset<flatbuffers::Vector<const jet::fbs::Vector3D *>> points) { fbb_.AddOffset(PointKdTreeSearcher3::VT_POINTS, points); }
    void add_nodes(flatbuffers::Offset<flatbuffers::Vector<const PointKdTreeSearcherNode3 *>> nodes) { fbb_.AddOffset(PointKdTreeSearcher3::VT_NODES, nodes); }
    PointKdTreeSearcher3Builder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
    PointKdTreeSearcher3Builder &operator=(const PointKdTreeSearcher3Builder &);
    flatbuffers::Offset<PointKdTreeSearcher3> Finish() {
        const auto end = fbb_.EndTable(start_, 2);
        auto o = flatbuffers::Offset<PointKdTreeSearcher3>(end);
        return o;
    }
};

inline flatbuffers::Offset<PointKdTreeSearcher3> CreatePointKdTreeSearcher3(flatbuffers::FlatBufferBuilder &_fbb, flatbuffers::Offset<flatbuffers::Vector<const jet::fbs::Vector3D *>> points = 0,
                                                                            flatbuffers::Offset<flatbuffers::Vector<const PointKdTreeSearcherNode3 *>> nodes = 0) {
    PointKdTreeSearcher3Builder builder_(_fbb);
    builder_.add_nodes(nodes);
    builder_.add_points(points);
    return builder_.Finish();
}

inline flatbuffers::Offset<PointKdTreeSearcher3> CreatePointKdTreeSearcher3Direct(flatbuffers::FlatBufferBuilder &_fbb, const std::vector<const jet::fbs::Vector3D *> *points = nullptr,
                                                                                  const std::vector<const PointKdTreeSearcherNode3 *> *nodes = nullptr) {
    return jet::fbs::CreatePointKdTreeSearcher3(_fbb, points ? _fbb.CreateVector<const jet::fbs::Vector3D *>(*points) : 0, nodes ? _fbb.CreateVector<const PointKdTreeSearcherNode3 *>(*nodes) : 0);
}

inline const jet::fbs::PointKdTreeSearcher3 *GetPointKdTreeSearcher3(const void *buf) { return flatbuffers::GetRoot<jet::fbs::PointKdTreeSearcher3>(buf); }

inline bool VerifyPointKdTreeSearcher3Buffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<jet::fbs::PointKdTreeSearcher3>(nullptr); }

inline void FinishPointKdTreeSearcher3Buffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<jet::fbs::PointKdTreeSearcher3> root) { fbb.Finish(root); }

}  // namespace fbs
}  // namespace jet

#endif  // FLATBUFFERS_GENERATED_POINTKDTREESEARCHER3_JET_FBS_H_

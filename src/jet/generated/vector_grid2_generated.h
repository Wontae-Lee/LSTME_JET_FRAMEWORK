// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_VECTORGRID2_JET_FBS_H_
#define FLATBUFFERS_GENERATED_VECTORGRID2_JET_FBS_H_

#include "flatbuffers/flatbuffers.h"

#include "basic_types_generated.h"

namespace jet {
namespace fbs {

struct VectorGrid2;

struct VectorGrid2 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
    enum { VT_RESOLUTION = 4, VT_GRIDSPACING = 6, VT_ORIGIN = 8, VT_DATA = 10 };
    const jet::fbs::Size2 *resolution() const { return GetStruct<const jet::fbs::Size2 *>(VT_RESOLUTION); }
    const jet::fbs::Vector2D *gridSpacing() const { return GetStruct<const jet::fbs::Vector2D *>(VT_GRIDSPACING); }
    const jet::fbs::Vector2D *origin() const { return GetStruct<const jet::fbs::Vector2D *>(VT_ORIGIN); }
    const flatbuffers::Vector<double> *data() const { return GetPointer<const flatbuffers::Vector<double> *>(VT_DATA); }
    bool Verify(flatbuffers::Verifier &verifier) const {
        return VerifyTableStart(verifier) && VerifyField<jet::fbs::Size2>(verifier, VT_RESOLUTION) && VerifyField<jet::fbs::Vector2D>(verifier, VT_GRIDSPACING) &&
               VerifyField<jet::fbs::Vector2D>(verifier, VT_ORIGIN) && VerifyOffset(verifier, VT_DATA) && verifier.Verify(data()) && verifier.EndTable();
    }
};

struct VectorGrid2Builder {
    flatbuffers::FlatBufferBuilder &fbb_;
    flatbuffers::uoffset_t start_;
    void add_resolution(const jet::fbs::Size2 *resolution) { fbb_.AddStruct(VectorGrid2::VT_RESOLUTION, resolution); }
    void add_gridSpacing(const jet::fbs::Vector2D *gridSpacing) { fbb_.AddStruct(VectorGrid2::VT_GRIDSPACING, gridSpacing); }
    void add_origin(const jet::fbs::Vector2D *origin) { fbb_.AddStruct(VectorGrid2::VT_ORIGIN, origin); }
    void add_data(flatbuffers::Offset<flatbuffers::Vector<double>> data) { fbb_.AddOffset(VectorGrid2::VT_DATA, data); }
    VectorGrid2Builder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
    VectorGrid2Builder &operator=(const VectorGrid2Builder &);
    flatbuffers::Offset<VectorGrid2> Finish() {
        const auto end = fbb_.EndTable(start_, 4);
        auto o = flatbuffers::Offset<VectorGrid2>(end);
        return o;
    }
};

inline flatbuffers::Offset<VectorGrid2> CreateVectorGrid2(flatbuffers::FlatBufferBuilder &_fbb, const jet::fbs::Size2 *resolution = 0, const jet::fbs::Vector2D *gridSpacing = 0,
                                                          const jet::fbs::Vector2D *origin = 0, flatbuffers::Offset<flatbuffers::Vector<double>> data = 0) {
    VectorGrid2Builder builder_(_fbb);
    builder_.add_data(data);
    builder_.add_origin(origin);
    builder_.add_gridSpacing(gridSpacing);
    builder_.add_resolution(resolution);
    return builder_.Finish();
}

inline flatbuffers::Offset<VectorGrid2> CreateVectorGrid2Direct(flatbuffers::FlatBufferBuilder &_fbb, const jet::fbs::Size2 *resolution = 0, const jet::fbs::Vector2D *gridSpacing = 0,
                                                                const jet::fbs::Vector2D *origin = 0, const std::vector<double> *data = nullptr) {
    return jet::fbs::CreateVectorGrid2(_fbb, resolution, gridSpacing, origin, data ? _fbb.CreateVector<double>(*data) : 0);
}

inline const jet::fbs::VectorGrid2 *GetVectorGrid2(const void *buf) { return flatbuffers::GetRoot<jet::fbs::VectorGrid2>(buf); }

inline bool VerifyVectorGrid2Buffer(flatbuffers::Verifier &verifier) { return verifier.VerifyBuffer<jet::fbs::VectorGrid2>(nullptr); }

inline void FinishVectorGrid2Buffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<jet::fbs::VectorGrid2> root) { fbb.Finish(root); }

}  // namespace fbs
}  // namespace jet

#endif  // FLATBUFFERS_GENERATED_VECTORGRID2_JET_FBS_H_

// automatically generated by the FlatBuffers compiler, do not modify
#ifndef FLATBUFFERS_GENERATED_PARTICLESYSTEMDATA3_JET_FBS_H_
#define FLATBUFFERS_GENERATED_PARTICLESYSTEMDATA3_JET_FBS_H_
#include "basic_types_generated.h"
#include "flatbuffers/flatbuffers.h"
namespace jet {
namespace fbs {
struct ScalarParticleData3;
struct VectorParticleData3;
struct PointNeighborSearcherSerialized3;
struct ParticleNeighborList3;
struct ParticleSystemData3;
struct ScalarParticleData3 FLATBUFFERS_FINAL_CLASS
    : private flatbuffers::Table {
  enum { VT_DATA = 4 };
  const flatbuffers::Vector<double> *data() const {
    return GetPointer<const flatbuffers::Vector<double> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_DATA) &&
           verifier.Verify(data()) && verifier.EndTable();
  }
};
struct ScalarParticleData3Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_data(flatbuffers::Offset<flatbuffers::Vector<double>> data) {
    fbb_.AddOffset(ScalarParticleData3::VT_DATA, data);
  }
  ScalarParticleData3Builder(flatbuffers::FlatBufferBuilder &_fbb)
      : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ScalarParticleData3Builder &operator=(const ScalarParticleData3Builder &);
  flatbuffers::Offset<ScalarParticleData3> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ScalarParticleData3>(end);
    return o;
  }
};
inline flatbuffers::Offset<ScalarParticleData3> CreateScalarParticleData3(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<double>> data = 0) {
  ScalarParticleData3Builder builder_(_fbb);
  builder_.add_data(data);
  return builder_.Finish();
}
inline flatbuffers::Offset<ScalarParticleData3>
CreateScalarParticleData3Direct(flatbuffers::FlatBufferBuilder &_fbb,
                                const std::vector<double> *data = nullptr) {
  return jet::fbs::CreateScalarParticleData3(
      _fbb, data ? _fbb.CreateVector<double>(*data) : 0);
}
struct VectorParticleData3 FLATBUFFERS_FINAL_CLASS
    : private flatbuffers::Table {
  enum { VT_DATA = 4 };
  const flatbuffers::Vector<const jet::fbs::Vector3D *> *data() const {
    return GetPointer<const flatbuffers::Vector<const jet::fbs::Vector3D *> *>(
        VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_DATA) &&
           verifier.Verify(data()) && verifier.EndTable();
  }
};
struct VectorParticleData3Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void
  add_data(flatbuffers::Offset<flatbuffers::Vector<const jet::fbs::Vector3D *>>
               data) {
    fbb_.AddOffset(VectorParticleData3::VT_DATA, data);
  }
  VectorParticleData3Builder(flatbuffers::FlatBufferBuilder &_fbb)
      : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VectorParticleData3Builder &operator=(const VectorParticleData3Builder &);
  flatbuffers::Offset<VectorParticleData3> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<VectorParticleData3>(end);
    return o;
  }
};
inline flatbuffers::Offset<VectorParticleData3> CreateVectorParticleData3(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<const jet::fbs::Vector3D *>> data =
        0) {
  VectorParticleData3Builder builder_(_fbb);
  builder_.add_data(data);
  return builder_.Finish();
}
inline flatbuffers::Offset<VectorParticleData3> CreateVectorParticleData3Direct(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<const jet::fbs::Vector3D *> *data = nullptr) {
  return jet::fbs::CreateVectorParticleData3(
      _fbb, data ? _fbb.CreateVector<const jet::fbs::Vector3D *>(*data) : 0);
}
struct PointNeighborSearcherSerialized3 FLATBUFFERS_FINAL_CLASS
    : private flatbuffers::Table {
  enum { VT_TYPE = 4, VT_DATA = 6 };
  const flatbuffers::String *type() const {
    return GetPointer<const flatbuffers::String *>(VT_TYPE);
  }
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_TYPE) &&
           verifier.Verify(type()) && VerifyOffset(verifier, VT_DATA) &&
           verifier.Verify(data()) && verifier.EndTable();
  }
};
struct PointNeighborSearcherSerialized3Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(flatbuffers::Offset<flatbuffers::String> type) {
    fbb_.AddOffset(PointNeighborSearcherSerialized3::VT_TYPE, type);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(PointNeighborSearcherSerialized3::VT_DATA, data);
  }
  PointNeighborSearcherSerialized3Builder(flatbuffers::FlatBufferBuilder &_fbb)
      : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PointNeighborSearcherSerialized3Builder &
  operator=(const PointNeighborSearcherSerialized3Builder &);
  flatbuffers::Offset<PointNeighborSearcherSerialized3> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<PointNeighborSearcherSerialized3>(end);
    return o;
  }
};
inline flatbuffers::Offset<PointNeighborSearcherSerialized3>
CreatePointNeighborSearcherSerialized3(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> type = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0) {
  PointNeighborSearcherSerialized3Builder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_type(type);
  return builder_.Finish();
}
inline flatbuffers::Offset<PointNeighborSearcherSerialized3>
CreatePointNeighborSearcherSerialized3Direct(
    flatbuffers::FlatBufferBuilder &_fbb, const char *type = nullptr,
    const std::vector<uint8_t> *data = nullptr) {
  return jet::fbs::CreatePointNeighborSearcherSerialized3(
      _fbb, type ? _fbb.CreateString(type) : 0,
      data ? _fbb.CreateVector<uint8_t>(*data) : 0);
}
struct ParticleNeighborList3 FLATBUFFERS_FINAL_CLASS
    : private flatbuffers::Table {
  enum { VT_DATA = 4 };
  const flatbuffers::Vector<uint64_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_DATA) &&
           verifier.Verify(data()) && verifier.EndTable();
  }
};
struct ParticleNeighborList3Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> data) {
    fbb_.AddOffset(ParticleNeighborList3::VT_DATA, data);
  }
  ParticleNeighborList3Builder(flatbuffers::FlatBufferBuilder &_fbb)
      : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ParticleNeighborList3Builder &operator=(const ParticleNeighborList3Builder &);
  flatbuffers::Offset<ParticleNeighborList3> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ParticleNeighborList3>(end);
    return o;
  }
};
inline flatbuffers::Offset<ParticleNeighborList3> CreateParticleNeighborList3(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> data = 0) {
  ParticleNeighborList3Builder builder_(_fbb);
  builder_.add_data(data);
  return builder_.Finish();
}
inline flatbuffers::Offset<ParticleNeighborList3>
CreateParticleNeighborList3Direct(flatbuffers::FlatBufferBuilder &_fbb,
                                  const std::vector<uint64_t> *data = nullptr) {
  return jet::fbs::CreateParticleNeighborList3(
      _fbb, data ? _fbb.CreateVector<uint64_t>(*data) : 0);
}
struct ParticleSystemData3 FLATBUFFERS_FINAL_CLASS
    : private flatbuffers::Table {
  enum {
    VT_RADIUS = 4,
    VT_MASS = 6,
    VT_POSITIONIDX = 8,
    VT_VELOCITYIDX = 10,
    VT_FORCEIDX = 12,
    VT_SCALARDATALIST = 14,
    VT_VECTORDATALIST = 16,
    VT_NEIGHBORSEARCHER = 18,
    VT_NEIGHBORLISTS = 20
  };
  double radius() const { return GetField<double>(VT_RADIUS, 0.0); }
  double mass() const { return GetField<double>(VT_MASS, 0.0); }
  uint64_t positionIdx() const { return GetField<uint64_t>(VT_POSITIONIDX, 0); }
  uint64_t velocityIdx() const { return GetField<uint64_t>(VT_VELOCITYIDX, 0); }
  uint64_t forceIdx() const { return GetField<uint64_t>(VT_FORCEIDX, 0); }
  const flatbuffers::Vector<flatbuffers::Offset<ScalarParticleData3>> *
  scalarDataList() const {
    return GetPointer<
        const flatbuffers::Vector<flatbuffers::Offset<ScalarParticleData3>> *>(
        VT_SCALARDATALIST);
  }
  const flatbuffers::Vector<flatbuffers::Offset<VectorParticleData3>> *
  vectorDataList() const {
    return GetPointer<
        const flatbuffers::Vector<flatbuffers::Offset<VectorParticleData3>> *>(
        VT_VECTORDATALIST);
  }
  const PointNeighborSearcherSerialized3 *neighborSearcher() const {
    return GetPointer<const PointNeighborSearcherSerialized3 *>(
        VT_NEIGHBORSEARCHER);
  }
  const flatbuffers::Vector<flatbuffers::Offset<ParticleNeighborList3>> *
  neighborLists() const {
    return GetPointer<const flatbuffers::Vector<
        flatbuffers::Offset<ParticleNeighborList3>> *>(VT_NEIGHBORLISTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_RADIUS) &&
           VerifyField<double>(verifier, VT_MASS) &&
           VerifyField<uint64_t>(verifier, VT_POSITIONIDX) &&
           VerifyField<uint64_t>(verifier, VT_VELOCITYIDX) &&
           VerifyField<uint64_t>(verifier, VT_FORCEIDX) &&
           VerifyOffset(verifier, VT_SCALARDATALIST) &&
           verifier.Verify(scalarDataList()) &&
           verifier.VerifyVectorOfTables(scalarDataList()) &&
           VerifyOffset(verifier, VT_VECTORDATALIST) &&
           verifier.Verify(vectorDataList()) &&
           verifier.VerifyVectorOfTables(vectorDataList()) &&
           VerifyOffset(verifier, VT_NEIGHBORSEARCHER) &&
           verifier.VerifyTable(neighborSearcher()) &&
           VerifyOffset(verifier, VT_NEIGHBORLISTS) &&
           verifier.Verify(neighborLists()) &&
           verifier.VerifyVectorOfTables(neighborLists()) &&
           verifier.EndTable();
  }
};
struct ParticleSystemData3Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_radius(double radius) {
    fbb_.AddElement<double>(ParticleSystemData3::VT_RADIUS, radius, 0.0);
  }
  void add_mass(double mass) {
    fbb_.AddElement<double>(ParticleSystemData3::VT_MASS, mass, 0.0);
  }
  void add_positionIdx(uint64_t positionIdx) {
    fbb_.AddElement<uint64_t>(ParticleSystemData3::VT_POSITIONIDX, positionIdx,
                              0);
  }
  void add_velocityIdx(uint64_t velocityIdx) {
    fbb_.AddElement<uint64_t>(ParticleSystemData3::VT_VELOCITYIDX, velocityIdx,
                              0);
  }
  void add_forceIdx(uint64_t forceIdx) {
    fbb_.AddElement<uint64_t>(ParticleSystemData3::VT_FORCEIDX, forceIdx, 0);
  }
  void add_scalarDataList(
      flatbuffers::Offset<
          flatbuffers::Vector<flatbuffers::Offset<ScalarParticleData3>>>
          scalarDataList) {
    fbb_.AddOffset(ParticleSystemData3::VT_SCALARDATALIST, scalarDataList);
  }
  void add_vectorDataList(
      flatbuffers::Offset<
          flatbuffers::Vector<flatbuffers::Offset<VectorParticleData3>>>
          vectorDataList) {
    fbb_.AddOffset(ParticleSystemData3::VT_VECTORDATALIST, vectorDataList);
  }
  void add_neighborSearcher(
      flatbuffers::Offset<PointNeighborSearcherSerialized3> neighborSearcher) {
    fbb_.AddOffset(ParticleSystemData3::VT_NEIGHBORSEARCHER, neighborSearcher);
  }
  void add_neighborLists(
      flatbuffers::Offset<
          flatbuffers::Vector<flatbuffers::Offset<ParticleNeighborList3>>>
          neighborLists) {
    fbb_.AddOffset(ParticleSystemData3::VT_NEIGHBORLISTS, neighborLists);
  }
  ParticleSystemData3Builder(flatbuffers::FlatBufferBuilder &_fbb)
      : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ParticleSystemData3Builder &operator=(const ParticleSystemData3Builder &);
  flatbuffers::Offset<ParticleSystemData3> Finish() {
    const auto end = fbb_.EndTable(start_, 9);
    auto o = flatbuffers::Offset<ParticleSystemData3>(end);
    return o;
  }
};
inline flatbuffers::Offset<ParticleSystemData3> CreateParticleSystemData3(
    flatbuffers::FlatBufferBuilder &_fbb, double radius = 0.0,
    double mass = 0.0, uint64_t positionIdx = 0, uint64_t velocityIdx = 0,
    uint64_t forceIdx = 0,
    flatbuffers::Offset<
        flatbuffers::Vector<flatbuffers::Offset<ScalarParticleData3>>>
        scalarDataList = 0,
    flatbuffers::Offset<
        flatbuffers::Vector<flatbuffers::Offset<VectorParticleData3>>>
        vectorDataList = 0,
    flatbuffers::Offset<PointNeighborSearcherSerialized3> neighborSearcher = 0,
    flatbuffers::Offset<
        flatbuffers::Vector<flatbuffers::Offset<ParticleNeighborList3>>>
        neighborLists = 0) {
  ParticleSystemData3Builder builder_(_fbb);
  builder_.add_forceIdx(forceIdx);
  builder_.add_velocityIdx(velocityIdx);
  builder_.add_positionIdx(positionIdx);
  builder_.add_mass(mass);
  builder_.add_radius(radius);
  builder_.add_neighborLists(neighborLists);
  builder_.add_neighborSearcher(neighborSearcher);
  builder_.add_vectorDataList(vectorDataList);
  builder_.add_scalarDataList(scalarDataList);
  return builder_.Finish();
}
inline flatbuffers::Offset<ParticleSystemData3> CreateParticleSystemData3Direct(
    flatbuffers::FlatBufferBuilder &_fbb, double radius = 0.0,
    double mass = 0.0, uint64_t positionIdx = 0, uint64_t velocityIdx = 0,
    uint64_t forceIdx = 0,
    const std::vector<flatbuffers::Offset<ScalarParticleData3>>
        *scalarDataList = nullptr,
    const std::vector<flatbuffers::Offset<VectorParticleData3>>
        *vectorDataList = nullptr,
    flatbuffers::Offset<PointNeighborSearcherSerialized3> neighborSearcher = 0,
    const std::vector<flatbuffers::Offset<ParticleNeighborList3>>
        *neighborLists = nullptr) {
  return jet::fbs::CreateParticleSystemData3(
      _fbb, radius, mass, positionIdx, velocityIdx, forceIdx,
      scalarDataList
          ? _fbb.CreateVector<flatbuffers::Offset<ScalarParticleData3>>(
                *scalarDataList)
          : 0,
      vectorDataList
          ? _fbb.CreateVector<flatbuffers::Offset<VectorParticleData3>>(
                *vectorDataList)
          : 0,
      neighborSearcher,
      neighborLists
          ? _fbb.CreateVector<flatbuffers::Offset<ParticleNeighborList3>>(
                *neighborLists)
          : 0);
}
inline const jet::fbs::ParticleSystemData3 *
GetParticleSystemData3(const void *buf) {
  return flatbuffers::GetRoot<jet::fbs::ParticleSystemData3>(buf);
}
inline bool VerifyParticleSystemData3Buffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<jet::fbs::ParticleSystemData3>(nullptr);
}
inline void FinishParticleSystemData3Buffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<jet::fbs::ParticleSystemData3> root) {
  fbb.Finish(root);
}
} // namespace fbs
} // namespace jet

#endif // FLATBUFFERS_GENERATED_PARTICLESYSTEMDATA3_JET_FBS_H_

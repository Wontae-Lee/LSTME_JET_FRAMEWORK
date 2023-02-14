// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_GRIDSYSTEMDATA3_JET_FBS_H_
#define FLATBUFFERS_GENERATED_GRIDSYSTEMDATA3_JET_FBS_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 22 && FLATBUFFERS_VERSION_MINOR == 11 && FLATBUFFERS_VERSION_REVISION == 23,
              "Non-compatible flatbuffers version included");

#include "basic_types_generated.h"

namespace jet {
namespace fbs {

struct ScalarGridSerialized3;
struct ScalarGridSerialized3Builder;

struct VectorGridSerialized3;
struct VectorGridSerialized3Builder;

struct GridSystemData3;
struct GridSystemData3Builder;

struct ScalarGridSerialized3 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
{
  typedef ScalarGridSerialized3Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE
  {
    VT_TYPE = 4,
    VT_DATA = 6
  };
  const flatbuffers::String* type() const { return GetPointer<const flatbuffers::String*>(VT_TYPE); }
  const flatbuffers::Vector<uint8_t>* data() const { return GetPointer<const flatbuffers::Vector<uint8_t>*>(VT_DATA); }
  bool Verify(flatbuffers::Verifier& verifier) const
  {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_TYPE) && verifier.VerifyString(type()) && VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) && verifier.EndTable();
  }
};

struct ScalarGridSerialized3Builder
{
  typedef ScalarGridSerialized3 Table;
  flatbuffers::FlatBufferBuilder& fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(flatbuffers::Offset<flatbuffers::String> type) { fbb_.AddOffset(ScalarGridSerialized3::VT_TYPE, type); }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) { fbb_.AddOffset(ScalarGridSerialized3::VT_DATA, data); }
  explicit ScalarGridSerialized3Builder(flatbuffers::FlatBufferBuilder& _fbb)
    : fbb_(_fbb)
  {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ScalarGridSerialized3> Finish()
  {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ScalarGridSerialized3>(end);
    return o;
  }
};

inline flatbuffers::Offset<ScalarGridSerialized3>
CreateScalarGridSerialized3(flatbuffers::FlatBufferBuilder& _fbb,
                            flatbuffers::Offset<flatbuffers::String> type = 0,
                            flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0)
{
  ScalarGridSerialized3Builder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<ScalarGridSerialized3>
CreateScalarGridSerialized3Direct(flatbuffers::FlatBufferBuilder& _fbb, const char* type = nullptr, const std::vector<uint8_t>* data = nullptr)
{
  auto type__ = type ? _fbb.CreateString(type) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return jet::fbs::CreateScalarGridSerialized3(_fbb, type__, data__);
}

struct VectorGridSerialized3 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
{
  typedef VectorGridSerialized3Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE
  {
    VT_TYPE = 4,
    VT_DATA = 6
  };
  const flatbuffers::String* type() const { return GetPointer<const flatbuffers::String*>(VT_TYPE); }
  const flatbuffers::Vector<uint8_t>* data() const { return GetPointer<const flatbuffers::Vector<uint8_t>*>(VT_DATA); }
  bool Verify(flatbuffers::Verifier& verifier) const
  {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_TYPE) && verifier.VerifyString(type()) && VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) && verifier.EndTable();
  }
};

struct VectorGridSerialized3Builder
{
  typedef VectorGridSerialized3 Table;
  flatbuffers::FlatBufferBuilder& fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(flatbuffers::Offset<flatbuffers::String> type) { fbb_.AddOffset(VectorGridSerialized3::VT_TYPE, type); }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) { fbb_.AddOffset(VectorGridSerialized3::VT_DATA, data); }
  explicit VectorGridSerialized3Builder(flatbuffers::FlatBufferBuilder& _fbb)
    : fbb_(_fbb)
  {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<VectorGridSerialized3> Finish()
  {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<VectorGridSerialized3>(end);
    return o;
  }
};

inline flatbuffers::Offset<VectorGridSerialized3>
CreateVectorGridSerialized3(flatbuffers::FlatBufferBuilder& _fbb,
                            flatbuffers::Offset<flatbuffers::String> type = 0,
                            flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0)
{
  VectorGridSerialized3Builder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<VectorGridSerialized3>
CreateVectorGridSerialized3Direct(flatbuffers::FlatBufferBuilder& _fbb, const char* type = nullptr, const std::vector<uint8_t>* data = nullptr)
{
  auto type__ = type ? _fbb.CreateString(type) : 0;
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  return jet::fbs::CreateVectorGridSerialized3(_fbb, type__, data__);
}

struct GridSystemData3 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
{
  typedef GridSystemData3Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE
  {
    VT_RESOLUTION = 4,
    VT_GRIDSPACING = 6,
    VT_ORIGIN = 8,
    VT_VELOCITYIDX = 10,
    VT_SCALARDATA = 12,
    VT_VECTORDATA = 14,
    VT_ADVECTABLESCALARDATA = 16,
    VT_ADVECTABLEVECTORDATA = 18
  };
  const jet::fbs::Size3* resolution() const { return GetStruct<const jet::fbs::Size3*>(VT_RESOLUTION); }
  const jet::fbs::Vector3D* gridSpacing() const { return GetStruct<const jet::fbs::Vector3D*>(VT_GRIDSPACING); }
  const jet::fbs::Vector3D* origin() const { return GetStruct<const jet::fbs::Vector3D*>(VT_ORIGIN); }
  uint64_t velocityIdx() const { return GetField<uint64_t>(VT_VELOCITYIDX, 0); }
  const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>* scalarData() const
  {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>*>(VT_SCALARDATA);
  }
  const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>* vectorData() const
  {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>*>(VT_VECTORDATA);
  }
  const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>* advectableScalarData() const
  {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>*>(VT_ADVECTABLESCALARDATA);
  }
  const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>* advectableVectorData() const
  {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>*>(VT_ADVECTABLEVECTORDATA);
  }
  bool Verify(flatbuffers::Verifier& verifier) const
  {
    return VerifyTableStart(verifier) && VerifyField<jet::fbs::Size3>(verifier, VT_RESOLUTION, 8) &&
           VerifyField<jet::fbs::Vector3D>(verifier, VT_GRIDSPACING, 8) && VerifyField<jet::fbs::Vector3D>(verifier, VT_ORIGIN, 8) &&
           VerifyField<uint64_t>(verifier, VT_VELOCITYIDX, 8) && VerifyOffset(verifier, VT_SCALARDATA) && verifier.VerifyVector(scalarData()) &&
           verifier.VerifyVectorOfTables(scalarData()) && VerifyOffset(verifier, VT_VECTORDATA) && verifier.VerifyVector(vectorData()) &&
           verifier.VerifyVectorOfTables(vectorData()) && VerifyOffset(verifier, VT_ADVECTABLESCALARDATA) &&
           verifier.VerifyVector(advectableScalarData()) && verifier.VerifyVectorOfTables(advectableScalarData()) &&
           VerifyOffset(verifier, VT_ADVECTABLEVECTORDATA) && verifier.VerifyVector(advectableVectorData()) &&
           verifier.VerifyVectorOfTables(advectableVectorData()) && verifier.EndTable();
  }
};

struct GridSystemData3Builder
{
  typedef GridSystemData3 Table;
  flatbuffers::FlatBufferBuilder& fbb_;
  flatbuffers::uoffset_t start_;
  void add_resolution(const jet::fbs::Size3* resolution) { fbb_.AddStruct(GridSystemData3::VT_RESOLUTION, resolution); }
  void add_gridSpacing(const jet::fbs::Vector3D* gridSpacing) { fbb_.AddStruct(GridSystemData3::VT_GRIDSPACING, gridSpacing); }
  void add_origin(const jet::fbs::Vector3D* origin) { fbb_.AddStruct(GridSystemData3::VT_ORIGIN, origin); }
  void add_velocityIdx(uint64_t velocityIdx) { fbb_.AddElement<uint64_t>(GridSystemData3::VT_VELOCITYIDX, velocityIdx, 0); }
  void add_scalarData(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>> scalarData)
  {
    fbb_.AddOffset(GridSystemData3::VT_SCALARDATA, scalarData);
  }
  void add_vectorData(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>> vectorData)
  {
    fbb_.AddOffset(GridSystemData3::VT_VECTORDATA, vectorData);
  }
  void add_advectableScalarData(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>> advectableScalarData)
  {
    fbb_.AddOffset(GridSystemData3::VT_ADVECTABLESCALARDATA, advectableScalarData);
  }
  void add_advectableVectorData(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>> advectableVectorData)
  {
    fbb_.AddOffset(GridSystemData3::VT_ADVECTABLEVECTORDATA, advectableVectorData);
  }
  explicit GridSystemData3Builder(flatbuffers::FlatBufferBuilder& _fbb)
    : fbb_(_fbb)
  {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<GridSystemData3> Finish()
  {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GridSystemData3>(end);
    return o;
  }
};

inline flatbuffers::Offset<GridSystemData3>
CreateGridSystemData3(flatbuffers::FlatBufferBuilder& _fbb,
                      const jet::fbs::Size3* resolution = nullptr,
                      const jet::fbs::Vector3D* gridSpacing = nullptr,
                      const jet::fbs::Vector3D* origin = nullptr,
                      uint64_t velocityIdx = 0,
                      flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>> scalarData = 0,
                      flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>> vectorData = 0,
                      flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>> advectableScalarData = 0,
                      flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>> advectableVectorData = 0)
{
  GridSystemData3Builder builder_(_fbb);
  builder_.add_velocityIdx(velocityIdx);
  builder_.add_advectableVectorData(advectableVectorData);
  builder_.add_advectableScalarData(advectableScalarData);
  builder_.add_vectorData(vectorData);
  builder_.add_scalarData(scalarData);
  builder_.add_origin(origin);
  builder_.add_gridSpacing(gridSpacing);
  builder_.add_resolution(resolution);
  return builder_.Finish();
}

inline flatbuffers::Offset<GridSystemData3>
CreateGridSystemData3Direct(flatbuffers::FlatBufferBuilder& _fbb,
                            const jet::fbs::Size3* resolution = nullptr,
                            const jet::fbs::Vector3D* gridSpacing = nullptr,
                            const jet::fbs::Vector3D* origin = nullptr,
                            uint64_t velocityIdx = 0,
                            const std::vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>* scalarData = nullptr,
                            const std::vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>* vectorData = nullptr,
                            const std::vector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>* advectableScalarData = nullptr,
                            const std::vector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>* advectableVectorData = nullptr)
{
  auto scalarData__ = scalarData ? _fbb.CreateVector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>(*scalarData) : 0;
  auto vectorData__ = vectorData ? _fbb.CreateVector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>(*vectorData) : 0;
  auto advectableScalarData__ =
    advectableScalarData ? _fbb.CreateVector<flatbuffers::Offset<jet::fbs::ScalarGridSerialized3>>(*advectableScalarData) : 0;
  auto advectableVectorData__ =
    advectableVectorData ? _fbb.CreateVector<flatbuffers::Offset<jet::fbs::VectorGridSerialized3>>(*advectableVectorData) : 0;
  return jet::fbs::CreateGridSystemData3(
    _fbb, resolution, gridSpacing, origin, velocityIdx, scalarData__, vectorData__, advectableScalarData__, advectableVectorData__);
}

inline const jet::fbs::GridSystemData3*
GetGridSystemData3(const void* buf)
{
  return flatbuffers::GetRoot<jet::fbs::GridSystemData3>(buf);
}

inline const jet::fbs::GridSystemData3*
GetSizePrefixedGridSystemData3(const void* buf)
{
  return flatbuffers::GetSizePrefixedRoot<jet::fbs::GridSystemData3>(buf);
}

inline bool
VerifyGridSystemData3Buffer(flatbuffers::Verifier& verifier)
{
  return verifier.VerifyBuffer<jet::fbs::GridSystemData3>(nullptr);
}

inline bool
VerifySizePrefixedGridSystemData3Buffer(flatbuffers::Verifier& verifier)
{
  return verifier.VerifySizePrefixedBuffer<jet::fbs::GridSystemData3>(nullptr);
}

inline void
FinishGridSystemData3Buffer(flatbuffers::FlatBufferBuilder& fbb, flatbuffers::Offset<jet::fbs::GridSystemData3> root)
{
  fbb.Finish(root);
}

inline void
FinishSizePrefixedGridSystemData3Buffer(flatbuffers::FlatBufferBuilder& fbb, flatbuffers::Offset<jet::fbs::GridSystemData3> root)
{
  fbb.FinishSizePrefixed(root);
}

} // namespace fbs
} // namespace jet

#endif // FLATBUFFERS_GENERATED_GRIDSYSTEMDATA3_JET_FBS_H_

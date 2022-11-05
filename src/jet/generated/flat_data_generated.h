// automatically generated by the FlatBuffers compiler, do not modify
#ifndef FLATBUFFERS_GENERATED_FLATDATA_JET_FBS_H_
#define FLATBUFFERS_GENERATED_FLATDATA_JET_FBS_H_
#include "flatbuffers/flatbuffers.h"
namespace jet {
namespace fbs {
struct FlatData;
struct FlatData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum { VT_DATA = 4 };
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) && VerifyOffset(verifier, VT_DATA) &&
           verifier.Verify(data()) && verifier.EndTable();
  }
};
struct FlatDataBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(FlatData::VT_DATA, data);
  }
  FlatDataBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  FlatDataBuilder &operator=(const FlatDataBuilder &);
  flatbuffers::Offset<FlatData> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<FlatData>(end);
    return o;
  }
};
inline flatbuffers::Offset<FlatData>
CreateFlatData(flatbuffers::FlatBufferBuilder &_fbb,
               flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0) {
  FlatDataBuilder builder_(_fbb);
  builder_.add_data(data);
  return builder_.Finish();
}
inline flatbuffers::Offset<FlatData>
CreateFlatDataDirect(flatbuffers::FlatBufferBuilder &_fbb,
                     const std::vector<uint8_t> *data = nullptr) {
  return jet::fbs::CreateFlatData(_fbb,
                                  data ? _fbb.CreateVector<uint8_t>(*data) : 0);
}
inline const jet::fbs::FlatData *GetFlatData(const void *buf) {
  return flatbuffers::GetRoot<jet::fbs::FlatData>(buf);
}
inline bool VerifyFlatDataBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<jet::fbs::FlatData>(nullptr);
}
inline void FinishFlatDataBuffer(flatbuffers::FlatBufferBuilder &fbb,
                                 flatbuffers::Offset<jet::fbs::FlatData> root) {
  fbb.Finish(root);
}
} // namespace fbs
} // namespace jet

#endif // FLATBUFFERS_GENERATED_FLATDATA_JET_FBS_H_

//
// Created by LSTME on 2022-10-17.
//

#ifndef LSTME_FBS_HELPERS_HPP
#define LSTME_FBS_HELPERS_HPP


#include <generated/basic_types_generated.hpp>
#include <size2.hpp>
#include <size3.hpp>
#include <vector2.hpp>
#include <vector3.hpp>
#include <algorithm>
#include <vector>

namespace lstme {

inline fbs::Size2 lstmeToFbs(const Size2& vec) {
  return fbs::Size2(vec.x, vec.y);
}

inline fbs::Size3 lstmeToFbs(const Size3& vec) {
  return fbs::Size3(vec.x, vec.y, vec.z);
}

inline fbs::Vector2D lstmeToFbs(const Vector2D& vec) {
  return fbs::Vector2D(vec.x, vec.y);
}

inline fbs::Vector3D lstmeToFbs(const Vector3D& vec) {
  return fbs::Vector3D(vec.x, vec.y, vec.z);
}

inline Size2 fbsToJet(const fbs::Size2& vec) {
  return Size2({vec.x(), vec.y()});
}

inline Size3 fbsToJet(const fbs::Size3& vec) {
  return Size3({vec.x(), vec.y(), vec.z()});
}

inline Vector2D fbsToJet(const fbs::Vector2D& vec) {
  return Vector2D(vec.x(), vec.y());
}

inline Vector3D fbsToJet(const fbs::Vector3D& vec) {
  return Vector3D(vec.x(), vec.y(), vec.z());
}

template <
  typename GridType,
  typename FbsFactoryFunc,
  typename FbsGridType>
void serializeGrid(
  flatbuffers::FlatBufferBuilder* builder,
  const std::vector<GridType>& gridList,
  FbsFactoryFunc func,
  std::vector<flatbuffers::Offset<FbsGridType>>* fbsGridList) {
  for (const auto& grid : gridList) {
    auto type = builder->CreateString(grid->typeName());

    std::vector<uint8_t> gridSerialized;
    grid->serialize(&gridSerialized);
    auto fbsGrid = func(
      *builder, type, builder->CreateVector(
                        gridSerialized.data(),
                        gridSerialized.size()));
    fbsGridList->push_back(fbsGrid);
  }
}

template <typename FbsGridList, typename GridType, typename FactoryFunc>
void deserializeGrid(
  FbsGridList* fbsGridList,
  FactoryFunc factoryFunc,
  std::vector<GridType>* gridList) {
  for (const auto& grid : (*fbsGridList)) {
    auto type = grid->type()->c_str();

    std::vector<uint8_t> gridSerialized(
      grid->data()->begin(),
      grid->data()->end());

    auto newGrid = factoryFunc(type);
    newGrid->deserialize(gridSerialized);

    gridList->push_back(newGrid);
  }
}

}  // namespace lstme


#endif // LSTME_FBS_HELPERS_HPP

//
// Created by LSTME on 2022-10-14.
//

#include <cstring>
#include <serialization.hpp>
#include <vector>

namespace lstme {

template<typename T>
void
serialize(const ConstArrayAccessor1<T>& array, std::vector<uint8_t>* buffer)
{
  size_t size = sizeof(T) * array.size();
  serialize(reinterpret_cast<const uint8_t*>(array.data()), size, buffer);
}

template<typename T>
void
deserialize(const std::vector<uint8_t>& buffer, Array1<T>* array)
{
  std::vector<uint8_t> data;
  deserialize(buffer, &data);
  array->resize(data.size() / sizeof(T));
  memcpy(reinterpret_cast<uint8_t*>(array->data()), data.data(), data.size());
}

} // namespace lstme
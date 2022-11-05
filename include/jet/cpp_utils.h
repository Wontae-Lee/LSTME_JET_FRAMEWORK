#pragma once
#include <algorithm>
#include <functional>
namespace jet {
template <class ForwardIt, class T, class Compare = std::less<T>>
ForwardIt binaryFind(ForwardIt first, ForwardIt last, const T& value,
                     Compare comp = {});
}  // namespace jet
#include "detail/cpp_utils.inl"
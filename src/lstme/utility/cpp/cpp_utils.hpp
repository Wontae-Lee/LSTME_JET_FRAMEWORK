#ifndef LSTME_CPP_UTILS_HPP
#define LSTME_CPP_UTILS_HPP

#include <algorithm>
#include <functional>

namespace lstme {

template<class ForwardIt, class T, class Compare = std::less<T>>
ForwardIt
binaryFind(ForwardIt first, ForwardIt last, const T& value, Compare comp = {});
} // namespace lstme

#endif // LSTME_CPP_UTILS_HPP

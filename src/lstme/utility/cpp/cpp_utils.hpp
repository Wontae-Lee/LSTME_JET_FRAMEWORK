//
// Created by LSTME on 2022-09-26.
//

#ifndef LSTME_CPP_UTILS_HPP
#define LSTME_CPP_UTILS_HPP

#include <algorithm>

namespace lstme {

template<class ForwardIt, class T, class Compare = std::less<T>>
ForwardIt
binaryFind(ForwardIt first, ForwardIt last, const T& value, Compare comp = {});
} // namespace jet

#endif // LSTME_CPP_UTILS_HPP

#pragma once
#include <jet/point.h>
namespace jet {
//! \brief N-D size type.
template <size_t N>
using Size = Point<size_t, N>;
}  // namespace jet
// #include "detail/size.inl"
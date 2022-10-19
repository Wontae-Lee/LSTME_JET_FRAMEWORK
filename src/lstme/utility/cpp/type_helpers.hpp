// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_TYPE_HELPERS_H_
#define INCLUDE_LSTME_TYPE_HELPERS_H_

namespace lstme {

//! Returns the type of the value itself.
template<typename T>
struct ScalarType
{
  typedef T value;
};

} // namespace lstme

#endif // INCLUDE_LSTME_TYPE_HELPERS_H_

// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_FIELD3_H_
#define INCLUDE_LSTME_FIELD3_H_

#include <memory>

namespace lstme {

//! Abstract base class for 3-D fields.
class Field3
{
public:
  Field3();

  virtual ~Field3();
};

typedef std::shared_ptr<Field3> Field3Ptr;

} // namespace lstme

#endif // INCLUDE_LSTME_FIELD3_H_

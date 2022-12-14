// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_FIELD2_H_
#define INCLUDE_LSTME_FIELD2_H_

#include <memory>

namespace lstme {

//! Abstract base class for 2-D fields.
class Field2
{
public:
  Field2();

  virtual ~Field2();
};

typedef std::shared_ptr<Field2> Field2Ptr;

} // namespace lstme

#endif // INCLUDE_LSTME_FIELD2_H_

#pragma once
#include <memory>
namespace jet {
//! Abstract base class for 3-D fields.
class Field3 {
 public:
    Field3();
    virtual ~Field3();
};
typedef std::shared_ptr<Field3> Field3Ptr;
}  // namespace jet

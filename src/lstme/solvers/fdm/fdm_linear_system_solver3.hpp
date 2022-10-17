// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_FDM_LINEAR_SYSTEM_SOLVER3_H_
#define INCLUDE_LSTME_FDM_LINEAR_SYSTEM_SOLVER3_H_

#include <fdm_linear_system3.hpp>

#include <memory>

namespace lstme {

//! Abstract base class for 3-D finite difference-type linear system solver.
class FdmLinearSystemSolver3 {
 public:
    FdmLinearSystemSolver3() = default;

    virtual ~FdmLinearSystemSolver3() = default;

    //! Solves the given linear system.
    virtual bool solve(FdmLinearSystem3* system) = 0;

    //! Solves the given compressed linear system.
    virtual bool solveCompressed(FdmCompressedLinearSystem3*) { return false; }
};

//! Shared pointer type for the FdmLinearSystemSolver3.
typedef std::shared_ptr<FdmLinearSystemSolver3> FdmLinearSystemSolver3Ptr;

}  // namespace lstme

#endif  // INCLUDE_LSTME_FDM_LINEAR_SYSTEM_SOLVER3_H_

// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_FDM_LINEAR_SYSTEM_SOLVER2_H_
#define INCLUDE_LSTME_FDM_LINEAR_SYSTEM_SOLVER2_H_

#include <fdm_linear_system2.hpp>

#include <memory>

namespace lstme {

//! Abstract base class for 2-D finite difference-type linear system solver.
class FdmLinearSystemSolver2 {
 public:
    FdmLinearSystemSolver2() = default;

    virtual ~FdmLinearSystemSolver2() = default;

    //! Solves the given linear system.
    virtual bool solve(FdmLinearSystem2* system) = 0;

    //! Solves the given compressed linear system.
    virtual bool solveCompressed(FdmCompressedLinearSystem2*) { return false; }
};

//! Shared pointer type for the FdmLinearSystemSolver2.
typedef std::shared_ptr<FdmLinearSystemSolver2> FdmLinearSystemSolver2Ptr;

}  // namespace lstme

#endif  // INCLUDE_LSTME_FDM_LINEAR_SYSTEM_SOLVER2_H_

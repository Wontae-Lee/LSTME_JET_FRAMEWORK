//
// Created by LSTME on 2022-09-26.
//

#ifndef LSTME_CG_HPP
#define LSTME_CG_HPP

#include <blas.hpp>

namespace lstme {

//!
//! \brief No-op preconditioner for conjugate gradient.
//!
//! This preconditioner does nothing but simply copies the input vector to the
//! output vector. Thus, it can be considered as an identity matrix.
//!

template <typename BlasType>
struct NullCgPreconditioner final {
  void build(const typename BlasType::MatrixType&) {}

  void solve(
    const typename BlasType::VectorType& b,
    typename BlasType::VectorType* x) {
    BlasType::set(b, x);
  }
};

//!
//! \brief Solves conjugate gradient.
//!
template <typename BlasType>
void cg(
  const typename BlasType::MatrixType& A,
  const typename BlasType::VectorType& b,
  unsigned int maxNumberOfIterations,
  double tolerance,
  typename BlasType::VectorType* x,
  typename BlasType::VectorType* r,
  typename BlasType::VectorType* d,
  typename BlasType::VectorType* q,
  typename BlasType::VectorType* s,
  unsigned int* lastNumberOfIterations,
  double* lastResidualNorm);

//!
//! \brief Solves pre-conditioned conjugate gradient.
//!
template <
  typename BlasType,
  typename PrecondType>
void pcg(
  const typename BlasType::MatrixType& A,
  const typename BlasType::VectorType& b,
  unsigned int maxNumberOfIterations,
  double tolerance,
  PrecondType* M,
  typename BlasType::VectorType* x,
  typename BlasType::VectorType* r,
  typename BlasType::VectorType* d,
  typename BlasType::VectorType* q,
  typename BlasType::VectorType* s,
  unsigned int* lastNumberOfIterations,
  double* lastResidualNorm);

}  // namespace lstme


#endif // LSTME_CG_HPP

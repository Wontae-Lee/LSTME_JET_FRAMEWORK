// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_LSTME_SVD_H_
#define INCLUDE_LSTME_SVD_H_

#include <matrix2x2.hpp>
#include <matrix3x3.hpp>
#include <matrix4x4.hpp>
#include <matrix_mxn.hpp>

namespace lstme {

//!
//! \brief Singular value decomposition (SVD).
//!
//! This function decompose the input matrix \p a to \p u * \p w * \p v^T.
//!
//! \tparam T Real-value type.
//!
//! \param a The input matrix to decompose.
//! \param u Left-most output matrix.
//! \param w The vector of singular values.
//! \param v Right-most output matrix.
//!
template<typename T>
void
svd(const MatrixMxN<T>& a, MatrixMxN<T>& u, VectorN<T>& w, MatrixMxN<T>& v);

//!
//! \brief Singular value decomposition (SVD).
//!
//! This function decompose the input matrix \p a to \p u * \p w * \p v^T.
//!
//! \tparam T Real-value type.
//!
//! \param a The input matrix to decompose.
//! \param u Left-most output matrix.
//! \param w The vector of singular values.
//! \param v Right-most output matrix.
//!
template<typename T, size_t M, size_t N>
void
svd(const Matrix<T, M, N>& a,
    Matrix<T, M, N>& u,
    Vector<T, N>& w,
    Matrix<T, N, N>& v);

} // namespace lstme

#endif // INCLUDE_LSTME_SVD_H_

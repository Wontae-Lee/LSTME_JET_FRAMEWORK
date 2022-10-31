//
// Created by LSTME on 2022-09-21.
//

#ifndef LSTME_MATH_UTILS_HPP
#define LSTME_MATH_UTILS_HPP

#include <cstddef>
#include <limits>
#include <macros.hpp>

namespace lstme {

//!
//! \brief      Returns true if \p x and \p y are similar.
//!
//! \param[in]  x     The first value.
//! \param[in]  y     The second value.
//! \param[in]  eps   The tolerance.
//!
//! \tparam     T     Value type.
//!
//! \return     True if similar.
//!
template<typename T>
bool
similar(T x, T y, T eps = std::numeric_limits<T>::epsilon());

//!
//! \brief      Returns the sign of the value.
//!
//! \param[in]  x     Input value.
//!
//! \tparam     T     Value type.
//!
//! \return     The sign.
//!
template<typename T>
T
sign(T x);

//!
//! \brief      Returns the minimum value among three inputs.
//!
//! \param[in]  x     The first value.
//! \param[in]  y     The second value.
//! \param[in]  z     The three value.
//!
//! \tparam     T     Value type.
//!
//! \return     The minimum value.
//!
template<typename T>
T
min3(T x, T y, T z);

//!
//! \brief      Returns the maximum value among three inputs.
//!
//! \param[in]  x     The first value.
//! \param[in]  y     The second value.
//! \param[in]  z     The three value.
//!
//! \tparam     T     Value type.
//!
//! \return     The maximum value.
//!
template<typename T>
T
max3(T x, T y, T z);

//! Returns minimum among n-elements.
template<typename T>
T
minn(const T* x, size_t n);

//! Returns maximum among n-elements.
template<typename T>
T
maxn(const T* x, size_t n);

//!
//! \brief      Returns the absolute minimum value among the two inputs.
//!
//! \param[in]  x     The first value.
//! \param[in]  y     The second value.
//!
//! \tparam     T     Value type.
//!
//! \return     The absolute minimum.
//!
template<typename T>
T
absmin(T x, T y);

//!
//! \brief      Returns the absolute maximum value among the two inputs.
//!
//! \param[in]  x     The first value.
//! \param[in]  y     The second value.
//!
//! \tparam     T     Value type.
//!
//! \return     The absolute maximum.
//!
template<typename T>
T
absmax(T x, T y);

//! Returns absolute minimum among n-elements.
template<typename T>
T
absminn(const T* x, size_t n);

//! Returns absolute maximum among n-elements.
template<typename T>
T
absmaxn(const T* x, size_t n);

template<typename T>
size_t
argmin2(T x, T y);

template<typename T>
size_t
argmax2(T x, T y);

template<typename T>
size_t
argmin3(T x, T y, T z);

template<typename T>
size_t
argmax3(T x, T y, T z);

//!
//! \brief      Returns the square of \p x.
//!
//! \param[in]  x     The input.
//!
//! \tparam     T     Value type.
//!
//! \return     The squared value.
//!
template<typename T>
T
square(T x);

//!
//! \brief      Returns the cubic of \p x.
//!
//! \param[in]  x     The input.
//!
//! \tparam     T     Value type.
//!
//! \return     The cubic of \p x.
//!
template<typename T>
T
cubic(T x);

//!
//! \brief      Returns the clamped value.
//!
//! \param[in]  val   The value.
//! \param[in]  low   The low value.
//! \param[in]  high  The high value.
//!
//! \tparam     T     Value type.
//!
//! \return     The clamped value.
//!
template<typename T>
T
clamp(T val, T low, T high);

//!
//! \brief      Converts degrees to radians.
//!
//! \param[in]  angleInDegrees The angle in degrees.
//!
//! \tparam     T              Value type.
//!
//! \return     Angle in radians.
//!
template<typename T>
T
degreesToRadians(T angleInDegrees);

//!
//! \brief      Converts radians to degrees.
//!
//! \param[in]  angleInDegrees The angle in radians.
//!
//! \tparam     T              Value type.
//!
//! \return     Angle in degrees.
//!
template<typename T>
T
radiansToDegrees(T angleInRadians);

//!
//! \brief      Gets the barycentric coordinate.
//!
//! \param[in]  x     The input value.
//! \param[in]  iLow  The lowest index.
//! \param[in]  iHigh The highest index.
//! \param      i     The output index.
//! \param      t     The offset from \p i.
//!
//! \tparam     T     Value type.
//!
template<class T>
void
getBarycentric(T x, ssize_t iLow, ssize_t iHigh, ssize_t* i, T* t);

//!
//! \brief      Computes linear interpolation.
//!
//! \param[in]  f0    The first value.
//! \param[in]  f1    The second value.
//! \param[in]  t     Relative offset [0, 1] from the first value.
//!
//! \tparam     S     Input value type.
//! \tparam     T     Offset type.
//!
//! \return     The interpolated value.
//!
template<typename S, typename T>
S
lerp(const S& f0, const S& f1, T t);

//! \brief      Computes bilinear interpolation.
template<typename S, typename T>
S
bilerp(const S& f00, const S& f10, const S& f01, const S& f11, T tx, T ty);

//! \brief      Computes trilinear interpolation.
template<typename S, typename T>
S
trilerp(const S& f000,
        const S& f100,
        const S& f010,
        const S& f110,
        const S& f001,
        const S& f101,
        const S& f011,
        const S& f111,
        T tx,
        T ty,
        T tz);

//! \brief      Computes Catmull-Rom interpolation.
template<typename S, typename T>
S
catmullRom(const S& f0, const S& f1, const S& f2, const S& f3, T t);

//! \brief      Computes monotonic Catmull-Rom interpolation.
template<typename T>
T
monotonicCatmullRom(const T& f0, const T& f1, const T& f2, const T& f3, T t);

}

#endif // LSTME_MATH_UTILS_HPP

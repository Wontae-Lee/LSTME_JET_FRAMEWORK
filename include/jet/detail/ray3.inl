#pragma once
#include <jet/ray3.h>
namespace jet {
template <typename T>
Ray<T, 3>::Ray() : Ray(Vector3<T>(), Vector3<T>(1, 0, 0)) {}
template <typename T>
Ray<T, 3>::Ray(const Vector3<T>& newOrigin, const Vector3<T>& newDirection)
    : origin(newOrigin), direction(newDirection.normalized()) {}
template <typename T>
Ray<T, 3>::Ray(const Ray& other)
    : origin(other.origin), direction(other.direction) {}
template <typename T>
Vector3<T> Ray<T, 3>::pointAt(T t) const {
    return origin + t * direction;
}
}  // namespace jet

//
// Created by LSTME on 2022-10-14.
//
#include <ray2.hpp>
namespace lstme {

template<typename T>
Ray<T, 2>::Ray()
  : Ray(Vector2<T>(), Vector2<T>(1, 0))
{
}

template<typename T>
Ray<T, 2>::Ray(const Vector2<T>& newOrigin, const Vector2<T>& newDirection)
  : origin(newOrigin)
  , direction(newDirection.normalized())
{
}

template<typename T>
Ray<T, 2>::Ray(const Ray& other)
  : origin(other.origin)
  , direction(other.direction)
{
}

template<typename T>
Vector2<T>
Ray<T, 2>::pointAt(T t) const
{
  return origin + t * direction;
}

} // namespace lstme
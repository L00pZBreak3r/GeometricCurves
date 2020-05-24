#pragma once

#include <cmath>
#include <iostream>

namespace GeometricCurvesLibrary
{
  template<typename T>
  struct point_t
  {
    T x;
    T y;
    T z;

    // if aPolar is true, ax = radius r, ay = inclination theta, az = azimuth phi
    point_t(T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0), bool aPolar = false)
      : x((aPolar) ? (ax * std::sin(ay) * std::cos(az)) : ax), y((aPolar) ? (ax * std::sin(ay) * std::sin(az)) : ay), z((aPolar) ? (ax * std::cos(ay)) : az)
    {
    }

    point_t<T> operator -() const
    {
      return point_t<T>(-x, -y, -z);
    }

    point_t<T>& operator +=(const point_t<T>& b)
    {
      x += b.x;
      y += b.y;
      z += b.z;
      return *this;
    }

    point_t<T>& operator -=(const point_t<T>& b)
    {
      x -= b.x;
      y -= b.y;
      z -= b.z;
      return *this;
    }

    friend point_t<T> operator +(point_t<T> a, const point_t<T>& b)
    {
      a += b;
      return a;
    }
    friend point_t<T> operator -(point_t<T> a, const point_t<T>& b)
    {
      a -= b;
      return a;
    }

    bool operator ==(const point_t<T>& b) const
    {
      return (x == b.x) && (y == b.y) && (z == b.z);
    }
    bool operator !=(const point_t<T>& b) const
    {
      return !(*this == b);
    }

    bool isZero() const
    {
      return (x == static_cast<T>(0)) && (y == static_cast<T>(0)) && (z == static_cast<T>(0));
    }

    friend std::ostream& operator <<(std::ostream& os, const point_t<T>& aPoint)
    {
      return os << "(" << aPoint.x << "; " << aPoint.y << "; " << aPoint.z << ")";
    }
    friend std::wostream& operator <<(std::wostream& os, const point_t<T>& aPoint)
    {
      return os << L"(" << aPoint.x << L"; " << aPoint.y << L"; " << aPoint.z << L")";
    }
  };

  template<typename T>
  struct vector_t : public point_t<T>
  {
    // if aPolar is true, ax = radius r, ay = inclination theta, az = azimuth phi
    vector_t(T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0), bool aPolar = false)
      : point_t<T>(ax, ay, az, aPolar)
    {
    }

    vector_t(const point_t<T>& a, const point_t<T>& b)
      : point_t<T>(b.x - a.x, b.y - a.y, b.z - a.z)
    {
    }

    T length() const
    {
      return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    friend T operator *(const vector_t<T>& a, const vector_t<T>& b)
    {
      return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    }

    vector_t<T> cross(const vector_t<T>& b) const
    {
      return vector_t<T>(this->y * b.z - this->z * b.y, this->z * b.x - this->x * b.z, this->x * b.y - this->y * b.x);
    }
  };

  using point_d = point_t<std::double_t>;
  using vector_d = vector_t<std::double_t>;

}
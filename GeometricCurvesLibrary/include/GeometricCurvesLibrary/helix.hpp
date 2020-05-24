#pragma once

#include "common.hpp"

#include <numbers>

namespace GeometricCurvesLibrary
{

  template<typename T>
  class helix_t : public ellipse_t<T>
  {
  public:
    helix_t(T aRadius, T aStep, const point_t<T>& aPivot)
      : ellipse_t<T>(aRadius, aStep, aPivot)
    {
      this->mName = L"helix";
    }
    helix_t(T aRadius, T aStep, T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0))
      : ellipse_t<T>(aRadius, aStep, ax, ay, az)
    {
      this->mName = L"helix";
    }

    T getRadiusX() const = delete;
    T getRadiusY() const = delete;

    T getRadius() const
    {
      return this->mRadiusX;
    }
    T getStep() const
    {
      return this->mRadiusY;
    }

    point_t<T> getCurvePoint(T at) const override
    {
      return point_t<T>(this->mRadiusX * std::cos(at), this->mRadiusX * std::sin(at), this->mRadiusY * (at / (2 * std::numbers::pi))) + this->mPivot;
    }
    vector_t<T> getFirstDerivative(T at) const override
    {
      return vector_t<T>(-this->mRadiusX * std::sin(at), this->mRadiusX * std::cos(at), this->mRadiusY / (2 * std::numbers::pi));
    }

    void printParameters(std::wostream& aOutStream, bool aPrintPivot = false) const override
    {
      aOutStream << L"Radius=" << this->mRadiusX << L"; Step=" << this->mRadiusY;
      if (aPrintPivot)
      {
        aOutStream << L"; ";
        ellipse_t<T>::printPivot(aOutStream);
      }
    }
  };

  using helix_d = helix_t<std::double_t>;

}
#pragma once

#include "common.hpp"

namespace GeometricCurvesLibrary
{

  template<typename T>
  class ellipse_t : public curve_t<T>
  {
  protected:
    T mRadiusX;
    T mRadiusY;

  public:
    ellipse_t(T aRadiusX, T aRadiusY, const point_t<T>& aPivot)
      : curve_t<T>(aPivot), mRadiusX(aRadiusX), mRadiusY((aRadiusY > static_cast<T>(0)) ? aRadiusY : aRadiusX)
    {
      this->mName = L"ellipse";
    }
    ellipse_t(T aRadiusX, T aRadiusY = static_cast<T>(0), T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0))
      : curve_t<T>(ax, ay, az), mRadiusX(aRadiusX), mRadiusY((aRadiusY > static_cast<T>(0)) ? aRadiusY : aRadiusX)
    {
      this->mName = L"ellipse";
    }

    T getRadiusX() const
    {
      return mRadiusX;
    }
    T getRadiusY() const
    {
      return mRadiusY;
    }

    point_t<T> getCurvePoint(T at) const override
    {
      return point_t<T>(mRadiusX * std::cos(at), mRadiusY * std::sin(at)) + this->mPivot;
    }
    vector_t<T> getFirstDerivative(T at) const override
    {
      return vector_t<T>(-mRadiusX * std::sin(at), mRadiusY * std::cos(at));
    }

    void printParameters(std::wostream& aOutStream, bool aPrintPivot = false) const override
    {
      aOutStream << L"RadiusX=" << mRadiusX << L"; RadiusY=" << mRadiusY;
      if (aPrintPivot)
      {
        aOutStream << L"; ";
        curve_t<T>::printPivot(aOutStream);
      }
    }
  };

  using ellipse_d = ellipse_t<std::double_t>;

}
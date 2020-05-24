#pragma once

#include "ellipse.hpp"

namespace GeometricCurvesLibrary
{

  template<typename T>
  class circle_t : public ellipse_t<T>
  {
  public:
    circle_t(T aRadius, const point_t<T>& aPivot)
      : ellipse_t<T>(aRadius, static_cast<T>(0), aPivot)
    {
      this->mName = L"circle";
    }
    circle_t(T aRadius, T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0))
      : ellipse_t<T>(aRadius, static_cast<T>(0), ax, ay, az)
    {
      this->mName = L"circle";
    }

    T getRadius() const
    {
      return this->mRadiusX;
    }

    void printParameters(std::wostream& aOutStream, bool aPrintPivot = false) const override
    {
      aOutStream << L"Radius=" << this->mRadiusX;
      if (aPrintPivot)
      {
        aOutStream << L"; ";
        ellipse_t<T>::printPivot(aOutStream);
      }
    }
  };

  using circle_d = circle_t<std::double_t>;

}
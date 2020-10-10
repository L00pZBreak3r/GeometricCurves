#pragma once

#include "ellipse.hpp"

namespace GeometricCurvesLibrary
{

  template<typename T>
  class circle_t : public curve_t<T>
  {
  protected:
    T mRadius;

  public:
    circle_t(T aRadius, const point_t<T>& aPivot)
      : curve_t<T>(aPivot), mRadius(aRadius)
    {
    }
    circle_t(T aRadius, T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0))
      : curve_t<T>(ax, ay, az), mRadius(aRadius)
    {
    }

    T getRadius() const
    {
      return this->mRadius;
    }

    point_t<T> getCurvePoint(T at) const override
    {
      return point_t<T>(mRadius * std::cos(at), mRadius * std::sin(at)) + this->mPivot;
    }
    vector_t<T> getFirstDerivative(T at) const override
    {
      return vector_t<T>(-mRadius * std::sin(at), mRadius * std::cos(at));
    }

    void printParameters(std::wostream& aOutStream, bool aPrintPivot = false) const override
    {
      aOutStream << L"circle: Radius=" << this->mRadius;
      if (aPrintPivot)
      {
        aOutStream << L"; ";
        curve_t<T>::printPivot(aOutStream);
      }
    }
  };

  using circle_d = circle_t<std::double_t>;

}
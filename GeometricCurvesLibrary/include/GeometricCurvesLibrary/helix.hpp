#pragma once

#include "common.hpp"

#include <numbers>

namespace GeometricCurvesLibrary
{

  template<typename T>
  class helix_t : public curve_t<T>
  {
  protected:
    T mRadius;
    T mStep;

  public:
    helix_t(T aRadius, T aStep, const point_t<T>& aPivot)
      : curve_t<T>(aPivot), mRadius(aRadius), mStep(aStep)
    {
    }
    helix_t(T aRadius, T aStep, T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0))
      : curve_t<T>(ax, ay, az), mRadius(aRadius), mStep(aStep)
    {
    }

    T getRadius() const
    {
      return this->mRadius;
    }
    T getStep() const
    {
      return this->mStep;
    }

    point_t<T> getCurvePoint(T at) const override
    {
      return point_t<T>(this->mRadius * std::cos(at), this->mRadius * std::sin(at), this->mStep * (at / (2 * std::numbers::pi))) + this->mPivot;
    }
    vector_t<T> getFirstDerivative(T at) const override
    {
      return vector_t<T>(-this->mRadius * std::sin(at), this->mRadius * std::cos(at), this->mStep / (2 * std::numbers::pi));
    }

    void printParameters(std::wostream& aOutStream, bool aPrintPivot = false) const override
    {
      aOutStream << L"helix: Radius=" << this->mRadius << L"; Step=" << this->mStep;
      if (aPrintPivot)
      {
        aOutStream << L"; ";
        curve_t<T>::printPivot(aOutStream);
      }
    }
  };

  using helix_d = helix_t<std::double_t>;

}
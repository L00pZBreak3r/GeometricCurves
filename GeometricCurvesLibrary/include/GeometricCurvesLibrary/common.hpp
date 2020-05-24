#pragma once

#include "point.hpp"

#include <memory>
#include <vector>

namespace GeometricCurvesLibrary
{

  template<typename T>
  class curve_t
  {
  protected:
    point_t<T> mPivot;
    const wchar_t* mName = L"";

    void printPivot(std::wostream& aOutStream) const
    {
      aOutStream << L"Pivot=" << mPivot;
    }

  public:
    curve_t(const point_t<T>& aPivot)
      : mPivot(aPivot)
    {
    }
    curve_t(T ax = static_cast<T>(0), T ay = static_cast<T>(0), T az = static_cast<T>(0))
      : mPivot(ax, ay, az)
    {
    }

    point_t<T> getPivot() const
    {
      return mPivot;
    }

    const wchar_t* getName() const
    {
      return mName;
    }


    virtual point_t<T> getCurvePoint(T at) const = 0;
    virtual vector_t<T> getFirstDerivative(T at) const = 0;

    virtual void printParameters(std::wostream& aOutStream, bool aPrintPivot = false) const
    {
      if (aPrintPivot)
        printPivot(aOutStream);
    }
    virtual void printPoint(std::wostream& aOutStream, T at) const
    {
      aOutStream << L"point(" << at << L")=" << getCurvePoint(at);
    }
    virtual void printFirstDerivative(std::wostream& aOutStream, T at) const
    {
      aOutStream << L"derivative(" << at << L")=" << getFirstDerivative(at);
    }
  };

  using curve_d = curve_t<std::double_t>;

  template<typename T>
  using curve_vector_shared_t = std::vector< std::shared_ptr<curve_t<T>> >;
  using curve_vector_shared_d = curve_vector_shared_t<std::double_t>;

}
#pragma once

#include "common.hpp"

namespace GeometricCurvesLibrary
{
  std::size_t FillContainerRandom(curve_vector_shared_d& aContainer, std::double_t aMin, std::double_t aMax, std::size_t aCount = 0);
  
  /*template<typename T>
  const wchar_t* GetCurveName(const curve_t<T>* aCurve)
  {
    const circle_t<T>* aCircle = dynamic_cast<const circle_t<T>*>(aCurve);
    if (aCircle)
      return L"circle";
    const ellipse_t<T>* aEllipse = dynamic_cast<const ellipse_t<T>*>(aCurve);
    if (aEllipse)
      return L"ellipse";
    const helix_t<T>* aHelix = dynamic_cast<const helix_t<T>*>(aCurve);
    if (aHelix)
      return L"helix";
    return L"curve";
  }*/
}
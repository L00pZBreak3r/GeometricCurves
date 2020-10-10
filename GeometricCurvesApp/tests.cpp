#include "pch.h"
#include "tests.h"

#include "GeometricCurvesLibrary/circle.hpp"
#include "GeometricCurvesLibrary/helix.hpp"
#include "GeometricCurvesLibrary/utilities.hpp"

#include <algorithm>
#include <numeric>

using namespace GeometricCurvesLibrary;

namespace GeometricCurves
{

template<typename T>
static bool TestForCircle(const curve_t<T>* aCurve)
{
  const circle_t<T>* aCircle = dynamic_cast<const circle_t<T>*>(aCurve);
  return aCircle != nullptr;
}

template<typename T>
static bool SortCircles(const curve_t<T>* aCurve1, const curve_t<T>* aCurve2)
{
  const circle_t<T>* aCircle1 = dynamic_cast<const circle_t<T>*>(aCurve1);
  const circle_t<T>* aCircle2 = dynamic_cast<const circle_t<T>*>(aCurve2);
  return aCircle1->getRadius() < aCircle2->getRadius();
}

template<typename T>
static T SumCircleRadius(T aSum, const curve_t<T>* aCurve)
{
  const circle_t<T>* aCircle = dynamic_cast<const circle_t<T>*>(aCurve);
  return aSum + aCircle->getRadius();
}

void Test1(std::wostream& aOutStream, std::double_t aMin, std::double_t aMax, std::size_t aCount)
{
  aOutStream << L"Test 1: creating a std::vector containing curves.\n";
  
  curve_vector_shared_d aContainer;
  /*std::size_t c =*/ FillContainerRandom(aContainer, aMin, aMax, aCount);
  int i;

  auto aPrintCurvePoints = [&aOutStream, &i](const std::shared_ptr<curve_d>& aCurve)
  {
    aOutStream << L"[" << ++i << L"]:";
    aCurve->printParameters(aOutStream);
    aOutStream << L"; ";
    aCurve->printPoint(aOutStream, std::numbers::pi / 4);
    aOutStream << L"; ";
    aCurve->printFirstDerivative(aOutStream, std::numbers::pi / 4);
    aOutStream << L"\n";
  };
  auto aTestForCircle = [](const std::shared_ptr<curve_d>& aCurve) -> bool
  {
    return TestForCircle(aCurve.get());
  };
  auto aSortCircles = [](const std::shared_ptr<curve_d>& aCurve1, const std::shared_ptr<curve_d>& aCurve2) -> bool
  {
    return SortCircles(aCurve1.get(), aCurve2.get());
  };
  auto aSumCircleRadius = [](std::double_t aSum, const std::shared_ptr<curve_d>& aCurve) -> std::double_t
  {
    return SumCircleRadius(aSum, aCurve.get());
  };
  
  aOutStream << L"\nCoordinates of the curves' points at t = PI/4:\n";
  i = 0;
  std::for_each(aContainer.begin(), aContainer.end(), aPrintCurvePoints);

  curve_vector_shared_d aContainer2;
  std::copy_if(aContainer.begin(), aContainer.end(), std::back_inserter(aContainer2), aTestForCircle);

  std::sort(aContainer2.begin(), aContainer2.end(), aSortCircles);

  aOutStream << L"\nSorted container 2:\n";
  i = 0;
  std::for_each(aContainer2.begin(), aContainer2.end(), aPrintCurvePoints);

  std::double_t sum = std::accumulate(aContainer2.begin(), aContainer2.end(), 0.0, aSumCircleRadius);
  aOutStream << L"\nThe total sum of the radii of all the curves in the second container:" << sum << L"\n";
}

}

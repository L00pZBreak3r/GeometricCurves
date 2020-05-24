#include "pch.h"

#include "GeometricCurvesLibrary/circle.hpp"
#include "GeometricCurvesLibrary/helix.hpp"

#include <random>

namespace GeometricCurvesLibrary
{

std::size_t FillContainerRandom(curve_vector_shared_d& aContainer, std::double_t aMin, std::double_t aMax, std::size_t aCount)
{
  std::random_device rd;
  std::mt19937 gen(rd());

  if (aCount == 0)
  {
    std::uniform_int_distribution<> dis_i(3, 1024);
    aCount = dis_i(gen);
  }
  else if (aCount < 3)
    aCount = 3;
  
  if (aMin <= 0.0)
    aMin = 0.001;
  if (aMax <= aMin)
    aMax = aMin + 100;

  std::uniform_real_distribution<> dis_radius(aMin, aMax);
  std::uniform_int_distribution<> dis_i2(0, 2);
  
  aContainer.push_back(std::make_shared<circle_d>(dis_radius(gen)));
  aContainer.push_back(std::make_shared<ellipse_d>(dis_radius(gen), dis_radius(gen)));
  aContainer.push_back(std::make_shared<helix_d>(dis_radius(gen), dis_radius(gen)));
  
  for (std::size_t i = 3; i < aCount; ++i)
  {
    switch (dis_i2(gen))
    {
      case 1:
        aContainer.push_back(std::make_shared<circle_d>(dis_radius(gen)));
        break;
      case 2:
        aContainer.push_back(std::make_shared<helix_d>(dis_radius(gen), dis_radius(gen)));
        break;
      default:
        aContainer.push_back(std::make_shared<ellipse_d>(dis_radius(gen), dis_radius(gen)));
        break;
    }
  }

  return aCount;
}

}
// cheremnykh.cpp : Defines the exported functions for the DLL application.
//

#include "pch.h"
#include "tests.h"

#include <iostream>

using namespace GeometricCurves;

int _tmain(int argc, _TCHAR* argv[])
{
  Test1(std::wcout, 0.001, 100.0, 20);

  return 0;
}


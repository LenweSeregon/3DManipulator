#include <cmath>

#include "MathsTools.hpp"

float MathsTools::epsilonEquals = 0.0001f;

bool MathsTools::AreEquals(float i, float j)
{
  return fabs(i - j) < epsilonEquals;
}

bool MathsTools::AreEquals(double i, double j)
{
  return fabs(i - j) < epsilonEquals;
}

bool MathsTools::AreEquals(double i, float j)
{
  return fabs(i - j) < epsilonEquals;
}

bool MathsTools::AreEquals(float i, double j)
{
  return fabs(i - j) < epsilonEquals;
}

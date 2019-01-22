#ifndef __FRUSTUM_HPP__
#define __FRUSTUM_HPP__

#include <cmath>

#include "Point.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "LineSegment.hpp"

namespace application
{
  class Frustum
  {

  private:


    
  public:

    geometry::Plane nearPlane;
    geometry::Plane farPlane;
    geometry::Plane rightPlane;
    geometry::Plane leftPlane;
    geometry::Plane topPlane;
    geometry::Plane bottomPlane;

    Frustum(){};
    Frustum(float focaleDistance, float aspectRatio, float near, float far);
    bool Outside(const geometry::Point<float,4>& p) const;
    bool Outside(const geometry::Point<float,3>& p) const;
    bool Outside(const geometry::Sphere& sphere) const;
    std::optional<geometry::LineSegment> Inter(const geometry::LineSegment& s) const;
  };
}

#endif

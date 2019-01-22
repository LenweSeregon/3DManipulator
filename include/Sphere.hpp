#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include <cmath>
#include "Vector.hpp"
#include "Plane.hpp"

namespace geometry
{
  class Sphere
  {

  private:
    om::Vector<3,float> point;
    float radius;
    
  public:

    Sphere()
    {

    }

    Sphere(om::Vector<3,float> point, float radius)
    {
      this->point = point;
      this->radius = radius;
    }

    om::Vector<3,float> GetPoint() const
    {
      return point;
    }

    float GetRadius() const
    {
      return radius;
    }

    bool IsNull()
    {
      return point.IsNull();
    }

    bool Behind(const Plane& plane) const
    {
      float distanceSigned = plane.GetNormalUnit().DotProduct(point) + plane.GetD();
      std::cout << "Distance = " << (fabs(distanceSigned) - radius) << std::endl;
      if(fabs(distanceSigned) - radius <= 0)
	{
	  return false;
	}
      else
	{
	  return distanceSigned < 0;
	}
    }

    friend std::ostream& operator<<(std::ostream& os, const Sphere& sphere)
    {
      os << "Sphere :" << std::endl;
      os << "\tPoint : " << sphere.point << std::endl;
      os << "\tRadius : " << sphere.radius << std::endl;
      return os;
    }
    
  };
}

#endif

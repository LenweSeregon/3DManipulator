#include <optional>

#include "Frustum.hpp"
#include "Vector.hpp"

namespace application
{
  Frustum::Frustum(float focaleDistance, float aspectRatio, float near, float far)
  {
      om::Vector<4,float> nearPlaneEquation;
      nearPlaneEquation[0] = 0.0f;
      nearPlaneEquation[1] = 0.0f;
      nearPlaneEquation[2] = -1.0f;
      nearPlaneEquation[3] = -near;
      nearPlane = geometry::Plane(nearPlaneEquation);

      om::Vector<4,float> farPlaneEquation;
      farPlaneEquation[0] = 0.0f;
      farPlaneEquation[1] = 0.0f;
      farPlaneEquation[2] = 1.0f;
      farPlaneEquation[3] = far;
      farPlane = geometry::Plane(farPlaneEquation);

      om::Vector<4,float> rightPlaneEquation;
      rightPlaneEquation[0] = -focaleDistance;
      rightPlaneEquation[1] = 0.0f;
      rightPlaneEquation[2] = -1.0f;
      rightPlaneEquation[3] = 0.0f;
      rightPlane = geometry::Plane(rightPlaneEquation);

      om::Vector<4,float> leftPlaneEquation;
      leftPlaneEquation[0] = focaleDistance;
      leftPlaneEquation[1] = 0.0f;
      leftPlaneEquation[2] = -1.0f;
      leftPlaneEquation[3] = 0.0f;
      leftPlane = geometry::Plane(leftPlaneEquation);

      om::Vector<4,float> topPlaneEquation;
      topPlaneEquation[0] = 0.0f;
      topPlaneEquation[1] = -focaleDistance;
      topPlaneEquation[2] = -aspectRatio;
      topPlaneEquation[3] = 0.0f;
      topPlane = geometry::Plane(topPlaneEquation);

      om::Vector<4,float> bottomPlaneEquation;
      bottomPlaneEquation[0] = 0.0f;
      bottomPlaneEquation[1] = focaleDistance;
      bottomPlaneEquation[2] = -aspectRatio;
      bottomPlaneEquation[3] = 0.0f;
      bottomPlane = geometry::Plane(bottomPlaneEquation);
  }

  bool Frustum::Outside(const geometry::Point<float,4>& p) const
  { 
    return
      p.Behind(nearPlane) ||
      p.Behind(farPlane) ||
      p.Behind(rightPlane) ||
      p.Behind(leftPlane) ||
      p.Behind(topPlane) ||
      p.Behind(bottomPlane);
  }

  bool Frustum::Outside(const geometry::Point<float,3>& p) const
  {
    return
      p.Behind(nearPlane) ||
      p.Behind(farPlane) ||
      p.Behind(rightPlane) ||
      p.Behind(leftPlane) ||
      p.Behind(topPlane) ||
      p.Behind(bottomPlane);    
  }

  bool Frustum::Outside(const geometry::Sphere& sphere) const
  {
    return
      sphere.Behind(nearPlane) ||
      sphere.Behind(farPlane) ||
      sphere.Behind(rightPlane) ||
      sphere.Behind(leftPlane) ||
      sphere.Behind(topPlane) ||
      sphere.Behind(bottomPlane);
  }

  std::optional<geometry::LineSegment> Frustum::Inter(const geometry::LineSegment& s) const
  {
    std::optional<geometry::LineSegment> ls = s;
    return ls;
    
    /*std::optional<geometry::Point<float,3>> first = std::nullopt;
    std::optional<geometry::Point<float,3>> second = std::nullopt;

    // ASSIGNATION DES VALEURS
    std::optional<geometry::Point<float,3>> point1 = s.Inter(nearPlane);
    if(point1 != std::nullopt && !Outside(*point1))
      {
	if(first == std::nullopt) first = *point1;
	else second = *point1;
      }
    
    std::optional<geometry::Point<float,3>> point2 = s.Inter(farPlane);
    if(point2 != std::nullopt && !Outside(*point2))
      {
	if(first == std::nullopt) first = *point2;
	else second = *point2;
      }
    
    std::optional<geometry::Point<float,3>> point3 = s.Inter(rightPlane);
    if(point3 != std::nullopt && !Outside(*point3))
      {
	if(first == std::nullopt) first = *point3;
	else second = *point3;
      }
	
    std::optional<geometry::Point<float,3>> point4 = s.Inter(leftPlane);
    if(point4 != std::nullopt && !Outside(*point4))
      {
	if(first == std::nullopt) first = *point4;
	else second = *point4;
      }
	
    std::optional<geometry::Point<float,3>> point5 = s.Inter(topPlane);
    if(point5 != std::nullopt && !Outside(*point5))
      {
	if(first == std::nullopt) first = *point5;
	else second = *point5;
      }
	
    std::optional<geometry::Point<float,3>> point6 = s.Inter(bottomPlane);
    if(point6 != std::nullopt && !Outside(*point6))
      {
	if(first == std::nullopt) first = *point6;
	else second = *point6;
      }

    // RETOUR
    if(first == std::nullopt && second == std::nullopt)
      {
	if(!Outside(s.GetBegin()) && !Outside(s.GetEnd()))
	  {
	    return s;
	  }
	else
	  {
	    std::cout << "RETURN NULLOPT" << std::endl;
	    return std::nullopt;
	  }
      }
    else if(first != std::nullopt && second == std::nullopt)
      {
	return geometry::LineSegment(*first,*first);
      }
    else
      {
	return geometry::LineSegment(*first,*second);
	}*/
  }

  void Update(float horizontal, float vertical, float e)
  {
    std::cout << horizontal << " " << vertical << " " << e << std::endl;
  }
}

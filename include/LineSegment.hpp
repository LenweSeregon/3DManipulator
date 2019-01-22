#ifndef __LINE_SEGMENT_HPP__
#define __LINE_SEGMENT_HPP__

#include <optional>
#include <climits>
#include "MathsTools.hpp"
#include "Point.hpp"
#include "Plane.hpp"

namespace geometry
{

  // @description classe representant un segment dans notre moteur graphique
  class LineSegment
  {

    private:

    Point<float,3> begin;
    Point<float,3> end;
    
    public:

    // @description constructeur par defaut
    LineSegment()
    {

    }

    // @description construire pour notre segment
    // @arg begin le point qui commence notre segment
    // @arg end le point qui termine notre segment
    LineSegment(Point<float,3> begin, Point<float,3> end)
    {
      this->begin = begin;
      this->end = end;
    }

    // @see Vector.IsNull()
    bool IsNull() const
    {
      return begin.IsNull() && end.IsNull();
    }

    // @description methode permettant de recuperer le premier point de notre segment
    // @return le premier point du segment
    Point<float,3> GetBegin() const
    {
      return begin;
    }

    // @description methode permettant de recuperer le deuxieme point de notre segment
    // @return le deuxieme point du segment
    Point<float,3> GetEnd() const
    {
      return end;
    }

    // @description methode permettant de recuperer le point d'intersection entre un plan
    // passe en parametre et notre segment
    // @arg plane le plan avec lequel on souhaite faire le test
    // @return un point representant l'intersection entre le segment et le plan si il existe
    // @throw invalid_argument si il n'y a pas d'intersection
    std::optional<Point<float,3>> Inter(const Plane& plane) const
    {
      try
	{
	  om::Vector<4,float> extendedPoint = begin.ExtendedPoint4D();
	  Direction<float,3> directionSegment = begin.LengthTo(end); 
	  om::Vector<4,float> directionVec = directionSegment.ExtendedDirection4D().GetVectorDirection();
	  float t = InterCoef(plane);
	  if(t > 1 || t < 0)
	    {
	      if(t == 0)
		{
		  return begin;
		}

	      return std::nullopt;
	    }
	  
	  om::Vector<4,float> res = extendedPoint + (t * directionVec);
	  Point<float,3> point;
	  for(unsigned int i = 0; i < 3; i++)
	    {
	      point[i] = res[i];
	    }
	  return point;
	}
      catch(const std::out_of_range& e)
	{
	  return std::nullopt;
	}
    }

    // @description methode permettant de connaitre l'intercoef entre un segment et un plan
    // cette valeur va permettre de dire de combien l'on se trouve de notre part par rapport à un
    // rayon
    // @arg plane le plan avec lequel on veut tester
    // @return le facteur t de l'intersection entre notre rayon et notre plan
    // @throw out of range si la droite est parallele et non confondu au plan
    float InterCoef(const Plane& plane) const
    {
      Direction<float,3> directionSegment = begin.LengthTo(end); 
      om::Vector<4,float> directionVec = directionSegment.ExtendedDirection4D().GetVectorDirection();
      om::Vector<4,float> planeEquation = plane.GetNormalDir();
      om::Vector<4,float> extendedPoint = begin.ExtendedPoint4D();
      float numerator = planeEquation.DotProduct(extendedPoint);
      float denominator = planeEquation.DotProduct(directionVec);

      if(denominator == 0)
	{
	  if(numerator == 0)
	    {
	      return 0;
	    }
	  throw std::out_of_range("NAN");
	}
      else
	{
	  return -(numerator / denominator);
	}
    }

    // @description operateur d'affichage pour notre segment
    friend std::ostream& operator<<(std::ostream& os, const LineSegment& seg)
    {
      os << "Line Segment :";
      os << "\tBegin : " << seg.begin << std::endl;
      os << "\tEnd : " << seg.end << std::endl;
      return os;
    }
    
  };
}

#endif

#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "Vector.hpp"
#include "Point.hpp"

namespace geometry
{
  // @description classe representant un triangle 2Davec 3 points de coordonnées 3D
  template <typename T, size_t N>
  class Triangle
  {

  private:

    Point<T,N> points[3];
    
  public:

    // @description constructeur par defaut
    Triangle()
    {
    }

    // @descritpion constructeur pour construire notre triangle avec une liste de 3 points
    // @arg list liste d'initialisation
    // @throw invalid_argument si la liste n'est pas de taille 3
    Triangle(std::initializer_list<Point<T,N>> list)
    {
      if(list.size() != 3)
	{
	  throw std::invalid_argument("List size should be 3 for triangles");
	}

      for(size_t i = 0; i < N; i++)
	{
	  points[i] = *(list.begin() + i);
	}
    }

    // @description methode permettant de retourner l'aire de notre triangle.
    // @return retourne l'aire de notre triangle
    float Area() const
    {
      om::Vector<N,T> vector1 = points[0].VectorFrom2Point(points[1]);
      om::Vector<N,T> vector2 = points[0].VectorFrom2Point(points[2]);

      return 1.0f/2.0f * ((vector1 * vector2).Norm());
    }

    // @see Vector.IsNull()
    bool IsNull() const
    {
      for(size_t i = 0; i < 3; i++)
	{
	  if(points[i].IsNull())
	    {
	      return true;
	    }
	}

      return false;
    }

    // @description methode permettant de recuperer le premier point du triangle
    // @return le premier point du triangle
    Point<T,N> GetP0() const
    {
      return points[0];
    }

    // @description methode permettant de recuperer le deuxieme point du triangle
    // @return le deuxieme point du triangle
    Point<T,N> GetP1() const
    {
      return points[1];
    }

    // @description methode permettant de recuperer le troisieme point du triangle
    // @return le troisieme point du triangle
    Point<T,N> GetP2() const
    {
      return points[2];
    }

    // @description operateur d'affichage pour notre triangle
    friend std::ostream& operator<<(std::ostream& os, const Triangle<T,N>& triangle)
    {
      os << "Triangle : " << std::endl;
      os << "\tP0 : " << triangle.points[0] << std::endl;
      os << "\tP1 : " << triangle.points[1] << std::endl;
      os << "\tP2 : " << triangle.points[2] << std::endl;
      return os;
    }
  
  };
}

#endif

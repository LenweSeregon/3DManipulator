#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <initializer_list>
#include <cmath>

#include "Vector.hpp"
#include "Direction.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Quaternion.hpp"

namespace geometry
{
  // @description classe representant un point dans notre moteur graphique
  template<typename T, size_t N>
  class Point
  {

  private:

    om::Vector<N,T> point;

  public:

    // @description constructeur par defaut
    Point():
      point()
    {
      
    }

    // @description constructeur prenant un vecteur afin d'initialiser notre point
    // @arg point le vecteur pour initialiser les valeurs du point
    Point(om::Vector<N,T> point)
    {
      this->point = point;
    }
    
    // @description constructeur prenant une liste de T afin de construire notre point
    // @arg list la liste avec les valeurs de notre point
    // @throw invalid_argument si la liste est d'une taille differente de la dimension du point
    Point(std::initializer_list<T> list)
    {
      if(list.size() != N)
	{
	  throw std::invalid_argument("List size should be " + std::to_string(N) +".");
	}

      for(size_t i = 0; i < list.size(); i++)
	{
	  point[i] = *(list.begin() + i);
	}
    }

    // @description retourne les coordonnes du points
    // @return les coordonnees
    om::Vector<N,T> Coords() const
    {
      return point;
    }

    // @description methode permettant d'etendre notre point en 4D avec la derniere composante à 0
    // @return notre point etant reellement un point avec une dimension suplementaire
    Point<T,N+1> ExtendedPoint4DAsPoint() const
    {
      om::Vector<N+1,T> extended;
      for(unsigned int i = 0; i < N; i++)
	{
	  extended[i] = point.At(i);
	}
      extended[N] = 1;
      return Point<T,N+1>(extended);
    }

    // @description methode permettant de recuperer notre point en point 3D si cela est possible
    // @return notre point avec une dimension en moins
    Point<T,N-1> ReduceToPoint3DAsPoint() const
    {
      if(N != 4) throw std::invalid_argument("Should be 4D");
      
      om::Vector<N-1,T> reduced;
      for(unsigned int i = 0; i < N - 1; i++)
	{
	  reduced[i] = point.At(i);
	}
      return Point<T,N-1>(reduced);
    }
    
    // @description methode permettant de recuperer notre point en point 3D si cela est possible
    // @return notre point avec une dimension en moins et sous forme de vecteur
    om::Vector<N-1,T> ReduceToPoint3D() const
    {
      if(N != 4) throw std::invalid_argument("Should be 4D");
      
      om::Vector<N-1,T> reduced;
      for(unsigned int i = 0; i < N - 1; i++)
	{
	  reduced[i] = point.At(i);
	}
      return reduced;
    }

    // @description methode permettant d'etendre notre point en 4D avec la derniere composante à 1
    // @return notre point avec une dimension en plus avec la valeur à 1
    om::Vector<N+1,T> ExtendedPoint4D() const
    {
      om::Vector<N+1,T> extended;
      for(unsigned int i = 0; i < N; i++)
	{
	  extended[i] = point.At(i);
	}
      extended[N] = 1;
      return extended;
    }

    // @description methode permettant de connaitre la direction sous forme d'un vecteur en 2 point 
    // @arg point2 le deuxieme point avec lequel on veut connaitre la direction
    // @return un vecteur representant la direction de notre point
    om::Vector<N,T> VectorFrom2Point(const Point<T,N>& point2) const
    {
      om::Vector<N,T> vector;
      for(size_t i = 0; i < N; i++)
	{
	  vector[i] = point2.At(i) - point.At(i);
	}
      
      return vector;
    }

    // @description methode permettant de savoir si notre point se trouve devant ou derriere un plan
    // @arg plane le plan avec lequel on veut faire le test
    // @return vrai si le point est derriere le plan, faux sinon
    bool Behind(const Plane& plane) const
    {
      if(N == 3)
	{
	  om::Vector<N+1,float> pointExtended;
	  for(unsigned int i = 0; i < N; i++)
	    {
	      pointExtended[i] = point.At(i);
	    }
	  pointExtended[N] = 1;
	  return plane.GetNormalizedEquation().DotProduct(pointExtended) < 0;
	}
      else
	{
	  return plane.GetNormalizedEquation().DotProduct(point) < 0;
	}
    }

        // @description methode permettant de savoir si notre point se trouve devant ou derriere un plan
    // @arg plane le plan avec lequel on veut faire le test
    // @return vrai si le point est derriere le plan, faux sinon
    float Dist(const Plane& plane) const
    {
      if(N == 3)
	{
	  om::Vector<N+1,float> pointExtended;
	  for(unsigned int i = 0; i < N; i++)
	    {
	      pointExtended[i] = point.At(i);
	    }
	  pointExtended[N] = 1;
	  return fabs(plane.GetNormalUnit().DotProduct(point) + plane.GetD());
	  //return plane.GetNormalUnit().DotProduct(point) + plane.GetD();
	}
      else
	{
	  auto pointAs3D = this->ReduceToPoint3DAsPoint();
	  return fabs(plane.GetNormalUnit().DotProduct(pointAs3D.Coords()) + plane.GetD());
	  //return plane.GetNormalUnit().DotProduct(pointAs3D.Coords()) + plane.GetD();
	}
    }

    // @description methode permettant de faire rotationner notre point via un quaternion
    // @arg quat le quaternion representant notre rotation
    // @return un nouveau point correspondant à la rotation de notre point par le quaternion
    Point<T,N> Rotate(const Quaternion<T>& quat)
    {
      om::Vector<3,float> imaginaryPart;
      for(unsigned int i = 0; i < 3; i++)
	{
	  imaginaryPart[i] = quat.Im()[i];
	}
      T scalarPart = quat.Re();

      om::Vector<N,T> newPoint
	= 2.0f * imaginaryPart.DotProduct(point) * imaginaryPart +
	(scalarPart * scalarPart - imaginaryPart.DotProduct(imaginaryPart)) * point +
	2.0f * scalarPart * imaginaryPart.CrossProduct(point);

      return Point<T,N>(newPoint);
    }

    // @description methode permettant de savoir si ce point se trouve à l'exterieur d'une sphere
    // @arg sphere la sphere avec laquelle on veut faire le test
    // @return vrai si le point est à l'exterieur de la sphere, faux sinon
    bool Outside(const Sphere& sphere) const
    {
      Point<T,N> asPoint = Point<T,N>(sphere.GetPoint());
      float distance = LengthTo(asPoint).Norm();
      return distance > sphere.GetRadius();
    }
    
    // @description permettant de connaitre la distance entre deux points mais sans utiliser sqrt
    // pour des raisons de performances
    // arg p le point avec lequel on veut connaitre la distance
    // @return la distance sans la racine carré
    float DistanceBetweenPoints(const Point<T,N>& p) const
    {
      float distance = 0;
      for(unsigned int i = 0; i < N; i++)
	{
	  distance += (point.At(i) - p.At(i)) * (point.At(i) - p.At(i));
	}
      return distance;
    }

    // @description permettant de connaitre la distance entre deux points en utilisant sqrt
    // arg p le point avec lequel on veut connaitre la distance
    // @return la distance
    float DistanceBetweenPointsSQRT(const Point<T,N>& p) const
    {
      float distance = 0;
      for(unsigned int i = 0; i < N; i++)
	{
	  distance += (point.At(i) - p.At(i)) * (point.At(i) - p.At(i));
	}
      return sqrt(distance);
    }

    // @description methode permettant de connaitre la direction entre notre point et un deuxieme point
    // @arg p le point avec lequel on veut connaitre la direction
    // @return une direction entre nos 2 points
    Direction<T,N> LengthTo(const Point<T,N>& p) const
    {
      om::Vector<N,T> vector;
      for(unsigned int i = 0; i < N; i++)
	{
	  vector[i] = p.At(i) - point.At(i);
	}
      return Direction<T,N>(vector);
    }

    // @see Vector.At()
    T At(int i) const
    {
      return point.At(i);
    }

    // @see Vector.operator[]
    T& operator[](int i)
    {
      return point[i];
    }

    // @see Vector.IsNull()
    bool IsNull() const
    {
      return point.IsNull();
    }

    // @description operateur d'affichage de notre point
    friend std::ostream& operator<<(std::ostream& os, const Point<T,N>& p)
    {
      os << "( ";
      for(size_t i = 0; i < N; i++)
	{
	  if(i == N -1)
	    {
	      os << p.At(i);
	    }
	  else
	    {
	      os << p.At(i) << ", ";
	    }
	}
      os << ")";
      return os;
    }
    
  };
}

#endif

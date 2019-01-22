#ifndef __DIRECTION_HPP__
#define __DIRECTION_HPP__

#include "Vector.hpp"

namespace geometry
{
  // @description classe representant une direction dans notre moteur graphique
  template <typename T, size_t N>
  class Direction
  {
    
  private:

    om::Vector<N,T> dir;
    
  public:

    // @description constructeur par defaut
    Direction()
    {
    }

    // @description constructeur prenant un vecteur pour l'assigner à notre direction
    // @arg direction la direction que l'on souhaite assigner
    Direction(om::Vector<N,T> direction)
    {
      dir = direction;
    }

    // @description methode permettant d'etendre notre direction en 4D (avec un 0 à la fin)
    // @return une direction d'un dimension plus grande avec le dernier composant à 0 et le reste égale à la direction.
    Direction<T,N+1> ExtendedDirection4D() const
    {
      Direction<T,N+1> extended;
      for(unsigned int i = 0; i < N; i++)
	{
	  extended[i] = dir.At(i);
	}
      extended[N] = 0;
      return extended;
    }

    // @description methode permettant de recuperer notre equation de plan
    // @return notre equation de plan dans un veteur3D
    om::Vector<N,T> GetVectorDirection() const
    {
      return dir;
    }

    // @see Vector.At();
    T At(int i) const
    {
      return dir.At(i);
    }

    // @see Vector.operator[]
    T& operator[](int i)
    {
      return dir[i];
    }

    // @see Vector.IsNull()
    bool IsNull() const
    {
      return dir.IsNull();
    }
    
    // @see Vector.IsUnit()
    bool IsUnit() const
    {
      return dir.IsUnit();
    }

    // @see Vector.Norm()
    T Norm() const
    {
      return dir.Norm();
    }

    // @see Vector.ToUnit()
    Direction ToUnit() const
    {
      Direction direction;
      direction.dir = dir.ToUnit();
      return direction;
    }

    // @description permet d'afficher notre direction
    friend std::ostream& operator<<(std::ostream& os, const Direction& direction)
    {
      os << "Direction : " << direction.dir << std::endl;
      return os;
    }

    // @see Vector.operator*(float)
    Direction<T,N> operator*(double scalar)
    {
      Direction<T,N> mult;
      mult.dir = dir * (float)scalar;
      return mult;
    }
    
    // @see Vector.operator*(float)
    Direction<T,N> operator*(float scalar)
    {
      Direction<T,N> mult;
      mult.dir = dir * scalar;
      return mult;
    }

    // @see Vector.operator*(int)
    Direction<T,N> operator*(int scalar)
    {
      Direction<T,N> mult;
      mult.dir = dir * scalar;
      return mult;
    }
  };
}

#endif

#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include "Vector.hpp"
#include "Direction.hpp"

namespace geometry
{
  // @description classe representant un plan dans notre moteur graphique represente
  // sous la forme d'equation ax + by + cz + d = 0
  class Plane
  {

  private:

    om::Vector<4,float> normalDir;

  public:

    // @description Constructeur par defaut
    Plane()
    {

    }

    // @description constructeur pour initialiser l'equation de notre plan
    Plane(om::Vector<4,float> representation)
    {
      normalDir = representation;
    }

    // @description methode permettant de recuperer l'equation de notre plan sans modification
    // @return l'equation de notre plan dans un vecteur 4D
    om::Vector<4,float> GetNormalDir() const
    {
      return normalDir;
    }

    om::Vector<3,float> GetNormal() const
    {
      om::Vector<3,float> normal;
      for(int i = 0; i < 3; i++)
	{
	  normal[i] = normalDir.At(i);
	}
      return normal;
    }

    om::Vector<3,float> GetNormalUnit() const
    {
      return GetNormal().ToUnit();
    }

    float GetD() const
    {
      return normalDir.At(3);
    }

    // @description methode permettant de recuperer l'equation de notre plan avec la normal unitaire
    // @return l'equation de notre plan dans un vecteur 4D et avec le vecteur normal unitaire
    om::Vector<4,float> GetNormalizedEquation() const
    {
      return normalDir.ToUnit();
    }

    // @see Vector.IsNull()
    bool IsNull()
    {
      return normalDir.IsNull();
    }

    // @description operateur d'affichage de notre plan
    friend std::ostream& operator<<(std::ostream& os, const Plane& plane)
    {
      os << "Plane : " << std::endl;
      os << "\tNormal : " << plane.normalDir << std::endl;
      return os;
    }
  };
}

#endif

#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Point.hpp"

namespace geometry
{
  // @description Classe representant un rectangle 2D avec des coordonnees 3D dans notre
  // moteur graphique
  class Rectangle
  {

  private:

    Point<float,3> leftBottom;
    Point<float,3> rightTop;
    
  public:

    // @description constructeur afin de construire le rectangle avec ces points extremes
    // @arg leftB le point ingerieur bas de notre rectangle
    // @arg rightT le point superieur haut de notre rectangle
    Rectangle(Point<float,3> leftB, Point<float,3> rightT):
      leftBottom(leftB),
      rightTop(rightT)
    {
     
    }

    // @see Vector.IsNull()
    bool IsNull()
    {
      return leftBottom.IsNull() && rightTop.IsNull();
    }

    // @description operateur d'affichage pour le rectangle
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
    {
      os << "Rectangle : " << std::endl;
      os << "  Left bottom : " << rect.leftBottom << std::endl;
      os << "  Right bottom : " << rect.rightTop << std::endl;
      return os;
    }
   
    
  };
}

#endif

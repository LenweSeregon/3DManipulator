#ifndef __OBJECT3D_HPP__
#define __OBJECT3D_HPP__

#include <string>
#include <vector>
#include "Vector.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"

namespace application
{

  class Object3D
  {

  private:

    std::string name;
    geometry::Point<float,3> position;
    std::vector<geometry::Point<float,3>> vertex;
    std::vector<geometry::Triangle<float,3>> faces;
    
  public:

    Object3D(std::string name, geometry::Point<float,3> position, std::vector<geometry::Point<float,3>> vertex);
    geometry::Sphere BSphere() const;
    unsigned int NbFaces() const;
    geometry::Triangle<float,3> Face(unsigned int face) const;
    void AddFace(unsigned int vertice1, unsigned int vertice2, unsigned int vertice3);
    void RemoveFace(unsigned int face);

    void DisplayPoints() const;
    void DisplayFaces() const;
    
  };
}

#endif

#include <cmath>
#include "Object3D.hpp"

namespace application
{

  Object3D::Object3D(std::string name, geometry::Point<float,3> position, std::vector<geometry::Point<float,3>> vertex):
    name(name),
    position(position),
    vertex(vertex)
  {
    
  }

  geometry::Sphere Object3D::BSphere() const
  {
    om::Vector<3,float> vector;
    for(auto point : vertex)
      {
	vector[0] += point.At(0);
	vector[1] += point.At(1);
	vector[2] += point.At(2);
      }
    vector[0] /= (float)vertex.size();
    vector[1] /= (float)vertex.size();
    vector[2] /= (float)vertex.size();

    float maxDistance = -1;
    geometry::Point<float,3> sphereCenter = geometry::Point<float,3>(vector);

    for(unsigned int i = 0; i < vertex.size(); i++)
      {
	float distance = sphereCenter.DistanceBetweenPoints(vertex[i]);
	if(distance > maxDistance)
	  {
	    maxDistance = distance;
	  }
      }

    geometry::Sphere bSphere(sphereCenter.Coords(), sqrt(maxDistance));
    return bSphere;
  }

  unsigned int Object3D::NbFaces() const
  {
    return faces.size();
  }
  
  geometry::Triangle<float,3> Object3D::Face(unsigned int face) const
  {
    return faces[face];
  }
  
  void Object3D::AddFace(unsigned int vertice1, unsigned int vertice2, unsigned int vertice3)
  {
    faces.push_back(geometry::Triangle<float,3>({vertex[vertice1],vertex[vertice2],vertex[vertice3]}));
  }

  void Object3D::RemoveFace(unsigned int face)
  {
    faces.erase(faces.begin() + face);
  }

  void Object3D::DisplayPoints() const
  {
    for(unsigned int i = 0; i < vertex.size(); i++)
      {
	std::cout << vertex[i] << std::endl;
      }
  }

  void Object3D::DisplayFaces() const
  {
    for(unsigned int i = 0; i < faces.size(); i++)
      {
	std::cout << faces[i] << std::endl;
      }
  }
}

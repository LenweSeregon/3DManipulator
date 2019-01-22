#include <iostream>

#include "VectorTest.hpp"
#include "MatrixTest.hpp"
#include "AliasesTest.hpp"
#include "GeometryTest.hpp"

#include "Matrix.hpp"
#include "Vector.hpp"
#include "Aliases.hpp"
#include "Point.hpp"
#include "Triangle.hpp"

#include "Object3D.hpp"
#include "Frustum.hpp"
#include "Scene.hpp"

int main(int argc, const char* argv[])
{
  om::VectorTest::StartTest();
  om::MatrixTest::StartTest();
  om::AliasesTest::StartTest();
  
  om::Mat33f mat = om::identity33r;
  std::cout << mat << std::endl;

  geometry::GeometryTest::StartTest();

  // Test Object3D
  std::string name = "Test1";
  geometry::Point<float,3> position({0.0f,0.0f,0.0f});
  std::vector<geometry::Point<float,3>> points;
  geometry::Point<float,3> point1({0.0f, -4.0f,0.0f});
  geometry::Point<float,3> point2({-2.0f, 0.0f, 0.0f});
  geometry::Point<float,3> point3({0.0f, 0.0f, 2.0f});
  geometry::Point<float,3> point4({2.0f, 0.0f, 0.0f});
  geometry::Point<float,3> point5({0.0f, 1.0f, 0.0f});
  points.push_back(point1);
  points.push_back(point2);
  points.push_back(point3);
  points.push_back(point4);
  points.push_back(point5);

  application::Object3D obj(name,position,points);
  std::cout << obj.BSphere() << std::endl;

  application::Scene scene;
  for(int i = 1; i < argc; i++)
    {
      scene.LoadGeoFile(std::string(argv[i]));
    }
  
  scene.Start();
  return 0;
}

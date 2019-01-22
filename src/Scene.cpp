#include <optional>
#include <fstream>

#include "MathsTools.hpp"
#include "Vector.hpp"
#include "Scene.hpp"

namespace application
{
  Scene::Scene()
  {
    gui = new gui::Gui();
    camera = Camera(170, 1024, 1024, 0.1f, 1000.0f);
  }

  void Scene::Start()
  {
    gui->start();
    gui->main_loop(this);
  }
  
  void Scene::LoadGeoFile(std::string filename)
  {
    std::ifstream file(filename);
    if(file)
      {
	geometry::Point<float,3> position({0.0f, 0.0f, 0.0f});
	std::vector<geometry::Point<float,3>> points;
      
	// Recuperation des points
	int nbPoints = 0;
	file >> nbPoints;
	for(int i = 0; i < nbPoints; i++)
	  {
	    float x, y, z;
	    file >> x >> y >> z;
	    points.push_back(geometry::Point<float,3>({x,y,z}));
	  }

	// Creation de l'objet
	application::Object3D obj(filename,position,points);

	// Recuperation des faces
	int nbFaces;
	file >> nbFaces;
	for(int i = 0; i < nbFaces; i++)
	  {
	    int index1, index2, index3;
	    file >> index1 >> index2 >> index3;
	    obj.AddFace(index1-1, index2-1, index3-1);
	  }

	AddObjs(obj);
      }
    else
      {
	std::cout << "Erreur pour tenter l'ouverture de " << filename << std::endl;
      }
  }

  Scene::~Scene()
  {
    gui->stop();
    delete gui;
  }
  
  void Scene::AddObjs(Object3D obj)
  {
    objs.push_back(obj);
  }

  geometry::Point<float,3> Scene::PerspectiveProjection(const geometry::Point<float,4>& point) const
  {
    geometry::Transform transformCamera = camera.GetTransform();
    geometry::Point<float,4> pointPersp = transformCamera.TransformTo(point);
    
    om::Vector<3,float> normalized;
    for(int i = 0; i < 3; i++)
      {
	if(!MathsTools::AreEquals(pointPersp.At(3), 0.0f))
	  {
	    normalized[i] = pointPersp.At(i) / pointPersp.At(3);
	  }
	else
	  {
	    normalized[i] = pointPersp.At(i);
	  }
      }
    
    return  geometry::Point<float,3>(normalized);
  }

  geometry::Point<float,3> Scene::Perspective(const geometry::Point<float,4>& point) const
  {
    geometry::Transform perspectiveTransform = camera.GetPerspectiveProjection();
    geometry::Point<float,4> pointHomogenous = perspectiveTransform.TransformTo(point);
    om::Vector<3,float> normalized;
    for(int i = 0; i < 3; i++)
      {
	normalized[i] = pointHomogenous.At(i) / pointHomogenous.At(3);
      }

    return geometry::Point<float,3>(normalized);
  }

  void Scene::draw() const
  {
    //std::cout << "Draw : " << objs.size() << std::endl;
    for(auto& obj : objs)
      {
	auto transform = camera.GetViewMatrix();
	auto bsphere = obj.BSphere();
	auto bsphereTransform = transform.TransformTo(bsphere);
	if(!camera.OutsideFrustum(bsphereTransform))
	  {
	    draw_object(obj);
	  }
	else
	  {
	    std::cout << "Outside frustum" << std::endl;
	  }
      }
  }

  void Scene::draw_object(const Object3D& obj) const
  {
    std::cout << "=================================" << std::endl;
    std::cout << "========= DRAWING OBJECT ========" << std::endl;
    std::cout << "=================================" << std::endl;
    for(unsigned int i = 0; i < obj.NbFaces(); i++)
      {
	geometry::Triangle<float,3> face = obj.Face(i);
	geometry::Triangle<float,3> faceTransformed = camera.GetViewMatrix().TransformTo(face);
	//std::cout << face << " " << i << std::endl;
	draw_wire_triangle(faceTransformed);
      }
  }
  
  void Scene::draw_wire_triangle(const geometry::Triangle<float,3>& triangle) const
  {
    geometry::Point<float,4> p0({0.0f, 0.0f, 0.0f, 1.0f});
    geometry::Point<float,4> pRight({0.5f, 0.0f, 0.0f, 1.0f});
    geometry::Point<float,4> pUp({0.0f, 0.5f, 0.0f, 1.0f});
    geometry::Point<float,4> pFront({0.0f, 0.0f, -0.5f, 1.0f});

    /*std::cout << "===================== DESSIN DE L'AXE X =====================" << std::endl;
    draw_edge(p0, pRight, gui::green);
    std::cout << "===================== DESSIN DE L'AXE Y =====================" << std::endl;
    draw_edge(p0, pUp, gui::red);
    std::cout << "===================== DESSIN DE L'AXE Z =====================" << std::endl;
    draw_edge(p0, pFront, gui::blue);*/
   
    

    draw_edge(triangle.GetP0().ExtendedPoint4DAsPoint(), triangle.GetP1().ExtendedPoint4DAsPoint(), gui::white);
    draw_edge(triangle.GetP0().ExtendedPoint4DAsPoint(), triangle.GetP2().ExtendedPoint4DAsPoint(), gui::white);
    draw_edge(triangle.GetP2().ExtendedPoint4DAsPoint(), triangle.GetP1().ExtendedPoint4DAsPoint(), gui::white);
  }
    
  void Scene::draw_edge(const geometry::Point<float,4>& p1, const geometry::Point<float,4>& p2, gui::Color c) const
  {
    /*auto p1Persp = PerspectiveProjection(p1);
    auto p2Persp = PerspectiveProjection(p2);
    
    om::Vector<2,float> p1Projection2D;
    om::Vector<2,float> p2Projection2D;
    for(int i = 0; i < 2; i++)
      {
	p1Projection2D[i] = p1Persp.At(i);
	p2Projection2D[i] = p2Persp.At(i);
      }
    
    gui->render_line(p1Projection2D,p2Projection2D,c);*/
    
    geometry::LineSegment ls(p1.ReduceToPoint3DAsPoint(), p2.ReduceToPoint3DAsPoint());
    std::optional<geometry::LineSegment> cls = camera.VisiblePart(ls);
    
    if(cls != std::nullopt)
      {
	auto p1Persp = Perspective((*cls).GetBegin().ExtendedPoint4DAsPoint());
	auto p2Persp = Perspective((*cls).GetEnd().ExtendedPoint4DAsPoint());

	om::Vector<2,float> p1Projection2D;
	om::Vector<2,float> p2Projection2D;

	p1Projection2D[0] = p1Persp.At(0);
	p1Projection2D[1] = p1Persp.At(1);
	p2Projection2D[0] = p2Persp.At(0);
	p2Projection2D[1] = p2Persp.At(1);
	
	std::cout << "P1 = "<< p1Projection2D << std::endl;
	std::cout << "P2 = " << p2Projection2D << std::endl;

	gui->render_line(p1Projection2D,p2Projection2D,c);
      }
    else
      {
	std::cout << "null" << std::endl;
      }
  }

  void Scene::press_up()
  {
    om::Vector<3,float> axis;
    axis[0] = 1.0f;
    axis[1] = 0.0f;
    axis[2] = 0.0f;
    camera.SetOrientation(camera.GetOrientation() * geometry::Quaternion<float>(1.0f, axis).ToNorm());
  }
  
  void Scene::press_down()
  {
    om::Vector<3,float> axis;
    axis[0] = -1.0f;
    axis[1] = 0.0f;
    axis[2] = 0.0f;
    camera.SetOrientation(camera.GetOrientation() * geometry::Quaternion<float>(1.0f, axis).ToNorm());
  }
  
  void Scene::press_left()
  {
    om::Vector<3,float> axis;
    axis[0] = 0.0f;
    axis[1] = -1.0f;
    axis[2] = 0.0f;
    camera.SetOrientation(camera.GetOrientation() * geometry::Quaternion<float>(1.0f, axis).ToNorm());
  }

  void Scene::press_right()
  {
    om::Vector<3,float> axis;
    axis[0] = 0.0f;
    axis[1] = 1.0f;
    axis[2] = 0.0f;
    camera.SetOrientation(camera.GetOrientation() * geometry::Quaternion<float>(1.0f, axis).ToNorm());
  }
  
  void Scene::press_space()
  {

  }
  
  void Scene::press_w()
  {

  }
  
  void Scene::press_s()
  {
    om::Vector<3,float> newPosition;
    newPosition[0] = camera.GetPosition()[0];
    newPosition[1] = camera.GetPosition()[1] - 0.05f;
    newPosition[2] = camera.GetPosition()[2];
    camera.SetPosition(geometry::Point<float,3>(newPosition));
  }
  
  void Scene::press_a()
  {
    camera.SetFocaleAngle(camera.GetFocaleAngle() - 1.0f);
  }
  
  void Scene::press_d()
  {
    om::Vector<3,float> newPosition;
    newPosition[0] = camera.GetPosition()[0] + 0.05f;
    newPosition[1] = camera.GetPosition()[1];
    newPosition[2] = camera.GetPosition()[2];
    camera.SetPosition(geometry::Point<float,3>(newPosition));
  }
  
  void Scene::press_q()
  {
    om::Vector<3,float> newPosition;
    newPosition[0] = camera.GetPosition()[0] - 0.05f;
    newPosition[1] = camera.GetPosition()[1];
    newPosition[2] = camera.GetPosition()[2];
    camera.SetPosition(geometry::Point<float,3>(newPosition));
  }
  
  void Scene::press_e()
  {
    camera.SetFocaleAngle(camera.GetFocaleAngle() + 1.0f);
  }
  
  void Scene::press_z()
  {
    om::Vector<3,float> newPosition;
    newPosition[0] = camera.GetPosition()[0];
    newPosition[1] = camera.GetPosition()[1] + 0.05f;
    newPosition[2] = camera.GetPosition()[2];
    camera.SetPosition(geometry::Point<float,3>(newPosition));
  }
  
  void Scene::press_x()
  {

  }

  void Scene::release_updown()
  {
    om::Vector<3,float> newCurrentRotation;
    newCurrentRotation[0] = 0.0f;
    newCurrentRotation[1] = 0.0f;
    newCurrentRotation[2] = 0.0f;
    camera.SetCurrentRotation(newCurrentRotation);
    camera.SetRotationSpeed(1.0f);
  }
  
  void Scene::release_leftright()
  {
    om::Vector<3,float> newCurrentRotation;
    newCurrentRotation[0] = camera.GetCurrentRotation()[0];
    newCurrentRotation[1] = 0.0f;
    newCurrentRotation[2] = camera.GetCurrentRotation()[2];
    camera.SetCurrentRotation(newCurrentRotation);
  }
  
  void Scene::release_space()
  {
    om::Vector<3,float> newOrientation;
  }
  
  void Scene::release_ws()
  {

  }
  
  void Scene::release_ad()
  {

  }
  
  void Scene::release_qe()
  {

  }
  
  void Scene::release_zx()
  {

  }

  void Scene::update()
  {

  }
}

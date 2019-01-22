#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <optional>

#include "Sphere.hpp"
#include "Triangle.hpp"
#include "Frustum.hpp"
#include "Vector.hpp"
#include "Transform.hpp"
#include "Quaternion.hpp"
#include "LineSegment.hpp"

namespace application
{
  
  class Camera
  {

  private:

    int widthScreen;
    int heightScreen;

    float movementSpeed;
    float rotationSpeed;
    float zoomSpeed;

    om::Vector<3,float> currentSpeed;
    om::Vector<3,float> currentRotation;
    om::Vector<3,float> currentZoom;

    float near;
    float far;
    float focaleAngle;
    float focaleDistance;
    float aspectRatio;
    Frustum frustum;

    geometry::Point<float,3> position;
    /*om::Vector<3,float> orientation;*/
    geometry::Quaternion<float> orientation;
    
  public:
    

    Camera(){}
    Camera(float focaleAngle, int width, int height, float near, float far);

    float GetFocaleAngle() const;
    void SetFocaleAngle(float angle);
    void Update();
    
    om::Vector<3,float> GetCurrentZoom() const;
    void SetCurrentZoom(om::Vector<3,float> zoom);
    
    geometry::Point<float,3> GetPosition() const;
    void SetPosition(geometry::Point<float,3> pos);

    float GetAspectRatio() const;
    
    float GetRotationSpeed() const;
    void SetRotationSpeed(float speed);
    
    geometry::Quaternion<float> GetOrientation() const;
    void SetOrientation(geometry::Quaternion<float> ori);

    om::Vector<3,float> GetCurrentRotation() const;
    void SetCurrentRotation(om::Vector<3,float> currentRot);


    geometry::Transform GetViewMatrix() const;
    geometry::Transform GetPerspectiveProjection() const;

    geometry::Transform GetTransformTMP() const;
    geometry::Transform GetTransformWithoutPerspective() const;
    geometry::Transform GetTransform() const;
      
    bool OutsideFrustum(const geometry::Sphere& sphere) const;
    bool Sees(const geometry::Triangle<float,3> &triangle) const;
    std::optional<geometry::LineSegment> VisiblePart( const geometry::LineSegment & ls) const;

    
    
  };
}

#endif

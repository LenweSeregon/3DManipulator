#include "Camera.hpp"

namespace application
{
  Camera::Camera(float focaleAngle, int width, int height, float near, float far):
    widthScreen(width),
    heightScreen(height),
    near(near),
    far(far)
  {
    this->focaleAngle = focaleAngle;
    float focaleAngleAsRadian = (focaleAngle * M_PI) / 180.0f;
    this->aspectRatio = (float)height / (float)width; // a
    this->focaleDistance = 1 / tan(focaleAngleAsRadian / 2.0f); // e

    om::Vector<3,float> orientationAxis;
    orientationAxis[0] = 0.0f;
    orientationAxis[1] = 0.0f;
    orientationAxis[2] = 0.0f;
    orientation = geometry::Quaternion<float>(1.0f, orientationAxis);

    currentRotation[0] = 0.0f;
    currentRotation[1] = 0.0f;
    currentRotation[2] = 0.0f;

    currentZoom[0] = 0.05f;
    currentZoom[1] = 0.05f;
    currentZoom[2] = 0.05f;
    
    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = 0.0f;
    rotationSpeed = 1;

    frustum = Frustum(focaleDistance, aspectRatio, near, far);

  }

  float Camera::GetFocaleAngle() const
  {
    return focaleAngle;
  }
  
  void Camera::SetFocaleAngle(float angle)
  {
    focaleAngle = angle;
    Update();
  }

  void Camera::Update()
  {
    float focaleAngleAsRadian = (focaleAngle * M_PI) / 180.0f;
    this->focaleDistance = 1 / tan(focaleAngleAsRadian / 2.0f);

    frustum = Frustum(focaleDistance, aspectRatio, near, far);
  }

  float Camera::GetAspectRatio() const
  {
    return aspectRatio;
  }
  
  om::Vector<3,float> Camera::GetCurrentZoom() const
  {
    return currentZoom;
  }
  
  void Camera::SetCurrentZoom(om::Vector<3,float> zoom)
  {
    currentZoom = zoom;
  }

  geometry::Quaternion<float> Camera::GetOrientation() const
  {
    return orientation;
  }
  
  void Camera::SetOrientation(geometry::Quaternion<float> ori)
  {
    orientation = ori;
  }
  
  geometry::Point<float,3> Camera::GetPosition() const
  {
    return position;
  }

  om::Vector<3,float> Camera::GetCurrentRotation() const
  {
    return currentRotation;
  }
  
  void Camera::SetCurrentRotation(om::Vector<3,float> currentRot)
  {
    currentRotation = currentRot;
  }
  
  void Camera::SetPosition(geometry::Point<float,3> pos)
  {
    position = pos;
  }

  float Camera::GetRotationSpeed() const
  {
    return rotationSpeed;
  }
  
  void Camera::SetRotationSpeed(float speed)
  {
    rotationSpeed = speed;
  }

  geometry::Transform Camera::GetTransformTMP() const
  {
    float nearValue = position.Dist(frustum.nearPlane);
    float farValue = position.Dist(frustum.farPlane);
    float rightValue;
    float leftValue;
    float topValue;
    float bottomValue;
    
    if(aspectRatio >= 1.0f)
      {
        rightValue = ( widthScreen / 2.0f);
        leftValue = -(widthScreen / 2.0f);
        topValue = aspectRatio * ((float)heightScreen / 2.0f);
	bottomValue = -aspectRatio * ((float)heightScreen / 2.0f);
      }
    else
      {
	rightValue = aspectRatio * ( widthScreen / 2.0f);
        leftValue = -aspectRatio * (widthScreen / 2.0f);
        topValue = ((float)heightScreen / 2.0f);
        bottomValue = -((float)heightScreen / 2.0f);
      }

    auto transformPersp = geometry::Transform(nearValue, farValue, rightValue, leftValue, topValue, bottomValue);
    auto transformPerspMatrixReverse = transformPersp.GetMatrix().Reverse();
    transformPersp = geometry::Transform(transformPerspMatrixReverse);
    
    om::Vector<3,float> orientationVector;
    orientationVector[0] = currentRotation.At(0);
    orientationVector[1] = currentRotation.At(1);
    orientationVector[2] = currentRotation.At(2);
    
    auto transformRotation = geometry::Transform(orientationVector, 1.0f * rotationSpeed);
    auto transformOrientation = geometry::Transform(orientation);
    auto transformScale = geometry::Transform(currentZoom,true);

    om::Vector<3,float> translationVector;
    translationVector[0] = position.At(0);
    translationVector[1] = position.At(1);
    translationVector[2] = position.At(2);
    auto transformPosition = geometry::Transform(translationVector);

    auto finalTransform = transformOrientation.Concat(transformRotation).Concat(transformScale).Concat(transformPosition);
    return finalTransform;
  }

  geometry::Transform Camera::GetTransformWithoutPerspective() const
  {
    om::Vector<3,float> orientationVector;
    orientationVector[0] = currentRotation.At(0);
    orientationVector[1] = currentRotation.At(1);
    orientationVector[2] = currentRotation.At(2);
    
    auto transformRotation = geometry::Transform(orientationVector, 1.0f * rotationSpeed);
    auto transformOrientation = geometry::Transform(orientation);
    auto transformScale = geometry::Transform(currentZoom,true);
    auto transformPosition = geometry::Transform(position.Coords());

    auto finalTransform = transformOrientation.Concat(transformRotation).Concat(transformScale).Concat(transformPosition);
    
    return finalTransform;
  }

  geometry::Transform Camera::GetViewMatrix() const
  {
    auto transformRotation = geometry::Transform(orientation);
    auto transformPosition = geometry::Transform(position.Coords());
    return transformRotation.GetInverse().Concat(transformPosition.GetInverse());
  }

  geometry::Transform Camera::GetPerspectiveProjection() const
  {
    float nearValue = position.Dist(frustum.nearPlane);
    float farValue = position.Dist(frustum.farPlane);
    float rightValue = nearValue / focaleDistance;
    float leftValue = -nearValue / focaleDistance;
    float topValue = (aspectRatio * nearValue) / focaleDistance;
    float bottomValue = -(aspectRatio * nearValue) / focaleDistance;

    auto perspective = geometry::Transform(nearValue, farValue, rightValue, leftValue, topValue, bottomValue);
    auto perspectiveInverse = perspective.GetMatrix().Reverse();
    perspective = geometry::Transform(perspectiveInverse);
    
    return perspective;
  }
  
  geometry::Transform Camera::GetTransform() const
  {
    float nearValue = position.Dist(frustum.nearPlane);
    float farValue = position.Dist(frustum.farPlane);
    float rightValue;
    float leftValue;
    float topValue;
    float bottomValue;
    if(aspectRatio >= 1.0f)
      {
        rightValue = ( widthScreen / 2.0f);
        leftValue = -(widthScreen / 2.0f);
        topValue = aspectRatio * ((float)heightScreen / 2.0f);
	bottomValue = -aspectRatio * ((float)heightScreen / 2.0f);
      }
    else
      {
	rightValue = aspectRatio * ( widthScreen / 2.0f);
        leftValue = -aspectRatio * (widthScreen / 2.0f);
        topValue = ((float)heightScreen / 2.0f);
        bottomValue = -((float)heightScreen / 2.0f);
      }

    auto transformPersp = geometry::Transform(nearValue, farValue, rightValue, leftValue, topValue, bottomValue);
    auto transformPerspMatrixReverse = transformPersp.GetMatrix().Reverse();
    transformPersp = geometry::Transform(transformPerspMatrixReverse);

    auto transformScale = geometry::Transform(currentZoom,true);
    auto finalTransform = transformScale.Concat(transformPersp);
    
    return finalTransform;
  }

  bool Camera::OutsideFrustum(const geometry::Sphere& sphere) const
  {
    return frustum.Outside(sphere);

    /*auto point = sphere.GetPoint();
    auto radius = sphere.GetRadius();
    return
      (point.At(0) + (radius+radius*currentZoom.At(0)) < -1.0f) ||
      (point.At(0) - (radius+radius*currentZoom.At(0)) > 1.0f) ||
      (point.At(1) + (radius+radius*currentZoom.At(0)) < -1.0f) ||
      (point.At(1) - (radius+radius*currentZoom.At(0)) > 1.0f);*/
			     
  }
  
  bool Camera::Sees(const geometry::Triangle<float,3> &triangle) const
  {
    auto p1 = triangle.GetP0();
    auto p2 = triangle.GetP1();
    auto p3 = triangle.GetP2();

    auto u = p1.LengthTo(p2);
    auto v = p1.LengthTo(p3);
    auto normal = u.GetVectorDirection().CrossProduct(v.GetVectorDirection()).ToUnit();
    return (p1.Coords() - orientation.GetAxis()).DotProduct(normal) < 0;
  }

  std::optional<geometry::LineSegment> Camera::VisiblePart( const geometry::LineSegment & ls) const
  {
    return frustum.Inter(ls);
  }
}

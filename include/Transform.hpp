#ifndef __TRANSFORM_HPP__
#define __TRANSFORM_HPP__

#include <cmath>
#include "Aliases.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Vector.hpp"
#include "Point.hpp"
#include "Sphere.hpp"

#define UNUSED(x) (void)(x)

namespace geometry
{
  class Transform
  {

  private:

    om::Matrix<float,4,4> transform;

  public:

    Transform()
    {
    }

    Transform(float near, float far, float right, float left, float top, float bottom)
    {
      transform[0][0] = (2*near)/(right - left);
      transform[0][1] = 0.0f;
      transform[0][2] = (right + left)/(right - left);
      transform[0][3] = 0.0f;

      transform[1][0] = 0.0f;
      transform[1][1] = (2*near)/(top - bottom);
      transform[1][2] = (top + bottom)/(top - bottom);
      transform[1][3] = 0.0f;

      transform[2][0] = 0.0f;
      transform[2][1] = 0.0f;
      transform[2][2] = -((far + near)/(far - near));
      transform[2][3] = -((2*near*far)/(far - near));

      transform[3][0] = 0.0f;
      transform[3][1] = 0.0f;
      transform[3][2] = -1.0f;
      transform[3][3] = 0.0f;
    }

    Transform(const Quaternion<float>& quat)
    {
      float t = sin((quat.GetAngle() * (M_PI / 180.0f)) / 2.0f);
      float w = quat.Re();
      float x = t * quat.GetAxis()[0];
      float y = t * quat.GetAxis()[1];
      float z = t * quat.GetAxis()[2];
      
      transform[0][0] = 1-(2*(y*y))-(2*(z*z));
      transform[0][1] = (2*x*y)-(2*w*z);
      transform[0][2] = (2*x*z)+(2*w*y);
      transform[1][0] = (2*x*y)+(2*w*z);
      transform[1][1] = 1-(2*(x*x))-(2*(z*z));
      transform[1][2] = (2*y*z)-(2*w*x);
      transform[2][0] = (2*x*z)-(2*w*y);
      transform[2][1] = (2*y*z)+(2*w*x);
      transform[2][2] = 1-(2*(x*x))-(2*(y*y));
      
      // TRANSLATION PART
      transform[0][3] = 0.0f;
      transform[1][3] = 0.0f;
      transform[2][3] = 0.0f;

      // LAST LINE PART
      transform[3][0] = 0.0f;
      transform[3][1] = 0.0f;
      transform[3][2] = 0.0f;
      transform[3][3] = 1.0f;
    }
    
    Transform(const om::Vector<3,float> axisRotation, float angle)
    {
      (*this) = Transform(Quaternion<float>(angle,axisRotation));
    }
    
    Transform(const om::Vector<3,float> axisTranslation)
    {
      // MATRIX PART
      for(unsigned int i = 0; i < 3; i++)
	{
	  for(unsigned int j = 0; j < 3; j++)
	    {
	      if(i == j)
		{
		  transform[i][j] = 1.0f;
		}
	      else
		{
		  transform[i][j] = 0.0f;
		}
	    }
	}

      // TRANSLATION PART
      transform[0][3] = axisTranslation.At(0);
      transform[1][3] = axisTranslation.At(1);
      transform[2][3] = axisTranslation.At(2);

      // LAST LINE PART
      transform[3][0] = 0.0f;
      transform[3][1] = 0.0f;
      transform[3][2] = 0.0f;
      transform[3][3] = 1.0f;
    }
    
    Transform(const om::Vector<3,float> axisScale, bool scale)
    {
      UNUSED(scale);
      // MATRIX PART
      int k = 0;
      for(unsigned int i = 0; i < 3; i++)
	{
	  for(unsigned int j = 0; j < 3; j++)
	    {
	      if(i == j)
		{
		  transform[i][j] = axisScale.At(k++);
		}
	      else
		{
		  transform[i][j] = 0.0f;
		}
	    }
	}

      // TRANSLATION PART
      transform[0][3] = 0.0f;
      transform[1][3] = 0.0f;
      transform[2][3] = 0.0f;

      // LAST LINE PART
      transform[3][0] = 0.0f;
      transform[3][1] = 0.0f;
      transform[3][2] = 0.0f;
      transform[3][3] = 1.0f;
    }

    Transform(om::Matrix<float,4,4> matrix)
    {
      this->transform = matrix;
    }

    om::Matrix<float,4,4> GetMatrix() const
    {
      return transform;
    }
    
    Transform Concat(const Transform& trans)
    {
      return Transform(trans.transform * transform);
    }

    Transform GetInverse()
    {
      auto inverse = transform.Reverse();
      return Transform(inverse);
    }

    Quaternion<float> ToQuat()
    {
      float w,x,y,z;

      float trace = transform[0][0] + transform[1][1] + transform[2][2]; 
      if( trace > 0 ) {
	float s = 0.5f / sqrtf(trace + 1.0f);
	w = 0.25f / s;
	x = ( transform[2][1] - transform[1][2] ) * s;
	y = ( transform[0][2] - transform[2][0] ) * s;
	z = ( transform[1][0] - transform[0][1] ) * s;
      } else {
	if ( transform[0][0] > transform[1][1] && transform[0][0] > transform[2][2] ) {
	  float s = 2.0f * sqrtf( 1.0f + transform[0][0] - transform[1][1] - transform[2][2]);
	  w = (transform[2][1] - transform[1][2] ) / s;
	  x = 0.25f * s;
	  y = (transform[0][1] + transform[1][0] ) / s;
	  z = (transform[0][2] + transform[2][0] ) / s;
	} else if (transform[1][1] > transform[2][2]) {
	  float s = 2.0f * sqrtf( 1.0f + transform[1][1] - transform[0][0] - transform[2][2]);
	  w = (transform[0][2] - transform[2][0] ) / s;
	  x = (transform[0][1] + transform[1][0] ) / s;
	  y = 0.25f * s;
	  z = (transform[1][2] + transform[2][1] ) / s;
	} else {
	  float s = 2.0f * sqrtf( 1.0f + transform[2][2] - transform[0][0] - transform[1][1] );
	  w = (transform[1][0] - transform[0][1] ) / s;
	  x = (transform[0][2] + transform[2][0] ) / s;
	  y = (transform[1][2] + transform[2][1] ) / s;
	  z = 0.25f * s;
	}
      }
      
      om::Vector<4,float> vec;
      vec[0] = w;
      vec[1] = x;
      vec[2] = y;
      vec[3] = z;
      Quaternion<float> quaternion(vec);
      return quaternion;
    }

    om::Vector<4,float> operator[](int i)
    {
      return transform[i];
    }

    friend std::ostream& operator<<(std::ostream& os, const Transform& trans)
    {
      std::cout << trans.transform << std::endl;
      return os;
    }

    template <typename T, size_t N>
    Point<float,4> TransformTo(const Point<T,N>& point) const
    {
      om::Vector<4,float> extended;
      if(N == 3)
	{
	  auto extendedPoint4D = point.ExtendedPoint4D();
	  for(int i = 0; i < 4; i++)
	    {
	      extended[i] = extendedPoint4D.At(i);
	    }
	}
      else
	{
	  for(int i = 0; i < 4; i++)
	    {
	      extended[i] = point.Coords().At(i);
	    }
	}
      
      om::Vector<4,float> result = transform * extended;
      return Point<float,4>(result);
    }

    template <typename T, size_t N>
    Direction<T,N> TransformTo(const Direction<T,N>& direction)
    {
      om::Vector<4,float> extendedDirectionVec = direction.ExtendedDirection4D().GetVectorDirection();
      om::Vector<4,float> result = transform * extendedDirectionVec;
      Direction<T,N> dirAs3D;
      dirAs3D[0] = result[0];
      dirAs3D[1] = result[1];
      dirAs3D[2] = result[2];

      return dirAs3D;
    }

    Sphere TransformTo(const Sphere& sphere)
    {
      float radius = sphere.GetRadius();
      om::Vector<3,float> center = sphere.GetPoint() * 2;
      Point<float,3> asPoint = Point<float,3>(center);
      Point<float,4> centerTransformed = TransformTo(asPoint);
      Sphere newSphere = Sphere(centerTransformed.ReduceToPoint3D(), radius);
      return newSphere;
    }

    Triangle<float,3> TransformTo(const Triangle<float,3>& triangle)
    {
      auto p1 = triangle.GetP0();
      auto p2 = triangle.GetP1();
      auto p3 = triangle.GetP2();

      auto p1Transform = TransformTo(p1);
      auto p2Transform = TransformTo(p2);
      auto p3Transform = TransformTo(p3);

      return Triangle<float,3>({p1Transform.ReduceToPoint3DAsPoint(),p2Transform.ReduceToPoint3DAsPoint(),p3Transform.ReduceToPoint3DAsPoint()});
    }
    
  };
}

#endif

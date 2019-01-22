#ifndef __ALIASES_HPP__
#define __ALIASES_HPP__

#include "Vector.hpp"
#include "Matrix.hpp"

namespace om
{
  using Vec2i = Vector<2,int>;
  using Vec3i = Vector<3,int>;
  using Vec4i = Vector<4,int>;
  using Vec2f = Vector<2,float>;
  using Vec3f = Vector<3,float>;
  using Vec4f = Vector<4,float>;
  using Vec2r = Vector<2,float>;
  using Vec3r = Vector<3,float>;
  using Vec4r = Vector<3,float>;
  using Mat33f = Matrix<float,3,3>;
  using Mat44f = Matrix<float,4,4>;

  const Vec2i zerovec2i;
  const Vec3i zerovec3i;
  const Vec4i zerovec4i;
  const Vec2f zerovec2f;
  const Vec3f zerovec3f;
  const Vec4f zerovec4f;
  const Mat33f identity33r;
  const Mat44f identity44r;

  //////////////////////////
  /// ALIAS CROSS
  //////////////////////////
  template <typename T, size_t A, size_t B>
  Vector<A,T> Cross(Vector<A,T> vector1, Vector<B,T> vector2)
  {
    return vector1.CrossProduct(vector2);
  }

  //////////////////////////
  /// ALIAS DOT VECTOR
  //////////////////////////
  template <typename T, size_t N>
  Vector<N,T> Dot(float scalaire, const Vector<N,T>& vector)
  {
    return scalaire * vector;
  }

  template <typename T, size_t N>
  Vector<N,T> Dot(const Vector<N,T>& vector, float scalaire)
  {
    return vector * scalaire;
  }

  template <typename T, size_t N>
  Vector<N,T> Dot(int scalaire, const Vector<N,T>& vector)
  {
    return scalaire * vector;
  }

  template <typename T, size_t N>
  Vector<N,T> Dot(const Vector<N,T>& vector, int scalaire)
  {
    return vector * scalaire;
  }

  template <typename T, typename B, size_t N, size_t A>
  T Dot(const Vector<N,T>& vector1, const Vector<A,B>& vector2)
  {
    return vector1.DotProduct(vector2);
  }

  template <typename T, typename A, size_t N, size_t B, size_t C>
  Matrix<T,1,C> Dot(const Vector<N,T>& vector, const Matrix<A,B,C>& matrix)
  {
    return vector * matrix;
  }

  //////////////////////////
  /// ALIAS DOT MATRIX
  //////////////////////////
  
  template <typename T, size_t N, size_t M>
  Matrix<T,N,M> Dot(float scalaire, const Matrix<T,N,M>& matrix)
  {
    return  matrix * scalaire;
  }

  template <typename T, size_t N, size_t M>
  Matrix<T,N,M> Dot(const Matrix<T,N,M>& matrix, float scalaire)
  {
    return matrix * scalaire;
  }

  template <typename T, size_t N, size_t M>
  Matrix<T,N,M> Dot(int scalaire, const Matrix<T,N,M>& matrix)
  {
    return matrix * scalaire;
  }

  template <typename T, size_t N, size_t M>
  Matrix<T,N,M> Dot(const Matrix<T,N,M>& matrix, int scalaire)
  {
    return matrix * scalaire;
  }

  template <typename T, typename A, size_t N, size_t M, size_t B, size_t C>
  Matrix<T,N,C> Dot(const Matrix<T,N,M>& matrix1, const Matrix<A,B,C>& matrix2)
  {
    return matrix1 * matrix2;
  }
  
  
  template <typename T, typename A, size_t N, size_t B, size_t C>
  Matrix<T,N,1> Dot(const Matrix<A,B,C>& matrix, const Vector<N,T>& vector)
  {
    return matrix * vector;
  }
  
}

#endif

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include <cmath>

#include "MathsTools.hpp"

class Matrix;

namespace om
{
  // @description Cette classe permet de representer des
  // vecteurs de n'importe quel type et taille.
  // @WARNING attention, aucune verification n'est faite sur le
  // type des vecteurs (nullite) durant les opérations pour une
  // questions d'efficacité, si il est necessaire de realiser ces tests
  // il faut donc le faire avant d'appeler la methode
  template<size_t N, typename T>
  class Vector
  {
    
  private:

    T vector[N];
    
  public:

    // @description constructeur de vecteur permettant d'initialiser
    // tous les elements à 0
    Vector()
    {
      if(!IsNull())
	{
	  for(unsigned int i = 0; i < N; i++)
	    {
	      vector[i] = 0.0f;
	    }
	}
    }

    Vector(std::initializer_list<T> list)
    {
      if(list.size() != N)
	{
	  throw std::invalid_argument("List size should be " + std::to_string(N) +".");
	}

      for(size_t i = 0; i < list.size(); i++)
	{
	  vector[i] = *(list.begin() + i);
	}
    }

    // @description methode permettant de connaitre la taille du vecteur
    // @return le nombre d'element que contient le vecteur
    unsigned int Length() const
    {
      return N;
    }

    // @description methode permettant de recuperer une copie de l'element
    // à l'indice index si cette indice est valide
    // @arg index l'indice dans le vecteur que l'on souhaite récupérer
    // @return une copie de l'element à l'indice index
    // @throw invalid_argument si l'indice est invalide.
    T At(unsigned int index) const
    {
      if(index < 0 || index >= N)
	{
	  throw std::invalid_argument("Wrong index");
	}

      return vector[index];
    }

    // @description methode permettant de recuperer une reference d'un element
    // @arg index l'indice dans le vecteur que l'on souhaite récupérer
    // @return une reference sur l'objet contenu à l'indice index, permettant
    // de le modifier
    T& operator[](int index)
    {
      return vector[index];
    }

    // @description methode permettant de connaitre le produit scalaire de 2 vecteurs
    // @arg element le deuxieme vecteur pour réaliser le produit scalaire
    // @return un scalaire de type T (parametre de la classe) representant le resultat
    // @throw invalid_argument si le vecteur n'est pas de la bonne taille ou null.
    template <typename A, size_t B>
    T DotProduct(const Vector<B,A>& element) const
    {
      if(B != N)
	{
	  throw std::invalid_argument("This vector is not valid for dot product");
	}
      
      T scalar = 0;
      for(unsigned int i = 0; i < N; i++)
	{
	  scalar += vector[i] * element.At(i);
	}

      return scalar;
    }

    // @description methode permettant de realiser le produit croise
    // @arg element le deuxieme vecteur pour le produit croise
    // @return un nouveau vecteur de meme type que l'objet representant le produit croise
    // @throw invalid_argument si l'un des 2 vecteurs n'est pas de taille 3
    template <typename A, size_t B>
    Vector<N,T> CrossProduct(const Vector<B,A>& element) const
    {
      if(N != 3 || B != 3)
	{
	  throw std::invalid_argument("Cross product available only for Vector<3,X>");
	}

      Vector<N,T> cross;
      cross.vector[0] = (vector[1] * element.At(2)) - (vector[2] * element.At(1));
      cross.vector[1] = (vector[2] * element.At(0)) - (vector[0] * element.At(2));
      cross.vector[2] = (vector[0] * element.At(1)) - (vector[1] * element.At(0));
      
      return cross;
    }

    // @description methode permettant de connaitre la norme du vecteur (taille)
    // @return un scalaire du meme type que le vecteur representant sa norme
    T Norm() const
    {
      T sum = 0.0f;
      for(unsigned int i = 0; i < N; i++)
	{
	  sum += vector[i] * vector[i];
	}

      return sqrt(sum);
    }

    // @description methode permettant d'obtenir un nouveau vecteur unitaire
    // @return un nouveau vecteur mais unitaire cette fois ci.
    Vector<N,T> ToUnit() const
    {
      Vector<N,T> unitVector;
      float norm = Norm();
      for(unsigned int i = 0; i < N; i++)
	{
	  unitVector[i] = vector[i] / norm;
	}

      return unitVector;
    }

    // @description methode permettant de savoir si 2 vecteurs sont orthogonaux
    // @arg element le deuxieme vecteur pour le test d'orthogonalite
    // @return vrai si les 2 vecteurs sont orthonomaux, faux sinon
    bool IsOrtho(const Vector& element) const
    {
      return DotProduct(element) == 0;
    }

    // @description methode permettant de savoir si le vecteur est valide ou non
    // @return vrai si le vecteur est null (non valide) faux sinon
    bool IsNull() const
    {
      if(std::is_same<T,int>::value) {
	return false;
      } else if(std::is_same<T,float>::value || std::is_same<T,double>::value) {
	return false;
      } else {
	return true;
      }
    }

    // @description methoder permettant de savoir si notre vecteur est unitaire
    // @return vrai si notre vecteur est un vecteur unitaire, faux sinon
    bool IsUnit() const
    {
      return MathsTools::AreEquals(Norm(),1.0f);
    }

    // @description method permettant d'addition 2 vecteurs
    // @arg element un deuxieme vecteur pour realiser l'addition
    // @return un nouveau vecteur etant le resultat de l'addition des 2 vecteurs
    // @throw invalid_argument si les vecteurs ne sont pas de meme taille
    template <typename A, size_t B>
    Vector<N,T> operator+(const Vector<B,A>& element) const
    {
      if(B != N)
	{
	  throw std::invalid_argument("Vector should have the same number of component");
	}
      
      Vector<N,T> addition;
      for(unsigned int i = 0; i < N; i++)
	{
	  addition[i] = vector[i] + element.At(i);
	}

      return addition;
    }

    // @description method permettant d'addition 2 vecteurs et de mettre le resultat dans le premier
    // @arg element un deuxieme vecteur pour realiser l'addition
    // @return une reference sur le vecteur courant qui vient d'obtenir le resultat de l'addition
    // @throw invalid_argument si les vecteurs ne sont pas de meme taille
    template <typename A, size_t B>
    Vector<N,T>& operator+=(const Vector<B,A>& element)
    {
      if(B != N)
	{
	  throw std::invalid_argument("Vector should have the same number of component");
	}
      
      for(unsigned int i = 0; i < N; i++)
	{
	  vector[i] = vector[i] + element.At(i);
	}
      
      return *this;
    }

    // @description method permettant d'obtenir le vecteur negatif du vecteur courant
    // @return un nouveau vecteur etant le resultat de la negativite du vecteur cible
    Vector<N,T> operator-() const
    {
      Vector<N,T> reverse;
      for(unsigned int i = 0; i < N; i++)
	{
	  reverse[i] = -vector[i];
	}

      return reverse;
    }

    // @description method permettant la soustraction 2 vecteurs
    // @arg element un deuxieme vecteur pour realiser la soustraction
    // @return un nouveau vecteur etant le resultat de la soustraciton des 2 vecteurs
    // @throw invalid_argument si les vecteurs ne sont pas de meme taille
    template <typename A, size_t B>
    Vector<N,T> operator-(const Vector<B,A>& element) const
    {
      if(B != N)
	{
	  throw std::invalid_argument("Vector should have the same number of component");
	}
	    
      Vector<N,T> minus;
      for(unsigned int i = 0; i < N; i++)
	{
	  minus[i] = vector[i] - element.At(i);
	}

      return minus;
    }

    // @description method permettant de soustraire 2 vecteurs et de mettre le resultat dans le premier
    // @arg element un deuxieme vecteur pour realiser la soustraction
    // @return un reference sur le vecteur courant qui vient d'obtenir le resultat de la soustraction
    // @throw invalid_argument si les vecteurs ne sont pas de meme taille
    template <typename A, size_t B>
    Vector<N,T>& operator-=(const Vector<B,A>& element)
    {
      if(B != N)
	{
	  throw std::invalid_argument("Vector should have the same number of component");
	}
	    
      for(unsigned int i = 0; i < N; i++)
	{
	  vector[i] = vector[i] - element.At(i);
	}

      return *this;
    }

    // @description methode permettant d'obtenir un nouveau vecteur multiplie par un scalaire entier
    // @arg scalaire le scalaire par lequel on souhaite multiplier notre vecteur
    // @return un nouveau vecteur étant le resultat de la multiplication
    Vector<N,T> operator*(int scalaire) const
    {
      Vector<N,T> mult;
      for(unsigned int i = 0; i < N; i++)
	{
	  mult[i] = vector[i] * scalaire;
	}

      return mult;
    }

    // @description methode permettant d'obtenir un nouveau vecteur multiplie par un scalaire flottant
    // @arg scalaire le scalaire par lequel on souhaite multiplier notre vecteur
    // @return un nouveau vecteur étant le resultat de la multiplication
    Vector<N,T> operator*(float scalaire) const
    {
      Vector<N,T> mult;
      for(unsigned int i = 0; i < N; i++)
	{
	  mult[i] = vector[i] * scalaire;
	}

      return mult;
    }

    // @description methode permettant d'obtenir un nouveau vecteur pour multiplication par un autre vecteur
    // @arg element le vecteur par lequel on souhaite multiplier notre vecteur courant
    // @return un nouveau vecteur étant le resultat de la multiplication
    // @throw invalid_argument si les vecteurs ne sont pas de taille 3
    template <typename A, size_t B>
    Vector<N,T> operator*(const Vector<B,A>& element) const
    {
      if(N != 3 || B != 3)
	{
	  throw std::invalid_argument("Vectorial Product only able for 3 dimension vector");
	}

      Vector<N,T> mult;
      mult[0] = (vector[1] * element.At(2)) - (vector[2] * element.At(1));
      mult[1] = (vector[2] * element.At(0)) - (vector[0] * element.At(2));
      mult[2] = (vector[0] * element.At(1)) - (vector[1] * element.At(0));

      return mult;
    }

    // @description methode permettant d'obtenir le resultat de notre vecteur multiplie par un scalaire entier
    // @arg scalaire le scalaire par lequel on souhaite multiplier notre vecteur
    // @return une reference sur notre vecteur etant le resultat de la multiplication
    Vector<N,T>& operator*=(int scalaire)
    {
      for(unsigned int i = 0; i < N; i++)
	{
	  vector[i] = vector[i] * scalaire;
	}

      return *this;
    }

    // @description methode permettant d'obtenir le resultat de notre vecteur multiplie par un scalaire flottant
    // @arg scalaire le scalaire par lequel on souhaite multiplier notre vecteur
    // @return une reference sur notre vecteur etant le resultat de la multiplication
    Vector<N,T>& operator*=(float scalaire)
    {
      for(unsigned int i = 0; i < N; i++)
	{
	  vector[i] = vector[i] * scalaire;
	}

      return *this;
    }

    // @description methode permettant d'obtenir le resultat de notre vecteur multiplie par un autre
    // @arg element le vecteur par lequel on souhaite multiplier notre vecteur courant
    // @return une reference sur le vecteur courant étant le resultat de la multiplication
    // @throw invalid_argument si les vecteurs ne sont pas de taille 3
    template <typename A, size_t B>
    Vector<N,T>& operator*=(const Vector<B,A>& element)
    {
      if(N != 3 || B != 3)
	{
	  throw std::invalid_argument("Vector Product only able for 3 dimension vector");
	}

      T x = (vector[1] * element.At(2)) - (vector[2] * element.At(1));
      T y = (vector[2] * element.At(0)) - (vector[0] * element.At(2));
      T z = (vector[0] * element.At(1)) - (vector[1] * element.At(0));

      vector[0] = x;
      vector[1] = y;
      vector[2] = z;
      
      return *this;
    }

    // @description operateur d'affichage classique
    friend std::ostream& operator<<(std::ostream& os, const Vector<N,T>& vector)
    {
      os << "(";
      for(unsigned int i = 0; i < N; i++)
	{
	  os << vector.vector[i];
	  if(i < N - 1) {
	    os << ",";
	  }
	}
      os << ")";
      return os;
    }
    
  };

  // @description methode permettant de realiser la multiplication par scalaire reel prefixe sur le vecteur
  // @arg scalaire un scalaire reel pour la multiplication
  // @arg vec le vecteur que l'on souhaite multiplier
  // @return un nouveau vecteur etant le resultat de la multiplication
  template <typename T, size_t N>
  Vector<N,T> operator*(int scalaire, const Vector<N,T>& vec)
  {
    Vector<N,T> mult;
    for(unsigned int i = 0; i < N; i++)
      {
	mult[i] = vec.At(i) * scalaire;
      }

    return mult;
  }

  // @description methode permettant de realiser la multiplication par scalaire flottant prefixe sur le vecteur
  // @arg scalaire un scalaire flottant pour la multiplication
  // @arg vec le vecteur que l'on souhaite multiplier
  // @return un nouveau vecteur etant le resultat de la multiplication
  template <typename T, size_t N>
  Vector<N,T> operator*(float scalaire, const Vector<N,T>& vec)
  {
    Vector<N,T> mult;
    for(unsigned int i = 0; i < N; i++)
      {
	mult[i] = vec.At(i) * scalaire;
      }

    return mult;
  }
  
}

#endif

#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__

#include <cmath>
#include "Aliases.hpp"
#include "Vector.hpp"

namespace geometry
{
  // @description Classe representant les quaternions qui vont etre utiliser pour la rotation
  template<typename T>
  class Quaternion
  {

  private:
    T real;
    om::Vector<3,T> vectorIm;

    om::Vector<4,T> GetVector4Form() const
    {
      om::Vector<4,T> regroup;
      regroup[0] = real;
      for(unsigned int i = 1; i < 4; i++)
	{
	  regroup[i] = vectorIm.At(i-1);
	}
      
      return regroup;
    }
    
  public:

    float angle;
    om::Vector<3,float> axis;
    
    // @description constructeur par défaut
    Quaternion()
    {
    }  

    // @description constructeur prenant les 4 composants (1 reel, 3 imaginaires) pour notre quaternion
    // @arg vector un vecteur 4D avec les 4 composantes composant un quaternion
    Quaternion(om::Vector<4,T> vector)
    {
      real = vector[0];
      for(unsigned int i = 1; i < 4; i++)
	{
	  vectorIm[i-1] = vector[i];
	}
    }

    // @description constructeur permettant d'initialiser les composants de notre quaternion avec
    // comme parametre l'angle de notre rotation et l'axe sur lequel on souhaite faire notre rotation.
    // @arg angle l'angle de notre rotation
    // @arg direction la direction pour notre rotation
    Quaternion(float angle, Direction<T,3> direction)
    {
      this->angle = angle;
      this->axis = direction.GetVectorDirection();
      
      float angleAsRadian = (angle * M_PI) / 180.0f;
      if(!direction.IsUnit() && direction.Norm() > 0)
	{
	  direction = direction.ToUnit();
	}

      real = cos(angleAsRadian/2.0f);
      Direction<T,3> dirMult = direction * sin(angleAsRadian/2.0f);
      for(unsigned int i = 0; i < 3; i++)
	{
	  vectorIm[i] = dirMult[i];
	}
    }

    // @description methode permettant de connaitre le conjugue de notre quaternion
    // @return un nouveau quaternion etant le conjugue de l'actuel
    Quaternion Conjugate() const
    {
      Quaternion<T> conjugate;
      conjugate.real = real;
      conjugate.vectorIm = -vectorIm;
      return conjugate;
    }

    // @description methode permettant de connaitre la norme de notre quaternion
    // @retrun la valeur representant la norme
    T Norm() const
    {
      om::Vector<4,T> vec4form = GetVector4Form();
      return vec4form.Norm();
    }

    // @description methode permettant de connaitre la partie reelle de notre quaternion
    // @return la valeur representant la partie reelle
    T Re() const
    {
      return real;
    }

    // @description methode permettant de connaitre la partie imaginaire (3 composants) du quaternion
    // @return vecteur 3D representant les valeurs imaginaires du quaternion
    om::Vector<3,T> Im() const
    {
      return vectorIm;
    }

    T GetAngle() const
    {
      return (acos(real)*180*2.0f)/M_PI;
    }

    om::Vector<3,T> GetAxis() const
    {
      float coef = sin((GetAngle()*(M_PI / 180.f))/2.f);
      om::Vector<3,T> values;
      values[0] = vectorIm.At(0) / coef;
      values[1] = vectorIm.At(1) / coef;
      values[2] = vectorIm.At(2) / coef;
      return values;
    }

    // @description methode permettant de retourner un quaternion unitaire
    // @return un nouveau quaternion unitaire.
    Quaternion ToNorm() const
    {
      om::Vector<4,T> vec4form = GetVector4Form();
      return vec4form.ToUnit();
    }

    // @description methode permettant de retourner l'inverse de notre quaternion
    // @return un nouveau quaternion etant l'inverse de l'actuel
    Quaternion Reverse() const
    {
      return Conjugate() * (1.0f / (Norm() * Norm()));
    }
    
    // @description operateur d'affichage pour le quaternion
    friend std::ostream& operator<<(std::ostream& os, const Quaternion<T>& quat)
    {
      os << quat.real << " + ";
      os << quat.vectorIm.At(0) << "i" << " + ";
      os << quat.vectorIm.At(1) << "j" << " + ";;
      os << quat.vectorIm.At(2) << "k";
      return os;
    }

    // @description methode permettant d'addition 1 quaternion et un flottant
    // @arg scalar le flottant à ajouter
    // @return un nouveau quaternion etant la somme
    Quaternion operator+(float scalar) const
    {
      Quaternion plus;
      plus.real = real + scalar;
      plus.vectorIm = vectorIm;
      return plus;
    }

    // @description methode permettant d'addition 1 quaternion et un flottant en prefix
    // @arg scalar le flottant à ajouter
    // @return un nouveau quaternion etant la somme
    friend Quaternion operator+(float scalar, const Quaternion& quat)
    {
      return quat + scalar;
    }

    // @description methode permettant d'addition 1 quaternion et un entier
    // @arg scalar l'entier à ajouter
    // @return un nouveau quaternion etant la somme
    Quaternion operator+(int scalar) const
    {
      Quaternion plus;
      plus.real = real + scalar;
      plus.vectorIm = vectorIm;
      return plus;
    }

    // @description methode permettant d'addition 1 quaternion et un entier en prefix
    // @arg scalar l'entier à ajouter
    // @return un nouveau quaternion etant la somme
    friend Quaternion operator+(int scalar, const Quaternion& quat)
    {
      return quat + scalar;
    }
    
    // @description methode permettant d'addition 1 quaternion et un autre quaternion
    // @arg quat le quaternion à ajouter
    // @return un nouveau quaternion etant la somme
    Quaternion operator+(const Quaternion& quat) const
    {
      Quaternion plus;
      plus.real = real + quat.real;
      plus.vectorIm = vectorIm + quat.vectorIm;
      return plus;
    }

    // @description methode permettant d'addition 1 quaternion et un flottant et d'affecter la valeur
    // @arg scalar le flottant à ajouter
    // @return l'objet actuel ayant été la cible de la somme
    Quaternion& operator+=(float scalar)
    {
      real += scalar;
      return *this;
    }
    
    // @description methode permettant d'addition 1 quaternion et un entier et d'affecter la valeur
    // @arg scalar l'entier à ajouter
    // @return l'objet actuel ayant été la cible de la somme
    Quaternion& operator+=(int scalar)
    {
      real += scalar;
      return *this;
    }

    // @description methode permettant d'addition 1 quaternion et un autre quaternion
    // @arg scalar le quaternion à ajouter
    // @return l'objet actuel ayant été la cible de la somme
    Quaternion& operator+=(const Quaternion& quat)
    {
      real += quat.real;
      vectorIm += quat.vectorIm;
      return *this;
    }

    // @description methode permettant de retourner la negation
    // @return un nouveau quaternion etant la negation de l'actuel
    Quaternion operator-() const
    {
      Quaternion negation;
      negation.real = -real;
      negation.vectorIm = -vectorIm; 
      return negation;
    }

    // @description methode permettant de soustraire 1 quaternion et un flottant
    // @arg scalar le flottant à soustraire
    // @return le nouveau quaternion ayant le resultat de la soustraction
    Quaternion operator-(float scalar) const
    {
      return *this + (-scalar);
    }
    
    // @description methode permettant de soustraire 1 quaternion et un flottant prefix
    // @arg scalar le flottant à soustraire
    // @return le nouveau quaternion ayant le resultat de la soustraction
    friend Quaternion operator-(float scalar, const Quaternion& quat)
    {
      return quat - scalar;
    }

    // @description methode permettant de soustraire 1 quaternion et un entier
    // @arg scalar l'entier à soustraire
    // @return le nouveau quaternion ayant le resultat de la soustraction
    Quaternion operator-(int scalar) const
    {
      return *this + (-scalar);
    }

    // @description methode permettant de soustraire 1 quaternion et un entier prefix
    // @arg scalar l'entier à soustraire
    // @return le nouveau quaternion ayant le resultat de la soustraction
    friend Quaternion operator-(int scalar, const Quaternion& quat)
    {
      return quat - scalar;
    }

    // @description methode permettant de soustraire 1 quaternion et un quaternion
    // @arg scalar le quaternion à soustraire
    // @return le nouveau quaternion ayant le resultat de la soustraction
    Quaternion operator-(const Quaternion& quat) const
    {
      return *this + (-quat);
    }

    // @description methode permettant de soustraire 1 quaternion et un flottant et d'affecter le resultat à l'objet courant
    // @arg scalar le flottant à soustraire
    // @return l'objet courant ayant été cible de la soustraction
    Quaternion& operator-=(float scalar)
    {
      *this = *this + (-scalar);
      return *this;
    }

    // @description methode permettant de soustraire 1 quaternion et un entier et d'affecter le resultat à l'objet courant
    // @arg scalar l'entier à soustraire
    // @return l'objet courant ayant été cible de la soustraction
    Quaternion& operator-=(int scalar)
    {
      *this = *this + (-scalar);
      return *this;
    }

    // @description methode permettant de soustraire 1 quaternion et un quaternion et d'affecter le resultat à l'objet courant
    // @arg scalar le quaternion à soustraire
    // @return l'objet courant ayant été cible de la soustraction
    Quaternion& operator-=(const Quaternion& quat)
    {
      *this = *this + (-quat);
      return *this;
    }

    // @description methode permettant de multiplier 1 quaternion et un flottant 
    // @arg scalar le flottant à multiplier
    // @return un nouveau quaternion ayant le resultat de la multiplication
    Quaternion operator*(float scalar)
    {
      Quaternion mult;
      mult.real = real * scalar;
      mult.vectorIm = vectorIm * scalar;
      return mult;
    }

    // @description methode permettant de multiplier 1 quaternion et un flottant prefix
    // @arg scalar le flottant à multiplier
    // @arg quat le quaternion à multiplier
    // @return un nouveau quaternion ayant le resultat de la multiplication
    friend Quaternion operator*(float scalar, const Quaternion& quat)
    {
      Quaternion mult;
      mult.real = quat.real * scalar;
      mult.vectorIm = quat.vectorIm * scalar;
      return mult;
    }

    // @description methode permettant de multiplier 1 quaternion et un entier 
    // @arg scalar l'entier à multiplier
    // @return un nouveau quaternion ayant le resultat de la multiplication
    Quaternion operator*(int scalar)
    {
      Quaternion mult;
      mult.real = real * scalar;
      mult.vectorIm = vectorIm * scalar;
      return mult;
    }

    // @description methode permettant de multiplier 1 quaternion et un entier prefix 
    // @arg scalar l'entier à multiplier
    // @return un nouveau quaternion ayant le resultat de la multiplication
     friend Quaternion operator*(int scalar, const Quaternion& quat)
    {
      Quaternion mult;
      mult.real = quat.real * scalar;
      mult.vectorIm = quat.vectorIm * scalar;
      return mult;
    }

    // @description methode permettant de multiplier 1 quaternion et un quaternion 
    // @arg scalar le quaternion à multiplier
    // @return un nouveau quaternion ayant le resultat de la multiplication
    Quaternion operator*(const Quaternion& quat)
    {
      Quaternion mult;
      mult.real = (real * quat.real) - vectorIm.DotProduct(quat.vectorIm);
      mult.vectorIm =
	(real * quat.vectorIm) +
	(quat.real * vectorIm) +
	(vectorIm.CrossProduct(quat.vectorIm));
      
      return mult;
    }

    // @description methode permettant de multiplier 1 quaternion et un flottant et d'affecter le resultat à l'objet courant 
    // @arg scalar le flottant à multiplier
    // @return l'objet courant ayant été cible de la multiplication
    Quaternion operator*=(float scalar)
    {
      *this = *this * scalar;
      return *this;
    }

    // @description methode permettant de multiplier 1 quaternion et un entier et d'affecter le resultat à l'objet courant 
    // @arg scalar l'entier à multiplier
    // @return l'objet courant ayant été cible de la multiplication
    Quaternion operator*=(int scalar)
    {
      *this = *this * scalar;
      return *this;
    }

    // @description methode permettant de multiplier 1 quaternion et un quaternion et d'affecter le resultat à l'objet courant 
    // @arg scalar le quaternion à multiplier
    // @return l'objet courant ayant été cible de la multiplication
    Quaternion operator*=(const Quaternion& quat)
    {
      *this = *this * quat;
      return *this;
    }
    
    
  };
}

#endif

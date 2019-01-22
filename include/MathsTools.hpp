#ifndef __MATHS_TOOLS_HPP__
#define __MATHS_TOOLS_HPP__

// @description classe representant une boite a outils pour les
// operations mathematiques
class MathsTools
{
private:

  static float epsilonEquals;
    
public:

  // @description methode statique permettant de savoir si 2 flottants sont egaux
  // @arg i le premier flottant
  // @arg j le deuxieme flottant
  // @return vrai si i et j sont egaux modulo notre epsilon, faux sinon
  static bool AreEquals(float i, float j);

  // @description methode statique permettant de savoir si 2 doubles sont egaux
  // @arg i le premier double
  // @arg j le deuxieme double
  // @return vrai si i et j sont egaux modulo notre epsilon, faux sinon
  static bool AreEquals(double i, double j);

  // @description methode statique permettant de savoir si un double et un flottant sont egaux 
  // @arg i le premier double
  // @arg j le deuxieme flottant
  // @return vrai si i et j sont egaux modulo notre epsilon, faux sinon
  static bool AreEquals(double i, float j);

  // @description methode statique permettant de savoir si un flottant et un double sont egaux
  // @arg i le premier flottant
  // @arg j le deuxieme double
  // @return vrai si i et j sont egaux modulo notre epsilon, faux sinon
  static bool AreEquals(float i, double j);
    
};

#endif

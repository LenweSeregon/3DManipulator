#ifndef __VECTOR_TEST_HPP__
#define __VECTOR_TEST_HPP__

#include <string>

#include "Vector.hpp"

namespace om
{
  // @description classe encapsulant tous les tests pour la classe Vector.
  class VectorTest
  {
    
  private:

    static Vector<2,float> unit;
    
    static Vector<3,float> ortho1;
    static Vector<3,float> ortho2;
    
    static Vector<3,float> vector1;
    static Vector<3,float> vector2;
    static Vector<2,float> vector3;
    static Vector<4,float> vector4;
    static Vector<4,float> vector5;
    static Vector<2,std::string> vector6;

    // @description methode permettant d'initialier les attributs avant chaque tests
    static void Init();

    // @description methode permettant de tester la methode Length
    // @return vrai si le test a reussi, faux sinon
    static bool TestLength();

    // @description methode permettant de tester la methode At
    // @return vrai si le test a reussi, faux sinon
    static bool TestAt();

    // @description methode permettant de tester l'exception de la methode At
    // @return vrai si le test a reussi, faux sinon
    static bool TestAtException();

    // @description methode permettant de tester l'operateur[]
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorHook();

    // @description methode permettant de tester le produit scalaire
    // @return vrai si le test a reussi, faux sinon
    static bool TestDotProduct();

    // @description methode permettant de tester le produit vectoriel
    // @return vrai si le test a reussi, faux sinon
    static bool TestCrossProduct();

    // @description methode permettant de tester l'exception du produit vectoriel
    // @return vrai si le test a reussi, faux sinon
    static bool TestCrossProductException();

    // @description methode permettant de tester la norme
    // @return vrai si le test a reussi, faux sinon
    static bool TestNorm();

    // @description methode permettant de tester la methode ToUnit
    // @return vrai si le test a reussi, faux sinon
    static bool TestToUnit();

    // @description methode permettant de tester la methode IsOrtho
    // @return vrai si le test a reussi, faux sinon
    static bool TestIsOrtho();

    // @description methode permettant de tester la methode IsNull
    // @return vrai si le test a reussi, faux sinon
    static bool TestIsNull();

    // @description methode permettant de tester la methode IsNull
    // @return vrai si le test a reussi, faux sinon
    static bool TestIsNotNull();

    // @description methode permettant de tester la methode IsUnit
    // @return vrai si le test a reussi, faux sinon
    static bool TestIsUnit();

    // @description methode permettant de tester l'addition de vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorPlus();

    // @description methode permettant de tester l'addition et affectation de vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorPlusEquals();

    // @description methode permettant de tester l'exception de l'addition
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorPlusException();

    // @description methode permettant de tester l'exception de l'addition et affectation
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorPlusEqualsException();

    // @description methode permettant de tester le moins unitaire
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorMinusUnit();

    // @description methode permettant de tester la soustraction
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorMinus();

    // @description methode permettant de tester la soustraction et affectation
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorMinusEquals();

    // @description methode permettant de tester l'exception de soustraction
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorMinusException();

    // @description methode permettant de tester l'exception de soustraction et affectation
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorMinusEqualsException();

    // @description methode permettant de tester la multiplication par scalaire
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeScalar();

    // @description methode permettant de tester la multiplication par un vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTime();

    // @description methode permettant de tester l'exception de la multiplication par un vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeException();

    // @description methode permettant de tester la multiplication et affectation par un scalaire
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeScalarEquals();

    // @description methode permettant de tester la multiplication et affectation par un vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeEquals();

    // @description methode permettant de tester l'exception de la multiplication et affectation par un vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeEqualsException();

    // @description methode permettant de tester la multiplication par un scalaire prefixe
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeScalarPrefix();
    
  public:

    // @description methode permettant de lancer tous les tests sur les Vector
    // @return vrai si tous les tests ont reussi, faux sinon
    static bool StartTest();
  };
}

#endif

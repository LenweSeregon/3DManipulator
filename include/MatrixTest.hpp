#ifndef __MATRIX_TEST_HPP__
#define __MATRIX_TEST_HPP__

#include "Matrix.hpp"
#include "Vector.hpp"

namespace om
{
  // @description classe representant l'encapsulation pour tous les tests sur les matrices
  class MatrixTest
  {

  private:

    static Vector<3,float> vector1;
    static Vector<2,float> vector2;

    static Matrix<float,3,3> ortho;
    static Matrix<std::string,1,1> asString;
    static Matrix<float,3,3> noReverse;
    static Matrix<float,3,3> reverse;
    
    static Matrix<float,2,3> mult1;
    static Matrix<float,3,2> mult2;

    static Matrix<float,2,2> add1;
    static Matrix<float,2,2> add2;
    

    // @description methode privee permettant d'initialiser les attributs avant chaque test
    static void Init();

    // @description methode privee permettant de tester la methode At
    // @return vrai si le test a reussi, faux sinon
    static bool TestAt();

    // @description methode privee permettant de tester l'exception de At
    // @return vrai si le test a reussi, faux sinon
    static bool TestAtException();

    // @description methode privee permettant de tester l'operateur[]
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorHook();

    // @description methode privee permettant de tester la methode IsOrtho
    // @return vrai si le test a reussi, faux sinon
    static bool TestIsOrtho();

    // @description methode privee permettant de tester la methode IsNull
    // @return vrai si le test a reussi, faux sinon
    static bool TestIsNull();

    // @description methode privee permettant de tester la methode Transpose
    // @return vrai si le test a reussi, faux sinon
    static bool TestTranspose();

    // @description methode privee permettant de tester la methode Reverse
    // @return vrai si le test a reussi, faux sinon
    static bool TestReverse();

    // @description methode privee permettant de tester l'exception de Reverse
    // @return vrai si le test a reussi, faux sinon
    static bool TestReverseImpossible();

    // @description methode privee permettant de tester l'addition de matrices
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorAdd();

    // @description methode privee permettant de tester l'equalite de matrices
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorAddEquals();

    // @description methode privee permettant de tester la multiplication par un scalaire
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeScalar();

    // @description methode privee permettant de tester la multiplication par un scalaire prefixe
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeScalarPrefix();

    // @description methode privee permettant de tester la multiplication et affectation par scalaire
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeScalarEquals();

    // @description methode privee permettant de tester la multiplication par un vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeVector();
    
    // @description methode privee permettant de tester l'exception de multiplication par vecteur
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeVectorException();

    // @description methode privee permettant de tester la multiplication par vecteur prefixe
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeVectorPrefix();

    // @description methode privee permettant de tester l'exception de multiplication par vecteur prefixe
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeVectorPrefixException();

    // @description methode privee permettant de tester la multiplication par matrice
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeMatrix();
    
    // @description methode privee permettant de tester l'exception de multiplication par matrice
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeMatrixException();

    // @description methode privee permettant de tester la multiplication et affectation par matrice
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeMatrixEquals();

    // @description methode privee permettant de tester l'exception par multiplication et affectation par matrice
    // @return vrai si le test a reussi, faux sinon
    static bool TestOperatorTimeMatrixEqualsException();

  public:

    // @description methode permettant de lancer les tests
    // @return vrai si tous les tests sont passés, faux sinon
    static bool StartTest();
    
  };
}

#endif

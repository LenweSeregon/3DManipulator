#ifndef __ALIASES_TEST_HPP__
#define __ALIASES_TEST_HPP__

#include "Aliases.hpp"

namespace om
{
  class AliasesTest
  {

  private:

    static Vec2f vec0;
    static Vec3f vec1;
    static Vec3f vec2;
    static Vec3f vec3;

    static Matrix<float,2,2> mat0;
    static Mat33f mat1;
    static Mat33f mat2;

    // @description methode privee permettant d'initialiser les attributs avant chaque test
    static void Init();

    // @description methode privee permettant de tester l'alias de cross
    // @return vrai si le test à réussi, faux sinon
    static bool TestCross();

    // @description methode privee permettant de tester l'alias de cross
    // @return vrai si le test à réussi, faux sinon
    static bool TestCrossException();

    // @description methode privee permettant de tester l'alias de multiplication scalaire vecteur
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotScalarFloatVector();

    // @description methode privee permettant de tester l'alias de multiplication scalaire vecteur
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotScalarIntegerVector();

    // @description methode privee permettant de tester l'alias de multiplication vecteur scalaire
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotVectorScalarFloat();

    // @description methode privee permettant de tester l'alias de multiplication vecteur scalaire
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotVectorScalarInteger();

    // @description methode privee permettant de tester l'alias de scalaire matrice
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotScalarFloatMatrix();

    // @description methode privee permettant de tester l'alias de scalaire matrice
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotScalarIntegerMatrix();

    // @description methode privee permettant de tester l'alias de matrice scalaire
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotMatrixScalarFloat();

    // @description methode privee permettant de tester l'alias de matrice scalaire
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotMatrixScalarInteger();

    // @description methode privee permettant de tester l'alias de vecteur vecteur
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotVectorVector();

    // @description methode privee permettant de tester l'alias de vecteur vecteur
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotVectorVectorException();
    
    // @description methode privee permettant de tester l'alias de vecteur matrice
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotVectorMatrix();
    
    // @description methode privee permettant de tester l'alias de vecteur matrice
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotVectorMatrixException();
    
    // @description methode privee permettant de tester l'alias de matrice vecteur
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotMatrixVector();
    
    // @description methode privee permettant de tester l'alias de matrice vecteur
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotMatrixVectorException();
    
    // @description methode privee permettant de tester l'alias de matrice matrice
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotMatrixMatrix();
    
    // @description methode privee permettant de tester l'alias de matrice matrice
    // @return vrai si le test à réussi, faux sinon
    static bool TestDotMatrixMatrixException();
    
  public:

    // @description methode permettant de lancer les tests
    // @return vrai si tous les tests sont passés, faux sinon
    static bool StartTest();
  };
}

#endif

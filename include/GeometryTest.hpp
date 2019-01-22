#ifndef __GEOMETRY_TEST_HPP__
#define __GEOMETRY_TEST_HPP__

#include <string>

#include "Point.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "LineSegment.hpp"
#include "Quaternion.hpp"
#include "Transform.hpp"

namespace geometry
{
  // @description classe representant l'encapsulation pour tous les tests sur la partie geometrie du moteur
  class GeometryTest
  {

  private:

    
    static Transform concatTranslation;
    static Transform concatScale;
    static Transform translateScale;
    static Transform scaleTranslate;
    static Transform transformToQuat;
    static Transform transformToQuat2;
    static Transform transformSphere;

    static Direction<float,3> transformDirection1;
    static Direction<float,3> transformDirection2;
    static Direction<float,3> transformDirection3;
    
    static Point<float,3> transformPoint0;
    static Point<float,3> transformPoint1;
    static Point<float,3> pointOutside0;
    static Point<float,3> pointOutside1;
    static Point<float,3> pointOutside2;
    static Point<float,3> pointRotation0;
    static Point<float,3> pointRotation1;
    static Point<float,3> pointBehindTest0;
    static Point<float,3> pointBehindTest1;
    static Point<float,3> pointBehindTest2;
    static Point<float,3> pointBehindTest3;
    static Point<float,3> pointBehindTest4;
    static Point<float,3> pointBehindTest5;
    static Point<float,3> pointBehindTest6;
    static Point<float,3> pointBehindTest7;
    static Point<float,3> pointBehindTest8;
    static Point<float,3> pointBehindTest9;
    static Point<float,3> point0;
    static Point<float,3> point1;
    static Point<int,2> point2;
    static Point<std::string,2> point3;

    static LineSegment segment1;
    static LineSegment segment2;
    static LineSegment segment3;
    static LineSegment segment4;
    static LineSegment segment5;
    static LineSegment segment6;
    static LineSegment segment7;
    static LineSegment segment8;
    
    static Triangle<float,3> triangle1;
    static Triangle<float,3> triangle2;

    static Sphere sphereOutside;
    static Sphere sphereBehind1;
    static Sphere sphereBehind2;
    static Sphere sphereBehind3;
    static Sphere sphereBehind4;
    static Sphere sphereBehind5;
    static Sphere sphereBehind6;
    static Sphere sphereTransform;

    static Plane planeBehindTest0;
    static Plane planeBehindTest1;
    static Plane planeBehindTest2;
    static Plane planeBehindTest3;
    
    static Quaternion<float> quaternion1;
    static Quaternion<float> quaternion2;
    static Quaternion<float> quaternion3;
    static Quaternion<float> quaternionMult1;
    static Quaternion<float> quaternionMult2;
    static Quaternion<float> quaternionConstructor;
    static Quaternion<float> quaternionRotate;
    static Quaternion<float> quaternionRotate2;
    static Quaternion<float> quaternionToQuatTest;
    static Quaternion<float> quaternionToQuatTest2;

    // @description methode privee permettant d'initialiser les attributs avant chaque test
    static void Init();


    
    // @description methode privee permettant de tester la methode concat dans Transform
    // @return vrai si le test a reussi, faux sinon
    static bool TestTransformConcat();

    // @description methode privee permettant de tester la methode transformTo(point) dans Transform
    // @return vrai si le test a reussi, faux sinon
    static bool TestTransformToPoint();

    // @description methode privee permettant de tester la methode transformTo(direction) dans Transform
    // @return vrai si le test a reussi, faux sinon
    static bool TestTransformToDirection();

    // @description methode privee permettant de tester la methode transformTo(pointsphere) dans Transform
    // @return vrai si le test a reussi, faux sinon
    static bool TestTransformToSphere();

    // @description methode privee permettant de tester la methode transformToQuat dans Transform
    // @return vrai si le test a reussi, faux sinon
    static bool TestTransformToQuat();
    
    

    // @description methode privee permettant de tester la methode lenghtTo dans Point
    // @return vrai si le test a reussi, faux sinon
    static bool TestPointLengthTo();

    // @description methode privee permettant de tester la methode BehindPlan dans Point
    // @return vrai si le test a reussi, faux sinon
    static bool TestPointBehind();

    // @description methode privee permettant de tester la methode Rotate dans Point
    // @return vrai si le test a reussi, faux sinon
    static bool TestPointRotate();

    // @description methode privee permettant de tester la methode OutsideSphere dans Point
    // @return vrai si le test a reussi, faux sinon
    static bool TestPointOutside();

    

    // @description methode privee permettant de tester la methode Aire du Triangle
    // @return vrai si le test a reussi, faux sinon
    static bool TestTriangleArea();

    // @description methode privee permettant de tester la methode GetP0 dans Triangle
    // @return vrai si le test a reussi, faux sinon
    static bool TestTriangleGetP0();

    // @description methode privee permettant de tester la methode GetP1 dans Triangle
    // @return vrai si le test a reussi, faux sinon
    static bool TestTriangleGetP1();

    // @description methode privee permettant de tester la methode GetP2 dans Triangle
    // @return vrai si le test a reussi, faux sinon
    static bool TestTriangleGetP2();

    

    // @description methode privee permettant de tester la methode GetBegin dans LineSegment
    // @return vrai si le test a reussi, faux sinon
    static bool TestLineSegmentGetBegin();

    // @description methode privee permettant de tester la methode GetEnd dans LineSegment
    // @return vrai si le test a reussi, faux sinon
    static bool TestLineSegmentGetEnd();

    // @description methode privee permettant de tester la methode InterCoefthrow dans LineSegment
    // @return vrai si le test a reussi, faux sinon
    static bool TestLineSegmentNANInterCoef();
    
    // @description methode privee permettant de tester la methode InterCoef dans LineSegment
    // @return vrai si le test a reussi, faux sinon
    static bool TestLineSegmentInterCoef();

    // @description methode privee permettant de tester la methode NotIntersection dans LineSegment
    // @return vrai si le test a reussi, faux sinon
    static bool TestLineSegmentNotInter();

    // @description methode privee permettant de tester la methode Intersection dans LineSegment
    // @return vrai si le test a reussi, faux sinon
    static bool TestLineSegmentInter();

    

    // @description methode privee permettant de tester la methode BehindPlane dans Sphere
    // @return vrai si le test a reussi, faux sinon
    static bool TestSphereBehind();



    // @description methode privee permettant de tester la methode Constructeur depuis angle direction dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionConstructorFromAngleDirection();

    // @description methode privee permettant de tester la methode Conjugate dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionConjugate();

    // @description methode privee permettant de tester la methode Norm dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionNorm();

    // @description methode privee permettant de tester la methode partie Reel dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionRe();

    // @description methode privee permettant de tester la methode partie Imaginaire dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionIm();

    // @description methode privee permettant de tester la methode ToNorm dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionToNorm();

    // @description methode privee permettant de tester la methode addition scalaire flottant dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionScalarFloat();

    // @description methode privee permettant de tester la methode addiition scalaire flottant prefix dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionScalarFloatPrefix();

    // @description methode privee permettant de tester la methode addition scalaire entier dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionScalarInteger();

    // @description methode privee permettant de tester la methode addition scalaire entier prefix dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionScalarIntegerPrefix();

    // @description methode privee permettant de tester la methode addition Quaternion dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionQuaternion();

    // @description methode privee permettant de tester la methode addition equale scalaire flottant dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionScalarFloatEquals();

    // @description methode privee permettant de tester la methode addition equale scalaire entier dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionScalarIntegerEquals();

    // @description methode privee permettant de tester la methode addition Quaternion equale dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionAdditionQuaternionEquals();

    // @description methode privee permettant de tester la methode negation dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionNegation();

    // @description methode privee permettant de tester la methode soustraction scalaire flottant dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionScalarFloat();

    // @description methode privee permettant de tester la methode soustraciton scalaire flottant prefix dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionScalarFloatPrefix();

    // @description methode privee permettant de tester la methode soustraction scalaire entier dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionScalarInteger();

    // @description methode privee permettant de tester la methode soustraction scalaire entier prefix dans Quaternion 
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionScalarIntegerPrefix();

    // @description methode privee permettant de tester la methode soustraction Quaternion dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionQuaternion();

    // @description methode privee permettant de tester la methode soustraction scalaire flottant equale dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionScalarFloatEquals();

    // @description methode privee permettant de tester la methode soustraction scalaire entier equale dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionScalarIntegerEquals();

    // @description methode privee permettant de tester la methode soustraction Quaternion dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionSubstractionQuaternionEquals();

    // @description methode privee permettant de tester la methode multiplication scalaire flottant dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationScalarFloat();

    // @description methode privee permettant de tester la methode multiplication scalaire flottant prefix dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationScalarFloatPrefix();

    // @description methode privee permettant de tester la methode multiplication scalaire entier dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationScalarInteger();

    // @description methode privee permettant de tester la methode multiplication scalaire entier prefix dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultipicationScalarIntegerPrefix();

    // @description methode privee permettant de tester la methode multiplication Quaternion dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationQuaternion();

    // @description methode privee permettant de tester la methode multiplication scalaire flottant equale dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationScalarFloatEquals();

    // @description methode privee permettant de tester la methode multiplication scalaire entier equale dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationScalarIntegerEquals();
 
    // @description methode privee permettant de tester la methode multiplication Quaternion egale dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionMultiplicationQuaternionEquals();

    // @description methode privee permettant de tester la methode Reverse dans Quaternion
    // @return vrai si le test a reussi, faux sinon
    static bool TestQuaternionReverse();
    
  public:

    // @description methode permettant de lancer les tests
    // @return vrai si tous les tests sont passés, faux sinon
    static bool StartTest();
  };
}

#endif

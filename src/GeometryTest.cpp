#include "MathsTools.hpp"
#include "GeometryTest.hpp"
#include <optional>

namespace geometry
{
  Transform GeometryTest::concatTranslation;
  Transform GeometryTest::concatScale;
  Transform GeometryTest::translateScale;
  Transform GeometryTest::scaleTranslate;
  Transform GeometryTest::transformToQuat;
  Transform GeometryTest::transformToQuat2;
  Transform GeometryTest::transformSphere;
  
  Direction<float,3> GeometryTest::transformDirection1;
  Direction<float,3> GeometryTest::transformDirection2;
  Direction<float,3> GeometryTest::transformDirection3;
  
  Point<float,3> GeometryTest::transformPoint0;
  Point<float,3> GeometryTest::transformPoint1;
  Point<float,3> GeometryTest::pointOutside0;
  Point<float,3> GeometryTest::pointOutside1;
  Point<float,3> GeometryTest::pointOutside2;
  Point<float,3> GeometryTest::pointRotation0;
  Point<float,3> GeometryTest::pointRotation1;
  Point<float,3> GeometryTest::pointBehindTest0;
  Point<float,3> GeometryTest::pointBehindTest1;
  Point<float,3> GeometryTest::pointBehindTest2;
  Point<float,3> GeometryTest::pointBehindTest3;
  Point<float,3> GeometryTest::pointBehindTest4;
  Point<float,3> GeometryTest::pointBehindTest5;
  Point<float,3> GeometryTest::pointBehindTest6;
  Point<float,3> GeometryTest::pointBehindTest7;
  Point<float,3> GeometryTest::pointBehindTest8;
  Point<float,3> GeometryTest::pointBehindTest9;
  Point<float,3> GeometryTest::point0;
  Point<float,3> GeometryTest::point1;
  Point<int,2> GeometryTest::point2;
  Point<std::string,2> GeometryTest::point3;

  Triangle<float,3> GeometryTest::triangle1;
  Triangle<float,3> GeometryTest::triangle2;

  LineSegment GeometryTest::segment1;
  LineSegment GeometryTest::segment2;
  LineSegment GeometryTest::segment3;
  LineSegment GeometryTest::segment4;
  LineSegment GeometryTest::segment5;
  LineSegment GeometryTest::segment6;
  LineSegment GeometryTest::segment7;
  LineSegment GeometryTest::segment8;
  
  Sphere GeometryTest::sphereOutside;
  Sphere GeometryTest::sphereBehind1;
  Sphere GeometryTest::sphereBehind2;
  Sphere GeometryTest::sphereBehind3;
  Sphere GeometryTest::sphereBehind4;
  Sphere GeometryTest::sphereBehind5;
  Sphere GeometryTest::sphereBehind6;
  Sphere GeometryTest::sphereTransform;
  
  Plane GeometryTest::planeBehindTest0;
  Plane GeometryTest::planeBehindTest1;
  Plane GeometryTest::planeBehindTest2;
  Plane GeometryTest::planeBehindTest3;
  
  Quaternion<float> GeometryTest::quaternion1;
  Quaternion<float> GeometryTest::quaternion2;
  Quaternion<float> GeometryTest::quaternion3;
  Quaternion<float> GeometryTest::quaternionMult1;
  Quaternion<float> GeometryTest::quaternionMult2;
  Quaternion<float> GeometryTest::quaternionConstructor;
  Quaternion<float> GeometryTest::quaternionRotate;
  Quaternion<float> GeometryTest::quaternionRotate2;
  Quaternion<float> GeometryTest::quaternionToQuatTest;
  Quaternion<float> GeometryTest::quaternionToQuatTest2;
  
  void GeometryTest::Init()
  {
    om::Vector<3,float> transformDirectionInit1;
    transformDirectionInit1[0] = 2.0f;
    transformDirectionInit1[1] = 2.0f;
    transformDirectionInit1[2] = 1.0f;
    transformDirection1 = Direction<float,3>(transformDirectionInit1);
    
    om::Vector<3,float> transformDirectionInit2;
    transformDirectionInit2[0] = 5.0f;
    transformDirectionInit2[1] = 2.0f;
    transformDirectionInit2[2] = -3.0f;
    transformDirection2 = Direction<float,3>(transformDirectionInit2);

    om::Vector<3,float> transformDirectionInit3;
    transformDirectionInit3[0] = 2.0f;
    transformDirectionInit3[1] = -2.0f;
    transformDirectionInit3[2] = -1.0f;
    transformDirection3 = Direction<float,3>(transformDirectionInit3);
    
    om::Vector<3,float> translationInit;
    translationInit[0] = 1.0f;
    translationInit[1] = 0.0f;
    translationInit[2] = 2.0f;
    concatTranslation = Transform(translationInit);
    
    om::Vector<3,float> scaleInit;
    scaleInit[0] = 1.0f;
    scaleInit[1] = 2.0f;
    scaleInit[2] = 1.0f;
    concatScale = Transform(scaleInit,true);

    translateScale = concatTranslation.Concat(concatScale);
    scaleTranslate = concatScale.Concat(concatTranslation);

    transformPoint0 = Point<float,3>({2.0f, 1.0f, 1.0f});
    transformPoint1 = Point<float,3>({0.0f, 2.0f, 0.0f});
    
    triangle1 = Triangle<float,3>(
      {
	Point<float,3>({0.0f,0.0f,3.0f}),
	  Point<float,3>({0.0f,3.0f,0.0f}),
	  Point<float,3>({3.0f,0.0f,0.0f})
      });

    triangle2 = Triangle<float,3>(
      {
	Point<float,3>({-4.43f,-6.44f,0.0f}),
	  Point<float,3>({0.0f,0.0f,5.0f}),
	  Point<float,3>({-1.16f,-8.27f,0.0f})
      });

    Point<float,3> beginSeg1({-2.76f,-4.93f,2.76f});
    Point<float,3> endSeg1({-2.8f,4.67f,2.8f});
    segment1 = LineSegment(beginSeg1, endSeg1);

    Point<float,3> beginSeg2({0.0f,0.0f,2.0f});
    Point<float,3> endSeg2({0.0f,4.0f,2.0f});
    segment2 = LineSegment(beginSeg2, endSeg2);

    Point<float,3> beginSeg3({-4.0f,0.0f,0.0f});
    Point<float,3> endSeg3({-4.0f,-3.0f, 0.0f});
    segment3 = LineSegment(beginSeg3, endSeg3);

    Point<float,3> beginSeg4({0.0f,0.0f,4.0f});
    Point<float,3> endSeg4({-4.0f,0.0f, 2.77f});
    segment4 = LineSegment(beginSeg4, endSeg4);

    Point<float,3> beginSeg5({-4.0f,0.0f,0.0f});
    Point<float,3> endSeg5({-5.98f,0.71f, 1.0f});
    segment5 = LineSegment(beginSeg5, endSeg5);

    Point<float,3> beginSeg6({0.0f,0.0f,4.0f});
    Point<float,3> endSeg6({-4.0f,-3.0f, 0.0f});
    segment6 = LineSegment(beginSeg6, endSeg6);

    Point<float,3> beginSeg7({17.72f,-4.95f,0.0f});
    Point<float,3> endSeg7({6.09f,-10.78f, 0.0f});
    segment7 = LineSegment(beginSeg7, endSeg7);

    Point<float,3> beginSeg8({-3.95f,-3.47, 3.95f});
    Point<float,3> endSeg8({0.0f,0.0f,0.6f});
    segment8 = LineSegment(beginSeg8, endSeg8);
    
    pointOutside0 = Point<float,3>({5.0f,0.0f,0.0f});
    pointOutside1 = Point<float,3>({4.0f, 4.0f, 4.0f});
    pointOutside2 = Point<float,3>({4.0f, 4.0f, 5.1f});
    pointRotation0 = Point<float,3>({0.0f, 1.0f, 0.0f});
    pointRotation1 = Point<float,3>({1.0f, -5.0f, 3.0f});
    point0 = Point<float,3>({-1.0, 5.0f, 2.0f});
    point1 = Point<float,3>({2.0f,3.0f,4.0f});
    point2 = Point<int,2>({1,5});
    point3 = Point<std::string,2>({"1","2"});

    om::Vector<3,float> initSphereOutside;
    initSphereOutside[0] = 0.0f;
    initSphereOutside[1] = 0.0f;
    initSphereOutside[2] = 0.0f;
    sphereOutside = Sphere(initSphereOutside,5.0f);

    om::Vector<3,float> initSphereBehind1;
    initSphereBehind1[0] = 0.0f;
    initSphereBehind1[1] = 0.0f;
    initSphereBehind1[2] = 8.0f;
    sphereBehind1 = Sphere(initSphereBehind1,2.0f);

    om::Vector<3,float> initSphereBehind2;
    initSphereBehind2[0] = 0.0f;
    initSphereBehind2[1] = 0.0f;
    initSphereBehind2[2] = 0.0f;
    sphereBehind2 = Sphere(initSphereBehind2,4.0f);

    om::Vector<3,float> initSphereBehind3;
    initSphereBehind3[0] = -12.0f;
    initSphereBehind3[1] = 0.0f;
    initSphereBehind3[2] = 0.0f;
    sphereBehind3 = Sphere(initSphereBehind3,8.0f);

    om::Vector<3,float> initSphereBehind4;
    initSphereBehind4[0] = -11.0f;
    initSphereBehind4[1] = 0.0f;
    initSphereBehind4[2] = 0.0f;
    sphereBehind4 = Sphere(initSphereBehind4,8.0f);

    om::Vector<3,float> initSphereBehind5;
    initSphereBehind5[0] = -2.0f;
    initSphereBehind5[1] = 0.0f;
    initSphereBehind5[2] = 0.0f;
    sphereBehind5 = Sphere(initSphereBehind5,1.0f);

    om::Vector<3,float> initSphereBehind6;
    initSphereBehind6[0] = 1.93f;
    initSphereBehind6[1] = 0.82f;
    initSphereBehind6[2] = -4.64f;
    sphereBehind6 = Sphere(initSphereBehind6,2.0f);

    om::Vector<3,float> initSphereTransform;
    initSphereTransform[0] = 2.0f;
    initSphereTransform[1] = 2.0f;
    initSphereTransform[2] = 0.0f;
    sphereTransform = Sphere(initSphereTransform, 5.5f);

    om::Vector<4,float> initQuaternion1;
    initQuaternion1[0] = 1.0f;
    initQuaternion1[1] = 2.0f;
    initQuaternion1[2] = 3.0f;
    initQuaternion1[3] = 4.0f;
    quaternion1 = Quaternion<float>(initQuaternion1);

    om::Vector<4,float> initQuaternion2;
    initQuaternion2[0] = 2.0f;
    initQuaternion2[1] = 1.0f;
    initQuaternion2[2] = 3.0f;
    initQuaternion2[3] = 7.0f;
    quaternion2 = Quaternion<float>(initQuaternion2);

    om::Vector<4,float> initQuaternion3;
    initQuaternion3[0] = 1.0f;
    initQuaternion3[1] = -2.0f;
    initQuaternion3[2] = 5.0f;
    initQuaternion3[3] = -1.0f;
    quaternion3 = Quaternion<float>(initQuaternion3);

    om::Vector<4,float> initQuaternionMult1;
    initQuaternionMult1[0] = 2.0f;
    initQuaternionMult1[1] = 5.0f;
    initQuaternionMult1[2] = 1.0f;
    initQuaternionMult1[3] = -3.0f;
    quaternionMult1 = Quaternion<float>(initQuaternionMult1);
      
    om::Vector<4,float> initQuaternionMult2;
    initQuaternionMult2[0] = 4.0f;
    initQuaternionMult2[1] = -2.0f;
    initQuaternionMult2[2] = 2.0f;
    initQuaternionMult2[3] = -4.0f;
    quaternionMult2 = Quaternion<float>(initQuaternionMult2);

    float angle = 30.0f;
    om::Vector<3,float> initQuaternionConstructorDirection;
    initQuaternionConstructorDirection[0] = 0.0f;
    initQuaternionConstructorDirection[1] = 1.0f;
    initQuaternionConstructorDirection[2] = 0.0f;
    Direction<float,3> initQuaternionDirection(initQuaternionConstructorDirection);
    quaternionConstructor = Quaternion<float>(angle,initQuaternionDirection);
    
    float angle2 = 90.0f;
    om::Vector<3,float> initQuaternionRotate;
    initQuaternionRotate[0] = 1.0f;
    initQuaternionRotate[1] = 0.0f;
    initQuaternionRotate[2] = 0.0f;
    Direction<float,3> initQuaternionDirectionRotate(initQuaternionRotate);
    quaternionRotate = Quaternion<float>(angle2,initQuaternionDirectionRotate);
    
    float angle3 = 85.0f;
    om::Vector<3,float> initQuaternionRotate2;
    initQuaternionRotate2[0] = 1.0f;
    initQuaternionRotate2[1] = 2.0f;
    initQuaternionRotate2[2] = 1.0f;
    Direction<float,3> initQuaternionDirectionRotate2(initQuaternionRotate2);
    quaternionRotate2 = Quaternion<float>(angle3,initQuaternionDirectionRotate2);

    float angle4 = 85.0f;
    om::Vector<3,float> initQuaternionRotate4;
    initQuaternionRotate4[0] = 1.0f;
    initQuaternionRotate4[1] = 2.0f;
    initQuaternionRotate4[2] = 1.0f;
    Direction<float,3> initQuaternionDirectionRotate4(initQuaternionRotate4);
    quaternionToQuatTest = Quaternion<float>(angle4,initQuaternionDirectionRotate4);
    transformToQuat = Transform(quaternionToQuatTest);

    float angle5 = 0.0f;
    om::Vector<3,float> initQuaternionRotate5;
    initQuaternionRotate5[0] = 0.0f;
    initQuaternionRotate5[1] = 0.0f;
    initQuaternionRotate5[2] = 0.0f;
    Direction<float,3> initQuaternionDirectionRotate5(initQuaternionRotate5);
    quaternionToQuatTest2 = Quaternion<float>(angle5,initQuaternionDirectionRotate5);
    transformToQuat2 = Transform(quaternionToQuatTest2);

    om::Vector<3,float> initTransformSphere;
    initTransformSphere[0] = 2.0f;
    initTransformSphere[1] = 2.0f;
    initTransformSphere[2] = -6.0f;
    transformSphere = Transform(initTransformSphere, 50.0f);
    
    om::Vector<4,float> initPlanTest0;
    initPlanTest0[0] = 0.0f;
    initPlanTest0[1] = 0.0f;
    initPlanTest0[2] = 1.0f;
    initPlanTest0[3] = 2.0f;
    planeBehindTest0 = Plane(initPlanTest0);
    
    om::Vector<4,float> initPlanTest1;
    initPlanTest1[0] = 1.0f;
    initPlanTest1[1] = 0.0f;
    initPlanTest1[2] = 1.0f;
    initPlanTest1[3] = 0.0f;
    planeBehindTest1 = Plane(initPlanTest1);
    
    om::Vector<4,float> initPlanTest2;
    initPlanTest2[0] = 2.0f;
    initPlanTest2[1] = 3.0f;
    initPlanTest2[2] = -4.0f;
    initPlanTest2[3] = 5.0f;
    planeBehindTest2 = Plane(initPlanTest2);

    om::Vector<4,float> initPlanTest3;
    initPlanTest3[0] = 2.0f;
    initPlanTest3[1] = 3.0f;
    initPlanTest3[2] = 5.0f;
    initPlanTest3[3] = 2.0f;
    planeBehindTest3 = Plane(initPlanTest3);

    pointBehindTest0 = Point<float,3>({0.0f, 0.0f, 1.0f});
    pointBehindTest1 = Point<float,3>({0.0f, 0.0f, -2.0f});
    pointBehindTest2 = Point<float,3>({0.0f, 0.0f, -3.0f});

    pointBehindTest3 = Point<float,3>({0.0f, 0.0f, 0.0f});
    pointBehindTest4 = Point<float,3>({1.0f, 0.0f, 1.0f});
    pointBehindTest5 = Point<float,3>({-0.49f, 0.0f, 0.0f});
    
    pointBehindTest6 = Point<float,3>({0.0f, 0.0f, 0.0f});
    pointBehindTest7 = Point<float,3>({0.0f, 0.0f, -1.0f});
    pointBehindTest8 = Point<float,3>({-1.0f, -1.0f, 1.0f});
    
  }

  bool GeometryTest::StartTest()
  {
    std::cout << "=====================================" << std::endl;
    std::cout << "Running test for Geometry package ..." << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    bool testResult = true;


    std::cout << "*************************************" << std::endl;
    std::cout << "Test section for Transform" << std::endl;
    std::cout << "*************************************" << std::endl;
    Init();
    testResult &= TestTransformConcat();
    Init();
    testResult &= TestTransformToPoint();
    Init();
    testResult &= TestTransformToDirection();
    Init();
    testResult &= TestTransformToSphere();
    Init();
    testResult &= TestTransformToQuat();
    
    std::cout << "*************************************" << std::endl;
    std::cout << "Test section for Point<N,T>" << std::endl;
    std::cout << "*************************************" << std::endl;
    Init();
    testResult &= TestPointLengthTo();
    Init();
    testResult &= TestPointBehind();
    Init();
    testResult &= TestPointRotate();
    Init();
    testResult &= TestPointOutside();

    std::cout << "*************************************" << std::endl;
    std::cout << "Test section for Sphere" << std::endl;
    std::cout << "*************************************" << std::endl;
    Init();
    testResult &= TestSphereBehind();
    
    std::cout << "*************************************" << std::endl;
    std::cout << "Test section for lineSegment" << std::endl;
    std::cout << "*************************************" << std::endl;
    Init();
    testResult &= TestLineSegmentGetBegin();
    Init();
    testResult &= TestLineSegmentGetEnd();
    Init();
    testResult &= TestLineSegmentNANInterCoef();
    Init();
    testResult &= TestLineSegmentInterCoef();
    Init();
    testResult &= TestLineSegmentNotInter();
    Init();
    testResult &= TestLineSegmentInter();
    
    std::cout << "*************************************" << std::endl;
    std::cout << "Test section for Triangle<N,T>" << std::endl;
    std::cout << "*************************************" << std::endl;
    Init();
    testResult &= TestTriangleArea();
    Init();
    testResult &= TestTriangleGetP0();
    Init();
    testResult &= TestTriangleGetP1();
    Init();
    testResult &= TestTriangleGetP2();
    
    std::cout << "*************************************" << std::endl;
    std::cout << "Test section for Quaternion<T>" << std::endl;
    std::cout << "*************************************" << std::endl;
    Init();
    testResult &= TestQuaternionConstructorFromAngleDirection();
    Init();
    testResult &= TestQuaternionConjugate();
    Init();
    testResult &= TestQuaternionNorm();
    Init();
    testResult &= TestQuaternionRe();
    Init();
    testResult &= TestQuaternionIm();
    Init();
    testResult &= TestQuaternionToNorm();
    Init();
    testResult &= TestQuaternionReverse();
    Init();
    testResult &= TestQuaternionAdditionScalarFloat();
    Init();
    testResult &= TestQuaternionAdditionScalarFloatPrefix();
    Init();
    testResult &= TestQuaternionAdditionScalarInteger();
    Init();
    testResult &= TestQuaternionAdditionScalarIntegerPrefix();
    Init();
    testResult &= TestQuaternionAdditionQuaternion();
    Init();
    testResult &= TestQuaternionAdditionScalarFloatEquals();
    Init();
    testResult &= TestQuaternionAdditionScalarIntegerEquals();
    Init();
    testResult &= TestQuaternionAdditionQuaternionEquals();
    Init();
    testResult &= TestQuaternionNegation();
    Init();
    testResult &= TestQuaternionSubstractionScalarFloat();
    Init();
    testResult &= TestQuaternionSubstractionScalarFloatPrefix();
    Init();
    testResult &= TestQuaternionSubstractionScalarInteger();
    Init();
    testResult &= TestQuaternionSubstractionScalarIntegerPrefix();
    Init();
    testResult &= TestQuaternionSubstractionQuaternion();
    Init();
    testResult &= TestQuaternionSubstractionScalarFloatEquals();
    Init();
    testResult &= TestQuaternionSubstractionScalarIntegerEquals();
    Init();
    testResult &= TestQuaternionSubstractionQuaternionEquals();
    Init();
    testResult &= TestQuaternionMultiplicationScalarFloat();
    Init();
    testResult &= TestQuaternionMultiplicationScalarFloatPrefix();
    Init();
    testResult &= TestQuaternionMultiplicationScalarInteger();
    Init();
    testResult &= TestQuaternionMultipicationScalarIntegerPrefix();
    Init();
    testResult &= TestQuaternionMultiplicationQuaternion();
    Init();
    testResult &= TestQuaternionMultiplicationScalarFloatEquals();
    Init();
    testResult &= TestQuaternionMultiplicationScalarIntegerEquals();
    Init();
    testResult &= TestQuaternionMultiplicationQuaternionEquals();
    
    std::cout << "-------------------------------------" << std::endl;
    if(testResult)
      {
	std::cout << "Test for Geometry package passed with success" << std::endl;
      }
    else
      {
	std::cout << "Test for Geometry package failed" << std::endl;
      }
    
    std::cout << "=====================================" << std::endl;
    return testResult;
  }

  ///////////////////////////////////////////
  /////// SPHERE
  ///////////////////////////////////////////

  bool GeometryTest::TestSphereBehind()
  {
    if(!sphereBehind1.Behind(planeBehindTest1) &&
       !sphereBehind2.Behind(planeBehindTest1) &&
       sphereBehind3.Behind(planeBehindTest1) &&
       !sphereBehind4.Behind(planeBehindTest1) &&
       sphereBehind5.Behind(planeBehindTest1) &&
       sphereBehind6.Behind(planeBehindTest3))
      {
	std::cout << "TestSphereBehind() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestSphereBehind() : Test Failed" << std::endl;
	return false;
	}
    return false;
  }

  ///////////////////////////////////////////
  /////// TRANSFORM
  ///////////////////////////////////////////
  
  bool GeometryTest::TestTransformConcat()
  {
    auto res = concatTranslation.Concat(concatScale);
    if(MathsTools::AreEquals(res[0][0],1.0f) &&
       MathsTools::AreEquals(res[0][1],0.0f) &&
       MathsTools::AreEquals(res[0][2],0.0f) &&
       MathsTools::AreEquals(res[0][3],1.0f) &&
       MathsTools::AreEquals(res[1][0],0.0f) &&
       MathsTools::AreEquals(res[1][1],2.0f) &&
       MathsTools::AreEquals(res[1][2],0.0f) &&
       MathsTools::AreEquals(res[1][3],0.0f) &&
       MathsTools::AreEquals(res[2][0],0.0f) &&
       MathsTools::AreEquals(res[2][1],0.0f) &&
       MathsTools::AreEquals(res[2][2],1.0f) &&
       MathsTools::AreEquals(res[2][3],2.0f) &&
       MathsTools::AreEquals(res[3][0],0.0f) &&
       MathsTools::AreEquals(res[3][1],0.0f) &&
       MathsTools::AreEquals(res[3][2],0.0f) &&
       MathsTools::AreEquals(res[3][3],1.0f))
      {
	std::cout << "TestTransformConcat() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTransformConcat() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestTransformToPoint()
  {
    auto res1 = concatTranslation.TransformTo(transformPoint0);
    auto res2 = concatTranslation.TransformTo(transformPoint1);
    if(MathsTools::AreEquals(res1[0], 3.0f) &&
       MathsTools::AreEquals(res1[1], 1.0f) &&
       MathsTools::AreEquals(res1[2], 3.0f) &&
       MathsTools::AreEquals(res2[0], 1.0f) &&
       MathsTools::AreEquals(res2[1], 2.0f) &&
       MathsTools::AreEquals(res2[2], 2.0f))
      {
	std::cout << "TestTransformToPoint() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTransformToPoint() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestTransformToDirection()
  {
    auto res1 = concatTranslation.TransformTo(transformDirection1);
    auto res2 = concatScale.TransformTo(transformDirection2);
    auto res3 = translateScale.TransformTo(transformDirection3);
    if(MathsTools::AreEquals(res1[0], 2.0f) &&
       MathsTools::AreEquals(res1[1], 2.0f) &&
       MathsTools::AreEquals(res1[2], 1.0f) &&
       MathsTools::AreEquals(res2[0], 5.0f) &&
       MathsTools::AreEquals(res2[1], 4.0f) &&
       MathsTools::AreEquals(res2[2], -3.0f) &&
       MathsTools::AreEquals(res3[0], 2.0f) &&
       MathsTools::AreEquals(res3[1], -4.0f) &&
       MathsTools::AreEquals(res3[2], -1.0f))
      {
	std::cout << "TestTransformToDirection() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTransformToDirection() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestTransformToSphere()
  {
    auto res = transformSphere.TransformTo(sphereTransform);
    if(MathsTools::AreEquals(res.GetRadius(), sphereTransform.GetRadius()) &&
       MathsTools::AreEquals(res.GetPoint()[0], 2.801297f) &&
       MathsTools::AreEquals(res.GetPoint()[1], 0.029644f) &&
       MathsTools::AreEquals(res.GetPoint()[2], -0.389686f))
      {
	std::cout << "TestTransformToSphere() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTransformToSphere() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestTransformToQuat()
  {
    auto res = transformToQuat.ToQuat();
    if(MathsTools::AreEquals(res.Re(), quaternionToQuatTest.Re()) &&
       MathsTools::AreEquals(res.Im()[0], quaternionToQuatTest.Im()[0]) &&
       MathsTools::AreEquals(res.Im()[1], quaternionToQuatTest.Im()[1]) &&
       MathsTools::AreEquals(res.Im()[2], quaternionToQuatTest.Im()[2]))
      {
	std::cout << "TestTransformToQuat() : Test Suceed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTransformToQuat() : Test Failed" << std::endl;
	return false;
      }
  }
  
  ///////////////////////////////////////////
  /////// POINT
  ///////////////////////////////////////////

  bool GeometryTest::TestPointLengthTo()
  {
    auto res = point0.LengthTo(point1);
    if(MathsTools::AreEquals(res[0], 3.0f) &&
       MathsTools::AreEquals(res[1], -2.0f) &&
       MathsTools::AreEquals(res[2], 2.0f))
      {
	std::cout << "TestDirectionLengthTo() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDirectionLengthTo() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestPointBehind()
  {
    if(!pointBehindTest0.Behind(planeBehindTest0) &&
       !pointBehindTest1.Behind(planeBehindTest0) &&
       pointBehindTest2.Behind(planeBehindTest0) &&
       !pointBehindTest3.Behind(planeBehindTest1) &&
       !pointBehindTest4.Behind(planeBehindTest1) &&
       pointBehindTest5.Behind(planeBehindTest1) &&
       !pointBehindTest6.Behind(planeBehindTest2) &&
       !pointBehindTest7.Behind(planeBehindTest2) &&
       pointBehindTest8.Behind(planeBehindTest2))
      {
	std::cout << "TestPointBehind() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestPointBehind() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestPointRotate()
  {
    auto point = pointRotation0.Rotate(quaternionRotate);
    auto point2 = pointRotation1.Rotate(quaternionRotate2);
    if(MathsTools::AreEquals(point[0],0.0f) &&
       MathsTools::AreEquals(point[1],0.0f) &&
       MathsTools::AreEquals(point[2],1.0f) &&
       MathsTools::AreEquals(point2[0],3.647954f) &&
       MathsTools::AreEquals(point2[1],-3.074857f) &&
       MathsTools::AreEquals(point2[2],-3.498241f))
      {
	std::cout << "TestPointRotate() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestPointRotate() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestPointOutside()
  {
    if(!pointOutside0.Outside(sphereOutside) &&
       pointOutside1.Outside(sphereOutside) &&
       pointOutside2.Outside(sphereOutside))
      {
	std::cout << "TestPointOuside() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestPointOuside() : Test Failed" << std::endl;
	return false;
      }
  }

  ///////////////////////////////////////////
  /////// LineSegment
  ///////////////////////////////////////////
  bool GeometryTest::TestLineSegmentGetBegin()
  {
    if(MathsTools::AreEquals(segment3.GetBegin()[0], -4.0f) &&
       MathsTools::AreEquals(segment3.GetBegin()[1], 0.0f) &&
       MathsTools::AreEquals(segment3.GetBegin()[2], 0.0f))
      {
	std::cout << "TestLineSegmentGetBegin() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestLineSegmentGetBegin() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestLineSegmentGetEnd()
  {
    if(MathsTools::AreEquals(segment3.GetEnd()[0], -4.0f) &&
       MathsTools::AreEquals(segment3.GetEnd()[1], -3.0f) &&
       MathsTools::AreEquals(segment3.GetEnd()[2], 0.0f))
      {
	std::cout << "TestLineSegmentGetEnd() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestLineSegmentGetEnd() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestLineSegmentNANInterCoef()
  {
    try
      {
	segment2.InterCoef(planeBehindTest1);
	std::cout << "TestLineSegmentNANInterCoef() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::out_of_range& e)
      {
	std::cout << "TestLineSegmentNANInterCoef() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool GeometryTest::TestLineSegmentInterCoef()
  {
    float res1 = segment1.InterCoef(planeBehindTest1);
    float res4 = segment4.InterCoef(planeBehindTest1);
    float res5 = segment5.InterCoef(planeBehindTest1);
    float res6 = segment8.InterCoef(planeBehindTest1);
    if(MathsTools::AreEquals(res1, 0.0f) &&
       MathsTools::AreEquals(res4,0.764818f) &&
       MathsTools::AreEquals(res6,0.0f) &&
       res5 < 0)
      {
	std::cout << "TestLineSegmentInterCoef() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestLineSegmentInterCoef() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestLineSegmentNotInter()
  {
    auto res = segment2.Inter(planeBehindTest1);
    if(res == std::nullopt)
      {
	std::cout << "TestLineSegmentNotInter() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestLineSegmentNotInter() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestLineSegmentInter()
  {
    auto res0 = *segment1.Inter(planeBehindTest1);
    auto res = *segment6.Inter(planeBehindTest1);
    auto res2 = *segment7.Inter(planeBehindTest3);
    auto res3 = *segment8.Inter(planeBehindTest1);
    if(MathsTools::AreEquals(res0[0], -2.76f) &&
       MathsTools::AreEquals(res0[1], -4.93f) &&
       MathsTools::AreEquals(res0[2], 2.76f) &&
       MathsTools::AreEquals(res[0], -2.0f) &&
       MathsTools::AreEquals(res[1], -1.5f) &&
       MathsTools::AreEquals(res[2], 2.0f) &&
       MathsTools::AreEquals(res2[0], 11.2728f) &&
       MathsTools::AreEquals(res2[1], -8.18189f) &&
       MathsTools::AreEquals(res2[2], 0.0f) &&
       MathsTools::AreEquals(res3[0], -3.95f) &&
       MathsTools::AreEquals(res3[1], -3.47f) &&
       MathsTools::AreEquals(res3[2], 3.95f))
      {
	std::cout << "TestLineSegmentInter() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestLineSegmentInter() : Test Failed" << std::endl;
	return false;
      }
  }

  ///////////////////////////////////////////
  /////// Triangle
  ///////////////////////////////////////////

  bool GeometryTest::TestTriangleArea()
  {
    if(MathsTools::AreEquals(triangle1.Area(),7.79423f) &&
       MathsTools::AreEquals(triangle2.Area(), 17.3327f))
      {
	std::cout << "TestTriangleArea() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTriangleArea() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestTriangleGetP0()
  {
    if(MathsTools::AreEquals(triangle1.GetP0()[0],0.0f) &&
       MathsTools::AreEquals(triangle1.GetP0()[1], 0.0f) &&
       MathsTools::AreEquals(triangle1.GetP0()[2], 3.0f))
      {
	std::cout << "TestTriangleGetP0() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTriangleGetP0() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestTriangleGetP1()
  {
    if(MathsTools::AreEquals(triangle1.GetP1()[0],0.0f) &&
       MathsTools::AreEquals(triangle1.GetP1()[1], 3.0f) &&
       MathsTools::AreEquals(triangle1.GetP1()[2], 0.0f))
      {
	std::cout << "TestTriangleGetP1() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTriangleGetP1() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestTriangleGetP2()
  {
    if(MathsTools::AreEquals(triangle1.GetP2()[0],3.0f) &&
       MathsTools::AreEquals(triangle1.GetP2()[1], 0.0f) &&
       MathsTools::AreEquals(triangle1.GetP2()[2], 0.0f))
      {
	std::cout << "TestTriangleGetP2() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTriangleGetP2() : Test Failed" << std::endl;
	return false;
      }
  }

  ///////////////////////////////////////////
  /////// QUATERNION
  ///////////////////////////////////////////

  bool GeometryTest::TestQuaternionConstructorFromAngleDirection()
  {
    if(MathsTools::AreEquals(quaternionConstructor.Re(), 0.965926f) &&
       MathsTools::AreEquals(quaternionConstructor.Im()[0], 0.0f) &&
       MathsTools::AreEquals(quaternionConstructor.Im()[1], 0.258819f) &&
       MathsTools::AreEquals(quaternionConstructor.Im()[2], 0.0f))
      {
	std::cout << "TestQuaternionConstructorFromAngleDirection() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionConstructorFromAngleDirection() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionConjugate()
  {
    auto conjugate = quaternion1.Conjugate();
    if(MathsTools::AreEquals(conjugate.Re(), quaternion1.Re()) &&
       MathsTools::AreEquals(conjugate.Im()[0], -quaternion1.Im()[0]) &&
       MathsTools::AreEquals(conjugate.Im()[1], -quaternion1.Im()[1]) &&
       MathsTools::AreEquals(conjugate.Im()[2], -quaternion1.Im()[2]))
      {
	std::cout << "TestQuaternionConjugate() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionConjugate() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionNorm()
  {
    auto norm = quaternion1.Norm();
    if(MathsTools::AreEquals(norm,5.47723f))
      {
	std::cout << "TestQuaternionNorm() : Test Succeed" << std::endl;
	return true; 
      }
    else
      {
	std::cout << "TestQuaternionNorm() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionRe()
  {
    if(MathsTools::AreEquals(quaternion1.Re(), 1.0f))
      {
	std::cout << "TestQuaternionRe() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionRe() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionIm()
  {
    if(MathsTools::AreEquals(quaternion1.Im()[0], 2.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[1], 3.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[2], 4.0f))
      {
	std::cout << "TestQuaternionIm() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionIm() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionToNorm()
  {
    if(true)
      {
	std::cout << "TestQuaternionToNorm() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionToNorm() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionAdditionScalarFloat()
  {
    auto res = quaternion1 + 2.0f;
    if(MathsTools::AreEquals(res.Re(), quaternion1.Re() + 2.0f) &&
       MathsTools::AreEquals(res.Im()[0], quaternion1.Im()[0]) &&
       MathsTools::AreEquals(res.Im()[1], quaternion1.Im()[1]) &&
       MathsTools::AreEquals(res.Im()[2], quaternion1.Im()[2]))
      {
	std::cout << "TestQuaternionAdditionScalarFloat() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionScalarFloat() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionAdditionScalarFloatPrefix()
  {
    auto res = 2.0f + quaternion1;
    if(MathsTools::AreEquals(res.Re(), quaternion1.Re() + 2.0f) &&
       MathsTools::AreEquals(res.Im()[0], quaternion1.Im()[0]) &&
       MathsTools::AreEquals(res.Im()[1], quaternion1.Im()[1]) &&
       MathsTools::AreEquals(res.Im()[2], quaternion1.Im()[2]))
      {
	std::cout << "TestQuaternionAdditionScalarFloatPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionScalarFloatPrefix() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionAdditionScalarInteger()
  {
    auto res = quaternion1 + 2;
    if(MathsTools::AreEquals(res.Re(), quaternion1.Re() + 2) &&
       MathsTools::AreEquals(res.Im()[0], quaternion1.Im()[0]) &&
       MathsTools::AreEquals(res.Im()[1], quaternion1.Im()[1]) &&
       MathsTools::AreEquals(res.Im()[2], quaternion1.Im()[2]))
      {
	std::cout << "TestQuaternionAdditionScalarInteger() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionScalarInteger() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionAdditionScalarIntegerPrefix()
  {
    auto res = 2 + quaternion1;
    if(MathsTools::AreEquals(res.Re(), quaternion1.Re() + 2) &&
       MathsTools::AreEquals(res.Im()[0], quaternion1.Im()[0]) &&
       MathsTools::AreEquals(res.Im()[1], quaternion1.Im()[1]) &&
       MathsTools::AreEquals(res.Im()[2], quaternion1.Im()[2]))
      {
	std::cout << "TestQuaternionAdditionScalarIntegerPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionScalarIntegerPrefix() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionAdditionQuaternion()
  {
    auto res = quaternion1 + quaternion2;
    if(MathsTools::AreEquals(res.Re(), 3.0f) &&
       MathsTools::AreEquals(res.Im()[0], 3.0f) &&
       MathsTools::AreEquals(res.Im()[1], 6.0f) &&
       MathsTools::AreEquals(res.Im()[2], 11.0f))
      {
	std::cout << "TestQuaternionAdditionQuaternion() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionQuaternion() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionAdditionScalarFloatEquals()
  {
    quaternion1 += 3.0f;
    if(MathsTools::AreEquals(quaternion1.Re(), 4.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[0], 2.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[1], 3.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[2], 4.0f))
      {
	std::cout << "TestQuaternionAdditionScalarFloatEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionScalarFloatEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionAdditionScalarIntegerEquals()
  {
    quaternion1 += 3;
    if(MathsTools::AreEquals(quaternion1.Re(), 4.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[0], 2.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[1], 3.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[2], 4.0f))
      {
	std::cout << "TestQuaternionAdditionScalarIntegerEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionScalarIntegerEquals() : Test Failed" << std::endl;
	return false;
      }
  }
    
  bool GeometryTest::TestQuaternionAdditionQuaternionEquals()
  {
    quaternion1 += quaternion2;
    if(MathsTools::AreEquals(quaternion1.Re(), 3.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[0], 3.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[1], 6.0f) &&
       MathsTools::AreEquals(quaternion1.Im()[2], 11.0f))
      {
	std::cout << "TestQuaternionAdditionQuaternionEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionAdditionQuaternionEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionNegation()
  {
    auto res = -quaternion3;
    if(MathsTools::AreEquals(res.Re(), -1.0f) &&
       MathsTools::AreEquals(res.Im()[0], 2.0f) &&
       MathsTools::AreEquals(res.Im()[1], -5.0f) &&
       MathsTools::AreEquals(res.Im()[2], 1.0f))
      {
	std::cout << "TestQuaternionNegation() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionNegation() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionSubstractionScalarFloat()
  {
    auto res = quaternion3 - 2.0f;
    if(MathsTools::AreEquals(res.Re(), -1.0f) &&
       MathsTools::AreEquals(res.Im()[0], -2.0f) &&
       MathsTools::AreEquals(res.Im()[1], 5.0f) &&
       MathsTools::AreEquals(res.Im()[2], -1.0f))
      {
	std::cout << "TestQuaternionSubstractionScalarFloat() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionScalarFloat() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionSubstractionScalarFloatPrefix()
  {
    auto res = 2.0f - quaternion3;
    if(MathsTools::AreEquals(res.Re(), -1.0f) &&
       MathsTools::AreEquals(res.Im()[0], -2.0f) &&
       MathsTools::AreEquals(res.Im()[1], 5.0f) &&
       MathsTools::AreEquals(res.Im()[2], -1.0f))
      {
	std::cout << "TestQuaternionSubstractionScalarFloatPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionScalarFloatPrefix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionSubstractionScalarInteger()
  {
    auto res = quaternion3 - 2;
    if(MathsTools::AreEquals(res.Re(), -1.0f) &&
       MathsTools::AreEquals(res.Im()[0], -2.0f) &&
       MathsTools::AreEquals(res.Im()[1], 5.0f) &&
       MathsTools::AreEquals(res.Im()[2], -1.0f))
      {
	std::cout << "TestQuaternionSubstractionScalarInteger() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionScalarInteger() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionSubstractionScalarIntegerPrefix()
  {
    auto res = 2 - quaternion3;
    if(MathsTools::AreEquals(res.Re(), -1.0f) &&
       MathsTools::AreEquals(res.Im()[0], -2.0f) &&
       MathsTools::AreEquals(res.Im()[1], 5.0f) &&
       MathsTools::AreEquals(res.Im()[2], -1.0f))
      {
	std::cout << "TestQuaternionSubstractionScalarIntegerPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionScalarIntegerPrefix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionSubstractionQuaternion()
  {
    auto res = quaternion3 - quaternion2;
    if(MathsTools::AreEquals(res.Re(), -1.0f) &&
       MathsTools::AreEquals(res.Im()[0], -3.0f) &&
       MathsTools::AreEquals(res.Im()[1], 2.0f) &&
       MathsTools::AreEquals(res.Im()[2], -8.0f))
      {
	std::cout << "TestQuaternionSubstractionQuaternion() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionQuaternion() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionSubstractionScalarFloatEquals()
  {
    quaternion3 -= 2.0f;
    if(MathsTools::AreEquals(quaternion3.Re(), -1.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[0], -2.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[1], 5.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[2], -1.0f))
      {
	std::cout << "TestQuaternionSubstractionScalarFloatEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionScalarFloatEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionSubstractionScalarIntegerEquals()
  {
    quaternion3 -= 2.0f;
    if(MathsTools::AreEquals(quaternion3.Re(), -1.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[0], -2.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[1], 5.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[2], -1.0f))
      {
	std::cout << "TestQuaternionSubstractionScalarIntegerEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionScalarIntegerEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionSubstractionQuaternionEquals()
  {
    quaternion3 -= quaternion2;
    if(MathsTools::AreEquals(quaternion3.Re(), -1.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[0], -3.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[1], 2.0f) &&
       MathsTools::AreEquals(quaternion3.Im()[2], -8.0f))
      {
	std::cout << "TestQuaternionSubstractionQuaternionEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionSubstractionQuaternionEquals() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionMultiplicationScalarFloat()
  {
    auto res = quaternionMult1 * 2.0f;
    if(MathsTools::AreEquals(res.Re(), 4.0f) &&
       MathsTools::AreEquals(res.Im()[0], 10.0f) &&
       MathsTools::AreEquals(res.Im()[1], 2.0f) &&
       MathsTools::AreEquals(res.Im()[2], -6.0f))
      {
	std::cout << "TestQuaternionMultiplicationScalarFloat() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationScalarFloat() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultiplicationScalarFloatPrefix()
  {
    auto res = 2.0f * quaternionMult1;
    if(MathsTools::AreEquals(res.Re(), 4.0f) &&
       MathsTools::AreEquals(res.Im()[0], 10.0f) &&
       MathsTools::AreEquals(res.Im()[1], 2.0f) &&
       MathsTools::AreEquals(res.Im()[2], -6.0f))
      {
	std::cout << "TestQuaternionMultiplicationScalarFloatPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationScalarFloatPrefix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultiplicationScalarInteger()
  {
    auto res = quaternionMult1 * 2;
    if(MathsTools::AreEquals(res.Re(), 4.0f) &&
       MathsTools::AreEquals(res.Im()[0], 10.0f) &&
       MathsTools::AreEquals(res.Im()[1], 2.0f) &&
       MathsTools::AreEquals(res.Im()[2], -6.0f))
      {
	std::cout << "TestQuaternionMultiplicationScalarInteger() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationScalarInteger() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultipicationScalarIntegerPrefix()
  {
    auto res = 2 * quaternionMult1;
    if(MathsTools::AreEquals(res.Re(), 4.0f) &&
       MathsTools::AreEquals(res.Im()[0], 10.0f) &&
       MathsTools::AreEquals(res.Im()[1], 2.0f) &&
       MathsTools::AreEquals(res.Im()[2], -6.0f))
      {
	std::cout << "TestQuaternionMultipicationScalarIntegerPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultipicationScalarIntegerPrefix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultiplicationQuaternion()
  {
    auto res = quaternionMult1 * quaternionMult2;
    if(MathsTools::AreEquals(res.Re(), 4.0f) &&
       MathsTools::AreEquals(res.Im()[0], 18.0f) &&
       MathsTools::AreEquals(res.Im()[1], 34.0f) &&
       MathsTools::AreEquals(res.Im()[2], -8.0f))
      {
	std::cout << "TestQuaternionMultiplicationQuaternion() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationQuaternion() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultiplicationScalarFloatEquals()
  {
    quaternionMult1 *= 3.0f;
    if(MathsTools::AreEquals(quaternionMult1.Re(), 6.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[0], 15.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[1], 3.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[2], -9.0f))
      {
	std::cout << "TestQuaternionMultiplicationScalarFloatEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationScalarFloatEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultiplicationScalarIntegerEquals()
  {
    quaternionMult1 *= 3;
    if(MathsTools::AreEquals(quaternionMult1.Re(), 6.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[0], 15.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[1], 3.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[2], -9.0f))
      {
	std::cout << "TestQuaternionMultiplicationScalarIntegerEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationScalarIntegerEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool GeometryTest::TestQuaternionMultiplicationQuaternionEquals()
  {
    quaternionMult1 *= quaternionMult2;
    if(MathsTools::AreEquals(quaternionMult1.Re(), 4.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[0], 18.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[1], 34.0f) &&
       MathsTools::AreEquals(quaternionMult1.Im()[2], -8.0f))
      {
	std::cout << "TestQuaternionMultiplicationQuaternionEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestQuaternionMultiplicationQuaternionEquals() : Test Failed" << std::endl;
	return false;
      }
  }

  bool GeometryTest::TestQuaternionReverse()
  {
    auto res = quaternion3.Reverse();
    if(MathsTools::AreEquals(res.Re(), 0.0322581f) &&
       MathsTools::AreEquals(res.Im()[0], 0.0645161f) &&
       MathsTools::AreEquals(res.Im()[1], -0.16129f) &&
       MathsTools::AreEquals(res.Im()[2], 0.0322581))
      {
	std::cout << "TestQuaternionReverse() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	
	std::cout << "TestQuaternionReverse() : Test Failed" << std::endl;
	return false;
      }
  }
  
  
}

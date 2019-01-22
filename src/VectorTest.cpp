#include <iostream>
#include <cmath>

#include "VectorTest.hpp"
#include "MathsTools.hpp"

namespace om
{
  Vector<2,float> VectorTest::unit;
  Vector<3,float> VectorTest::ortho1;
  Vector<3,float> VectorTest::ortho2;
  Vector<3,float> VectorTest::vector1;
  Vector<3,float> VectorTest::vector2;
  Vector<2,float> VectorTest::vector3;
  Vector<4,float> VectorTest::vector4;
  Vector<4,float> VectorTest::vector5;
  Vector<2,std::string> VectorTest::vector6;
  
  void VectorTest::Init()
  { 
    unit[0] = 1.0f / sqrt(2);
    unit[1] = -(1.0f / sqrt(2));
    
    ortho1[0] = 1.0f;
    ortho1[1] = 0.0f;
    ortho1[2] = -1.0f;

    ortho2[0] = 1.0f;
    ortho2[1] = sqrt(2);
    ortho2[2] = 1.0f;
    
    vector1[0] = 1.0f;
    vector1[1] = 2.0f;
    vector1[2] = 3.0f;

    vector2[0] = 4.0f;
    vector2[1] = 5.0f;
    vector2[2] = 6.0f;

    vector3[0] = 7.0f;
    vector3[1] = 8.0f;
    
    vector4[0] = 9.0f;
    vector4[1] = 10.0f;
    vector4[2] = 11.0f;
    vector4[3] = 12.0f;

    vector5[0] = 13.0f;
    vector5[1] = 14.0f;
    vector5[2] = 15.0f;
    vector5[3] = 16.0f;
    
    vector6[0] = "1";
    vector6[1] = "2";
   
  }
  
  bool VectorTest::StartTest()
  {
    std::cout << "=================================" << std::endl;
    std::cout << "Running test for Vector<N,T> ..." << std::endl;
    std::cout << "---------------------------------"<< std::endl;

    bool testResult = true;
    Init();
    testResult &= TestLength();
    Init();
    testResult &= TestAt();
    Init();
    testResult &= TestAtException();
    Init();
    testResult &= TestOperatorHook();
    Init();
    testResult &= TestDotProduct();
    Init();
    testResult &= TestCrossProduct();
    Init();
    testResult &= TestCrossProductException();
    Init();
    testResult &= TestNorm();
    Init();
    testResult &= TestToUnit();
    Init();
    testResult &= TestIsOrtho();
    Init();
    testResult &= TestIsNull();
    Init();
    testResult &= TestIsNotNull();
    Init();
    testResult &= TestIsUnit();
    Init();
    testResult &= TestOperatorPlus();
    Init();
    testResult &= TestOperatorPlusEquals();
    Init();
    testResult &= TestOperatorPlusException();
    Init();
    testResult &= TestOperatorPlusEqualsException();
    Init();
    testResult &= TestOperatorMinusUnit();
    Init();
    testResult &= TestOperatorMinus();
    Init();
    testResult &= TestOperatorMinusEquals();
    Init();
    testResult &= TestOperatorMinusException();
    Init();
    testResult &= TestOperatorMinusEqualsException();
    Init();
    testResult &= TestOperatorTimeScalar();
    Init();
    testResult &= TestOperatorTime();
    Init();
    testResult &= TestOperatorTimeException();
    Init();
    testResult &= TestOperatorTimeScalarEquals();
    Init();
    testResult &= TestOperatorTimeEquals();
    Init();
    testResult &= TestOperatorTimeEqualsException();
    Init();
    testResult &= TestOperatorTimeScalarPrefix();
    
    std::cout << "---------------------------------"<< std::endl;
    if(testResult)
      {
	std::cout << "Test for Vector<N,T> passed with success" << std::endl;
      }
    else
      {
	std::cout << "Test for Vector<N,T> failed" << std::endl;
      }
    
    std::cout << "=================================" << std::endl;
    return testResult;
  }

  bool VectorTest::TestLength()
  {
    if(vector1.Length() == 3 && vector3.Length() == 2)
      {
	std::cout << "TestLength() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestLength() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestAt()
  {
    if(MathsTools::AreEquals(vector1.At(0),1.0f) &&
       MathsTools::AreEquals(vector2.At(0),4.0f))
      {
	std::cout << "TestAt() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestAt() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestAtException()
  {
    try
      {
	vector3.At(3);
	std::cout << "TestAtException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestAtException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool VectorTest::TestOperatorHook()
  {
    if(MathsTools::AreEquals(vector1[0],1.0f) &&
       MathsTools::AreEquals(vector4[0],9.0f))
      {
	std::cout << "TestOperator[]() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperator[]() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestDotProduct()
  {
    if(MathsTools::AreEquals(vector4.DotProduct(vector5),614.0f) &&
       MathsTools::AreEquals(unit.DotProduct(vector3),-(1.0f/sqrt(2))))
      {
	std::cout << "TestDotProduct() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotProduct() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestCrossProduct()
  {
    const auto answer = vector1.CrossProduct(vector2);
    if(answer.At(0) == -3 && answer.At(1) == 6 && answer.At(2) == -3)
      {
	std::cout << "TestCrossProduct() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestCrossProduct() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestCrossProductException()
  {
    try
      {
        vector4.CrossProduct(vector5);
	std::cout << "TestCrossProductException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestCrossProductExcepton() : Test Succeed" << std::endl;
	return true;
	}
  }
  
  bool VectorTest::TestNorm()
  {
    if(MathsTools::AreEquals(vector1.Norm(),sqrt(14.0f)) &&
       MathsTools::AreEquals(vector5.Norm(),3*sqrt(94.0f)))
      {
	std::cout << "TestNorm() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestNorm() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestToUnit()
  {
    auto toUnit = vector5.ToUnit();
    float x = (13.0f) / (3.0f * sqrt(94));
    float y = (7.0f * sqrt(2)) / (3.0f * sqrt(47));
    float z = (5.0f) / (sqrt(94));
    float w = (8.0f * sqrt(2)) / (3.0f * sqrt(47));
    
    if(MathsTools::AreEquals(toUnit.At(0), x) &&
       MathsTools::AreEquals(toUnit.At(1), y) &&
       MathsTools::AreEquals(toUnit.At(2), z) &&
       MathsTools::AreEquals(toUnit.At(3), w))
      {
	std::cout << "TestToUnit() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestToUnit() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestIsOrtho()
  {
    if(ortho1.IsOrtho(ortho2))
      {
	std::cout << "TestIsOrtho() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestIsOrtho() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestIsNull()
  {
    if(vector6.IsNull())
      {
	std::cout << "TestIsNull() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestIsNull() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestIsNotNull()
  {
    if(vector1.IsNull())
      {
	std::cout << "TestIsNotNull() : Test Failed" << std::endl;
	return false;
      }
    else
      {
	std::cout << "TestIsNotNull() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool VectorTest::TestIsUnit()
  {
    if(unit.IsUnit())
      {
	std::cout << "TestIsUnit() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestIsUnit() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestOperatorPlus()
  {
    auto plus = vector1 + vector2;
    if(MathsTools::AreEquals(plus.At(0),5.0f) &&
       MathsTools::AreEquals(plus.At(1),7.0f) &&
       MathsTools::AreEquals(plus.At(2),9.0f))
      {
	std::cout << "TestOperatorPlus() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorPlus() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestOperatorPlusEquals()
  {
    vector1 += vector2;
    if(MathsTools::AreEquals(vector1.At(0),5.0f) &&
       MathsTools::AreEquals(vector1.At(1),7.0f) &&
       MathsTools::AreEquals(vector1.At(2),9.0f))
      {
	std::cout << "TestOperatorPlusEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorPlusEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestOperatorMinusUnit()
  {
    auto minusUnit = -vector4;
    if(MathsTools::AreEquals(minusUnit.At(0),-9.0f) &&
       MathsTools::AreEquals(minusUnit.At(1),-10.0f) &&
       MathsTools::AreEquals(minusUnit.At(2),-11.0f) &&
       MathsTools::AreEquals(minusUnit.At(3),-12.0f))
      {
	std::cout << "TestOperatorMinusUnit() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorMinusUnit() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestOperatorMinus()
  {
    auto minus = vector4 - vector5;
    if(MathsTools::AreEquals(minus.At(0),-4.0f) &&
       MathsTools::AreEquals(minus.At(1),-4.0f) &&
       MathsTools::AreEquals(minus.At(2),-4.0f) &&
       MathsTools::AreEquals(minus.At(3),-4.0f))
      {
	std::cout << "TestOperatorMinus() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorMinus() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestOperatorMinusEquals()
  {
    vector5 -= vector4;
    if(MathsTools::AreEquals(vector5.At(0),4.0f) &&
       MathsTools::AreEquals(vector5.At(1),4.0f) &&
       MathsTools::AreEquals(vector5.At(2),4.0f) &&
       MathsTools::AreEquals(vector5.At(3),4.0f))
      {
	std::cout << "TestOperatorMinusEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorMinusEquals() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestOperatorTimeScalar()
  {
    auto timeScalar = vector1 * 3;
    if(MathsTools::AreEquals(timeScalar.At(0),3.0f) &&
       MathsTools::AreEquals(timeScalar.At(1),6.0f) &&
       MathsTools::AreEquals(timeScalar.At(2),9.0f))
      {
	std::cout << "TestOperatorTimeScalar() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeScalar() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestOperatorTime()
  {
    auto time = vector1 * vector2;
    if(MathsTools::AreEquals(time.At(0), -3.0f) &&
       MathsTools::AreEquals(time.At(1), 6.0f) &&
       MathsTools::AreEquals(time.At(2), -3.0f))
      {
	std::cout << "TestOperatorTime() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTime() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestOperatorTimeScalarEquals() 
  {
    vector1 *= 3;
    if(MathsTools::AreEquals(vector1.At(0),3.0f) &&
       MathsTools::AreEquals(vector1.At(1),6.0f) &&
       MathsTools::AreEquals(vector1.At(2),9.0f))
      {
	std::cout << "TestOperatorTimeScalarEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeScalarEquals() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestOperatorTimeEquals()
  {
    vector1 *= vector2;
    if(MathsTools::AreEquals(vector1.At(0), -3.0f) &&
       MathsTools::AreEquals(vector1.At(1), 6.0f) &&
       MathsTools::AreEquals(vector1.At(2), -3.0f))
      {
	std::cout << "TestOperatorTimeEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeEquals() : Test Failed" << std::endl;
	return false;
      }
  }

  bool VectorTest::TestOperatorTimeScalarPrefix()
  {
    auto timeScalar = 3 * vector1;
    auto timeScalar2 = 3.0f * vector1;
    if(MathsTools::AreEquals(timeScalar.At(0),3.0f) &&
       MathsTools::AreEquals(timeScalar.At(1),6.0f) &&
       MathsTools::AreEquals(timeScalar.At(2),9.0f) &&
       MathsTools::AreEquals(timeScalar2.At(0),3.0f) &&
       MathsTools::AreEquals(timeScalar2.At(1),6.0f) &&
       MathsTools::AreEquals(timeScalar2.At(2),9.0f))
      {
	std::cout << "TestOperatorTimeScalarPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeScalarPrefix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool VectorTest::TestOperatorPlusException()
  {
    try
      {
	vector1 + vector3;
	std::cout << "TestOperatorPlusException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorPlusException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool VectorTest::TestOperatorPlusEqualsException()
  {
    try
      {
	vector1 += vector3;
	std::cout << "TestOperatorPlusEqualsException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorPlusEqualsException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool VectorTest::TestOperatorMinusException()
  {
    try
      {
	vector1 - vector3;
	std::cout << "TestOperatorMinusException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorMinusException() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool VectorTest::TestOperatorMinusEqualsException()
  {
    try
      {
	vector1 -= vector3;
	std::cout << "TestOperatorMinusEqualsException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorMinusEqualsException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool VectorTest::TestOperatorTimeException()
  {
    try
      {
	ortho1 * vector3;
	std::cout << "TestOperatorTimeException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorTimeException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool VectorTest::TestOperatorTimeEqualsException()
  {
    try
      {
	ortho1 *= vector3;
	std::cout << "TestOperatorTimeEqualsException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorTimeEqualsException() : Test Succeed" << std::endl;
	return true;
      }
  }
}

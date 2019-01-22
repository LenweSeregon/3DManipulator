#include "MatrixTest.hpp"
#include "MathsTools.hpp"

namespace om
{

  Vector<3,float> MatrixTest::vector1;
  Vector<2,float> MatrixTest::vector2;
  Matrix<float,3,3> MatrixTest::ortho;
  Matrix<float,3,3> MatrixTest::noReverse;
  Matrix<float,3,3> MatrixTest::reverse;
  Matrix<float,2,3> MatrixTest::mult1;
  Matrix<float,3,2> MatrixTest::mult2;
  Matrix<float,2,2> MatrixTest::add1;
  Matrix<float,2,2> MatrixTest::add2;
  Matrix<std::string,1,1> MatrixTest::asString;
  
  void MatrixTest::Init()
  {
    ortho[0][0] = 1.0f;
    ortho[0][1] = 0.0f;
    ortho[0][2] = 0.0f;
    ortho[1][0] = 0.0f;
    ortho[1][1] = 1.0f;
    ortho[1][2] = 0.0f;
    ortho[2][0] = 0.0f;
    ortho[2][1] = 0.0f;
    ortho[2][2] = -1.0f;
    
    vector1[0] = 1.0f;
    vector1[1] = 2.0f;
    vector1[2] = 3.0f;

    vector2[0] = 2.0f;
    vector2[1] = 4.0f;
    
    asString[0][0] = "salut";
    
    reverse[0][0] = 2.0f;
    reverse[0][1] = 3.0f;
    reverse[0][2] = 8.0f;
    reverse[1][0] = 6.0f;
    reverse[1][1] = 0.0f;
    reverse[1][2] = -3.0f;
    reverse[2][0] = -1.0f;
    reverse[2][1] = 3.0f;
    reverse[2][2] = 2.0f;

    noReverse[0][0] = 2.0f;
    noReverse[0][1] = 1.0f;
    noReverse[0][2] = 0.0f;
    noReverse[1][0] = -1.0f;
    noReverse[1][1] = 2.0f;
    noReverse[1][2] = 3.0f;
    noReverse[2][0] = 0.0f;
    noReverse[2][1] = 5.0f;
    noReverse[2][2] = 6.0f;

    mult1[0][0] = 2.0f;
    mult1[0][1] = -8.0f;
    mult1[0][2] = 4.0f;
    mult1[1][0] = 2.0f;
    mult1[1][1] = -3.0f;
    mult1[1][2] = 1.0f;

    mult2[0][0] = 7.0f;
    mult2[0][1] = 9.0f;
    mult2[1][0] = 6.0f;
    mult2[1][1] = 3.0f;
    mult2[2][0] = 4.0f;
    mult2[2][1] = -1.0f;

    add1[0][0] = 1.0f;
    add1[0][1] = 2.0f;
    add1[1][0] = 3.0f;
    add1[1][1] = 4.0f;

    add2[0][0] = 1.0f;
    add2[0][1] = 2.0f;
    add2[1][0] = 3.0f;
    add2[1][1] = 4.0f;
  }

  bool MatrixTest::StartTest()
  {
    std::cout << "=================================" << std::endl;
    std::cout << "Running test for Matrix<T,N,M> ..." << std::endl;
    std::cout << "---------------------------------"<< std::endl;

    bool testResult = true;
    Init();
    testResult &= TestAt();
    Init();
    testResult &= TestAtException();
    Init();
    testResult &= TestOperatorHook();
    Init();
    testResult &= TestIsOrtho();
    Init();
    testResult &= TestIsNull();
    Init();
    testResult &= TestReverse();
    Init();
    testResult &= TestReverseImpossible();
    Init();
    testResult &= TestTranspose();
    Init();
    testResult &= TestOperatorAdd();
    Init();
    testResult &= TestOperatorAddEquals();
    Init();
    testResult &= TestOperatorTimeScalar();
    Init();
    testResult &= TestOperatorTimeScalarPrefix();
    Init();
    testResult &= TestOperatorTimeScalarEquals();
    Init();
    testResult &= TestOperatorTimeVector();
    Init();
    testResult &= TestOperatorTimeVectorException();
    Init();
    testResult &= TestOperatorTimeVectorPrefix();
    Init();
    testResult &= TestOperatorTimeVectorPrefixException();
    Init();
    testResult &= TestOperatorTimeMatrix();
    Init();
    testResult &= TestOperatorTimeMatrixException();
    Init();
    testResult &= TestOperatorTimeMatrixEquals();
    Init();
    testResult &= TestOperatorTimeMatrixEqualsException();
    
    std::cout << "---------------------------------"<< std::endl;
    if(testResult)
      {
	std::cout << "Test for Matrix<T,N,M> passed with success" << std::endl;
      }
    else
      {
	std::cout << "Test for Vector<T,N,M> failed" << std::endl;
      }
    
    std::cout << "=================================" << std::endl;
    return testResult;
  }

  bool MatrixTest::TestAt()
  {
    if(MathsTools::AreEquals(mult1.At(0,1),-8.0f) &&
       MathsTools::AreEquals(reverse.At(2,2), 2.0f))
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

  bool MatrixTest::TestAtException()
  {
    try
      {
	mult1.At(3,3);
	std::cout << "TestAtException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestAtException() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool MatrixTest::TestOperatorHook()
  {
    if(MathsTools::AreEquals(mult1[1][2],1.0f) &&
       MathsTools::AreEquals(mult2[1][1],3.0f))
      {
	std::cout << "TestOperatorHook() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorHook() : Test Failed" << std::endl;
	return false;
      }
  }

  bool MatrixTest::TestIsOrtho()
  {
    if(!mult1.IsOrtho() && ortho.IsOrtho())
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

  bool MatrixTest::TestIsNull()
  {
    if(asString.IsNull() && !reverse.IsNull())
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

  bool MatrixTest::TestReverse()
  {
    auto rev = reverse.Reverse();
    if(MathsTools::AreEquals(rev[0][0],3.0f / 45.0f) &&
       MathsTools::AreEquals(rev[0][1],6.0f / 45.0f) &&
       MathsTools::AreEquals(rev[0][2],-3.0f / 45.0f) &&
       MathsTools::AreEquals(rev[1][0],-3.0f / 45.0f) &&
       MathsTools::AreEquals(rev[1][1],4.0f / 45.0f) &&
       MathsTools::AreEquals(rev[1][2],18.0f / 45.0f) &&
       MathsTools::AreEquals(rev[2][0],6.0f / 45.0f) &&
       MathsTools::AreEquals(rev[2][1],-3.0f / 45.0f) &&
       MathsTools::AreEquals(rev[2][2],-6.0f / 45.0f))
      {
	std::cout << "TestReverse() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestReverse() : Test Failed" << std::endl;
	return false;
      }
  }

  bool MatrixTest::TestReverseImpossible()
  {
    try
      {
	noReverse.Reverse();
	std::cout << "TestReverseImpossible() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestReverseImpossible() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool MatrixTest::TestTranspose()
  {
    auto transpose = mult1.Transpose();
    if(MathsTools::AreEquals(transpose[0][0],2.0f) &&
       MathsTools::AreEquals(transpose[0][1],2.0f) &&
       MathsTools::AreEquals(transpose[1][0],-8.0f) &&
       MathsTools::AreEquals(transpose[1][1],-3.0f) &&
       MathsTools::AreEquals(transpose[2][0],4.0f) &&
       MathsTools::AreEquals(transpose[2][1],1.0f))
      {
	std::cout << "TestTranspose() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestTranspose() : Test Failed" << std::endl;
	return false;
      }
  }

  bool MatrixTest::TestOperatorAdd()
  {
    auto add = add1 + add2;
    if(MathsTools::AreEquals(add[0][0],2.0f) &&
       MathsTools::AreEquals(add[0][1],4.0f) &&
       MathsTools::AreEquals(add[1][0],6.0f) &&
       MathsTools::AreEquals(add[1][1],8.0f))
      {
	std::cout << "TestOperatorAdd() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorAdd() : Test failed" << std::endl;
	return false;
      }
  }

  bool MatrixTest::TestOperatorAddEquals()
  {
    add1 += add2;
    if(MathsTools::AreEquals(add1[0][0],2.0f) &&
       MathsTools::AreEquals(add1[0][1],4.0f) &&
       MathsTools::AreEquals(add1[1][0],6.0f) &&
       MathsTools::AreEquals(add1[1][1],8.0f))
      {
	std::cout << "TestOperatorAddEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorAddEquals() : Test failed" << std::endl;
	return false;
      }    
  }

  bool MatrixTest::TestOperatorTimeScalar()
  {
    auto scalarMat = add1 * 2;
    auto scalarMat2 = add1 * 2.0f;
    if(MathsTools::AreEquals(scalarMat[0][0], 2.0f) &&
       MathsTools::AreEquals(scalarMat[0][1], 4.0f) &&
       MathsTools::AreEquals(scalarMat[1][0], 6.0f) &&
       MathsTools::AreEquals(scalarMat[1][1], 8.0f) &&
       MathsTools::AreEquals(scalarMat2[0][0], 2.0f) &&
       MathsTools::AreEquals(scalarMat2[0][1], 4.0f) &&
       MathsTools::AreEquals(scalarMat2[1][0], 6.0f) &&
       MathsTools::AreEquals(scalarMat2[1][1], 8.0f))
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

  bool MatrixTest::TestOperatorTimeScalarPrefix()
  {
    auto scalarMat = 2.0f * add2;
    auto scalarMat2 = 2 * add2;
    
    if(MathsTools::AreEquals(scalarMat[0][0], 2.0f) &&
       MathsTools::AreEquals(scalarMat[0][1], 4.0f) &&
       MathsTools::AreEquals(scalarMat[1][0], 6.0f) &&
       MathsTools::AreEquals(scalarMat[1][1], 8.0f) &&
       MathsTools::AreEquals(scalarMat2[0][0], 2.0f) &&
       MathsTools::AreEquals(scalarMat2[0][1], 4.0f) &&
       MathsTools::AreEquals(scalarMat2[1][0], 6.0f) &&
       MathsTools::AreEquals(scalarMat2[1][1], 8.0f))
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

  bool MatrixTest::TestOperatorTimeScalarEquals()
  {
    add1 *= 2.0f;
    add2 *= 2;
    if(MathsTools::AreEquals(add1[0][0], 2.0f) &&
       MathsTools::AreEquals(add1[0][1], 4.0f) &&
       MathsTools::AreEquals(add1[1][0], 6.0f) &&
       MathsTools::AreEquals(add1[1][1], 8.0f) &&
       MathsTools::AreEquals(add2[0][0], 2.0f) &&
       MathsTools::AreEquals(add2[0][1], 4.0f) &&
       MathsTools::AreEquals(add2[1][0], 6.0f) &&
       MathsTools::AreEquals(add2[1][1], 8.0f))
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

  bool MatrixTest::TestOperatorTimeVector()
  {
    auto result = add1 * vector2;
    auto result2 = mult2 * vector2;
    if(MathsTools::AreEquals(result[0],10.0f) &&
       MathsTools::AreEquals(result[1], 22.0f) &&
       MathsTools::AreEquals(result2[0], 50.0f) &&
       MathsTools::AreEquals(result2[1], 24.0f) &&
       MathsTools::AreEquals(result2[2], 4.0f))
      {
	std::cout << "TestOperatorTimeVector() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeVector() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool MatrixTest::TestOperatorTimeVectorException()
  {
    try
      {
	add1 * vector1;
	std::cout << "TestOperatorTimeVectorException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorTimeVectorException() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool MatrixTest::TestOperatorTimeVectorPrefix()
  {
    auto result = vector2 * add1;
    auto result2 = vector2 * mult1;
    if(MathsTools::AreEquals(result[0],14.0f) &&
       MathsTools::AreEquals(result[1], 20.0f) &&
       MathsTools::AreEquals(result2[0], 12.0f) &&
       MathsTools::AreEquals(result2[1], -28.0f) &&
       MathsTools::AreEquals(result2[2], 12.0f))
      {
	std::cout << "TestOperatorTimeVectorPrefix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeVectorPrefix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool MatrixTest::TestOperatorTimeVectorPrefixException()
  {
    try
      {
	vector1 * add1;
	std::cout << "TestOperatorTimeVectorPrefixException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorTimeVectorPrefixException() : Test Succeed" << std::endl;
	return true;
      }
  }
  
  bool MatrixTest::TestOperatorTimeMatrix()
  {
    auto result1 = mult1 * mult2;
    auto result2 = add1 * add2;
    if(MathsTools::AreEquals(result2[0][0],7.0f) &&
       MathsTools::AreEquals(result2[0][1],10.0f) &&
       MathsTools::AreEquals(result2[1][0],15.0f) &&
       MathsTools::AreEquals(result2[1][1],22.0f) &&
       MathsTools::AreEquals(result1[0][0],-18.0f) &&
       MathsTools::AreEquals(result1[0][1],-10.0f) &&
       MathsTools::AreEquals(result1[1][0],0.0f) &&
       MathsTools::AreEquals(result1[1][1],8.0f))
       
      {
	std::cout << "TestOperatorTimeMatrix() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeMatrix() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool MatrixTest::TestOperatorTimeMatrixException()
  {
    try
      {
	mult1 * add1;
	std::cout << "TestOperatorTimeMatrixException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorTimeMatrixException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool MatrixTest::TestOperatorTimeMatrixEquals()
  {
    auto result2 = add1 * add2;
    if(MathsTools::AreEquals(result2[0][0],7.0f) &&
       MathsTools::AreEquals(result2[0][1],10.0f) &&
       MathsTools::AreEquals(result2[1][0],15.0f) &&
       MathsTools::AreEquals(result2[1][1],22.0f))
       
      {
	std::cout << "TestOperatorTimeMatrixEquals() : Test Succeed" << std::endl;
	return true;
      }
    else
      {
	std::cout << "TestOperatorTimeMatrixEquals() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool MatrixTest::TestOperatorTimeMatrixEqualsException()
  {
    try
      {
	mult1 *= mult2;
	std::cout << "TestOperatorTimeMatrixEqualsException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestOperatorTimeMatrixEqualsException() : Test Succeed" << std::endl;
	return true;
      }
  }
}

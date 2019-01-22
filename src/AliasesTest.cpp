#include "AliasesTest.hpp"
#include "MathsTools.hpp"

namespace om
{

  Vec2f AliasesTest::vec0;
  Vec3f AliasesTest::vec1;
  Vec3f AliasesTest::vec2;
  Vec3f AliasesTest::vec3;
  Matrix<float,2,2> AliasesTest::mat0;
  Mat33f AliasesTest::mat1;
  Mat33f AliasesTest::mat2;
  
  void AliasesTest::Init()
  {
    vec0[0] = 2.0f;
    vec0[1] = 1.0f;
    
    vec1[0] = 5.0f;
    vec1[1] = 1.0f;
    vec1[2] = 3.0f;

    vec2[0] = 2.0f;
    vec2[1] = 5.0f;
    vec2[2] = 0.5f;

    mat0[0][0] = 1.0f;
    mat0[0][1] = 4.0f;
    mat0[1][0] = 2.0f;
    mat0[1][1] = 3.0f;

    mat1[0][0] = 5.0f;
    mat1[0][1] = 2.0f;
    mat1[0][2] = 1.0f;
    mat1[1][0] = 3.0f;
    mat1[1][1] = 4.0f;
    mat1[1][2] = 8.0f;
    mat1[2][0] = 11.0f;
    mat1[2][1] = 2.0f;
    mat1[2][2] = 0.0f;

    mat2[0][0] = 4.0f;
    mat2[0][1] = 3.0f;
    mat2[0][2] = 2.0f;
    mat2[1][0] = 7.0f;
    mat2[1][1] = 7.0f;
    mat2[1][2] = 1.0f;
    mat2[2][0] = 2.0f;
    mat2[2][1] = 4.0f;
    mat2[2][2] = 3.0f;
  }

  bool AliasesTest::StartTest()
  {
    std::cout << "=================================" << std::endl;
    std::cout << "Running test for Aliases ..." << std::endl;
    std::cout << "---------------------------------"<< std::endl;

    bool testResult = true;
    Init();
    testResult &= TestCross();
    Init();
    testResult &= TestCrossException();
    Init();
    testResult &= TestDotScalarFloatVector();
    Init();
    testResult &= TestDotScalarIntegerVector();
    Init();
    testResult &= TestDotVectorScalarFloat();
    Init();
    testResult &= TestDotVectorScalarInteger();
    Init();
    testResult &= TestDotScalarFloatMatrix();
    Init();
    testResult &= TestDotScalarIntegerMatrix();
    Init();
    testResult &= TestDotMatrixScalarFloat();
    Init();
    testResult &= TestDotMatrixScalarInteger();
    Init();
    testResult &= TestDotVectorVector();
    Init();
    testResult &= TestDotVectorVectorException();
    Init();
    testResult &= TestDotVectorMatrix();
    Init();
    testResult &= TestDotVectorMatrixException();
    Init();
    testResult &= TestDotMatrixVector();
    Init();
    testResult &= TestDotMatrixVectorException();
    Init();
    testResult &= TestDotMatrixMatrix();
    Init();
    testResult &= TestDotMatrixMatrixException();
    
    std::cout << "---------------------------------"<< std::endl;
    if(testResult)
      {
	std::cout << "Test for Aliases passed with success" << std::endl;
      }
    else
      {
	std::cout << "Test for Aliases failed" << std::endl;
      }
    
    std::cout << "=================================" << std::endl;
    return testResult;
  }

  bool AliasesTest::TestCross()
  {
    auto result = Cross(vec1,vec2);
    if(MathsTools::AreEquals(result[0],-14.5f) &&
       MathsTools::AreEquals(result[1],3.5f) &&
       MathsTools::AreEquals(result[2],23.0f))
      {
	std::cout << "TestCross() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestCross() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestCrossException()
  {
    try
      {
	Cross(vec0,vec3);
	std::cout << "TestCrossException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestCrossException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool AliasesTest::TestDotScalarFloatVector()
  {
    auto result = Dot(2.0f,vec1);
    if(MathsTools::AreEquals(result[0], 10.f) &&
       MathsTools::AreEquals(result[1], 2.0f) &&
       MathsTools::AreEquals(result[2], 6.0f))
      {
	std::cout << "TestDotScalarFloatVector() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotScalarFloatVector() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotScalarIntegerVector()
  {
    auto result = Dot(2,vec1);
    if(MathsTools::AreEquals(result[0], 10.f) &&
       MathsTools::AreEquals(result[1], 2.0f) &&
       MathsTools::AreEquals(result[2], 6.0f))
      {
	std::cout << "TestDotScalarIntegerVector() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotScalarIntegerVector() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool AliasesTest::TestDotVectorScalarFloat() 
  {
    auto result = Dot(vec1,2.0f);
    if(MathsTools::AreEquals(result[0], 10.f) &&
       MathsTools::AreEquals(result[1], 2.0f) &&
       MathsTools::AreEquals(result[2], 6.0f))
      {
	std::cout << "TestDotVectorScalarFloat() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotVectorScalarFloat() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotVectorScalarInteger()
  {
    auto result = Dot(vec1,2);
    if(MathsTools::AreEquals(result[0], 10.f) &&
       MathsTools::AreEquals(result[1], 2.0f) &&
       MathsTools::AreEquals(result[2], 6.0f))
      {
	std::cout << "TestDotVectorScalarInteger() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotVectorScalarInteger() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotScalarFloatMatrix()
  {
    auto result = Dot(2.0f,mat0);
    if(MathsTools::AreEquals(result[0][0], 2.0f) &&
       MathsTools::AreEquals(result[0][1], 8.0f) &&
       MathsTools::AreEquals(result[1][0], 4.0f) &&
       MathsTools::AreEquals(result[1][1], 6.0f))
      {
	std::cout << "TestDotScalarFloatMatrix() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotScalarFloatMatrix() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotScalarIntegerMatrix()
  {
    auto result = Dot(2,mat0);
    if(MathsTools::AreEquals(result[0][0], 2.0f) &&
       MathsTools::AreEquals(result[0][1], 8.0f) &&
       MathsTools::AreEquals(result[1][0], 4.0f) &&
       MathsTools::AreEquals(result[1][1], 6.0f))
      {
	std::cout << "TestDotScalarIntegerMatrix() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotScalarIntegerMatrix() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotMatrixScalarFloat()
  {
    auto result = Dot(mat0, 2.0f);
    if(MathsTools::AreEquals(result[0][0], 2.0f) &&
       MathsTools::AreEquals(result[0][1], 8.0f) &&
       MathsTools::AreEquals(result[1][0], 4.0f) &&
       MathsTools::AreEquals(result[1][1], 6.0f))
      {
	std::cout << "TestDotMatrixScalarFloat() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotMatrixScalarFloat() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotMatrixScalarInteger()
  {
    auto result = Dot(mat0,2);
    if(MathsTools::AreEquals(result[0][0], 2.0f) &&
       MathsTools::AreEquals(result[0][1], 8.0f) &&
       MathsTools::AreEquals(result[1][0], 4.0f) &&
       MathsTools::AreEquals(result[1][1], 6.0f))
      {
	std::cout << "TestDotMatrixScalarInteger() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotMatrixScalarInteger() : Test Failed" << std::endl;
	return false;
      }
  }
  
  bool AliasesTest::TestDotVectorVector()
  {
    auto res = Dot(vec1,vec2);
    if(MathsTools::AreEquals(res,16.5f))
      {
	std::cout << "TestDotVectorVector() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotVectorVector() : Test Failed" << std::endl;
	return false;
      }
  }

  bool AliasesTest::TestDotVectorVectorException()
  {
    try
      {
        Dot(vec0,vec2);
	std::cout << "TestDotVectorVectorException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestDotVectorVectorException() : Test Succeed" << std::endl;
	return true;
      }
  }

  bool AliasesTest::TestDotVectorMatrix()
  {
    auto res = vec0 * mat0;
    if(MathsTools::AreEquals(res[0], 4.0f) &&
       MathsTools::AreEquals(res[1], 11.0f))
      {
	std::cout << "TestDotVectorMatrix() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotVectorMatrix() : Test Failed" << std::endl;
	return false;
      }
  }
    
  bool AliasesTest::TestDotVectorMatrixException()
  {
    try
      {
	vec0 * mat1;
	std::cout << "TestDotVectorMatrixException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestDotVectorMatrixException() : Test Succeed" << std::endl;
	return true;
      }
  }
    
  bool AliasesTest::TestDotMatrixVector()
  {
    auto res = mat0 * vec0;
    if(MathsTools::AreEquals(res[0], 6.0f) &&
       MathsTools::AreEquals(res[1], 7.0f))
      {
	std::cout << "TestDotMatrixVector() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotMatrixVector() : Test Failed" << std::endl;
	return false;
      }
  }
    
  bool AliasesTest::TestDotMatrixVectorException()
  {
    try
      {
	mat0 * vec1;
	std::cout << "TestDotMatrixVectorException() : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestDotMatrixVectorException() : Test Succeed" << std::endl;
	return true;
      }
  }
    
  bool AliasesTest::TestDotMatrixMatrix()
  {
    auto res = Dot(mat1,mat2);
    if(MathsTools::AreEquals(res[0][0], 36.0f) &&
       MathsTools::AreEquals(res[0][1], 33.0f) &&
       MathsTools::AreEquals(res[0][2], 15.0f) &&
       MathsTools::AreEquals(res[1][0], 56.0f) &&
       MathsTools::AreEquals(res[1][1], 69.0f) &&
       MathsTools::AreEquals(res[1][2], 34.0f) &&
       MathsTools::AreEquals(res[2][0], 58.0f) &&
       MathsTools::AreEquals(res[2][1], 47.0f) &&
       MathsTools::AreEquals(res[2][2], 24.0f))
      {
	std::cout << "TestDotMatrixMatrix() : Test Succeed"<< std::endl;
	return true;
      }
    else
      {
	std::cout << "TestDotMatrixMatrix() : Test Failed" << std::endl;
	return false;
      }
  }
    
  bool AliasesTest::TestDotMatrixMatrixException()
  {
    try
      {
	Dot(mat0,mat2);
	std::cout << "TestDotMatrixMatrixException : Test Failed" << std::endl;
	return false;
      }
    catch(const std::invalid_argument& e)
      {
	std::cout << "TestDotMatrixMatrixException() : Test Succeed" << std::endl;
	return true;
      }
  }
}


/**
 * xstring测试用例
 * xstring可以提供将string转换为其他类型，如int,double等
 * @Author : Allen.Wu(allenlikeu@gmail.com)
 * @Date : 2015.05.24
 */
#include <stdio.h>

#include <regex>
#include <sstream>

#include <gtest/gtest.h>
#include <util/xstring.h>

namespace {

  using namespace std;
  
  bool isNumber(const std::string& param)
  {
    if ( param == "" ) return false;

    string rgx = "^[-]{0,1}\\d+[\\.]{0,1}\\d*$";
    regex exp(rgx);
    return regex_match(param, exp);
  }
  
};

//参数化测试，具体参考google test的参数化测试文档
///////////////////////////////////////////////////////////////////
class XStringTranslateInt8 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateInt8, XStringTranslateInt8, testing::Values("0","256","127","128","-127","-128","100","abc"));

TEST_P(XStringTranslateInt8, TranslateInt8)
{
  using namespace std;
  
  int8 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);

  if ( !::isNumber(param) ) {
    param = "0";
  }
  
  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////////
class XStringTranslateUInt8 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateUInt8, XStringTranslateUInt8, testing::Values("0","256","127","128","-127","-128","100","abc"));

TEST_P(XStringTranslateUInt8, TranslateUInt8)
{
  using namespace std;

  uint8 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);

  if ( !::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

////////////////////////////////////////////////////////////////
class XStringTranslateInt16 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateInt16, XStringTranslateInt16, testing::Values("0","-32768","32767","32768","-32769","xyz","1000000"));

TEST_P(XStringTranslateInt16, TranslateInt16)
{
  using namespace std;

  int16 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateUInt16 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateUInt16, XStringTranslateUInt16, testing::Values("0","-1","xyz","65535","65536","65537"));

TEST_P(XStringTranslateUInt16, TranslateUInt16)
{
  using namespace std;

  uint16 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateInt32 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateInt32, XStringTranslateInt32, testing::Values("0","xyz","-1000000000","1000000000","-2200000000","2200000000"));

TEST_P(XStringTranslateInt32, TranslateInt32)
{
  using namespace std;

  int32 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateUInt32 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateUInt32, XStringTranslateUInt32, testing::Values("0","xyz","-1","400000000","4500000000",""));

TEST_P(XStringTranslateUInt32, TranslateUInt32)
{
  using namespace std;

  uint32 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateInt64 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateInt64, XStringTranslateInt64, testing::Values("0","xyz","-1","400000000","4500000000",""));

TEST_P(XStringTranslateInt64, TranslateInt64)
{
  using namespace std;

  int64 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateUInt64 : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateUInt64, XStringTranslateUInt64, testing::Values("0","xyz","-1","400000000","4500000000",""));

TEST_P(XStringTranslateUInt64, TranslateUInt64)
{
  using namespace std;

  uint64 val = 0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateFloat : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateFloat, XStringTranslateFloat, testing::Values("0","xyz","-1","123.123456","-123.1234567",""));

TEST_P(XStringTranslateFloat, TranslateFloat)
{
  using namespace std;

  float val = 0.0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0.0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}

//////////////////////////////////////////////////////////////
class XStringTranslateDouble : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(TranslateDouble, XStringTranslateDouble, testing::Values("0","xyz","-1","123.123456","-123.1234567",""));

TEST_P(XStringTranslateDouble, TranslateDouble)
{
  using namespace std;

  double val = 0.0;
  string param = GetParam();
  XString::getInstance()->translate(param, val);
  
  if ( ::isNumber(param) ) {
    param = "0.0";
  }

  EXPECT_EQ(param, XString::getInstance()->toString(val));
  
}






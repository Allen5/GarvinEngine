
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
  
  int8 val2 = atoi(param.c_str());
  EXPECT_EQ(val2, val);
  
}

class XStringInt8ToString : public ::testing::TestWithParam<int8>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(Int8ToString, XStringInt8ToString, testing::Values(-128, -127, 0, 127, 128));

TEST_P(XStringInt8ToString, Int8ToString)
{
  using namespace std;

  int8 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  //  EXPECT_STREQ(val2.c_str(), val.c_str());
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

  uint8 val2 = atoi(param.c_str());
  EXPECT_EQ(val2, val);
}

class XStringUInt8ToString : public ::testing::TestWithParam<uint8>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(UInt8ToString, XStringUInt8ToString, testing::Values(-128, -127, 0, 127, 128, 255, 256));

TEST_P(XStringUInt8ToString, UInt8ToString)
{
  using namespace std;

  uint8 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  //  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0";
  }

  int16 val2 = atoi(param.c_str());
  EXPECT_EQ(val2, val);
}

class XStringInt16ToString : public ::testing::TestWithParam<int16>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(Int16ToString, XStringInt16ToString, testing::Values(-32768,-32767, 0, 32767, 32768));

TEST_P(XStringInt16ToString, Int16ToString)
{
  using namespace std;

  int16 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0";
  }

  uint16 val2 = atoi(param.c_str());
  EXPECT_EQ(val2, val);
}

class XStringUInt16ToString : public ::testing::TestWithParam<uint16>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(UInt16ToString, XStringUInt16ToString, testing::Values(-1,0,65535,65536,65537));

TEST_P(XStringUInt16ToString, UInt16ToString)
{
  using namespace std;

  uint16 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0";
  }

  int32 val2 = stol(param);
  EXPECT_EQ(val2, val);
}

class XStringInt32ToString : public ::testing::TestWithParam<int32>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(Int32ToString, XStringInt32ToString, testing::Values(-1000000000, 1000000000, -220000000, 2200000000));

TEST_P(XStringInt32ToString, Int32ToString)
{
  using namespace std;

  int32 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0";
  }

  uint32 val2 = stoul(param);
  EXPECT_EQ(val2, val);
}

class XStringUInt32ToString : public ::testing::TestWithParam<uint32>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(UInt32ToString, XStringUInt32ToString, testing::Values(4000000000, 4500000000));

TEST_P(XStringUInt32ToString, UInt32ToString)
{
  using namespace std;

  uint32 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0";
  }

  int64 val2 = stoll(param);
  EXPECT_EQ(val2, val);
}

class XStringInt64ToString : public ::testing::TestWithParam<int64>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(Int64ToString, XStringInt64ToString, testing::Values(4000000000, 4500000000,-1));

TEST_P(XStringInt64ToString, Int64ToString)
{
  using namespace std;

  int64 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0";
  }

  uint64 val2 = stoull(param);
  EXPECT_EQ(val2, val);
}

class XStringUInt64ToString : public ::testing::TestWithParam<uint64>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(UInt64ToString, XStringUInt64ToString, testing::Values(-1, 4000000000, 4500000000));

TEST_P(XStringUInt64ToString, UInt64ToString)
{
  using namespace std;

  uint64 param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss << param;
  ss >> val2;
  ss.clear();

  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0.0";
  }

  float val2 = atof(param.c_str());
  EXPECT_FLOAT_EQ(val2, val);  
}

class XStringFloatToString : public ::testing::TestWithParam<float>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(FloatToString, XStringFloatToString, testing::Values(-123.064, 123.012));

TEST_P(XStringFloatToString, FloatToString)
{
  using namespace std;

  float param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  string val2;
  ss.precision(6);
  ss << param;
  ss >> val2;
  ss.clear();

  //  EXPECT_STREQ(val2.c_str(), val.c_str());
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
  
  if ( !::isNumber(param) ) {
    param = "0.0";
  }

  double val2 = atof(param.c_str());
  EXPECT_DOUBLE_EQ(val2, val);
}

class XStringDoubleToString : public ::testing::TestWithParam<double>
{
  //DO NOTHING
};
INSTANTIATE_TEST_CASE_P(DoubleToString, XStringDoubleToString, testing::Values(-123.456, 123.123));

TEST_P(XStringDoubleToString, DoubleToString)
{
  using namespace std;

  double param = GetParam();
  
  string val = XString::getInstance()->toString(param);

  stringstream ss;
  ss.precision(6);
  ss << param;
  
  string val2(ss.str());
  ss.clear();

  //  EXPECT_STREQ(val2.c_str(), val.c_str());
}






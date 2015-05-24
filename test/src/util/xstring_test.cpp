
/**
 * xstring测试用例
 * xstring可以提供将string转换为其他类型，如int,double等
 * @Author : Allen.Wu(allenlikeu@gmail.com)
 * @Date : 2015.05.24
 */

#include <gtest/gtest.h>
#include <util/xstring.h>
#include <sstream>
#include <regex>

//参数化测试，具体参考google test的参数化测试文档
class XStringTranslateInt8Test : public ::testing::TestWithParam<std::string>
{
  //DO NOTHING
};

INSTANTIATE_TEST_CASE_P(TranslateInt8, XStringTranslateInt8Test, testing::Values("0","256","127","128","-127","-128","100","abc"));

TEST_P(XStringTranslateInt8Test, TranslateInt8)
{
  using namespace std;
  
  int8 val1 = 0;
  
  string param = GetParam();
  string rgx = "^[-]{0,1}\\d+[\\.]{0,1}\\d*$";
  regex exp(rgx);
  if ( regex_match(param, exp) ) {
    stringstream ss;
    ss << param;
    ss >> val1;
    ss.clear();
  }

  int8 val2 = 0;
  XString::getInstance()->translate(param, val2);
  
  EXPECT_EQ(val1, val2);
  
}

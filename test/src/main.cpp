

/**
 * 单元测试入口
 * 基于gtest执行单元测试
 * @Author : Allen.Wu(allenlike@gmail.com)
 * @Date: 2015.05.24
 */

#include <stdio.h>
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

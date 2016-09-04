
cmake_minimum_required(VERSION 3.2)

project(GarvinEngine C CXX)

# 默认设定为debug模式
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

# 设定编译选项
set(CXX_FLAGS
  -gdwarf-2
  -D_FILE_OFFSET_BITS=64
  
  -w
  -Wall
  -Wextra
  -Wconversion
  -Wno-unused-parameter
  -Wno-sign-conversion
  -Wno-old-style-cast
  -Woverloaded-virtual
  -Wpointer-arith
  -Wshadow
  -Write-strings
  -Wno-deprecated

  -march=native
  -std=c++11)

if (CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
endif()

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# 跨平台设定
if (APPLE)
  set(CMAKE_CXX_COMPILER "clang++")
elseif(UNIX)
  set(CMAKE_CXX_COMPILER "g++")
endif()

# 设定优化等级
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

# 设定可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 包含子目录
add_subdirectory(base)
add_subdirectory(network)



cmake_minimum_required(VERSION 3.2)

PROJECT(GarvinEngine)

#set version
SET(LIBAPI_VERSION 0)
SET(LIBITR_VERSION 2)

MESSAGE(status " this is SOURCE dir : " ${PROJECT_SOURCE_DIR})
MESSAGE(status " this is BINARY dir : " ${PROJECT_BINARY_DIR})

#set env
#SET(CMAKE_VERBOSE_MAKEFILE on) //not open the verbose
SET(CMAKE_CXX_FLAGS "")
SET(CMAKE_CXX_FLAGS_DEBUG "-g3 -Wall")
SET(CMAKE_CXX_FLAGS_RELEASE "-o2 -Wall")

#add include directories
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include /usr/local/mysql/include)

#add link directories
LINK_DIRECTORIES(/usr/local/mysql/lib)

#set source file
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src/base SRC_LIST)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src/database TMP_SRC_LIST)
LIST(APPEND SRC_LIST ${TMP_SRC_LIST})

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src/network TMP_SRC_LIST)
LIST(APPEND SRC_LIST ${TMP_SRC_LIST})

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src/util TMP_SRC_LIST)
LIST(APPEND SRC_LIST ${TMP_SRC_LIST})

#output library
ADD_LIBRARY(garvinengine_static STATIC ${SRC_LIST})
TARGET_LINK_LIBRARIES(garvinengine_static mysqlclient)
SET_TARGET_PROPERTIES(garvinengine_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

ADD_LIBRARY(garvinengine_shared SHARED ${SRC_LIST})
SET_TARGET_PROPERTIES(garvinengine_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(garvinengine_shared PROPERTIES VERSION ${LIBAPI_VERSION}.${LIBITR_VERSION} SOVERSION ${LIBAPI_VERSION})
TARGET_LINK_LIBRARIES(garvinengine_shared mysqlclient)

ADD_LIBRARY(garvinengine_module MODULE ${SRC_LIST})
SET_TARGET_PROPERTIES(garvinengine_module PROPERTIES CLEAN_DIRECT_OUTPUT 1)
TARGET_LINK_LIBRARIES(garvinengine_module mysqlclient)

if (${CMAKE_BUILD_TYPE} MATCHES "debug")
  SET_TARGET_PROPERTIES(garvinengine_static PROPERTIES OUTPUT_NAME "garvinengine_d")
  SET_TARGET_PROPERTIES(garvinengine_shared PROPERTIES OUTPUT_NAME "garvinengine_d")
  SET_TARGET_PROPERTIES(garvinengine_module PROPERTIES OUTPUT_NAME "garvinengine_d")
  #set output lib path
  SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/debug)
else()
  SET_TARGET_PROPERTIES(garvinengine_static PROPERTIES OUTPUT_NAME "garvinengine")
  SET_TARGET_PROPERTIES(garvinengine_shared PROPERTIES OUTPUT_NAME "garvinengine")
  SET_TARGET_PROPERTIES(garvinengine_module PROPERTIES OUTPUT_NAME "garvinengine")
  #set output lib path
  SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
endif()



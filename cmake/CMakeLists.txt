# @file			CMakeLists.txt    
# @author		qiuleping
# @version		v1.0
# @create data	02-03-2018    	
# @brief		This file is cmake file for project association.
# @logs			2018-03-22 change source file name.
#				2018-03-22 add database source file name.
#
#

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(DISPATCH)

SET(CMAKE_BUILD_TYPE "Debug")
if(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
    MESSAGE(STATUS "optional:-std=c++11")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

SET(CUDA_USE_STATIC_CUDA_RUNTIME OFF)

FILE(GLOB HEADER_LIST_STAR ../code/startup/*.h)
FILE(GLOB HEADER_LIST_AlGO ../code/algorithm/*.h)
FILE(GLOB HEADER_LIST_APPL ../code/application/*.h)
FILE(GLOB HEADER_LIST_CONF ../code/configration/*.h)
FILE(GLOB HEADER_LIST_DEVI ../code/device/*.h)
FILE(GLOB HEADER_LIST_DRIV ../code/driver/*.h)
FILE(GLOB HEADER_LIST_HIRE ../code/hiredis/)
FILE(GLOB HEADER_LIST_JSON ../code/json/src/*.h)
FILE(GLOB HEADER_LIST_CURL ../code/libcurl/*.h)
FILE(GLOB HEADER_LIST_PROT ../code/protocol/*.h)

FILE(GLOB SOURCE_LIST_STAR ../code/startup/*.cpp)
FILE(GLOB SOURCE_LIST_AlGO ../code/algorithm/*.cpp)
FILE(GLOB SOURCE_LIST_APPL ../code/application/*.cpp)
FILE(GLOB SOURCE_LIST_CONF ../code/configration/*.cpp)
FILE(GLOB SOURCE_LIST_DEVI ../code/device/*.cpp)
FILE(GLOB SOURCE_LIST_DRIV ../code/driver/*.cpp)
FILE(GLOB SOURCE_LIST_HIRE ../code/hiredis/*.cpp)
FILE(GLOB SOURCE_LIST_JSON ../code/json/*.cpp)
FILE(GLOB SOURCE_LIST_CURL ../code/libcurl/*.cpp)
FILE(GLOB SOURCE_LIST_PROT ../code/protocol/*.cpp)

INCLUDE_DIRECTORIES(${HEADER_LIST_STAR} ${HEADER_LIST_AlGO} ${HEADER_LIST_APPL} ${HEADER_LIST_CONF} ${HEADER_LIST_DEVI} ${HEADER_LIST_DRIV} ${HEADER_LIST_HIRE} ${HEADER_LIST_JSON} ${HEADER_LIST_CURL} ${HEADER_LIST_PROT})

ADD_EXECUTABLE(dataBase ${SOURCE_LIST_STAR} ${SOURCE_LIST_AlGO} ${SOURCE_LIST_APPL} ${SOURCE_LIST_CONF} ${SOURCE_LIST_DEVI} ${SOURCE_LIST_DRIV} ${SOURCE_LIST_JSON} ${SOURCE_LIST_CURL} ${SOURCE_LIST_HIRE} ${SOURCE_LIST_PROT})

LINK_DIRECTORIES(/home/qlp/GitRepository/DataBase/code/hiredis)

TARGET_LINK_LIBRARIES (dataBase libhiredis.so)



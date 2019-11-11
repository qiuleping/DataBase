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

#FIND_LIBRARY(THIRD_PARTY_LIB third ../02lib/ NO_DEFAULT_PATH)
#link_libraries(${THIRD_PARTY_LIB})

FILE(GLOB SOURCE_LIST_STA ../01code/01start/src/*.cpp)
FILE(GLOB SOURCE_LIST_CON ../01code/02config/src/*.cpp)
FILE(GLOB SOURCE_LIST_APP ../01code/03application/src/*.cpp)
FILE(GLOB SOURCE_LIST_ALG ../01code/04algorithm/src/*.cpp)
FILE(GLOB SOURCE_LIST_PRO ../01code/05protocol/src/*.cpp)
FILE(GLOB SOURCE_LIST_DEV ../01code/06device/src/*.cpp)
FILE(GLOB SOURCE_LIST_DRI ../01code/07driver/src/*.cpp)
FILE(GLOB SOURCE_LIST_URL ../01code/08curllib/src/*.cpp)
FILE(GLOB SOURCE_LIST_JSN ../01code/09jsonlib/src/*.cpp)

FILE(GLOB HEADER_LIST_STA ../01code/01start/inc/)
FILE(GLOB HEADER_LIST_CON ../01code/02config/inc/)
FILE(GLOB HEADER_LIST_APP ../01code/03application/inc/)
FILE(GLOB HEADER_LIST_ALG ../01code/04algorithm/inc/)
FILE(GLOB HEADER_LIST_PRO ../01code/05protocol/inc/)
FILE(GLOB HEADER_LIST_DEV ../01code/06device/inc/)
FILE(GLOB HEADER_LIST_DRI ../01code/07driver/inc/)
FILE(GLOB HEADER_LIST_URL ../01code/08curllib/inc/)
FILE(GLOB HEADER_LIST_JSN ../01code/09jsonlib/inc/)

INCLUDE_DIRECTORIES(${HEADER_LIST_STA} ${HEADER_LIST_CON} ${HEADER_LIST_APP} ${HEADER_LIST_ALG} ${HEADER_LIST_PRO} ${HEADER_LIST_DEV} ${HEADER_LIST_DRI} ${HEADER_LIST_URL} ${HEADER_LIST_JSN})
ADD_EXECUTABLE(dispatch ${SOURCE_LIST_STA} ${SOURCE_LIST_CON} ${SOURCE_LIST_APP} ${SOURCE_LIST_ALG} ${SOURCE_LIST_PRO} ${SOURCE_LIST_DEV} ${SOURCE_LIST_DRI} ${SOURCE_LIST_URL} ${SOURCE_LIST_JSN})

TARGET_LINK_LIBRARIES (dispatch libpthread.so librt.so libcurl.so librabbitmq.so libjsoncpp.so)



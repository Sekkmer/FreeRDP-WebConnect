cmake_minimum_required(VERSION 3.0)
project(libwsgate VERSION 0.1.0)

include(CTest)
enable_testing()

#add_library(libwsgate)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/wsgate/cmake/)

# include cmake modules
include(CheckIncludeFile)
include(CheckLibraryExists) 
include(CheckFunctionExists)
include(CheckCXXCompilerFlag)
include(CheckTypeSize)

include_directories(/usr/include/freerdp2)
include_directories(/usr/include/winpr2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(USE_BFD True)
add_subdirectory(wsgate)

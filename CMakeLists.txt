cmake_minimum_required(VERSION 3.6)
project(SimpleGraphicsLayer)

#===============================================================================
# Global Dependencies
#===============================================================================
add_subdirectory(dependencies)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glew-2.0.0/include)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glm/include)

#===============================================================================
# SGL Library
#===============================================================================
add_subdirectory(code)

#===============================================================================
# Examples
#===============================================================================
option(EXAMPLES "Build all tests." ON)
#if(EXAMPLES)
    add_subdirectory(examples)
#endif()


cmake_minimum_required(VERSION 3.6)
project(TRIANGLE_EXAMPLE)

#===============================================================================
# Settings
#===============================================================================
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set (CMAKE_CXX_STANDARD 14)

#===============================================================================
# Sources
#===============================================================================
set(SOURCE_FILES main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/code )
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glfw-3.1.2/include)

#===============================================================================
# Compilation
#===============================================================================
add_executable(SGLTriangleExample ${SOURCE_FILES})

#===============================================================================
# Linking
#===============================================================================
target_link_libraries(SGLTriangleExample SGL)
target_link_libraries(SGLTriangleExample glfw ${GLFW_LIBRARIES})
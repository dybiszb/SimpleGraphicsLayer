cmake_minimum_required(VERSION 3.6)
project(SKYBOX_EXAMPLE)

#===============================================================================
# Settings
#===============================================================================
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

#===============================================================================
# Sources
#===============================================================================
set(SOURCE_FILES main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/code )
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glfw-3.1.2/include)

#===============================================================================
# Compilation
#===============================================================================
add_executable(SGLSkyboxExample ${SOURCE_FILES})

#===============================================================================
# Linking
#===============================================================================
target_link_libraries(SGLSkyboxExample SGL)
target_link_libraries(SGLSkyboxExample glfw ${GLFW_LIBRARIES})
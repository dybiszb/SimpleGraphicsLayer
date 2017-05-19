cmake_minimum_required(VERSION 3.6)

set(SOURCE_FILES main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/code)
add_executable(SGLSkyboxExample ${SOURCE_FILES})
target_link_libraries(SGLSkyboxExample SGL)
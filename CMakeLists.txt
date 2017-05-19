cmake_minimum_required(VERSION 3.6)
project(SimpleGraphicsLayer)

add_subdirectory(code)

option(EXAMPLES "Build all tests." ON)

#if(EXAMPLES)
    add_subdirectory(examples)
#endif()
cmake_minimum_required(VERSION 3.10)
project(expression_tree 
    DESCRIPTION "A basic Qt application with C++"
    VERSION 1.0.0
    LANGUAGES CXX)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

# Generate compile_commands.json for LLVM tooling
option(CMAKE_EXPORT_COMPILE_COMMANDS "Generates compile_commands.json when enabled")
mark_as_advanced(CLEAR CMAKE_EXPORT_COMPILE_COMMANDS)

#include_directories( include )
#add_subdirectory( tests )
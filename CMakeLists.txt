# attach to vcpkg's cmake configuration for project dependencies
set(CMAKE_TOOLCHAIN_FILE ../vcpkg/scripts/buildsystems/vcpkg.cmake)

cmake_minimum_required(VERSION 3.10)
project(qt_test_app 
    DESCRIPTION "A basic Qt application with C++"
    VERSION 1.0.0
    LANGUAGES CXX)

# Generate compile_commands.json for LLVM tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

OPTION( COMMON_BIN_DIRECTORY "Puts all libs and binaries in bin/" ON )
IF( COMMON_BIN_DIRECTORY )
  set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
  set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
ENDIF()

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#include_directories( include )
add_subdirectory( src )
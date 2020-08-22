# CMake Version management

cmake_minimum_required(VERSION 3.7)

if (${CMAKE_VERSION} VERSION_LESS 3.18)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.18)
endif()

# Extract version information from header file

# This assumes that the canonical version is listed in a single line
# like for example: #define INTRODUCTION_VERSION 0.1.0
set(VERSION_REGEX "#define INTRODUCTION_VERSION[ \t]+\"(.+)\"")

# The PROJECT_SOURCE_DIR variable is not set yet
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/introduction/version.h"
  VERSION_STRING REGEX ${VERSION_REGEX})

# Pick out just the version
string(REGEX REPLACE ${VERSION_REGEX} "\\1" VERSION_STRING "${VERSION_STRING}")

# Project configuration

project(Introduction
  VERSION ${VERSION_STRING}
  DESCRIPTION "A project that is an introduction to modern CMake."
  HOMEPAGE_URL "https://hungrybluedev.in/"
  LANGUAGES C
)

# All targets must follow the C99 standard
set(CMAKE_C_STANDARD 99)
# This property can also be set on a per-target basis.
# However, it is recommended to apply the same standard for all targets
# in order to ensure compatibility and simplicity.

# Configuration for the util library
add_library("util_lib-${PROJECT_VERSION}" STATIC
  src/introduction/util/util.c
  include/introduction/util/util.h
)
target_include_directories("util_lib-${PROJECT_VERSION}" PUBLIC include)

# Configuration for the munit testing library
add_library(munit STATIC
  test/src/external/munit/munit.c
  test/include/external/munit/munit.h
)
target_include_directories(munit PUBLIC test/include/external/munit)

# Configuration for the final executable
add_executable(run-tests test/src/run-tests.c)
target_link_libraries(run-tests PRIVATE "util_lib-${PROJECT_VERSION}" munit)
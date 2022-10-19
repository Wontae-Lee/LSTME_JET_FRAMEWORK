# CMake version
cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

# Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Declare project
project(lstme)

# Useful paths
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

# Includes
include_directories(external)
include_directories(external/pybind11/include)
include_directories(external/Clara/include)
include_directories(external/tinyobj)
include_directories(src/examples)

# Configure tasking system backend
include(cmake/TaskingSystemOptions.cmake)

# Compile options
include(cmake/CompileOptions.cmake)

# Code coverage - Debug only
# NOTE: Code coverage results with an optimized (non-Debug) build may be misleading
option(BUILD_COVERAGE "Build code coverage" OFF)
if (CMAKE_BUILD_TYPE MATCHES Debug AND CMAKE_COMPILER_IS_GNUCXX AND BUILD_COVERAGE)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage unit_tests coverage)
endif()

# Project modules
include(external.cmake)
include(lstme.cmake)


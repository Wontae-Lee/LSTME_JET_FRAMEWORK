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


# Configure tasking system backend
include(cmake/FindTBB.cmake)

# Project modules

# external module
add_subdirectory(${EXTERNAL_DIR}/pystring)
add_subdirectory(${EXTERNAL_DIR}/oneTBB)


# lstme 
include(lstme.cmake)


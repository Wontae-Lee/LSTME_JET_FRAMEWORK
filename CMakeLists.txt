#
# Copyright (c) 2023 Wontae Lee
#
# License: MIT License
#
# Copyright (c) 2019 Doyub Kim
#
# I am making my contributions/submissions to this project solely in my personal
# capacity and am not conveying any rights to any intellectual property of any
# third parties.
#

# CMake version
cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

# Declare project
project(jet VERSION 1.0.0)

# Useful paths
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Includes
include_directories(include)
include_directories(external)
include_directories(external/pybind11/include)
include_directories(external/Clara/include)
include_directories(external/tinyobj)
include_directories(src/examples)

# Tasking system
find_package(TBB REQUIRED)
include_directories(${TBB_INCLUDE_DIRS})

# Build type - Release by default
message("CMake build type: " ${CMAKE_BUILD_TYPE})
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()


# Compile options
set(DEFAULT_PROJECT_OPTIONS
        CXX_STANDARD              20
        LINKER_LANGUAGE           "CXX"
        POSITION_INDEPENDENT_CODE ON
        )


# Project modules
add_subdirectory(external/cnpy)
add_subdirectory(external/pystring)
add_subdirectory(src/jet)
add_subdirectory(src/examples/hello_fluid_sim)
add_subdirectory(src/examples/hybrid_liquid_sim)
add_subdirectory(src/examples/level_set_liquid_sim)
add_subdirectory(src/examples/obj2sdf)
add_subdirectory(src/examples/particles2obj)
add_subdirectory(src/examples/particles2xml)
add_subdirectory(src/examples/smoke_sim)
add_subdirectory(src/examples/sph_sim)
add_subdirectory(src/examples/porous)
add_subdirectory(src/examples/sph_kpconv3D)
add_subdirectory(src/examples/sph_kpconv2D)
add_subdirectory(src/examples/playground)
add_subdirectory(external/pybind11)

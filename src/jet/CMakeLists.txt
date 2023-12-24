#
# Copyright (c) 2018 Doyub Kim
#
# I am making my contributions/submissions to this project solely in my personal
# capacity and am not conveying any rights to any intellectual property of any
# third parties.
#

# Target name
set(target jet)

# Define
set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Sources
file(GLOB header_dir
        ${root_dir}/include/${target})

file(GLOB_RECURSE headers
        ${header_dir}/*.h
        )

file(GLOB_RECURSE sources
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


# Build library
add_library(${target} ${sources})

# Project options
set_target_properties(${target}
        PROPERTIES
        ${DEFAULT_PROJECT_OPTIONS}
        )

# Compile options
target_compile_options(${target}
        PRIVATE
        ${DEFAULT_COMPILE_OPTIONS}

        PUBLIC

        INTERFACE
        )

target_link_libraries(${target}
        PRIVATE

        PUBLIC
        ${DEFAULT_LINKER_OPTIONS}
        ${DEFAULT_LIBRARIES}
        TBB::tbb

        INTERFACE
        )

# Includes
target_include_directories(${target}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}

        PUBLIC

        INTERFACE
        $<BUILD_INTERFACE:${header_dir}>
        $<INSTALL_INTERFACE:include>
        )

# Install
install(TARGETS ${target} DESTINATION lib EXPORT ${target}_Export)
install(DIRECTORY ${header_dir} DESTINATION include)
install(EXPORT ${target}_Export
        DESTINATION lib/cmake/${target}
        FILE ${target}Config.cmake
        )

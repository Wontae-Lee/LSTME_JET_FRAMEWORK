
# Target name
set(target lstme)

# Define
set(LSTME_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/lstme)
set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/examples)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Sources
file(GLOB headers

        # Example dir
        ${EXAMPLE_DIR}/example_utils/*.hpp
        ${EXAMPLE_DIR}/sph_sim/*.hpp

        # Include dir
        ${INCLUDE_DIR}/*.hpp



        # current directory
        ${LSTME_SOURCE_DIR}/*.hpp

        # structures
        ${LSTME_SOURCE_DIR}/structures/array/*.hpp
        ${LSTME_SOURCE_DIR}/structures/point/*.hpp
        ${LSTME_SOURCE_DIR}/structures/size/*.hpp
        ${LSTME_SOURCE_DIR}/structures/vector/*.hpp
        ${LSTME_SOURCE_DIR}/structures/octree/*.hpp

        # utility
        ${LSTME_SOURCE_DIR}/utility/parallel/*.hpp
        ${LSTME_SOURCE_DIR}/utility/math/*.hpp
        ${LSTME_SOURCE_DIR}/utility/animation/*.hpp
        ${LSTME_SOURCE_DIR}/utility/cpp/*.hpp
        ${LSTME_SOURCE_DIR}/utility/timer/*.hpp

        # solvers

        ${LSTME_SOURCE_DIR}/solvers/particle/*.hpp
        ${LSTME_SOURCE_DIR}/solvers/kernels/*.hpp


        # Space
        ${LSTME_SOURCE_DIR}/space/grid/*.hpp
        ${LSTME_SOURCE_DIR}/space/converter/*.hpp
        ${LSTME_SOURCE_DIR}/space/generator/*.hpp

        # space/shape
        ${LSTME_SOURCE_DIR}/space/shape/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/box/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/cylinder/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/emitter/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/plane/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/ray/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/sphere/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/triangle/*.hpp
        ${LSTME_SOURCE_DIR}/space/shape/vertex/*.hpp

        # space/tools
        ${LSTME_SOURCE_DIR}/space/tools/sampler/*.hpp
        ${LSTME_SOURCE_DIR}/space/tools/converter/*.hpp
        ${LSTME_SOURCE_DIR}/space/tools/generator/*.hpp
        ${LSTME_SOURCE_DIR}/space/tools/searcher/*.hpp
        ${LSTME_SOURCE_DIR}/space/tools/transform/*.hpp
        ${LSTME_SOURCE_DIR}/space/tools/wrappers/*.hpp
        ${LSTME_SOURCE_DIR}/space/tools/factory/*.hpp

        ${LSTME_SOURCE_DIR}/space/field/*.hpp
        ${LSTME_SOURCE_DIR}/space/surface/*.hpp
        ${LSTME_SOURCE_DIR}/space/utility/sampler/*.hpp
        ${LSTME_SOURCE_DIR}/space/matrix/*.hpp

        # physics
        ${LSTME_SOURCE_DIR}/physics/*.hpp

        # System
        ${LSTME_SOURCE_DIR}/system/*.hpp

        # Engine
        ${LSTME_SOURCE_DIR}/engine/*.hpp

        # 3rdparty
        ${LSTME_SOURCE_DIR}/3rdparty/flatbuffers/*.hpp

        # Generated
        ${LSTME_SOURCE_DIR}/generated/*.hpp

        # Schema
        ${LSTME_SOURCE_DIR}/schema/*.hpp
        )

file(GLOB sources

        # Example dir
        ${EXAMPLE_DIR}/example_utils/*.cpp
        ${EXAMPLE_DIR}/sph_sim/*.cpp

        # Include dir
        ${INCLUDE_DIR}/*.cpp



        # current directory
        ${LSTME_SOURCE_DIR}/*.cpp

        # structures
        ${LSTME_SOURCE_DIR}/structures/array/*.cpp
        ${LSTME_SOURCE_DIR}/structures/point/*.cpp
        ${LSTME_SOURCE_DIR}/structures/size/*.cpp
        ${LSTME_SOURCE_DIR}/structures/vector/*.cpp
        ${LSTME_SOURCE_DIR}/structures/octree/*.cpp

        # utility
        ${LSTME_SOURCE_DIR}/utility/parallel/*.cpp
        ${LSTME_SOURCE_DIR}/utility/math/*.cpp
        ${LSTME_SOURCE_DIR}/utility/animation/*.cpp
        ${LSTME_SOURCE_DIR}/utility/cpp/*.cpp
        ${LSTME_SOURCE_DIR}/utility/timer/*.cpp

        # solvers
        ${LSTME_SOURCE_DIR}/solvers/advection/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/apic/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/lagrangian/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/eno_level_set/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/fdm/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/flip/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/grid/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/particle/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/kernels/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/pic/*.cpp

        # Space
        ${LSTME_SOURCE_DIR}/space/grid/*.cpp
        ${LSTME_SOURCE_DIR}/space/converter/*.cpp
        ${LSTME_SOURCE_DIR}/space/generator/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/*.cpp
        ${LSTME_SOURCE_DIR}/space/field/*.cpp
        ${LSTME_SOURCE_DIR}/space/surface/*.cpp
        ${LSTME_SOURCE_DIR}/solvers/level_set/*.cpp
        ${LSTME_SOURCE_DIR}/space/matrix/*.cpp

        # space/shape
        ${LSTME_SOURCE_DIR}/space/shape/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/box/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/cylinder/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/emitter/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/plane/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/ray/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/sphere/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/triangle/*.cpp
        ${LSTME_SOURCE_DIR}/space/shape/vertex/*.cpp

        # space/tools
        ${LSTME_SOURCE_DIR}/space/tools/sampler/*.cpp
        ${LSTME_SOURCE_DIR}/space/tools/converter/*.cpp
        ${LSTME_SOURCE_DIR}/space/tools/generator/*.cpp
        ${LSTME_SOURCE_DIR}/space/tools/searcher/*.cpp
        ${LSTME_SOURCE_DIR}/space/tools/transform/*.cpp
        ${LSTME_SOURCE_DIR}/space/tools/wrappers/*.cpp
        ${LSTME_SOURCE_DIR}/space/tools/factory/*.cpp

        # physics
        ${LSTME_SOURCE_DIR}/physics/*.cpp

        # System
        ${LSTME_SOURCE_DIR}/system/*.cpp

        # Engine
        ${LSTME_SOURCE_DIR}/engine/*.cpp

        # 3rdparty
        ${LSTME_SOURCE_DIR}/3rdparty/flatbuffers/*.cpp

        # Generated
        ${LSTME_SOURCE_DIR}/generated/*.cpp

        # Schema
        ${LSTME_SOURCE_DIR}/schema/*.cpp
        )

#
# add_library
#
add_library(${target} ${headers} ${sources})

#
# Target include directories
#
target_include_directories(${target}
        PRIVATE

        # Example dir
        ${EXAMPLE_DIR}/example_utils
        ${EXAMPLE_DIR}/sph_sim

        # Include dir
        ${INCLUDE_DIR}



        # current directory
        ${LSTME_SOURCE_DIR}/

        # structures
        ${LSTME_SOURCE_DIR}/structures/array
        ${LSTME_SOURCE_DIR}/structures/point
        ${LSTME_SOURCE_DIR}/structures/size
        ${LSTME_SOURCE_DIR}/structures/vector
        ${LSTME_SOURCE_DIR}/structures/octree

        # utility
        ${LSTME_SOURCE_DIR}/utility/parallel
        ${LSTME_SOURCE_DIR}/utility/math
        ${LSTME_SOURCE_DIR}/utility/animation
        ${LSTME_SOURCE_DIR}/utility/cpp
        ${LSTME_SOURCE_DIR}/utility/timer

        # solvers
        ${LSTME_SOURCE_DIR}/solvers/advection
        ${LSTME_SOURCE_DIR}/solvers/apic
        ${LSTME_SOURCE_DIR}/solvers/lagrangian
        ${LSTME_SOURCE_DIR}/solvers/eno_level_set
        ${LSTME_SOURCE_DIR}/solvers/fdm
        ${LSTME_SOURCE_DIR}/solvers/flip
        ${LSTME_SOURCE_DIR}/solvers/level_set
        ${LSTME_SOURCE_DIR}/solvers/grid
        ${LSTME_SOURCE_DIR}/solvers/particle
        ${LSTME_SOURCE_DIR}/solvers/kernels
        ${LSTME_SOURCE_DIR}/solvers/pic

        # Space
        ${LSTME_SOURCE_DIR}/space/grid
        ${LSTME_SOURCE_DIR}/space/converter
        ${LSTME_SOURCE_DIR}/space/generator
        ${LSTME_SOURCE_DIR}/space/shape
        ${LSTME_SOURCE_DIR}/space/field
        ${LSTME_SOURCE_DIR}/space/surface
        ${LSTME_SOURCE_DIR}/space/matrix

        # space/tools
        ${LSTME_SOURCE_DIR}/space/tools/sampler
        ${LSTME_SOURCE_DIR}/space/tools/converter
        ${LSTME_SOURCE_DIR}/space/tools/generator
        ${LSTME_SOURCE_DIR}/space/tools/searcher
        ${LSTME_SOURCE_DIR}/space/tools/transform
        ${LSTME_SOURCE_DIR}/space/tools/wrappers
        ${LSTME_SOURCE_DIR}/space/tools/factory

        # space/shape
        ${LSTME_SOURCE_DIR}/space/shape
        ${LSTME_SOURCE_DIR}/space/shape/box
        ${LSTME_SOURCE_DIR}/space/shape/cylinder
        ${LSTME_SOURCE_DIR}/space/shape/emitter
        ${LSTME_SOURCE_DIR}/space/shape/plane
        ${LSTME_SOURCE_DIR}/space/shape/ray
        ${LSTME_SOURCE_DIR}/space/shape/sphere
        ${LSTME_SOURCE_DIR}/space/shape/triangle
        ${LSTME_SOURCE_DIR}/space/shape/vertex

        # physics
        ${LSTME_SOURCE_DIR}/physics

        # System
        ${LSTME_SOURCE_DIR}/system

        # Engine
        ${LSTME_SOURCE_DIR}/engine

        # 3rdparty
        ${LSTME_SOURCE_DIR}/3rdparty/flatbuffers

        # Generated
        ${LSTME_SOURCE_DIR}/generated

        # Schema
        ${LSTME_SOURCE_DIR}/schema
        )



#
#   Target name
#
set(target lstme)

#
#   Sources
#
file(GLOB headers
        # current directory
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp

        # structures
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/array/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/point/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/size/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/vector/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/octree/*.hpp

        # utility
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/parallel/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/math/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/animation/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/cpp/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/timer/*.hpp

        # solvers
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/advection/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/apic/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/lagrangian/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/eno_level_set/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/fdm/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/flip/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/level_set/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/grid/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/particle/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/kernels/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/pic/*.hpp


        # Space
        ${CMAKE_CURRENT_SOURCE_DIR}/space/grid/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/converter/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/generator/*.hpp



        # space/shape
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/box/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/cylinder/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/emitter/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/plane/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/ray/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/sphere/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/triangle/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/vertex/*.hpp

        #space/tools
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/sampler/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/converter/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/generator/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/searcher/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/transform/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/wrappers/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/factory/*.hpp






        ${CMAKE_CURRENT_SOURCE_DIR}/space/field/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/surface/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/utility/sampler/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/matrix/*.hpp


        #physics
        ${CMAKE_CURRENT_SOURCE_DIR}/physics/*.hpp

        # System
        ${CMAKE_CURRENT_SOURCE_DIR}/system/*.hpp

        # Engine
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/*.hpp

        # 3rdparty
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/flatbuffers/*.hpp

        # Generated
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/*.hpp

        # Schema
        ${CMAKE_CURRENT_SOURCE_DIR}/schema/*.hpp




        )



file(GLOB sources

        # current directory
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp

        # structures
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/array/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/point/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/size/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/vector/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/octree/*.cpp

        # utility
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/parallel/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/math/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/animation/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/cpp/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/timer/*.cpp


        # solvers
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/advection/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/apic/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/lagrangian/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/eno_level_set/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/fdm/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/flip/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/grid/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/particle/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/kernels/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/pic/*.cpp


        # Space
        ${CMAKE_CURRENT_SOURCE_DIR}/space/grid/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/converter/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/generator/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/field/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/surface/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/level_set/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/matrix/*.cpp

        # space/shape
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/box/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/cylinder/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/emitter/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/plane/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/ray/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/sphere/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/triangle/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/vertex/*.cpp

        #space/tools
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/sampler/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/converter/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/generator/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/searcher/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/transform/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/wrappers/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/factory/*.cpp

        #physics
        ${CMAKE_CURRENT_SOURCE_DIR}/physics/*.cpp

        # System
        ${CMAKE_CURRENT_SOURCE_DIR}/system/*.cpp

        # Engine
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/*.cpp

        # 3rdparty
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/flatbuffers/*.cpp

        # Generated
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/*.cpp

        # Schema
        ${CMAKE_CURRENT_SOURCE_DIR}/schema/*.cpp

        )






#
#   add_library
#
add_library(${target} ${headers} ${sources} )


#
#   Target include directories
#
target_include_directories(${target}
        PRIVATE

        # current directory
        ${CMAKE_CURRENT_SOURCE_DIR}/

        # structures
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/array
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/point
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/size
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/vector
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/octree

        # utility
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/parallel
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/math
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/animation
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/timer

        # solvers
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/advection
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/apic
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/lagrangian
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/eno_level_set
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/fdm
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/flip
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/level_set
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/grid
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/particle
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/kernels
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/pic



        # Space
        ${CMAKE_CURRENT_SOURCE_DIR}/space/grid
        ${CMAKE_CURRENT_SOURCE_DIR}/space/converter
        ${CMAKE_CURRENT_SOURCE_DIR}/space/generator
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape
        ${CMAKE_CURRENT_SOURCE_DIR}/space/field
        ${CMAKE_CURRENT_SOURCE_DIR}/space/surface
        ${CMAKE_CURRENT_SOURCE_DIR}/space/matrix

        #space/tools
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/sampler
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/converter
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/generator
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/searcher
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/transform
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/wrappers
        ${CMAKE_CURRENT_SOURCE_DIR}/space/tools/factory

        # space/shape
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/box
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/cylinder
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/emitter
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/plane
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/ray
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/sphere
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/triangle
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/vertex

        #physics
        ${CMAKE_CURRENT_SOURCE_DIR}/physics

        # System
        ${CMAKE_CURRENT_SOURCE_DIR}/system

        # Engine
        ${CMAKE_CURRENT_SOURCE_DIR}/engine

        # 3rdparty
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/flatbuffers

        # Generated
        ${CMAKE_CURRENT_SOURCE_DIR}/generated

        # Schema
        ${CMAKE_CURRENT_SOURCE_DIR}/schema







        )

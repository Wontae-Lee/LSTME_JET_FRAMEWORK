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

        # utility
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/parallel/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/math/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/animation/*.hpp

        # solvers
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/advection/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/apic/*.hpp

        # Space
        ${CMAKE_CURRENT_SOURCE_DIR}/space/grid/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/converter/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/generator/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/*.hpp

        #physics
        ${CMAKE_CURRENT_SOURCE_DIR}/physics/*.hpp

        )



file(GLOB sources

        # current directory
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp

        # structures
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/array/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/point/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/structures/size/*.cpp

        # utility
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/parallel/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/math/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/animation/*.cpp

        # solvers
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/advection/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/apic/*.cpp

        # Space
        ${CMAKE_CURRENT_SOURCE_DIR}/space/grid/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/converter/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/generator/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape/*.cpp


        #physics
        ${CMAKE_CURRENT_SOURCE_DIR}/physics/*.cpp

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

        # utility
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/parallel
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/math
        ${CMAKE_CURRENT_SOURCE_DIR}/utility/animation

        # solvers
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/advection
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers/apic

        # Space
        ${CMAKE_CURRENT_SOURCE_DIR}/space/grid
        ${CMAKE_CURRENT_SOURCE_DIR}/space/converter
        ${CMAKE_CURRENT_SOURCE_DIR}/space/generator
        ${CMAKE_CURRENT_SOURCE_DIR}/space/shape

        #physics
        ${CMAKE_CURRENT_SOURCE_DIR}/physics


        )

# 1. C++로 짜여진 프로그램을 개발하기 위하여.


<br>
<br>
C++를 배울 때 보통 Microsoft사의 Visual Studio를 사용하였을 것이다. 물론 Visual Studio도 아주 좋은 프로그램이고, 많은 회사에서 사용하지만, <br>
나의 경험상 빼곡히 들어찬 Visual Studio의 메뉴화면에 압도되어 금방 길을 잃기 쉬웠다. 그에 반해 CMake는 간단한 코딩으로 C++를 빌드하기 용이했다.<br>
<br>
<br>
Jet Framework 에서는 CMake를 사용하여 코드를 빌드하였고, CMake만 읽어도 프로그램이 어떤 구조를 가지고 있는지 대충은 파악할 수 있다.<br>
<br>
<br>


## 1) [CMake]()


<br>
<br>

CMake는 Make파일를 작성하기 위한 일종의 매크로이다. Make파일을 작성하는 것 보다 훨씬 코드가 간결하면서, 최근에는 [Cross-compilation]() 프로그램을 <br>
개발하기 위한 방법으로 각광받고 있다. <br>
기본적인 사용법을 포함하여, CMake의 철학을 더욱 깊게 CMake를 이해하고 싶다면, 책 [CMake Cookbook]()과 [YouTube]() 동영상 또는 [CMake Document]()을 <br>
참고하기 바란다. 이 문서에서는 가장 기초적이고 필수적인 CMake 문법만 소개한다. Cross compilation에 대한 내용은 다루지 않는다.<br>
<br>
<br>

### (1) Root directory.

<br>
<br>

먼저, 빌드를 하기위한 root directory에 [CMakeList.txt]()를 생성해야한다. root directory 의 CMakeLists.txt 는 다음과 같다. <br>

```cmake

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
add_subdirectory(src/examples/playground)
add_subdirectory(external/pybind11)
```

### (2) Sub directory

<br>
<br>

```cmake


# Target name
set(target jet)

# Define
set(root_dir ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Sources
file(GLOB_RECURSE header_dir
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

```

<br>
<br>

### (3) main.cpp directory

<br>
<br>

```cmake
# Target name
set(target sph_sim)

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Sources
file(GLOB sources
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Build executable
add_executable(${target}
    ${sources})

# Project options
set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

# Compile options
target_compile_options(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}

    INTERFACE
)
target_compile_definitions(${target}
    PRIVATE
    RESOURCES_DIR="${RESOURCES_DIR}"
)

# Link libraries
target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
    jet
    pystring)
```


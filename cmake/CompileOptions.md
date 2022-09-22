# Platform and architecture setup


```cmake
option(LSTME_JET_WARNINGS_AS_ERRORS "Treat all warnings as errors" ON)
if(LSTME_JET_WARNINGS_AS_ERRORS)
    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(WARN_AS_ERROR_FLAGS "/WX")
    else()
        set(WARN_AS_ERROR_FLAGS "-Werror")
    endif()
endif()
```

### (1) [CMAKE_<LANG>_COMPILER_ID](https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html)
A short string unique to the compiler vendor.

### (2) [if](https://cmake.org/cmake/help/latest/command/if.html)
Conditionally execute a group of commands.

### (3) [flags](https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html)

- [-Werror]() : Turn any warning into a compilation error.
- [/WX](https://docs.microsoft.com/ko-kr/cpp/build/reference/compiler-option-warning-level?view=msvc-170) : Turn any warning into a compilation error. ("MSVC")







# Get upper case system name
```cmake
string(TOUPPER ${CMAKE_SYSTEM_NAME} SYSTEM_NAME_UPPER)
```
### (1) [string(TOUPPER <string> <output_variable>)](https://cmake.org/cmake/help/latest/command/string.html?highlight=string)
Convert <string> to upper characters.







# Determine architecture (32/64 bit)
```cmake
set(X64 OFF)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(X64 ON)
endif()
```
### (1) [CMAKE_SIZEOF_VOID_P](https://cmake.org/cmake/help/latest/variable/CMAKE_SIZEOF_VOID_P.html)
This is set to the size of a pointer on the target machine, and is determined by a try compile. If a 64-bit size is found, then the library search path is modified to look for 64-bit libraries first.






# Project options


```cmake
set(DEFAULT_PROJECT_OPTIONS
    CXX_STANDARD              17 # Not available before CMake 3.1; see below for manual command line argument addition
    LINKER_LANGUAGE           "CXX"
    POSITION_INDEPENDENT_CODE ON
)
```

### (1) [set](https://cmake.org/cmake/help/latest/command/set.html?highlight=set)
Set a normal, cache, or environment variable to a given value. See the cmake-language(7) variables documentation for the scopes and interaction of normal variables and cache entries.

Signatures of this command that specify a values .. placeholder expect zero or more arguments. Multiple arguments will be joined as a semicolon-separated list to form the actual variable value to be set. Zero arguments will cause normal variables to be unset. See the unset() command to unset variables explicitly.

### (2) [CXX_STANDARD](https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html)
The C++ standard whose features are requested to build this target.

### (3) [LINKER_LANGUAGE](https://cmake.org/cmake/help/latest/prop_tgt/LINKER_LANGUAGE.html?highlight=linker_language)
Specifies language whose compiler will invoke the linker.

### (4) [POSITION_INDEPENDENT_CODE](https://cmake.org/cmake/help/latest/prop_tgt/POSITION_INDEPENDENT_CODE.html?highlight=position_independent_code)
Whether to create a position-independent target


# Include directories

```cmake
set(DEFAULT_INCLUDE_DIRECTORIES)
```


# Libraries

```cmake
set(DEFAULT_LIBRARIES
  PUBLIC
  ${TASKING_SYSTEM_LIBS}
  PRIVATE
)
```



# Compile definitions

```cmake
set(DEFAULT_COMPILE_DEFINITIONS
    SYSTEM_${SYSTEM_NAME_UPPER}
)
```

# MSVC compiler options
```cmake
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(DEFAULT_COMPILE_DEFINITIONS ${DEFAULT_COMPILE_DEFINITIONS}
        _SCL_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the Standard C++ Library
        _CRT_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the CRT Library
    )
endif ()

```

# Compile options

```cmake
set(DEFAULT_COMPILE_OPTIONS)
```

# MSVC compiler options

```cmake
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        /MP           # -> build with multiple processes
        /W4           # -> warning level 4
        ${WARN_AS_ERROR_FLAGS}

        # /wd4251       # -> disable warning: 'identifier': class 'type' needs to have dll-interface to be used by clients of class 'type2'
        # /wd4592       # -> disable warning: 'identifier': symbol will be dynamically initialized (implementation limitation)
        # /wd4201     # -> disable warning: nonstandard extension used: nameless struct/union (caused by GLM)
        # /wd4127     # -> disable warning: conditional expression is constant (caused by Qt)
        /wd4717 # -> disable warning:  recursive on all control paths, function will cause runtime stack overflow (wrong warning)
        /wd4819 # -> disable warning:  The file contains a character that cannot be represented in the current code page (949) (wrong warning)

        #$<$<CONFIG:Debug>:
        #/RTCc         # -> value is assigned to a smaller data type and results in a data loss
        #>

        $<$<CONFIG:Release>:
        /Gw           # -> whole program global optimization
        /GS-          # -> buffer security check: no
        /GL           # -> whole program optimization: enable link-time code generation (disables Zi)
        /GF           # -> enable string pooling
        >

        # No manual c++11 enable for MSVC as all supported MSVC versions for cmake-init have C++11 implicitly enabled (MSVC >=2013)
    )
endif ()

# GCC and Clang compiler options
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        -Wall
        -Wno-range-loop-analysis # -> disable warning: loop variable 'grid' is always a copy because the range of type '...' does not return a reference (caused by flatbuffers) 
        ${WARN_AS_ERROR_FLAGS}

        # Required for CMake < 3.1; should be removed if minimum required CMake version is raised.
        $<$<VERSION_LESS:${CMAKE_VERSION},3.1>:
            -std=c++11
        >
    )
endif ()
```



# Linker options

```cmake
set(DEFAULT_LINKER_OPTIONS)
```

# Use pthreads on mingw and linux

```cmake
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(DEFAULT_LINKER_OPTIONS
        -pthread
    )
endif()


# Code coverage - Debug only
# NOTE: Code coverage results with an optimized (non-Debug) build may be misleading
if (CMAKE_BUILD_TYPE MATCHES Debug AND CMAKE_COMPILER_IS_GNUCXX)
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        -g
        -O0
        -fprofile-arcs
        -ftest-coverage
    )

    set(DEFAULT_LINKER_OPTIONS ${DEFAULT_LINKER_OPTIONS}
        -fprofile-arcs
        -ftest-coverage
    )
endif()
```

### (1) [-ftest-coverage](http://korea.gnu.org/manual/release/gcov/gcov_1.html)

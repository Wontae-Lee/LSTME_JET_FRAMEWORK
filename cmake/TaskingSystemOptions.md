

# Setup tasking system build configuration

```cmake
# Determine the best default option for tasking system backend
if(NOT DEFINED LSTME_JET_TASKING_SYSTEM)
  find_package(TBB QUIET)
  if(TBB_FOUND)
    set(TASKING_DEFAULT TBB)
  else()
    find_package(OpenMP QUIET)
    if(OpenMP_FOUND)
      set(TASKING_DEFAULT OpenMP)
    else()
      set(TASKING_DEFAULT CPP11Threads)
    endif()
  endif()
else()
  set(TASKING_DEFAULT ${LSTME_JET_TASKING_SYSTEM})
endif()

set(LSTME_JET_TASKING_SYSTEM ${TASKING_DEFAULT} CACHE STRING
    "Per-node thread tasking system [CPP11Threads,TBB,OpenMP,Serial]")

set_property(CACHE LSTME_JET_TASKING_SYSTEM PROPERTY
             STRINGS CPP11Threads TBB OpenMP Serial)
```

### (1) [find_package](https://cmake.org/cmake/help/latest/command/find_package.html?highlight=find_package)

The basic signature is supported by both Module and Config modes. The MODULE keyword implies that only Module mode can be used to find the package, with no fallback to Config mode.

Regardless of the mode used, a [PackageName]()_FOUND variable will be set to indicate whether the package was found. When the package is found, package-specific information may be provided through other variables and Imported Targets documented by the package itself. The QUIET option disables informational messages, including those indicating that the package cannot be found if it is not REQUIRED. The REQUIRED option stops processing with an error message if the package cannot be found.

A package-specific list of required components may be listed after the COMPONENTS keyword. If any of these components are not able to be satisfied, the package overall is considered to be not found. If the REQUIRED option is also present, this is treated as a fatal error, otherwise execution still continues. As a form of shorthand, if the REQUIRED option is present, the COMPONENTS keyword can be omitted and the required components can be listed directly after REQUIRED.

Additional optional components may be listed after OPTIONAL_COMPONENTS. If these cannot be satisfied, the package overall can still be considered found, as long as all required components are satisfied.

The set of available components and their meaning are defined by the target package. Formally, it is up to the target package how to interpret the component information given to it, but it should follow the expectations stated above. For calls where no components are specified, there is no single expected behavior and target packages should clearly define what occurs in such cases. Common arrangements include assuming it should find all components, no components or some well-defined subset of the available components.

### (2) [set](https://cmake.org/cmake/help/latest/command/set.html?highlight=set)

Sets the given [cache]() variable (cache entry). Since cache entries are meant to provide user-settable values this does not overwrite existing cache entries by default. Use the FORCE option to overwrite existing entries.

The type must be specified as one of:

BOOL
Boolean ON/OFF value. cmake-gui(1) offers a checkbox.

FILEPATH
Path to a file on disk. cmake-gui(1) offers a file dialog.

PATH
Path to a directory on disk. cmake-gui(1) offers a file dialog.

STRING
A line of text. cmake-gui(1) offers a text field or a drop-down selection if the STRINGS cache entry property is set.

INTERNAL
A line of text. cmake-gui(1) does not show internal entries. They may be used to store variables persistently across runs. Use of this type implies FORCE.

The [docstring]() must be specified as a line of text providing a quick summary of the option for presentation to cmake-gui(1) users.

If the cache entry does not exist prior to the call or the FORCE option is given then the cache entry will be set to the given value.


# NOTE(jda) - Make the JET_TASKING_SYSTEM build option case-insensitive
```cmake
string(TOUPPER ${JET_TASKING_SYSTEM} JET_TASKING_SYSTEM_ID)

set(LSTME_JET_TASKING_TBB          FALSE)
set(LSTME_JET_TASKING_OPENMP       FALSE)
set(LSTME_JET_TASKING_CPP11THREADS FALSE)
set(LSTME_JET_TASKING_SERIAL       FALSE)

if(${LSTME_JET_TASKING_SYSTEM_ID} STREQUAL "TBB")
  set(LSTME_JET_TASKING_TBB TRUE)
elseif(${LSTME_JET_TASKING_SYSTEM_ID} STREQUAL "OPENMP")
  set(LSTME_JET_TASKING_OPENMP TRUE)
elseif(${LSTME_JET_TASKING_SYSTEM_ID} STREQUAL "CPP11THREADS")
  set(LSTME_JET_TASKING_CPP11THREADS TRUE)
else()
  set(LSTME_JET_TASKING_SERIAL TRUE)
endif()

unset(TASKING_SYSTEM_LIBS)
unset(TASKING_SYSTEM_LIBS_MIC)

if(LSTME_JET_TASKING_TBB)
  find_package(TBB REQUIRED)
  add_definitions(-DLSTME_JET_TASKING_TBB)
  include_directories(${TBB_INCLUDE_DIRS})
  set(TASKING_SYSTEM_LIBS ${TBB_LIBRARIES})
  set(TASKING_SYSTEM_LIBS_MIC ${TBB_LIBRARIES_MIC})
else()
  unset(TBB_INCLUDE_DIR          CACHE)
  unset(TBB_LIBRARY              CACHE)
  unset(TBB_LIBRARY_DEBUG        CACHE)
  unset(TBB_LIBRARY_MALLOC       CACHE)
  unset(TBB_LIBRARY_MALLOC_DEBUG CACHE)
  unset(TBB_INCLUDE_DIR_MIC      CACHE)
  unset(TBB_LIBRARY_MIC          CACHE)
  unset(TBB_LIBRARY_MALLOC_MIC   CACHE)
  if(LSTME_JET_TASKING_OPENMP)
    find_package(OpenMP)
    if(OPENMP_FOUND)
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
      set(CMAKE_EXE_LINKER_FLAGS
          "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
      add_definitions(-DLSTME_JET_TASKING_OPENMP)
    endif()
  elseif(LSTME_JET_TASKING_CPP11THREADS)
      add_definitions(-DLSTME_JET_TASKING_CPP11THREADS)
  else()#Serial
    # Do nothing, will fall back to scalar code (useful for debugging)
  endif()
endif()
```

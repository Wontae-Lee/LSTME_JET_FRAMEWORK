
#
# Setup tasking system build configuration
#

# Determine the best default option for tasking system backend
if(NOT DEFINED LSTME_TASKING_SYSTEM)
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
  set(TASKING_DEFAULT ${LSTME_TASKING_SYSTEM})
endif()

set(LSTME_TASKING_SYSTEM ${TASKING_DEFAULT} CACHE STRING
    "Per-node thread tasking system [CPP11Threads,TBB,OpenMP,Serial]")

set_property(CACHE LSTME_TASKING_SYSTEM PROPERTY
             STRINGS CPP11Threads TBB OpenMP Serial)

# NOTE(jda) - Make the LSTME_TASKING_SYSTEM build option case-insensitive
string(TOUPPER ${LSTME_TASKING_SYSTEM} LSTME_TASKING_SYSTEM_ID)

set(LSTME_TASKING_TBB          FALSE)
set(LSTME_TASKING_OPENMP       FALSE)
set(LSTME_TASKING_CPP11THREADS FALSE)
set(LSTME_TASKING_SERIAL       FALSE)

if(${LSTME_TASKING_SYSTEM_ID} STREQUAL "TBB")
  set(LSTME_TASKING_TBB TRUE)
elseif(${LSTME_TASKING_SYSTEM_ID} STREQUAL "OPENMP")
  set(LSTME_TASKING_OPENMP TRUE)
elseif(${LSTME_TASKING_SYSTEM_ID} STREQUAL "CPP11THREADS")
  set(LSTME_TASKING_CPP11THREADS TRUE)
else()
  set(LSTME_TASKING_SERIAL TRUE)
endif()

unset(TASKING_SYSTEM_LIBS)
unset(TASKING_SYSTEM_LIBS_MIC)

if(LSTME_TASKING_TBB)
  find_package(TBB REQUIRED)
  add_definitions(-DLSTME_TASKING_TBB)
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
  if(LSTME_TASKING_OPENMP)
    find_package(OpenMP)
    if(OPENMP_FOUND)
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
      set(CMAKE_EXE_LINKER_FLAGS
          "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
      add_definitions(-DLSTME_TASKING_OPENMP)
    endif()
  elseif(LSTME_TASKING_CPP11THREADS)
      add_definitions(-DLSTME_TASKING_CPP11THREADS)
  else()#Serial
    # Do nothing, will fall back to scalar code (useful for debugging)
  endif()
endif()

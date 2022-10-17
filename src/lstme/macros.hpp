//
// Created by LSTME on 2022-09-21.
//

#ifndef LSTME_MACROS_HPP
#define LSTME_MACROS_HPP

#if defined(_WIN32) || defined(_WIN64)
#   define LSTME_WINDOWS
#elif defined(__APPLE__)
#   define LSTME_APPLE
#   ifndef LSTME_IOS
#       define LSTME_MACOSX
#   endif
#elif defined(linux) || defined(__linux__)
#   define LSTME_LINUX
#endif

#if defined(DEBUG) || defined(_DEBUG)
#   define LSTME_DEBUG_MODE
#   include <cassert>
#   define LSTME_ASSERT(x) assert(x)
#else
#   define LSTME_ASSERT(x)
#endif

#ifdef __cplusplus
#define LSTME_NON_COPYABLE(ClassName) \
    ClassName(const ClassName&) = delete; \
    ClassName& operator=(const ClassName&) = delete;
#endif

#ifdef __cplusplus
#include <stdexcept>
#define LSTME_THROW_INVALID_ARG_IF(expression) \
    if (expression) { throw std::invalid_argument(#expression); }
#define LSTME_THROW_INVALID_ARG_WITH_MESSAGE_IF(expression, message) \
    if (expression) { throw std::invalid_argument(message); }
#endif

#if defined(LSTME_WINDOWS) && defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#define LSTME_DIAG_STR(s) #s
#define LSTME_DIAG_JOINSTR(x, y) LSTME_DIAG_STR(x ## y)
#ifdef _MSC_VER
#define LSTME_DIAG_DO_PRAGMA(x) __pragma (#x)
#define LSTME_DIAG_PRAGMA(compiler, x) LSTME_DIAG_DO_PRAGMA(warning(x))
#else
#define LSTME_DIAG_DO_PRAGMA(x) _Pragma (#x)
#define LSTME_DIAG_PRAGMA(compiler, x) LSTME_DIAG_DO_PRAGMA(compiler diagnostic x)
#endif
#if defined(__clang__)
# define LSTME_DISABLE_CLANG_WARNING(clang_option) \
    LSTME_DIAG_PRAGMA(clang, push) \
    LSTME_DIAG_PRAGMA(clang, ignored LSTME_DIAG_JOINSTR(-W, clang_option))
# define LSTME_ENABLE_CLANG_WARNING(clang_option) LSTME_DIAG_PRAGMA(clang, pop)
# define LSTME_DISABLE_MSVC_WARNING(gcc_option)
# define LSTME_ENABLE_MSVC_WARNING(gcc_option)
# define LSTME_DISABLE_GCC_WARNING(gcc_option)
# define LSTME_ENABLE_GCC_WARNING(gcc_option)
#elif defined(_MSC_VER)
# define LSTME_DISABLE_CLANG_WARNING(gcc_option)
# define LSTME_ENABLE_CLANG_WARNING(gcc_option)
# define LSTME_DISABLE_MSVC_WARNING(msvc_errorcode) \
    LSTME_DIAG_PRAGMA(msvc, push) \
    LSTME_DIAG_DO_PRAGMA(warning(disable:##msvc_errorcode))
# define LSTME_ENABLE_MSVC_WARNING(msvc_errorcode) LSTME_DIAG_PRAGMA(msvc, pop)
# define LSTME_DISABLE_GCC_WARNING(gcc_option)
# define LSTME_ENABLE_GCC_WARNING(gcc_option)
#elif defined(__GNUC__)
#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 406
# define LSTME_DISABLE_CLANG_WARNING(gcc_option)
# define LSTME_ENABLE_CLANG_WARNING(gcc_option)
# define LSTME_DISABLE_MSVC_WARNING(gcc_option)
# define LSTME_ENABLE_MSVC_WARNING(gcc_option)
# define LSTME_DISABLE_GCC_WARNING(gcc_option) \
    LSTME_DIAG_PRAGMA(GCC, push) \
    LSTME_DIAG_PRAGMA(GCC, ignored LSTME_DIAG_JOINSTR(-W, gcc_option))
# define LSTME_ENABLE_GCC_WARNING(gcc_option) LSTME_DIAG_PRAGMA(GCC, pop)
#else
# define LSTME_DISABLE_CLANG_WARNING(gcc_option)
# define LSTME_ENABLE_CLANG_WARNING(gcc_option)
# define LSTME_DISABLE_MSVC_WARNING(gcc_option)
# define LSTME_ENABLE_MSVC_WARNING(gcc_option)
# define LSTME_DISABLE_GCC_WARNING(gcc_option) \
    LSTME_DIAG_PRAGMA(GCC, ignored LSTME_DIAG_JOINSTR(-W, gcc_option))
# define LSTME_ENABLE_GCC_WARNING(gcc_option) \
    LSTME_DIAG_PRAGMA(GCC, warning LSTME_DIAG_JOINSTR(-W, gcc_option))
#endif
#endif


#endif // LSTME_MACROS_HPP

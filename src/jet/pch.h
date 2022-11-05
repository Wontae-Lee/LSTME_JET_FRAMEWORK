// Jet public headers
#include <jet/logging.h>
#include <jet/macros.h>
#ifdef JET_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <objbase.h>
#endif

// Jet private headers
#include <private_helpers.h>

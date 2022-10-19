//
// Created by LSTME on 2022-10-15.
//

#ifndef LSTME_PCH_HPP
#define LSTME_PCH_HPP

#include <logging.hpp>
#include <macros.hpp>

#ifdef LSTME_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <objbase.h>
#endif

// Jet private headers
#include <private_helpers.hpp>

#endif // LSTME_PCH_HPP

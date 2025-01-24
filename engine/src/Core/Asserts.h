#pragma once

#include "Defines.h"

/* Comment this line to disable assertions. */
#define ASSERTIONS_ENABLED

#ifdef ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugbreak() __debugbreak()
#else
#define debugbreak() __builtin_trap()
#endif

SAPI void reportAssertionFailure(const char* expression, const char* message, const char* file, I32 line);

#define SASSERT(expression)                                                 \
    {                                                                       \
        if (expression) {                                                   \
            /* Do nothing. */                                               \
        } else {                                                            \
            reportAssertionFailure(#expression, "", __FILE__, __LINE__);    \
            debugbreak();                                                   \
        }                                                                   \
    }

#define SASSERT_MSG(expression, message)                                        \
    {                                                                           \
        if (expression) {                                                       \
            /* Do nothing. */                                                   \
        } else {                                                                \
            reportAssertionFailure(#expression, message, __FILE__, __LINE__);   \
            debugbreak();                                                       \
        }                                                                       \
    }
    
#ifdef _DEBUG
#define SASSERT_DEBUG(expression)                                           \
    {                                                                       \
        if (expression) {                                                   \
            /* Do nothing. */                                               \
        } else {                                                            \
            reportAssertionFailure(#expression, "", __FILE__, __LINE__);    \
            debugbreak();                                                   \
        }                                                                   \
    }
#else
#define SASSERT_DEBUG(expression)
#endif

#else
#define SASSERT(expression)
#define SASSERT_MSG(expresssion, message)
#define SASSERT_DEBUG(expression)

#endif  /* ASSERTIONS_ENABLED */
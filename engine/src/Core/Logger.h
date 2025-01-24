#pragma once

#include "Defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

/*
 * DEBUG and TRACE informations are not available in 'Release' Builds.
 */
#if SRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum LOG_LEVEL
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN  = 2,
    LOG_LEVEL_INFO  = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,
} LOG_LEVEL;

B8 InitializeLogging();
void ShudownLogging();

SAPI void LogOutput(LOG_LEVEL level, const char* message, ...);

#ifndef SFATAL
// Logs a fatal-level message.
#define SFATAL(message, ...) LogOutput(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#endif

#ifndef SERROR
// Logs a error-level message.
#define SERROR(message, ...) LogOutput(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

// Ability to switch warning-level messages on and off.
#if LOG_WARN_ENABLED == 1
// Logs a warning-level message.
#define SWARN(message, ...) LogOutput(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define SWARN(message, ...)
#endif

// Ability to switch info-level messages on and off.
#if LOG_INFO_ENABLED == 1
// Logs a info-level message.
#define SINFO(message, ...) LogOutput(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define SINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs a debug-level message.
#define SDEBUG(message, ...) LogOutput(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define SDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs a trace-level message.
#define STRACE(message, ...) LogOutput(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define STRACE(message, ...)
#endif

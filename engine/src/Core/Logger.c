#include "Logger.h"

// TODO: Temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "Asserts.h"

B8 InitializeLogging()
{
    // TODO: Create a log file.
    return TRUE;
}

void ShudownLogging()
{

}

void reportAssertionFailure(const char* expression, const char* message, const char* file, I32 line)
{
    LogOutput(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, line: %d\n", expression, message, file, line);
}

void LogOutput(LOG_LEVEL level, const char* message, ...)
{
    const char* levelStrings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARNING]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    //B8 isError = level < 2;

    // TODO: Potential issue, message can have 16k character limit.
    // - For a lower memory footprint maybe use a memory allocator instead for each log and queue.
    char outputMessage[16000];
    memset(outputMessage, 0, sizeof(outputMessage));

    // Format original message.
    __builtin_va_list argPtr;
    va_start(argPtr, message);
    vsnprintf(outputMessage, 16000, message, argPtr);
    va_end(argPtr);

    char outputMessage2[16000];
    sprintf(outputMessage2, "%s%s\n", levelStrings[level], outputMessage);

    // TODO: platform-specific output
    printf("%s", outputMessage2);
}
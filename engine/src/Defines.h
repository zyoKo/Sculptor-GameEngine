#pragma once

// Unsigned Types
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long long U64;

// Signed Types
typedef signed char I8;
typedef signed short I16;
typedef signed int I32;
typedef signed long long I64;

// Floating Point Types
typedef float F32;
typedef double F64;

// Boolean Types
typedef char B8;
typedef int B32;

// Properly defined static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size
STATIC_ASSERT(sizeof(U8)  == 1, "Expected  U8 to be 1 byte.");
STATIC_ASSERT(sizeof(U16) == 2, "Expected U16 to be 2 byte.");
STATIC_ASSERT(sizeof(U32) == 4, "Expected U32 to be 4 byte.");
STATIC_ASSERT(sizeof(U64) == 8, "Expected U64 to be 8 byte.");

STATIC_ASSERT(sizeof(I8)  == 1, "Expected  I8 to be 1 byte.");
STATIC_ASSERT(sizeof(I16) == 2, "Expected I16 to be 2 byte.");
STATIC_ASSERT(sizeof(I32) == 4, "Expected I32 to be 4 byte.");
STATIC_ASSERT(sizeof(I64) == 8, "Expected I64 to be 8 byte.");

STATIC_ASSERT(sizeof(F32) == 4, "Expected F32 to be 4 byte.");
STATIC_ASSERT(sizeof(F64) == 8, "Expected F64 to be 8 byte.");

#define TRUE 1
#define FALSE 0

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define SPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// LinuxOS
#define SPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define SPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above
#define SPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
#define SPLATFORM_POSIX 1
#elif __APPLE__
// Apple plaform
#define SPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
//iOS Simulator
#define SPLATFORM_IOS 1
#define SPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define SPLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of MacOS
#else
#error "Unknown Apple Platform"alignas
#endif
#else
#error "Unknown Platform:"
#endif

#ifdef SEXPORT
// Exports
#ifdef _MSC_VER
#define SAPI __declspec(dllexport)
#else
#define SAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define SAPI __declspec(dllimport)
#else
#define SAPI
#endif
#endif

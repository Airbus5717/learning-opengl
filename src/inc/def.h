#pragma once

// stdlib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define local static

typedef float f32;
typedef double f64;
typedef long double f128; // not nesserily 128bits

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef long long isize;
typedef unsigned long long usize;

typedef const char *string; // immutable string (null char terminated)
typedef char *cstring;      // mutable string (null char terminated)

#define U8_MAX 0xff
#define U8_MIN 0
#define I8_MAX 0x7f
#define I8_MIN -0x80
#define U16_MAX 0xffff
#define U16_MIN 0
#define I16_MAX 0x7fff
#define I16_MIN -0x8000
#define U32_MAX 0xffffffff
#define U32_MIN 0
#define I32_MAX 0x7fffffff
#define I32_MIN -0x80000000
#define U64_MAX 0xffffffffffffffff
#define U64_MIN 0
#define I64_MAX 0x7fffffffffffffff
#define I64_MIN -0x8000000000000000

// END OF DEF.H

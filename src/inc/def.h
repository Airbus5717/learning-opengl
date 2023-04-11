#pragma once

// stdlib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

const u8 TRUE = (0 == 0);
const u8 FALSE = !TRUE;

const usize U8_MAX = 0xff;
const usize U8_MIN = 0;
const usize I8_MAX = 0x7f;
const usize I8_MIN = -0x80;

const usize U16_MAX = 0xffff;
const usize U16_MIN = 0;
const usize I16_MAX = 0x7fff;
const usize I16_MIN = -0x8000;

const usize U32_MAX = 0xffffffff;
const usize U32_MIN = 0;
const usize I32_MAX = 0x7fffffff;
const usize I32_MIN = -0x80000000;

const usize U64_MAX = 0xffffffffffffffff;
const usize U64_MIN = 0;
const usize I64_MAX = 0x7fffffffffffffff;
const usize I64_MIN = -0x8000000000000000;

// END OF DEF.H

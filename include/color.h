#ifndef AXIS_COLOR_H
#define AXIS_COLOR_H

#include "global.h"

typedef struct rgb8_color {
    u8 r, g, b;
} Color_RGB8;

typedef struct rgba8_color {
    u8 r, g, b, a;
} Color_RGBA8;

typedef union rgba8_color_u32 {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Color_RGBA8_u32;

typedef struct rgbaf_color {
    f32 r, g, b, a;
} Color_RGBAf;

typedef union rgba16_color {
    struct {
        u16 r : 5;
        u16 g : 5;
        u16 b : 5;
        u16 a : 1;
    };
    u16 rgba;
} Color_RGBA16, Color_RGBA_5551;

typedef union rgb24_color {
    struct {
        u8 r, g, b;
    };
    u32 rgb;
} Color_RGB24;

typedef union rgba32_color {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Color_RGBA32;

typedef struct hsvf_color {
    f32 h, s, v;
} Color_HSVf;

#endif /* AXIS_COLOR_H */
#ifndef LIBAXIS_COLOR_H
#define LIBAXIS_COLOR_H

/**
* @brief Convert a 16-bit color to a 32-bit color.
* 
**/
#define COLOR16_TO_COLOR32(CARG0) (                 \
      COLOR32((((CARG0) & 0xF800) >> 11) /* red */  \
    , (((CARG0) & 0x07C0) >> 6) /* green */         \
    , (((CARG0) & 0x003E) >> 1) /* blue  */         \
    , ((((CARG0) & 0x1) > 0) ? 255 : 0) /* alpha */ \
))

/**
* @brief Convert a 32-bit color to a 16-bit color.
* 
**/
#define COLOR32_TO_COLOR16(CARG0) (              \
      (((CARG0) & 0xF8000000) >> 16) /* red   */  \
    | (((CARG0) & 0x00F80000) >> 13) /* green */  \
    | (((CARG0) & 0x0000F800) >> 10) /* blue  */  \
    | (((CARG0) & 0x00000080) >>  7) /* alpha */  \
)

#define COLOR16(r, g, b, a) COLOR32_TO_COLOR16(COLOR32((r), (g), (b), (a)))
#define C16TO32(CARG0) COLOR16_TO_COLOR32((CARG0))
#define C32TO16(CARG0) COLOR32_TO_COLOR16((CARG0))

#ifdef __LA_STANDALONE__

typedef union rgb8_color {
    struct {
        unsigned char r, g, b;
    };
    unsigned int rgb;
} Color_RGB8, Color_RGB24;

typedef union {
    struct {
        unsigned short r : 5;
        unsigned short g : 5;
        unsigned short b : 5;
        unsigned short a : 1;
    };
    unsigned short rgba;
} Color_RGBA16, Color_RGBA5551;

typedef union rgba32_color {
    struct {
        unsigned char r, g, b, a;
    };
    unsigned int rgba;
} Color_RGBA8, Color_RGBA8_u32, Color_RGBA32;

typedef struct rgbaf_color {
    float r, g, b, a;
} Color_RGBAf;

#endif

typedef struct hsvf_color {
    float h, s, v;
} Color_HSVf;

#endif /* LIBAXIS_COLOR_H */
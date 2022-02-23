#ifndef LIBAXIS_COLOR_H
#define LIBAXIS_COLOR_H

typedef union rgba32_color {
    struct {
        unsigned char r, g, b, a;
    };
    unsigned int rgba;
} Color_RGBA32;

typedef struct hsvf_color {
    float h, s, v;
} Color_HSVf;

#endif /* LIBAXIS_COLOR_H */
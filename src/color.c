/**
 * @file: color.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief A colorful library.
**/

#include "../include/libaxis.h"


/**
* @brief Convert RGB color space to HSV. This is primarily based off of the math found on RapidTables.
* @param r Red Channel (0 - 255)
* @param g Green Channel (0 - 255)
* @param b Blue Channel (0 - 255)
* @param h Hue (Pointer)
* @param s Saturation (Pointer)
* @param b Value (Pointer)
* @return void
**/
void LibAxis_Color_RGBToHSV(uint8_t r, uint8_t g, uint8_t b, float* h, float* s, float* v) {
    float _r, _g, _b;
    float cmax, cmin, delta;

    _r = (r / 255.0f);
    _g = (g / 255.0f);
    _b = (b / 255.0f);

    cmax = LibAxis_MaxF3(_r, _g, _b);
    cmin = LibAxis_MinF3(_r, _g, _b);
    delta = (cmax - cmin);

    if (cmax == 0.0f) {
        *s = 0.0f; *h = 0.0f;
    } else if (delta == 0.0f) {
        *s = 0.0f; *h = 0.0f;
    } else {
        *s = (delta / cmax);

        if (cmax == _r) {
            *h = (60 * fmodf(((_g - _b)), 6));
        } else if (cmax == _g) {
            *h = (60 * (((_b - _r) / delta) + 2));
        } else {
            *h = (60 * (((_r - _g) / delta) + 4));
        }
    }

    if (*h < 0.0f)
        *h += 360.0f;
    
    *v = cmax;
}

/**
* @brief Convert HSV color space to RGB
* 
* @param h Hue (0.0 - 359.0)
* @param s Saturation (0.0 - 1.0)
* @param b Value (0.0 - 1.0)
* @param r Red Channel (Pointer)
* @param g Green Channel (Pointer)
* @param b Blue Channel (Pointer)
* @return void
* @remark Slighty Lossy
**/
void LibAxis_Color_HSVToRGB(float h, float s, float v, uint8_t* r, uint8_t* g, uint8_t* b) {
    float c, x, m;
    float rgb[3] = {0.0f, 0.0f, 0.0f};

    // Clamp
    h = LA_CLAMP(h, 0, 360);
    s = LA_CLAMP01(s);
    v = LA_CLAMP01(v);

    c = (v * s);
    x = c * (1.0f - fabsf(fmodf(h / 60.0f, 2) - 1.0f));
    m = (v - c);

    if (LA_RANGE_HIE(h, 0, 60)) {
        rgb[0] = c; rgb[1] = x; rgb[2] = 0.0f;
    } else if (LA_RANGE_HIE(h, 60, 120)) {
        rgb[0] = x; rgb[1] = c; rgb[2] = 0.0f;
    } else if (LA_RANGE_HIE(h, 120, 180)) {
        rgb[0] = 0.0f; rgb[1] = c; rgb[2] = x;
    } else if (LA_RANGE_HIE(h, 180, 240)) {
        rgb[0] = 0.0f; rgb[1] = x; rgb[2] = c;
    } else if (LA_RANGE_HIE(h, 240, 300)) {
        rgb[0] = x; rgb[1] = 0.0f; rgb[2] = c;
    } else if (LA_RANGE_HIE(h, 300, 360)) {
        rgb[0] = c; rgb[1] = 0.0f; rgb[2] = x;
    }

    *r = ((rgb[0] + m) * 255);
    *g = ((rgb[1] + m) * 255);
    *b = ((rgb[2] + m) * 255);
}

/**
* @brief Constantly cycle through the hue spectrum at a specified rate.
* 
* @param hue A pointer to the hue value to change.
* @param speed The speed at which hue is added to.
* @return void
**/
void LibAxis_Color_CycleHue(float* hue, float speed) {
    if (*hue >= 0.0f && *hue < 360.0f) {
        *hue += speed;
    } else if (*hue >= 360.0f) {
        *hue = 0.0f;
    }
}

/**
* @brief Interpolate along a cosine wave.
* See https://www.desmos.com/calculator/tzxvgjvpmu to illustrate how this works.
* 
* @param value A pointer to the float to change.
* @param timer A constant timer that affects the rate of change.
* @param min The minimum of val.
* @return void
**/
void LibAxis_Color_LerpCosine(float* value, float timer, float min) {
    // Clamp Minimum
    min = (min < 0.0f) ? 0.0f : (min > 1.0f) ? 1.0f : min;

    *value = (((cosf(timer) + 1.0f) / 2) * (1.0f - min) + min);
}

/**
* @brief Interpolate to a color that is a percentage between two other colors.
* 
* @param rgba1 The first color as a 32-bit RGBA value.
* @param rgba2 The second color as a 32-bit RGBA value.
* @param percent The percent (0.0f to 1.0f for 0% to 100%, respectively) of transition from the first to second color.
* @return Color_RGBA32 
**/
Color_RGBA32 LibAxis_Color_LerpRBA32Percent(uint32_t rgba1, uint32_t rgba2, float percent) {
    Color_RGBA32 a, b, return_value;
    a.rgba = rgba1;
    b.rgba = rgba2;

    return_value.r = LA_TWEEN_PERCENT(a.r, b.r, percent);
    return_value.g = LA_TWEEN_PERCENT(a.g, b.g, percent);
    return_value.b = LA_TWEEN_PERCENT(a.b, b.b, percent);
    return_value.a = 255;

    return return_value;
}
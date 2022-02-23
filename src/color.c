/**
 * @file: color.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief A colorful library.
**/

#include "libaxis.h"

/**
* @brief Convert RGB color space to HSV
* 
* @param r Red Channel (0 - 255)
* @param g Green Channel (0 - 255)
* @param b Blue Channel (0 - 255)
* @param h Hue (Pointer)
* @param s Saturation (Pointer)
* @param b Value (Pointer)
* @return void 
**/
void LibAxis_Color_RGBToHSV(unsigned char r, unsigned char g, unsigned char b, float* h, float* s, float* v)
{
    float _r, _g, _b;
    float cmax, cmin, delta;

    // Clamp
    r = (r < 0) ? 0 : (r > 255) ? 255 : r;
    g = (g < 0) ? 0 : (g > 255) ? 255 : g;
    b = (b < 0) ? 0 : (b > 255) ? 255 : b;

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
            *h = (60 * LibAxis_ModF(((_g - _b)), 6));
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
**/
void LibAxis_Color_HSVToRGB(float h, float s, float v, unsigned char* r, unsigned char* g, unsigned char* b) {
    float c, x, m;
    float rgb[3];

    // Clamp
    h = (h < 0.0f) ? 0.0f : (h >= 360.0f) ? 359.0f : h;
    s = (s < 0.0f) ? 0.0f : (s > 1.0f) ? 1.0f : s;
    v = (v < 0.0f) ? 0.0f : (v > 1.0f) ? 1.0f : v;

    c = (v * s);
    x = c * (1.0f - LA_ABS(LibAxis_ModF((h / 60.0f), 2.0f) - 1.0f));
    m = (v - c);

    if (h >= 0.0f && h < 60.0f) {
        rgb[0] = c; rgb[1] = x; rgb[2] = 0;
    } else if (h >= 60.0f && h < 120.0f) {
        rgb[0] = x; rgb[1] = c; rgb[2] = 0;
    } else if (h >= 120.0f && h < 180.0f) {
        rgb[0] = 0; rgb[1] = c; rgb[2] = x;
    } else if (h >= 180.0f && h < 240.0f) {
        rgb[0] = 0; rgb[1] = x; rgb[2] = c;
    } else if (h >= 240.0f && h < 300.0f) {
        rgb[0] = x; rgb[1] = 0; rgb[2] = c;
    } else if (h >= 300.0f && h < 360.0f) {
        rgb[0] = c; rgb[1] = 0; rgb[2] = x;
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
Color_RGBA32 LibAxis_Color_LerpRBA32Percent(unsigned int rgba1, unsigned int rgba2, float percent) {
    Color_RGBA32 a, b, return_value;
    a.rgba = rgba1;
    b.rgba = rgba2;

    return_value.r = LA_TWEEN_PERCENT(a.r, b.r, percent);
    return_value.g = LA_TWEEN_PERCENT(a.g, b.g, percent);
    return_value.b = LA_TWEEN_PERCENT(a.b, b.b, percent);
    return_value.a = 255;

    return return_value;
}
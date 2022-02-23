/**
 * @file: color.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief A colorful library.
**/

#include "global.h"

/**
* @brief Convert a red, green, and blue value to an HSV structure.
* 
* @param red Red Channel (0 - 255)
* @param green Green Channel (0 - 255)
* @param blue Blue Channel (0 - 255)
* @return Color_HSVf 
**/
Color_HSVf LibAxis_Color_RGBToHSVf(u8 red, u8 green, u8 blue) {
    Color_HSVf return_value;
    f32 _r, _g, _b;
    f32 cmax, cmin, delta;

    _r = (red / 255.0f);
    _g = (green / 255.0f);
    _b = (blue / 255.0f);

    cmax = LibAxis_MaxF3(_r, _g, _b);
    cmin = LibAxis_MinF3(_r, _g, _b);
    delta = (cmax - cmin);

    if (cmax == 0.0f) {
        return_value.s = 0.0f;
        return_value.h = 0.0f;
    } else if (delta == 0.0f) {
        return_value.s = 0.0f;
        return_value.h = 0.0f;
    } else {
        return_value.s = (delta / cmax);

        if (cmax == _r) {
            return_value.h = (60 * LibAxis_ModF(((_g - _b)), 6));
        } else if (cmax == _g) {
            return_value.h = (60 * (((_b - _r) / delta) + 2));
        } else {
            return_value.h = (60 * (((_r - _g) / delta) + 4));
        }
    }

    if (return_value.h < 0.0f) {
        return_value.h += 360.0f;
    }

    return_value.v = cmax;

    return return_value;
}

/**
* @brief Convert an HSV structure to an RGBA32 color structure.
* 
* @param hsv A Hue/Saturation/Value Structure
* @return Color_RGBA32 
**/
Color_RGBA32 LibAxis_Color_HSVfToRGBA32(Color_HSVf* hsv) {
    Color_RGBA32 return_value;
    f32 c, x, m;
    f32 _rgb[3];

    c = (hsv->v * hsv->s);
    x = c * (1 - fabsf(LibAxis_ModF((hsv->h / 60), 2 - 1)));
    m = (hsv->v - c);

    if (hsv->h >= 0.0f && hsv->h <= 60.0f) {
        _rgb[0] = c; _rgb[1] = x; _rgb[2] = 0;
    }
    else if (hsv->h >= 60.0f && hsv->h <= 120.0f) {
        _rgb[0] = x; _rgb[1] = c; _rgb[2] = 0;
    }
    else if (hsv->h >= 120.0f && hsv->h <= 180.0f) {
        _rgb[0] = 0; _rgb[1] = c; _rgb[2] = x;
    }
    else if (hsv->h >= 180.0f && hsv->h <= 240.0f) {
        _rgb[0] = 0; _rgb[1] = x; _rgb[2] = c;
    }
    else if (hsv->h >= 240.0f && hsv->h <= 300.0f) {
        _rgb[0] = x; _rgb[1] = 0; _rgb[2] = c;
    }
    else if (hsv->h >= 300.0f && hsv->h <= 360.0f) {
        _rgb[0] = c; _rgb[1] = 0; _rgb[2] = x;
    }

    return_value.r = (u8)((_rgb[0] + m) * 255);
    return_value.g = (u8)((_rgb[1] + m) * 255);
    return_value.b = (u8)((_rgb[2] + m) * 255);
    return_value.a = 255;

    return return_value;
}

/**
* @brief Constantly cycle through the hue spectrum at a specified rate.
* 
* @param hue A pointer to the hue value to change.
* @param speed The speed at which hue is added to.
* @return void
**/
void LibAxis_Color_CycleHue(f32* hue, f32 speed) {
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
* @param val A pointer to the float to change.
* @param timer A constant timer that affects the rate of change.
* @param min The minimum of val.
* @return void
**/
void LibAxis_Color_LerpCosine(f32* val, f32 timer, f32 min) {
    /* Cap Minimum */
    if (min < 0.0f) {
        min = 0.0f;
    } else if (min > 1.0f) {
        min = 1.0f;
    }

    *val = (((cosf(timer) + 1.0f) / 2) * (1.0f - min) + min);
}

/**
* @brief Interpolate to a color that is a percentage between two other colors.
* 
* @param rgba1 The first color as a 32-bit RGBA value.
* @param rgba2 The second color as a 32-bit RGBA value.
* @param percent The percent (0.0f to 1.0f for 0% to 100%, respectively) of transition from the first to second color.
* @return Color_RGBA32 
**/
Color_RGBA32 LibAxis_Color_LerpPercent(u32 rgba1, u32 rgba2, f32 percent) {
    Color_RGBA32 a, b, return_value;
    a.rgba = rgba1;
    b.rgba = rgba2;

    return_value.r = TWEEN_PERCENT(a.r, b.r, percent);
    return_value.g = TWEEN_PERCENT(a.g, b.g, percent);
    return_value.b = TWEEN_PERCENT(a.b, b.b, percent);
    return_value.a = 255;

    return return_value;
}
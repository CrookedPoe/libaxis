/**
 * @file: math.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief A math library.
**/

#include "global.h"

/**
* @brief Determine the smallest value from a set of 3.
* @param a
* @param b 
* @param c 
* @return float 
**/
f32 LibAxis_MinF3(f32 a, f32 b, f32 c) {
    return MIN(a, MIN(b, c));
}

/**
* @brief Determine the largest value from a set of 3.
* @param a
* @param b 
* @param c 
* @return float 
**/
f32 LibAxis_MaxF3(f32 a, f32 b, f32 c) {
    return MAX(a, MAX(b, c));
}

/**
* @brief Modulous of two floats (x % y).
* @param x
* @param y
* @return float 
**/
f32 LibAxis_ModF(f32 x, f32 y) {
    return (y == 0.0f) ? 0.0f : (x - (x / y) * y);
}

/**
* @brief Raise base to the power of exp
* 
* @param base 
* @param exp exponent
* @return int 
**/
s32 LibAxis_PowI(s32 base, s32 exp) {
    s32 ret = 1;

    while (exp > 0) {
        exp--;
        ret *= base;
    }
    return ret;
}

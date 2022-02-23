/**
 * @file: math.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief A math library.
**/

#include "libaxis.h"

/**
* @brief Determine the smallest value from a set of 3.
* @param a
* @param b 
* @param c 
* @return float 
**/
float LibAxis_MinF3(float a, float b, float c) {
    return LA_MIN2(a, LA_MIN2(b, c));
}

/**
* @brief Determine the largest value from a set of 3.
* @param a
* @param b 
* @param c 
* @return float 
**/
float LibAxis_MaxF3(float a, float b, float c) {
    return LA_MAX2(a, LA_MAX2(b, c));
}

/**
* @brief Modulous of two floats (x % y).
* @param x
* @param y
* @return float 
**/
float LibAxis_ModF(float x, float y) {
    return (y == 0.0f) ? 0.0f : (x - (x / y) * y);
}

/**
* @brief Raise base to the power of exp
* 
* @param base 
* @param exp exponent
* @return int 
**/
int LibAxis_PowI(int base, int exp) {
    int ret = 1;

    while (exp > 0) {
        exp--;
        ret *= base;
    }
    return ret;
}

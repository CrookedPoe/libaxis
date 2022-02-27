/**
 * @file: math.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief A math library.
**/

#include "../include/libaxis.h"

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
    float mod;

    mod = (x < 0) ? -x : x;
    y = (y < 0) ? -y : y;

    while (mod >= y)
        mod -= y;
    
    return (x < 0) ? -mod : mod;
}

/**
* @brief Raise base to the power of exp
* 
* @param base 
* @param exp exponent
* @return int32_t 
**/
int32_t LibAxis_PowI(int32_t base, int32_t exp) {
    int32_t ret = 1;

    while (exp > 0) {
        exp--;
        ret *= base;
    }
    return ret;
}

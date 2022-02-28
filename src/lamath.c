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

/**
* @brief Raise base to the power of exp (float)
* 
* @param base 
* @param exp exponent
* @return float 
**/
float LibAxis_PowF(float base, int32_t exp) {
    float ret = 1;

    if (exp == 0)
        return 1;
    ret = LibAxis_PowF(base, exp / 2);
    if (exp % 2 == 0)
        return ret*ret;
    else {
        if (exp > 0)
            return base * ret * ret;
        else
            return (ret * ret) / base;
    }
}

/**
* @brief Return the absolute value of n.
* 
* @param n
* @return int32_t 
**/
int32_t LibAxis_Abs(int32_t n) {
    return (n < 0) ? -n : n;
}

/**
* @brief Return the Sine of f;
* 
* @param f
* @return float 
**/
float LibAxis_SinF(float f) {
    return ((float)sin((double)f));
}

/**
* @brief Return the Cosine of f;
* 
* @param f
* @return float 
**/
float LibAxis_CosF(float f) {
    return ((float)cos((double)f));
}

/**
* @brief Return the Inverse Cosine of f;
* 
* @param f
* @return float 
**/
float LibAxis_ArcCosF(float f) {
    return LibAxis_PowF(LibAxis_CosF((f)), -1);
}

/**
* @brief Return the Square Root of n
* 
* @param n
* @return float 
**/
float LibAxis_SqrtF(float n) {
    int s, m, e;
    s = 0;
    e = n;

    float sqrt;
 
    while (s <= e) {
 
        m = (s + e) / 2;
 
        if (m * m == n) {
            sqrt = m;
            break;
        }
 
        if (m * m < n) {
            sqrt=s;
            s = m + 1;
        }
 
        else {
            e = m - 1;
        }
    }
 
    float inc = 0.1;
    for (int i = 0; i < 5; i++) {
        while (sqrt * sqrt <= n) {
            sqrt += inc;
        }
 
        sqrt = sqrt - inc;
        inc = inc / 10;
    }
    return sqrt;
}
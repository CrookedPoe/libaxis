#ifndef LIBAXIS_MACROS_H
#define LIBAXIS_MACROS_H

/* Find the minimum value of two inputs. */
#define LA_MIN2(MINA0, MINA1)                  (((MINA0)<(MINA1))?(MINA0):(MINA1))

/* Find the maximum value of two inputs. */
#define LA_MAX2(MAXA0, MAXA1)                  (((MAXA0)>(MAXA1))?(MAXA0):(MAXA1))

/* Find the minimum value of three inputs. */
#define LA_MIN3(MINA0, MINA1, MINA2)           LA_MIN2((MINA0),LA_MIN2((MINA1),(MINA2)))

/* Find the maximum value of three inputs. */
#define LA_MAX3(MAXA0, MAXA1, MAXA2)           LA_MAX2((MAXA0),LA_MAX2((MAXA1),(MAXA2)))

/* Find the absolute value of an input. */
#define LA_ABS(ABSA0)                          (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#define fabsf(n)                               LA_ABS((n))

/* Interpolate to the percentage of a value between a minimum and maximum bound. */
#define LA_TWEEN_PERCENT(MIN, MAX, PER)        ((MIN)*(PER)+(MAX)*(1.0f-(PER)))

/* Test if a value is in the range [LO, HI) */
#define LA_RANGE_HIE(V, LO, HI)                ((LO) <= (V) && (V) < (HI))

/* Clamp a value to within the range [LO, HI] */
#define LA_CLAMP(CLARG0, LO, HI)               (((CLARG0) < (LO)) ? (LO) : ((CLARG0) > (HI)) ? (HI) : (CLARG0))

/* Clamp a value to within the range [0, 1] */
#define LA_CLAMP01(CLARG0)                     LA_CLAMP((CLARG0), 0, 1)                     

#endif /* LIBAXIS_MACROS_H */
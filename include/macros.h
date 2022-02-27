#ifndef LIBAXIS_MACROS_H
#define LIBAXIS_MACROS_H

#define LA_MIN2(MINA0, MINA1)                  (((MINA0)<(MINA1))?(MINA0):(MINA1))
#define LA_MAX2(MAXA0, MAXA1)                  (((MAXA0)>(MAXA1))?(MAXA0):(MAXA1))
#define LA_MIN3(MINA0, MINA1, MINA2)           LA_MIN2((MINA0),LA_MIN2((MINA1),(MINA2)))
#define LA_MAX3(MAXA0, MAXA1, MAXA2)           LA_MAX2((MAXA0),LA_MAX2((MAXA1),(MAXA2)))
#define LA_ABS(ABSA0)                          (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#define LA_TWEEN_PERCENT(MIN, MAX, PER)        ((MIN)*(PER)+(MAX)*(1.0f-(PER)))
#define LA_RANGE_HIE(V, LO, HI)                ((LO) <= (V) && (V) < (HI))
#define LA_CLAMP(CLARG0, LO, HI)               (((CLARG0) < (LO)) ? (LO) : ((CLARG0) > (HI)) ? (HI) : (CLARG0))
#define LA_CLAMP01(CLARG0)                     LA_CLAMP((CLARG0), 0, 1)

#endif /* LIBAXIS_MACROS_H */
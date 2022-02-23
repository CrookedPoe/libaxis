#ifndef LIBAXIS_MACROS_H
#define LIBAXIS_MACROS_H

#define LA_MIN2(MINA0, MINA1)                  (((MINA0)<(MINA1))?(MINA0):(MINA1))
#define LA_MAX2(MAXA0, MAXA1)                  (((MAXA0)>(MAXA1))?(MAXA0):(MAXA1))
#define LA_MIN3(MINA0, MINA1, MINA2)           LA_MIN2((MINA0),LA_MIN2((MINA1),(MINA2)))
#define LA_MAX3(MAXA0, MAXA1, MAXA2)           LA_MAX2((MAXA0),LA_MAX2((MAXA1),(MAXA2)))
#define LA_MODF(MODFA0, MODFA1)                ((MODFA1)==0.0f)?0.0f:((MODFA0)-((MODFA0)/(MODFA1))*(MODFA1))
#define LA_ABS(ABSA0)                          (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#define LA_TWEEN_PERCENT(MIN, MAX, PER)        ((MIN)*(PER)+(MAX)*(1.0f-(PER)))

#endif /* LIBAXIS_MACROS_H */
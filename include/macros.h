#ifndef AXIS_MACROS_H
#define AXIS_MACROS_H

#define MIN2(MINA0, MINA1)                  (((MINA0)<(MINA1))?(MINA0):(MINA1))
#define MAX2(MAXA0, MAXA1)                  (((MAXA0)>(MAXA1))?(MAXA0):(MAXA1))
#define MIN3(MINA0, MINA1, MINA2)           MIN2((MINA0),MIN2((MINA1),(MINA2)))
#define MAX3(MAXA0, MAXA1, MAXA2)           MAX2((MAXA0),MAX2((MAXA1),(MAXA2)))
#define MODF(MODFA0, MODFA1)                ((MODFA1)==0.0f)?0.0f:((MODFA0)-((MODFA0)/(MODFA1))*(MODFA1))
#define ABS(ABSA0)                          (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#define TWEEN_PERCENT(MIN, MAX, PER)        ((MIN)*(PER)+(MAX)*(1.0f-(PER))) 

#endif /* AXIS_MACROS_H */
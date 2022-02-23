#ifndef LIBAXIS_MATH_COMMON_H
#define LIBAXIS_MATH_COMMON_H

#define PI (3.14159265358979323)
#define TAU (PI * 2.0)
#define HPI (PI * 0.5)

#define DEG2RAD (0.0174532925199433)
#define RAD2DEG (57.29577951308231)
#define S2RAD (0.0000958737992429)
#define S2DEG (0.0054931640625)
#define RAD2S (10430.37835047045)
#define DEG2S (182.0444444444444)

// My math could be wrong here
#define C2SEC (1.06666666e-8)
#define C2MSEC (0.00001066666)

#define STOR(RHS) (S2RAD * RHS)
#define STOD(RHS) (S2DEG * RHS)
#define RTOS(RHS) (RAD2S * RHS)
#define DTOS(RHS) (DEG2S * RHS)
#define DTOR(RHS) (DEG2RAD * RHS)
#define RTOD(RHS) (RAD2DEG * RHS)

// If you ever need to explicitly truncate these
#define STORF(RHS) ((float)S2RAD * RHS)
#define STODF(RHS) ((float)S2DEG * RHS)
#define RTOSF(RHS) ((float)RAD2S * RHS)
#define DTOSF(RHS) ((float)DEG2S * RHS)
#define DTORF(RHS) ((float)DEG2RAD * RHS)
#define RTODF(RHS) ((float)RAD2DEG * RHS)

#define OS_CYCLES_TO_SEC(LHS) (((double)(LHS)) * C2SEC)
#define OS_CYCLES_TO_MSEC(LHS) (((double)(LHS)) * C2MSEC)


static const double MATH_PI = PI;
static const double MATH_TAU = TAU;
static const double MATH_HPI = HPI;
static const float MATHF_PI = (float)PI;
static const float MATHF_TAU = (float)TAU;
static const float MATHF_HPI = (float)HPI;

static const double MATH_DTOR = DEG2RAD;
static const double MATH_RTOD = RAD2DEG;
static const double MATH_STOR = S2RAD;
static const double MATH_STOD = S2DEG;
static const double MATH_RTOS = RAD2S;
static const double MATH_DTOS = DEG2S;
static const float MATHF_DTOR = (float)DEG2RAD;
static const float MATHF_RTOD = (float)RAD2DEG;
static const float MATHF_STOR = (float)S2RAD;
static const float MATHF_STOD = (float)S2DEG;
static const float MATHF_RTOS = (float)RAD2S;
static const float MATHF_DTOS = (float)DEG2S;

static const double MATH_C2SEC = C2SEC;
static const double MATH_C2MSEC = C2MSEC;
static const float MATHF_C2SEC = (float)C2SEC;
static const float MATHF_C2MSEC = (float)C2MSEC;

#endif /* LIBAXIS_MATH_COMMON_H */
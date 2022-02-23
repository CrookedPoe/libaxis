#ifndef AXIS_MATH_H
#define AXIS_MATH_H

typedef struct {
    s16 x, y;
} Vec2s;

typedef struct {
    s32 x, y;
} Vec2i;

#ifndef Z64MATH_H
typedef struct {
    f32 x, y;
} Vec2f;

typedef struct {
    s16 x, y, z;
} Vec3s;

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    f32 x, y, z;
} Vec3f;
#endif /* Z64MATH_H */

typedef struct {
    s16 x, y, z, w;
} Vec4s;

typedef struct {
    s32 x, y, z, w;
} Vec4i;

typedef struct {
    f32 x, y, z, w;
} Vec4f, QuatF;

#ifndef MACROS_H
#define MIN(MINA0, MINA1)               (((MINA0)<(MINA1))?(MINA0):(MINA1))
#define MAX(MAXA0, MAXA1)               (((MAXA0)>(MAXA1))?(MAXA0):(MAXA1))
#define ABS(ABSA0)                      (((ABSA0)<0)?(-(ABSA0)):ABSA0)
#endif /* MACROS_H */
#define TWEEN_PERCENT(MIN, MAX, PER)    ((MIN) * (PER) + (MAX) * (1.0f - (PER)))

#define PI                              (3.14159265358979323846)
#define TAU                             (PI * 2.0)
#define HPI                             (PI * 0.5)

#define DEG2RAD                         (0.0174532925199433)
#define RAD2DEG                         (57.29577951308231)
#define S2RAD                           (0.0000958737992429)
#define S2DEG                           (0.0054931640625)
#define RAD2S                           (10430.37835047045)
#define DEG2S                           (182.0444444444444)

// My math could be wrong here
#define C2SEC                           (1.06666666e-8)
#define C2MSEC                          (0.00001066666)

#define STOR(RHS)                       (S2RAD * RHS)
#define STOD(RHS)                       (S2DEG * RHS)
#define RTOS(RHS)                       (RAD2S * RHS)
#define DTOS(RHS)                       (DEG2S * RHS)
#define DTOR(RHS)                       (DEG2RAD * RHS)
#define RTOD(RHS)                       (RAD2DEG * RHS)

// If you ever need to explicitly truncate these
#define STORF(RHS)                      ((f32)S2RAD * RHS)
#define STODF(RHS)                      ((f32)S2DEG * RHS)
#define RTOSF(RHS)                      ((f32)RAD2S * RHS)
#define DTOSF(RHS)                      ((f32)DEG2S * RHS)
#define DTORF(RHS)                      ((f32)DEG2RAD * RHS)
#define RTODF(RHS)                      ((f32)RAD2DEG * RHS)

#define OS_CYCLES_TO_SEC(LHS)           (((f64)(LHS)) * C2SEC)
#define OS_CYCLES_TO_MSEC(LHS)          (((f64)(LHS)) * C2MSEC)


static const f64 MATH_PI                = PI;
static const f64 MATH_TAU               = TAU;
static const f64 MATH_HPI               = HPI;
static const f32 MATHF_PI               = (f32)PI;
static const f32 MATHF_TAU              = (f32)TAU;
static const f32 MATHF_HPI              = (f32)HPI;

static const f64 MATH_DTOR              = DEG2RAD;
static const f64 MATH_RTOD              = RAD2DEG;
static const f64 MATH_STOR              = S2RAD;
static const f64 MATH_STOD              = S2DEG;
static const f64 MATH_RTOS              = RAD2S;
static const f64 MATH_DTOS              = DEG2S;
static const f32 MATHF_DTOR             = (f32)DEG2RAD;
static const f32 MATHF_RTOD             = (f32)RAD2DEG;
static const f32 MATHF_STOR             = (f32)S2RAD;
static const f32 MATHF_STOD             = (f32)S2DEG;
static const f32 MATHF_RTOS             = (f32)RAD2S;
static const f32 MATHF_DTOS             = (f32)DEG2S;

static const f64 MATH_C2SEC             = C2SEC;
static const f64 MATH_C2MSEC            = C2MSEC;
static const f32 MATHF_C2SEC            = (f32)C2SEC;
static const f32 MATHF_C2MSEC           = (f32)C2MSEC;

/*#define acosf                           Math_FAcosF

#define VEC2F_NEW(x, y)                 (Vec2f){(x), (y)}
#define VEC3F_NEW(x, y, z)              (Vec3f){(x), (y), (z)}
#define VEC4F_NEW(x, y, z, w)           (Vec4f){(x), (y), (z), (w)}
#define VEC2I_NEW(x, y)                 (Vec2i){(x), (y)}
#define VEC3I_NEW(x, y, z)              (Vec3i){(x), (y), (z)}
#define VEC4I_NEW(x, y, z, w)           (Vec4i){(x), (y), (z), (w)}
#define VEC2S_NEW(x, y)                 (Vec2s){(x), (y)}
#define VEC3S_NEW(x, y, z)              (Vec3s){(x), (y), (z)}
#define VEC4S_NEW(x, y, z, w)           (Vec4s){(x), (y), (z), (w)}
#define VEC2_IS_EQUAL(lhs, rhs)         (lhs.x == rhs.x && lhs.y == rhs.y)
#define VEC3_IS_EQUAL(lhs, rhs)         (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
#define VEC4_IS_EQUAL(lhs, rhs)         (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w)
#define VEC3F_X(r, p, y)                ((r) * (sinf(DTOR(y))) * (cosf(DTOR(p))))
#define VEC3F_Y(r, p, y)                ((r) * (cosf(DTOR(y))) * (sinf(DTOR(p))))
#define VEC3F_Z(r, p, y)                ((r) * (cosf(DTOR(y))) * (cosf(DTOR(p))))

#define QuatF_AddAssignment             Vec4f_AddAssignment
#define QuatF_SubAssignment             Vec4f_SubAssignment
#define QuatF_MultiplyAssignment        Vec4f_MultiplyAssignment
#define QuatF_DivideAssignment          Vec4f_DivideAssignment
#define QuatF_MultiplyFAssignment       Vec4f_MultiplyFAssignment
#define QuatF_DivideFAssignment         Vec4f_DivideFAssignment
#define QuatF_Add                       Vec4f_Add
#define QuatF_Sub                       Vec4f_Sub
#define QuatF_Multiply                  Vec4f_Multiply
#define QuatF_Divide                    Vec4f_Divide
#define QuatF_MultiplyF                 Vec4f_MultiplyF
#define QuatF_DivideF                   Vec4f_DivideF
#define QuatF_Dot                       Vec4f_Dot
#define QuatF_Cross                     Vec4f_Cross
#define QuatF_SquareMagnitude           Vec4f_SquareMagnitude
#define QuatF_SquareMagnitudePtr        Vec4f_SquareMagnitudePtr
#define QuatF_MagnitudePtr              Vec4f_MagnitudePtr
#define QuatF_NormalizeAssignment       Vec4f_NormalizeAssignment
#define QuatF_Normalize                 Vec4f_Normalize
#define QuatF_Distance                  Vec4f_Distance
#define QuatF_InverseAssignment         Vec4f_InverseAssignment
#define QuatF_Inverse                   Vec4f_Inverse

#define Vec2f_Right                     VEC2F_NEW(1.0f, 0.0f);
#define Vec2f_Up                        VEC2F_NEW(0.0f, 1.0f);
#define Vec2f_Left                      VEC2F_NEW(-1.0f, 0.0f);
#define Vec2f_Down                      VEC2F_NEW(0.0f, -1.0f);
#define Vec2f_Zero                      VEC2F_NEW(0.0f, 0.0f);
#define Vec3f_Right                     VEC3F_NEW(1.0f, 0.0f, 0.0f);
#define Vec3f_Up                        VEC3F_NEW(0.0f, 1.0f, 0.0f);
#define Vec3f_Forward                   VEC3F_NEW(0.0f, 0.0f, 1.0f);
#define Vec3f_Left                      VEC3F_NEW(-1.0f, 0.0f, 0.0f);
#define Vec3f_Down                      VEC3F_NEW(0.0f, -1.0f, 0.0f);
#define Vec3f_Backward                  VEC3F_NEW(0.0f, 0.0f, -1.0f);
#define Vec3f_Zero                      VEC3F_NEW(0.0f, 0.0f, 0.0f);
#define Vec4f_Right                     VEC4F_NEW(1.0f, 0.0f, 0.0f, 0.0f);
#define Vec4f_Up                        VEC4F_NEW(0.0f, 1.0f, 0.0f, 0.0f);
#define Vec4f_Forward                   VEC4F_NEW(0.0f, 0.0f, 1.0f, 0.0f);
#define Vec4f_Identity                  VEC4F_NEW(0.0f, 0.0f, 0.0f, 1.0f);
#define Vec4f_Left                      VEC4F_NEW(-1.0f, 0.0f, 0.0f, 0.0f);
#define Vec4f_Down                      VEC4F_NEW(0.0f, -1.0f, 0.0f, 0.0f);
#define Vec4f_Backward                  VEC4F_NEW(0.0f, 0.0f, -1.0f, 0.0f);
#define Vec4f_Ndentity                  VEC4F_NEW(0.0f, 0.0f, 0.0f, -1.0f);
#define Vec4f_Zero                      VEC4F_NEW(0.0f, 0.0f, 0.0f, 0.0f);
#define Vec2i_Right                     VEC2I_NEW(1, 0);
#define Vec2i_Up                        VEC2I_NEW(0, 1);
#define Vec2i_Left                      VEC2I_NEW(-1, 0);
#define Vec2i_Down                      VEC2I_NEW(0, -1);
#define Vec2i_Zero                      VEC2I_NEW(0, 0);
#define Vec3i_Right                     VEC3I_NEW(1, 0, 0);
#define Vec3i_Up                        VEC3I_NEW(0, 1, 0);
#define Vec3i_Forward                   VEC3I_NEW(0, 0, 1);
#define Vec3i_Left                      VEC3I_NEW(-1, 0, 0);
#define Vec3i_Down                      VEC3I_NEW(0, -1, 0);
#define Vec3i_Backward                  VEC3I_NEW(0, 0, -1);
#define Vec3i_Zero                      VEC3I_NEW(0, 0, 0);
#define Vec4i_Right                     VEC4I_NEW(1, 0, 0, 0);
#define Vec4i_Up                        VEC4I_NEW(0, 1, 0, 0);
#define Vec4i_Forward                   VEC4I_NEW(0, 0, 1, 0);
#define Vec4i_Identity                  VEC4I_NEW(0, 0, 0, 1);
#define Vec4i_Left                      VEC4I_NEW(-1, 0, 0, 0);
#define Vec4i_Down                      VEC4I_NEW(0, -1, 0, 0);
#define Vec4i_Backward                  VEC4I_NEW(0, 0, -1, 0);
#define Vec4i_Ndentity                  VEC4I_NEW(0, 0, 0, -1);
#define Vec4i_Zero                      VEC4I_NEW(0, 0, 0, 0);
#define Vec2s_Right                     VEC2S_NEW(1, 0);
#define Vec2s_Up                        VEC2S_NEW(0, 1);
#define Vec2s_Left                      VEC2S_NEW(-1, 0);
#define Vec2s_Down                      VEC2S_NEW(0, -1);
#define Vec2s_Zero                      VEC2S_NEW(0, 0);
#define Vec3s_Right                     VEC3S_NEW(1, 0, 0);
#define Vec3s_Up                        VEC3S_NEW(0, 1, 0);
#define Vec3s_Forward                   VEC3S_NEW(0, 0, 1);
#define Vec3s_Left                      VEC3S_NEW(-1, 0, 0);
#define Vec3s_Down                      VEC3S_NEW(0, -1, 0);
#define Vec3s_Backward                  VEC3S_NEW(0, 0, -1);
#define Vec3s_Zero                      VEC3S_NEW(0, 0, 0);
#define Vec4s_Right                     VEC4S_NEW(1, 0, 0, 0);
#define Vec4s_Up                        VEC4S_NEW(0, 1, 0, 0);
#define Vec4s_Forward                   VEC4S_NEW(0, 0, 1, 0);
#define Vec4s_Identity                  VEC4S_NEW(0, 0, 0, 1);
#define Vec4s_Left                      VEC4S_NEW(-1, 0, 0, 0);
#define Vec4s_Down                      VEC4S_NEW(0, -1, 0, 0);
#define Vec4s_Backward                  VEC4S_NEW(0, 0, -1, 0);
#define Vec4s_Ndentity                  VEC4S_NEW(0, 0, 0, -1);
#define Vec4s_Zero                      VEC4S_NEW(0, 0, 0, 0);
#define QuatF_Right                     Vec4f_Right   
#define QuatF_Up                        Vec4f_Up      
#define QuatF_Forward                   Vec4f_Forward 
#define QuatF_Identity                  Vec4f_Identity
#define QuatF_Left                      Vec4f_Left    
#define QuatF_Down                      Vec4f_Down    
#define QuatF_Backward                  Vec4f_Backward
#define QuatF_Ndentity                  Vec4f_Ndentity
#define QuatF_Zero                      Vec4f_Zero */

#endif /* AXIS_MATH_H */
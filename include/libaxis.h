#ifndef LIBAXIS_H
#define LIBAXIS_H

#ifdef __LA_STANDALONE__
#ifdef MIPS
#define cosf __builtin_cosf
#define sinf __builtin_sinf
#define sqrtf __builtin_sqrtf
#define powf __builtin_powf
#define acosf __builtin_acosf
#define fmodf __builtin_fmodf
#define fabsf __builtin_fabsf
#else
#include <math.h>
#endif
#endif

#include "lainttypes.h"
#include "macros.h"
#include "math/lamath.h"
#include "color.h"

/* math.c */
extern float LibAxis_MinF3(float a, float b, float c);
extern float LibAxis_MaxF3(float a, float b, float c);
extern float LibAxis_ModF(float x, float y);
extern int32_t LibAxis_PowI(int32_t base, int32_t exp);

/* color.c */
extern void LibAxis_Color_RGBToHSV(uint8_t r, uint8_t g, uint8_t b, float* h, float* s, float* v);
extern void LibAxis_Color_HSVToRGB(float h, float s, float v, uint8_t* r, uint8_t* g, uint8_t* b);
extern void LibAxis_Color_CycleHue(float* hue, float speed);
extern void LibAxis_Color_LerpCosine(float* value, float timer, float min);
extern Color_RGBA32 LibAxis_Color_LerpRBA32Percent(uint32_t rgba1, uint32_t rgba2, float percent);

/* vector.c */
extern void Vec2f_AddAssignment(Vec2f* lhs, Vec2f* rhs);
extern void Vec2f_SubAssignment(Vec2f* lhs, Vec2f* rhs);
extern void Vec2f_MultiplyAssignment(Vec2f* lhs, Vec2f* rhs);
extern void Vec2f_DivideAssignment(Vec2f* lhs, Vec2f* rhs);
extern void Vec2f_MultiplyAssignmentF(Vec2f* lhs, float rhs);
extern void Vec2f_DivideAssignmentF(Vec2f* lhs, float rhs);
extern Vec2f Vec2f_Add(Vec2f lhs, Vec2f rhs);
extern Vec2f Vec2f_Sub(Vec2f lhs, Vec2f rhs);
extern Vec2f Vec2f_Multiply(Vec2f lhs, Vec2f rhs);
extern Vec2f Vec2f_Divide(Vec2f lhs, Vec2f rhs);
extern Vec2f Vec2f_MultiplyF(Vec2f lhs, float rhs);
extern Vec2f Vec2f_DivideF(Vec2f lhs, float rhs);
extern float Vec2f_Dot(Vec2f* lhs, Vec2f* rhs);
extern float Vec2f_SquareMagnitude(Vec2f lhs);
extern float Vec2f_Magnitude(Vec2f lhs);
extern float Vec2f_SquareMagnitudePtr(Vec2f* lhs);
extern float Vec2f_MagnitudePtr(Vec2f* lhs);
extern void Vec2f_NormalizeAssignment(Vec2f* lhs);
extern Vec2f Vec2f_Normalize(Vec2f lhs);
extern float Vec2f_Distance(Vec2f lhs, Vec2f rhs);
extern void Vec2f_InverseAssignment(Vec2f* lhs);
extern Vec2f Vec2f_Inverse(Vec2f lhs);
extern void Vec2f_FromVec2iAssignment(Vec2f* lhs, Vec2i* rhs);
extern void Vec2f_FromVec2sAssignment(Vec2f* lhs, Vec2s* rhs);
extern Vec2f Vec2f_FromVec2i(Vec2i* lhs);
extern Vec2f Vec2f_FromVec2s(Vec2s* lhs);
extern void Vec2i_AddAssignment(Vec2i* lhs, Vec2i* rhs);
extern void Vec2i_SubAssignment(Vec2i* lhs, Vec2i* rhs);
extern void Vec2i_MultiplyAssignment(Vec2i* lhs, Vec2i* rhs);
extern void Vec2i_DivideAssignment(Vec2i* lhs, Vec2i* rhs);
extern void Vec2i_MultiplyAssignmentF(Vec2i* lhs, int32_t rhs);
extern void Vec2i_DivideAssignmentF(Vec2i* lhs, int32_t rhs);
extern Vec2i Vec2i_Add(Vec2i lhs, Vec2i rhs);
extern Vec2i Vec2i_Sub(Vec2i lhs, Vec2i rhs);
extern Vec2i Vec2i_Multiply(Vec2i lhs, Vec2i rhs);
extern Vec2i Vec2i_Divide(Vec2i lhs, Vec2i rhs);
extern Vec2i Vec2i_MultiplyF(Vec2i lhs, int32_t rhs);
extern Vec2i Vec2i_DivideF(Vec2i lhs, int32_t rhs);
extern int32_t Vec2i_Dot(Vec2i* lhs, Vec2i* rhs);
extern int32_t Vec2i_SquareMagnitude(Vec2i lhs);
extern int32_t Vec2i_Magnitude(Vec2i lhs);
extern int32_t Vec2i_SquareMagnitudePtr(Vec2i* lhs);
extern int32_t Vec2i_MagnitudePtr(Vec2i* lhs);
extern void Vec2i_NormalizeAssignment(Vec2i* lhs);
extern Vec2i Vec2i_Normalize(Vec2i lhs);
extern int32_t Vec2i_Distance(Vec2i lhs, Vec2i rhs);
extern void Vec2i_InverseAssignment(Vec2i* lhs);
extern Vec2i Vec2i_Inverse(Vec2i lhs);
extern void Vec2i_FromVec2fAssignment(Vec2i* lhs, Vec2f* rhs);
extern void Vec2i_FromVec2sAssignment(Vec2i* lhs, Vec2s* rhs);
extern Vec2i Vec2i_FromVec2f(Vec2f* lhs);
extern Vec2i Vec2i_FromVec2s(Vec2s* lhs);
extern void Vec2s_AddAssignment(Vec2s* lhs, Vec2s* rhs);
extern void Vec2s_SubAssignment(Vec2s* lhs, Vec2s* rhs);
extern void Vec2s_MultiplyAssignment(Vec2s* lhs, Vec2s* rhs);
extern void Vec2s_DivideAssignment(Vec2s* lhs, Vec2s* rhs);
extern void Vec2s_MultiplyAssignmentF(Vec2s* lhs, int16_t rhs);
extern void Vec2s_DivideAssignmentF(Vec2s* lhs, int16_t rhs);
extern Vec2s Vec2s_Add(Vec2s lhs, Vec2s rhs);
extern Vec2s Vec2s_Sub(Vec2s lhs, Vec2s rhs);
extern Vec2s Vec2s_Multiply(Vec2s lhs, Vec2s rhs);
extern Vec2s Vec2s_Divide(Vec2s lhs, Vec2s rhs);
extern Vec2s Vec2s_MultiplyF(Vec2s lhs, int16_t rhs);
extern Vec2s Vec2s_DivideF(Vec2s lhs, int16_t rhs);
extern int16_t Vec2s_Dot(Vec2s* lhs, Vec2s* rhs);
extern int16_t Vec2s_SquareMagnitude(Vec2s lhs);
extern int16_t Vec2s_Magnitude(Vec2s lhs);
extern int16_t Vec2s_SquareMagnitudePtr(Vec2s* lhs);
extern int16_t Vec2s_MagnitudePtr(Vec2s* lhs);
extern void Vec2s_NormalizeAssignment(Vec2s* lhs);
extern Vec2s Vec2s_Normalize(Vec2s lhs);
extern int16_t Vec2s_Distance(Vec2s lhs, Vec2s rhs);
extern void Vec2s_InverseAssignment(Vec2s* lhs);
extern Vec2s Vec2s_Inverse(Vec2s lhs);
extern void Vec2s_FromVec2fAssignment(Vec2s* lhs, Vec2f* rhs);
extern void Vec2s_FromVec2iAssignment(Vec2s* lhs, Vec2i* rhs);
extern Vec2s Vec2s_FromVec2f(Vec2f* lhs);
extern Vec2s Vec2s_FromVec2i(Vec2i* lhs);
extern void Vec3f_AddAssignment(Vec3f* lhs, Vec3f* rhs);
extern void Vec3f_SubAssignment(Vec3f* lhs, Vec3f* rhs);
extern void Vec3f_MultiplyAssignment(Vec3f* lhs, Vec3f* rhs);
extern void Vec3f_DivideAssignment(Vec3f* lhs, Vec3f* rhs);
extern void Vec3f_MultiplyAssignmentF(Vec3f* lhs, float rhs);
extern void Vec3f_DivideAssignmentF(Vec3f* lhs, float rhs);
extern Vec3f Vec3f_Add(Vec3f lhs, Vec3f rhs);
extern Vec3f Vec3f_Sub(Vec3f lhs, Vec3f rhs);
extern Vec3f Vec3f_Multiply(Vec3f lhs, Vec3f rhs);
extern Vec3f Vec3f_Divide(Vec3f lhs, Vec3f rhs);
extern Vec3f Vec3f_MultiplyF(Vec3f lhs, float rhs);
extern Vec3f Vec3f_DivideF(Vec3f lhs, float rhs);
extern float Vec3f_Dot(Vec3f* lhs, Vec3f* rhs);
extern Vec3f Vec3f_Cross(Vec3f* lhs, Vec3f* rhs);
extern float Vec3f_SquareMagnitude(Vec3f lhs);
extern float Vec3f_Magnitude(Vec3f lhs);
extern float Vec3f_SquareMagnitudePtr(Vec3f* lhs);
extern float Vec3f_MagnitudePtr(Vec3f* lhs);
extern void Vec3f_NormalizeAssignment(Vec3f* lhs);
extern Vec3f Vec3f_Normalize(Vec3f lhs);
extern float Vec3f_Distance(Vec3f lhs, Vec3f rhs);
extern void Vec3f_InverseAssignment(Vec3f* lhs);
extern Vec3f Vec3f_Inverse(Vec3f lhs);
extern void Vec3f_FromVec3iAssignment(Vec3f* lhs, Vec3i* rhs);
extern void Vec3f_FromVec3sAssignment(Vec3f* lhs, Vec3s* rhs);
extern Vec3f Vec3f_FromVec3i(Vec3i* lhs);
extern Vec3f Vec3f_FromVec3s(Vec3s* lhs);
extern Vec3f Vec3f_PointOnCylinder(float radius, float yaw, float pitch);
extern Vec3f Vec3f_PointOnSphere(float radius, float yaw, float pitch);
extern void Vec3i_AddAssignment(Vec3i* lhs, Vec3i* rhs);
extern void Vec3i_SubAssignment(Vec3i* lhs, Vec3i* rhs);
extern void Vec3i_MultiplyAssignment(Vec3i* lhs, Vec3i* rhs);
extern void Vec3i_DivideAssignment(Vec3i* lhs, Vec3i* rhs);
extern void Vec3i_MultiplyAssignmentF(Vec3i* lhs, int32_t rhs);
extern void Vec3i_DivideAssignmentF(Vec3i* lhs, int32_t rhs);
extern Vec3i Vec3i_Add(Vec3i lhs, Vec3i rhs);
extern Vec3i Vec3i_Sub(Vec3i lhs, Vec3i rhs);
extern Vec3i Vec3i_Multiply(Vec3i lhs, Vec3i rhs);
extern Vec3i Vec3i_Divide(Vec3i lhs, Vec3i rhs);
extern Vec3i Vec3i_MultiplyF(Vec3i lhs, int32_t rhs);
extern Vec3i Vec3i_DivideF(Vec3i lhs, int32_t rhs);
extern int32_t Vec3i_Dot(Vec3i* lhs, Vec3i* rhs);
extern Vec3i Vec3i_Cross(Vec3i* lhs, Vec3i* rhs);
extern int32_t Vec3i_SquareMagnitude(Vec3i lhs);
extern int32_t Vec3i_Magnitude(Vec3i lhs);
extern int32_t Vec3i_SquareMagnitudePtr(Vec3i* lhs);
extern int32_t Vec3i_MagnitudePtr(Vec3i* lhs);
extern void Vec3i_NormalizeAssignment(Vec3i* lhs);
extern Vec3i Vec3i_Normalize(Vec3i lhs);
extern int32_t Vec3i_Distance(Vec3i lhs, Vec3i rhs);
extern void Vec3i_InverseAssignment(Vec3i* lhs);
extern Vec3i Vec3i_Inverse(Vec3i lhs);
extern void Vec3i_FromVec3fAssignment(Vec3i* lhs, Vec3f* rhs);
extern void Vec3i_FromVec3sAssignment(Vec3i* lhs, Vec3s* rhs);
extern Vec3i Vec3i_FromVec3f(Vec3f* lhs);
extern Vec3i Vec3i_FromVec3s(Vec3s* lhs);
extern void Vec3s_AddAssignment(Vec3s* lhs, Vec3s* rhs);
extern void Vec3s_SubAssignment(Vec3s* lhs, Vec3s* rhs);
extern void Vec3s_MultiplyAssignment(Vec3s* lhs, Vec3s* rhs);
extern void Vec3s_DivideAssignment(Vec3s* lhs, Vec3s* rhs);
extern void Vec3s_MultiplyAssignmentF(Vec3s* lhs, int16_t rhs);
extern void Vec3s_DivideAssignmentF(Vec3s* lhs, int16_t rhs);
extern Vec3s Vec3s_Add(Vec3s lhs, Vec3s rhs);
extern Vec3s Vec3s_Sub(Vec3s lhs, Vec3s rhs);
extern Vec3s Vec3s_Multiply(Vec3s lhs, Vec3s rhs);
extern Vec3s Vec3s_Divide(Vec3s lhs, Vec3s rhs);
extern Vec3s Vec3s_MultiplyF(Vec3s lhs, int16_t rhs);
extern Vec3s Vec3s_DivideF(Vec3s lhs, int16_t rhs);
extern int16_t Vec3s_Dot(Vec3s* lhs, Vec3s* rhs);
extern Vec3s Vec3s_Cross(Vec3s* lhs, Vec3s* rhs);
extern int16_t Vec3s_SquareMagnitude(Vec3s lhs);
extern int16_t Vec3s_Magnitude(Vec3s lhs);
extern int16_t Vec3s_SquareMagnitudePtr(Vec3s* lhs);
extern int16_t Vec3s_MagnitudePtr(Vec3s* lhs);
extern void Vec3s_NormalizeAssignment(Vec3s* lhs);
extern Vec3s Vec3s_Normalize(Vec3s lhs);
extern int16_t Vec3s_Distance(Vec3s lhs, Vec3s rhs);
extern void Vec3s_InverseAssignment(Vec3s* lhs);
extern Vec3s Vec3s_Inverse(Vec3s lhs);
extern void Vec3s_FromVec3fAssignment(Vec3s* lhs, Vec3f* rhs);
extern void Vec3s_FromVec3iAssignment(Vec3s* lhs, Vec3i* rhs);
extern Vec3s Vec3s_FromVec3f(Vec3f* lhs);
extern Vec3s Vec3s_FromVec3i(Vec3i* lhs);
extern void Vec4f_AddAssignment(Vec4f* lhs, Vec4f* rhs);
extern void Vec4f_SubAssignment(Vec4f* lhs, Vec4f* rhs);
extern void Vec4f_MultiplyAssignment(Vec4f* lhs, Vec4f* rhs);
extern void Vec4f_DivideAssignment(Vec4f* lhs, Vec4f* rhs);
extern void Vec4f_MultiplyAssignmentF(Vec4f* lhs, float rhs);
extern void Vec4f_DivideAssignmentF(Vec4f* lhs, float rhs);
extern Vec4f Vec4f_Add(Vec4f lhs, Vec4f rhs);
extern Vec4f Vec4f_Sub(Vec4f lhs, Vec4f rhs);
extern Vec4f Vec4f_Multiply(Vec4f lhs, Vec4f rhs);
extern Vec4f Vec4f_Divide(Vec4f lhs, Vec4f rhs);
extern Vec4f Vec4f_MultiplyF(Vec4f lhs, float rhs);
extern Vec4f Vec4f_DivideF(Vec4f lhs, float rhs);
extern float Vec4f_Dot(Vec4f* lhs, Vec4f* rhs);
extern Vec4f Vec4f_Cross(Vec4f* lhs, Vec4f* rhs);
extern float Vec4f_SquareMagnitude(Vec4f lhs);
extern float Vec4f_SquareMagnitudePtr(Vec4f* lhs);
extern float Vec4f_MagnitudePtr(Vec4f* lhs);
extern void Vec4f_NormalizeAssignment(Vec4f* lhs);
extern Vec4f Vec4f_Normalize(Vec4f lhs);
extern float Vec4f_Distance(Vec4f lhs, Vec4f rhs);
extern void Vec4f_InverseAssignment(Vec4f* lhs);
extern Vec4f Vec4f_Inverse(Vec4f lhs);
extern void Vec4f_FromVec4iAssignment(Vec4f* lhs, Vec4i* rhs);
extern void Vec4f_FromVec4sAssignment(Vec4f* lhs, Vec4s* rhs);
extern Vec4f Vec4f_FromVec4i(Vec4i* lhs);
extern Vec4f Vec4f_FromVec4s(Vec4s* lhs);
extern void Vec4i_AddAssignment(Vec4i* lhs, Vec4i* rhs);
extern void Vec4i_SubAssignment(Vec4i* lhs, Vec4i* rhs);
extern void Vec4i_MultiplyAssignment(Vec4i* lhs, Vec4i* rhs);
extern void Vec4i_DivideAssignment(Vec4i* lhs, Vec4i* rhs);
extern void Vec4i_MultiplyAssignmentF(Vec4i* lhs, int32_t rhs);
extern void Vec4i_DivideAssignmentF(Vec4i* lhs, int32_t rhs);
extern Vec4i Vec4i_Add(Vec4i lhs, Vec4i rhs);
extern Vec4i Vec4i_Sub(Vec4i lhs, Vec4i rhs);
extern Vec4i Vec4i_Multiply(Vec4i lhs, Vec4i rhs);
extern Vec4i Vec4i_Divide(Vec4i lhs, Vec4i rhs);
extern Vec4i Vec4i_MultiplyF(Vec4i lhs, int32_t rhs);
extern Vec4i Vec4i_DivideF(Vec4i lhs, int32_t rhs);
extern int32_t Vec4i_Dot(Vec4i* lhs, Vec4i* rhs);
extern Vec4i Vec4i_Cross(Vec4i* lhs, Vec4i* rhs);
extern int32_t Vec4i_SquareMagnitude(Vec4i lhs);
extern int32_t Vec4i_Magnitude(Vec4i lhs);
extern int32_t Vec4i_SquareMagnitudePtr(Vec4i* lhs);
extern int32_t Vec4i_MagnitudePtr(Vec4i* lhs);
extern void Vec4i_NormalizeAssignment(Vec4i* lhs);
extern Vec4i Vec4i_Normalize(Vec4i lhs);
extern int32_t Vec4i_Distance(Vec4i lhs, Vec4i rhs);
extern void Vec4i_InverseAssignment(Vec4i* lhs);
extern Vec4i Vec4i_Inverse(Vec4i lhs);
extern void Vec4i_FromVec4fAssignment(Vec4i* lhs, Vec4f* rhs);
extern void Vec4i_FromVec4sAssignment(Vec4i* lhs, Vec4s* rhs);
extern Vec4i Vec4i_FromVec4f(Vec4f* lhs);
extern Vec4i Vec4i_FromVec4s(Vec4s* lhs);
extern void Vec4s_AddAssignment(Vec4s* lhs, Vec4s* rhs);
extern void Vec4s_SubAssignment(Vec4s* lhs, Vec4s* rhs);
extern void Vec4s_MultiplyAssignment(Vec4s* lhs, Vec4s* rhs);
extern void Vec4s_DivideAssignment(Vec4s* lhs, Vec4s* rhs);
extern void Vec4s_MultiplyAssignmentF(Vec4s* lhs, int16_t rhs);
extern void Vec4s_DivideAssignmentF(Vec4s* lhs, int16_t rhs);
extern Vec4s Vec4s_Add(Vec4s lhs, Vec4s rhs);
extern Vec4s Vec4s_Sub(Vec4s lhs, Vec4s rhs);
extern Vec4s Vec4s_Multiply(Vec4s lhs, Vec4s rhs);
extern Vec4s Vec4s_Divide(Vec4s lhs, Vec4s rhs);
extern Vec4s Vec4s_MultiplyF(Vec4s lhs, int16_t rhs);
extern Vec4s Vec4s_DivideF(Vec4s lhs, int16_t rhs);
extern int16_t Vec4s_Dot(Vec4s* lhs, Vec4s* rhs);
extern Vec4s Vec4s_Cross(Vec4s* lhs, Vec4s* rhs);
extern int16_t Vec4s_SquareMagnitude(Vec4s lhs);
extern int16_t Vec4s_Magnitude(Vec4s lhs);
extern int16_t Vec4s_SquareMagnitudePtr(Vec4s* lhs);
extern int16_t Vec4s_MagnitudePtr(Vec4s* lhs);
extern void Vec4s_NormalizeAssignment(Vec4s* lhs);
extern Vec4s Vec4s_Normalize(Vec4s lhs);
extern int16_t Vec4s_Distance(Vec4s lhs, Vec4s rhs);
extern void Vec4s_InverseAssignment(Vec4s* lhs);
extern Vec4s Vec4s_Inverse(Vec4s lhs);
extern void Vec4s_FromVec4fAssignment(Vec4s* lhs, Vec4f* rhs);
extern void Vec4s_FromVec4iAssignment(Vec4s* lhs, Vec4i* rhs);
extern Vec4s Vec4s_FromVec4f(Vec4f* lhs);
extern Vec4s Vec4s_FromVec4i(Vec4i* lhs);
extern void QuatF_AddWAssignment(QuatF* lhs, float rhs);
extern void QuatF_SubWAssignment(QuatF* lhs, float rhs);
extern QuatF QuatF_AddW(QuatF lhs, float rhs);
extern QuatF QuatF_SubW(QuatF lhs, float rhs);
extern void QuatF_ConjugateAssignment(QuatF* lhs);
extern QuatF QuatF_Conjugate(QuatF lhs);
extern void QuatF_AxisAngleAssignment(QuatF* lhs, Vec3f* axis, float angle);
extern QuatF QuatF_AxisAngle(QuatF lhs, Vec3f* axis, float angle);
extern void QuatF_FromEulerAssignment(QuatF* lhs, Vec3f* rhs);
extern QuatF QuatF_FromEuler(Vec3f rhs);
extern void QuatF_ToAngleAxisAssignment(QuatF* lhs, Vec3f* axis, float* angle);
extern Vec3f QuatF_ToAngleAxis(QuatF* lhs, Vec3f axis, float* angle);
extern void QuatF_FromLookRotationAssignment(QuatF* lhs, Vec3f* look_at, Vec3f* up);
extern QuatF QuatF_FromLookRotation(Vec3f* look_at, Vec3f* up);
extern void QuatF_ToMatrixAssignment(float matrix[4][4], QuatF lhs);

#endif /* LIBAXIS_h */
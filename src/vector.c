/**
 * @file: vector.c
 * @author: Drahsid (https://github.com/Drahsid)
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * @author: Evan20k (https://github.com/Evan20k)
 * 
 * @brief A thicc vector library.
**/

#include "global.h"

/**
* @brief Adds theVec2f rhs to the Vec2f lhs and stores the result in lhs.
* (Vec2f)lhs -= (Vec2f)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_AddAssignment(Vec2f* lhs, Vec2f* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
}

/**
* @brief Subtracts the Vec2f rhs from the Vec2f lhs and stores the result in lhs.
* (Vec2f)lhs -= (Vec2f)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_SubAssignment(Vec2f* lhs, Vec2f* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
}

/**
* @brief Scales the Vec2f lhs to the Vec2f rhs and stores the result in lhs;
* (Vec2f)lhs *= (Vec2f)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_MultiplyAssignment(Vec2f* lhs, Vec2f* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
}

/**
* @brief Divide the Vec2f lhs by the Vec2f rhs and stores the result in lhs;
* (Vec2f)lhs /= (Vec2f)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_DivideAssignment(Vec2f* lhs, Vec2f* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
}

/**
* @brief Scales the Vec2f lhs to the float rhs and stores the result in lhs;
* (Vec2f)lhs *= (float)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_MultiplyAssignmentF(Vec2f* lhs, f32 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
}

/**
* @brief Divides the Vec2f lhs by the float rhs and stores the result in lhs;
* (Vec2f)lhs *= (float)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_DivideAssignmentF(Vec2f* lhs, f32 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
}

/**
* @brief Returns the sum of the Vec2f rhs and the Vec2f lhs as a Vec2f.
* v = ((Vec2f)lhs += (Vec2f)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_Add(Vec2f lhs, Vec2f rhs) {
    Vec2f_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec2f lhs subtracted from the Vec2f rhs as a Vec2f.
* v = ((Vec2f)lhs -= (Vec2f)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_Sub(Vec2f lhs, Vec2f rhs) {
    Vec2f_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec2f lhs scaled to the Vec2f rhs as a Vec2f.
* v = ((Vec2f)lhs *= (Vec2f)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_Multiply(Vec2f lhs, Vec2f rhs) {
    Vec2f_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec2f lhs divided by the Vec2f rhs as a Vec2f.
* v = ((Vec2f)lhs *= (Vec2f)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_Divide(Vec2f lhs, Vec2f rhs) {
    Vec2f_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec2f lhs scaled to the float rhs as a Vec2f.
* v = ((Vec2f)lhs *= (float)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_MultiplyF(Vec2f lhs, f32 rhs) {
    Vec2f_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec2f lhs divided by the float rhs as a Vec2f.
* v = ((Vec2f)lhs *= (float)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_DivideF(Vec2f lhs, f32 rhs) {
    Vec2f_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec2f lhs and the Vec2f rhs as a float.
* v = ((Vec2f)lhs • (Vec2f)rhs);
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return float
**/
f32 Vec2f_Dot(Vec2f* lhs, Vec2f* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y);
}

/**
* @brief Returns the square magnitude of the Vec2f lhs as a float.
* v = ((Vec2f)lhs^2)
* @param lhs Left Hand Side
* @return float
**/
f32 Vec2f_SquareMagnitude(Vec2f lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y);
}

/**
* @brief Returns the magnitude of the Vec2f lhs as a float.
* v = √((Vec2f)lhs^2)
* @param lhs Left Hand Side
* @return float
**/
f32 Vec2f_Magnitude(Vec2f lhs) {
    return sqrtf(Vec2f_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec2f lhs as a float.
* v = ((Vec2f)lhs^2)
* @param lhs Left Hand Side
* @return float
**/
f32 Vec2f_SquareMagnitudePtr(Vec2f* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y);
}

/**
* @brief Returns the magnitude of the Vec2f lhs as a float.
* v = √((Vec2f)lhs^2)
* @param lhs Left Hand Side
* @return float
**/
f32 Vec2f_MagnitudePtr(Vec2f* lhs) {
    return sqrtf(Vec2f_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec2f lhs into a unit vector.
* @param lhs Left Hand Side
* @return float
**/
void Vec2f_NormalizeAssignment(Vec2f* lhs) {
    f32 magnitude = Vec2f_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec2f lhs as a Vec2f.
* @param lhs Left Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_Normalize(Vec2f lhs) {
    Vec2f_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec2f lhs subtracted from the Vec2f rhs as a float.
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return float
**/
f32 Vec2f_Distance(Vec2f lhs, Vec2f rhs) {
    Vec2f_SubAssignment(&lhs, &rhs);
    return Vec2f_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec2f lhs.
* @param lhs Left Hand Side
* @return void
**/
void Vec2f_InverseAssignment(Vec2f* lhs) {
    Vec2f_MultiplyAssignmentF(lhs, -1.0f);
}

/**
* @brief Returns the inverse of the Vec2f lhs as a Vec2f.
* @param lhs Left Hand Side
* @return 2D Vector
**/
Vec2f Vec2f_Inverse(Vec2f lhs) {
    Vec2f_MultiplyAssignmentF(&lhs, -1.0f);
    return lhs;
}

/**
* @brief Stores and casts the Vec2i rhs into the Vec2f lhs.
* (Vec2f)lhs = (Vec2i)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_FromVec2iAssignment(Vec2f* lhs, Vec2i* rhs) {
    lhs->x = (f32)(rhs->x);
    lhs->y = (f32)(rhs->y);
}

/**
* @brief Stores and casts the Vec2s rhs into the Vec2f lhs.
* (Vec2f)lhs = (Vec2s)rhs;
* @param lhs Left Hand Side
* @param rhs Right Hand Side
* @return void
**/
void Vec2f_FromVec2sAssignment(Vec2f* lhs, Vec2s* rhs) {
    lhs->x = (f32)(rhs->x);
    lhs->y = (f32)(rhs->y);
}

/**
* @brief Returns the Vec2i lhs as a Vec2f.
**/
Vec2f Vec2f_FromVec2i(Vec2i* lhs) {
    Vec2f return_value;
    Vec2f_FromVec2iAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec2s lhs as a Vec2f.
**/
Vec2f Vec2f_FromVec2s(Vec2s* lhs) {
    Vec2f return_value;
    Vec2f_FromVec2sAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec2i rhs to the Vec2i lhs and stores the result in lhs.
* (Vec2i)lhs += (Vec2i)rhs;
**/
void Vec2i_AddAssignment(Vec2i* lhs, Vec2i* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
}

/**
* @brief Subtracts the Vec2i rhs from the Vec2i lhs and stores the result in lhs.
* (Vec2i)lhs -= (Vec2i)rhs;
**/
void Vec2i_SubAssignment(Vec2i* lhs, Vec2i* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
}

/**
* @brief Scales the Vec2i lhs to the Vec2i rhs and stores the result in lhs;
* (Vec2i)lhs *= (Vec2i)rhs;
**/
void Vec2i_MultiplyAssignment(Vec2i* lhs, Vec2i* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
}

/**
* @brief Divide the Vec2i lhs by the Vec2i rhs and stores the result in lhs;
* (Vec2i)lhs /= (Vec2i)rhs;
**/
void Vec2i_DivideAssignment(Vec2i* lhs, Vec2i* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
}

/**
* @brief Scales the Vec2i lhs to the int rhs and stores the result in lhs;
* (Vec2i)lhs *= (int)rhs;
**/
void Vec2i_MultiplyAssignmentF(Vec2i* lhs, s32 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
}

/**
* @brief Divides the Vec2i lhs by the int rhs and stores the result in lhs;
* (Vec2i)lhs *= (int)rhs;
**/
void Vec2i_DivideAssignmentF(Vec2i* lhs, s32 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
}

/**
* @brief Returns the sum of the Vec2i rhs and the Vec2i lhs as a Vec2i.
* v = ((Vec2i)lhs += (Vec2i)rhs);
**/
Vec2i Vec2i_Add(Vec2i lhs, Vec2i rhs) {
    Vec2i_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec2i lhs subtracted from the Vec2i rhs as a Vec2i.
* v = ((Vec2i)lhs -= (Vec2i)rhs);
**/
Vec2i Vec2i_Sub(Vec2i lhs, Vec2i rhs) {
    Vec2i_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec2i lhs scaled to the Vec2i rhs as a Vec2i.
* v = ((Vec2i)lhs *= (Vec2i)rhs);
**/
Vec2i Vec2i_Multiply(Vec2i lhs, Vec2i rhs) {
    Vec2i_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec2i lhs divided by the Vec2i rhs as a Vec2i.
* v = ((Vec2i)lhs *= (Vec2i)rhs);
**/
Vec2i Vec2i_Divide(Vec2i lhs, Vec2i rhs) {
    Vec2i_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec2i lhs scaled to the int rhs as a Vec2i.
* v = ((Vec2i)lhs *= (int)rhs);
**/
Vec2i Vec2i_MultiplyF(Vec2i lhs, s32 rhs) {
    Vec2i_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec2i lhs divided by the int rhs as a Vec2i.
* v = ((Vec2i)lhs *= (int)rhs);
**/
Vec2i Vec2i_DivideF(Vec2i lhs, s32 rhs) {
    Vec2i_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec2i lhs and the Vec2i rhs as a int.
* v = ((Vec2i)lhs • (Vec2i)rhs);
**/
s32 Vec2i_Dot(Vec2i* lhs, Vec2i* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y);
}

/**
* @brief Returns the square magnitude of the Vec2i lhs as a int.
* v = ((Vec2i)lhs^2)
**/
s32 Vec2i_SquareMagnitude(Vec2i lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y);
}

/**
* @brief Returns the magnitude of the Vec2i lhs as a int.
* v = √((Vec2i)lhs^2)
**/
s32 Vec2i_Magnitude(Vec2i lhs) {
    return sqrtf(Vec2i_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec2i lhs as a int.
* v = ((Vec2i)lhs^2)
**/
s32 Vec2i_SquareMagnitudePtr(Vec2i* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y);
}

/**
* @brief Returns the magnitude of the Vec2i lhs as a int.
* v = √((Vec2i)lhs^2)
**/
s32 Vec2i_MagnitudePtr(Vec2i* lhs) {
    return sqrtf(Vec2i_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec2i lhs into a unit vector.
**/
void Vec2i_NormalizeAssignment(Vec2i* lhs) {
    s32 magnitude = Vec2i_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = 0;
        lhs->y = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec2i lhs as a Vec2i.
**/
Vec2i Vec2i_Normalize(Vec2i lhs) {
    Vec2i_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec2i lhs subtracted from the Vec2i rhs as a int.
**/
s32 Vec2i_Distance(Vec2i lhs, Vec2i rhs) {
    Vec2i_SubAssignment(&lhs, &rhs);
    return Vec2i_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec2i lhs.
**/
void Vec2i_InverseAssignment(Vec2i* lhs) {
    Vec2i_MultiplyAssignmentF(lhs, -1);
}

/**
* @brief Returns the inverse of the Vec2i lhs as a Vec2i.
**/
Vec2i Vec2i_Inverse(Vec2i lhs) {
    Vec2i_MultiplyAssignmentF(&lhs, -1);
    return lhs;
}

/**
* @brief Stores and casts the Vec2f rhs into the Vec2i lhs.
* (Vec2i)lhs = (Vec2f)rhs;
**/
void Vec2i_FromVec2fAssignment(Vec2i* lhs, Vec2f* rhs) {
    lhs->x = (s32)(rhs->x);
    lhs->y = (s32)(rhs->y);
}

/**
* @brief Stores and casts the Vec2s rhs into the Vec2i lhs.
* (Vec2i)lhs = (Vec2s)rhs;
**/
void Vec2i_FromVec2sAssignment(Vec2i* lhs, Vec2s* rhs) {
    lhs->x = (s32)(rhs->x);
    lhs->y = (s32)(rhs->y);
}

/**
* @brief Returns the Vec2f lhs as a Vec2i.
**/
Vec2i Vec2i_FromVec2f(Vec2f* lhs) {
    Vec2i return_value;
    Vec2i_FromVec2fAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec2s lhs as a Vec2i.
**/
Vec2i Vec2i_FromVec2s(Vec2s* lhs) {
    Vec2i return_value;
    Vec2i_FromVec2sAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec2s rhs to the Vec2s lhs and stores the result in lhs.
* (Vec2s)lhs += (Vec2s)rhs;
**/
void Vec2s_AddAssignment(Vec2s* lhs, Vec2s* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
}

/**
* @brief Subtracts the Vec2s rhs from the Vec2s lhs and stores the result in lhs.
* (Vec2s)lhs -= (Vec2s)rhs;
**/
void Vec2s_SubAssignment(Vec2s* lhs, Vec2s* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
}

/**
* @brief Scales the Vec2s lhs to the Vec2s rhs and stores the result in lhs;
* (Vec2s)lhs *= (Vec2s)rhs;
**/
void Vec2s_MultiplyAssignment(Vec2s* lhs, Vec2s* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
}

/**
* @brief Divide the Vec2s lhs by the Vec2s rhs and stores the result in lhs;
* (Vec2s)lhs /= (Vec2s)rhs;
**/
void Vec2s_DivideAssignment(Vec2s* lhs, Vec2s* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
}

/**
* @brief Scales the Vec2s lhs to the short rhs and stores the result in lhs;
* (Vec2s)lhs *= (short)rhs;
**/
void Vec2s_MultiplyAssignmentF(Vec2s* lhs, s16 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
}

/**
* @brief Divides the Vec2s lhs by the short rhs and stores the result in lhs;
* (Vec2s)lhs *= (short)rhs;
**/
void Vec2s_DivideAssignmentF(Vec2s* lhs, s16 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
}

/**
* @brief Returns the sum of the Vec2s rhs and the Vec2s lhs as a Vec2s.
* v = ((Vec2s)lhs += (Vec2s)rhs);
**/
Vec2s Vec2s_Add(Vec2s lhs, Vec2s rhs) {
    Vec2s_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec2s lhs subtracted from the Vec2s rhs as a Vec2s.
* v = ((Vec2s)lhs -= (Vec2s)rhs);
**/
Vec2s Vec2s_Sub(Vec2s lhs, Vec2s rhs) {
    Vec2s_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec2s lhs scaled to the Vec2s rhs as a Vec2s.
* v = ((Vec2s)lhs *= (Vec2s)rhs);
**/
Vec2s Vec2s_Multiply(Vec2s lhs, Vec2s rhs) {
    Vec2s_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec2s lhs divided by the Vec2s rhs as a Vec2s.
* v = ((Vec2s)lhs *= (Vec2s)rhs);
**/
Vec2s Vec2s_Divide(Vec2s lhs, Vec2s rhs) {
    Vec2s_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec2s lhs scaled to the short rhs as a Vec2s.
* v = ((Vec2s)lhs *= (short)rhs);
**/
Vec2s Vec2s_MultiplyF(Vec2s lhs, s16 rhs) {
    Vec2s_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec2s lhs divided by the short rhs as a Vec2s.
* v = ((Vec2s)lhs *= (short)rhs);
**/
Vec2s Vec2s_DivideF(Vec2s lhs, s16 rhs) {
    Vec2s_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec2s lhs and the Vec2s rhs as a short.
* v = ((Vec2s)lhs • (Vec2s)rhs);
**/
s16 Vec2s_Dot(Vec2s* lhs, Vec2s* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y);
}

/**
* @brief Returns the square magnitude of the Vec2s lhs as a short.
* v = ((Vec2s)lhs^2)
**/
s16 Vec2s_SquareMagnitude(Vec2s lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y);
}

/**
* @brief Returns the magnitude of the Vec2s lhs as a short.
* v = √((Vec2s)lhs^2)
**/
s16 Vec2s_Magnitude(Vec2s lhs) {
    return sqrtf(Vec2s_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec2s lhs as a short.
* v = ((Vec2s)lhs^2)
**/
s16 Vec2s_SquareMagnitudePtr(Vec2s* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y);
}

/**
* @brief Returns the magnitude of the Vec2s lhs as a short.
* v = √((Vec2s)lhs^2)
**/
s16 Vec2s_MagnitudePtr(Vec2s* lhs) {
    return sqrtf(Vec2s_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec2s lhs shorto a unit vector.
**/
void Vec2s_NormalizeAssignment(Vec2s* lhs) {
    s16 magnitude = Vec2s_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = 0;
        lhs->y = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec2s lhs as a Vec2s.
**/
Vec2s Vec2s_Normalize(Vec2s lhs) {
    Vec2s_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec2s lhs subtracted from the Vec2s rhs as a short.
**/
s16 Vec2s_Distance(Vec2s lhs, Vec2s rhs) {
    Vec2s_SubAssignment(&lhs, &rhs);
    return Vec2s_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec2s lhs.
**/
void Vec2s_InverseAssignment(Vec2s* lhs) {
    Vec2s_MultiplyAssignmentF(lhs, -1);
}

/**
* @brief Returns the inverse of the Vec2s lhs as a Vec2s.
**/
Vec2s Vec2s_Inverse(Vec2s lhs) {
    Vec2s_MultiplyAssignmentF(&lhs, -1);
    return lhs;
}

/**
* @brief Stores and casts the Vec2f rhs into the Vec2s lhs.
* (Vec2s)lhs = (Vec2f)rhs;
**/
void Vec2s_FromVec2fAssignment(Vec2s* lhs, Vec2f* rhs) {
    lhs->x = (s16)(rhs->x);
    lhs->y = (s16)(rhs->y);
}

/**
* @brief Stores and casts the Vec2i rhs into the Vec2s lhs.
* (Vec2s)lhs = (Vec2i)rhs;
**/
void Vec2s_FromVec2iAssignment(Vec2s* lhs, Vec2i* rhs) {
    lhs->x = (s16)(rhs->x);
    lhs->y = (s16)(rhs->y);
}

/**
* @brief Returns the Vec2f lhs as a Vec2s.
**/
Vec2s Vec2s_FromVec2f(Vec2f* lhs) {
    Vec2s return_value;
    Vec2s_FromVec2fAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec2i lhs as a Vec2s.
**/
Vec2s Vec2s_FromVec2i(Vec2i* lhs) {
    Vec2s return_value;
    Vec2s_FromVec2iAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec3f rhs to the Vec3f lhs and stores the result in lhs.
* (Vec3f)lhs += (Vec3f)rhs;
**/
void Vec3f_AddAssignment(Vec3f* lhs, Vec3f* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
}

/**
* @brief Subtracts the Vec3f rhs from the Vec3f lhs and stores the result in lhs.
* (Vec3f)lhs -= (Vec3f)rhs;
**/
void Vec3f_SubAssignment(Vec3f* lhs, Vec3f* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
    lhs->z -= rhs->z;
}

/**
* @brief Scales the Vec3f lhs to the Vec3f rhs and stores the result in lhs;
* (Vec3f)lhs *= (Vec3f)rhs;
**/
void Vec3f_MultiplyAssignment(Vec3f* lhs, Vec3f* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
    lhs->z *= rhs->z;
}

/**
* @brief Divide the Vec3f lhs by the Vec3f rhs and stores the result in lhs;
* (Vec3f)lhs /= (Vec3f)rhs;
**/
void Vec3f_DivideAssignment(Vec3f* lhs, Vec3f* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
    lhs->z /= rhs->z;
}

/**
* @brief Scales the Vec3f lhs to the float rhs and stores the result in lhs;
* (Vec3f)lhs *= (float)rhs;
**/
void Vec3f_MultiplyAssignmentF(Vec3f* lhs, f32 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
    lhs->z *= rhs;
}

/**
* @brief Divides the Vec3f lhs by the float rhs and stores the result in lhs;
* (Vec3f)lhs *= (float)rhs;
**/
void Vec3f_DivideAssignmentF(Vec3f* lhs, f32 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
    lhs->z /= rhs;
}

/**
* @brief Returns the sum of the Vec3f rhs and the Vec3f lhs as a Vec3f.
* v = ((Vec3f)lhs += (Vec3f)rhs);
**/
Vec3f Vec3f_Add(Vec3f lhs, Vec3f rhs) {
    Vec3f_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec3f lhs subtracted from the Vec3f rhs as a Vec3f.
* v = ((Vec3f)lhs -= (Vec3f)rhs);
**/
Vec3f Vec3f_Sub(Vec3f lhs, Vec3f rhs) {
    Vec3f_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec3f lhs scaled to the Vec3f rhs as a Vec3f.
* v = ((Vec3f)lhs *= (Vec3f)rhs);
**/
Vec3f Vec3f_Multiply(Vec3f lhs, Vec3f rhs) {
    Vec3f_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec3f lhs divided by the Vec3f rhs as a Vec3f.
* v = ((Vec3f)lhs *= (Vec3f)rhs);
**/
Vec3f Vec3f_Divide(Vec3f lhs, Vec3f rhs) {
    Vec3f_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec3f lhs scaled to the float rhs as a Vec3f.
* v = ((Vec3f)lhs *= (float)rhs);
**/
Vec3f Vec3f_MultiplyF(Vec3f lhs, f32 rhs) {
    Vec3f_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec3f lhs divided by the float rhs as a Vec3f.
* v = ((Vec3f)lhs *= (float)rhs);
**/
Vec3f Vec3f_DivideF(Vec3f lhs, f32 rhs) {
    Vec3f_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec3f lhs and the Vec3f rhs as a float.
* v = ((Vec3f)lhs • (Vec3f)rhs);
**/
f32 Vec3f_Dot(Vec3f* lhs, Vec3f* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z);
}

/**
* @brief Returns the cross product of the Vec3f lhs and the Vec3f rhs as a Vec3f.
* v = ((Vec3f)lhs • (Vec3f)rhs);
**/
Vec3f Vec3f_Cross(Vec3f* lhs, Vec3f* rhs) {
    Vec3f return_value;
    return_value.x = lhs->y * rhs->z - rhs->y * lhs->z;
    return_value.y = lhs->z * rhs->x - rhs->z * lhs->x;
    return_value.z = lhs->x * rhs->y - rhs->x * lhs->y;
    return return_value;
}

/**
* @brief Returns the square magnitude of the Vec3f lhs as a float.
* v = ((Vec3f)lhs^2)
**/
f32 Vec3f_SquareMagnitude(Vec3f lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y) + (lhs.z * lhs.z);
}

/**
* @brief Returns the magnitude of the Vec3f lhs as a float.
* v = √((Vec3f)lhs^2)
**/
f32 Vec3f_Magnitude(Vec3f lhs) {
    return sqrtf(Vec3f_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec3f lhs as a float.
* v = ((Vec3f)lhs^2)
**/
f32 Vec3f_SquareMagnitudePtr(Vec3f* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y) + (lhs->z * lhs->z);
}

/**
* @brief Returns the magnitude of the Vec3f lhs as a float.
* v = √((Vec3f)lhs^2)
**/
f32 Vec3f_MagnitudePtr(Vec3f* lhs) {
    return sqrtf(Vec3f_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec3f lhs into a unit vector.
**/
void Vec3f_NormalizeAssignment(Vec3f* lhs) {
    f32 magnitude = Vec3f_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = lhs->z = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
        lhs->z = (lhs->z / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec3f lhs as a Vec3f.
**/
Vec3f Vec3f_Normalize(Vec3f lhs) {
    Vec3f_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec3f lhs subtracted from the Vec3f rhs as a float.
**/
f32 Vec3f_Distance(Vec3f lhs, Vec3f rhs) {
    Vec3f_SubAssignment(&lhs, &rhs);
    return Vec3f_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec3f lhs.
**/
void Vec3f_InverseAssignment(Vec3f* lhs) {
    Vec3f_MultiplyAssignmentF(lhs, -1.0f);
}

/**
* @brief Returns the inverse of the Vec3f lhs as a Vec3f.
**/
Vec3f Vec3f_Inverse(Vec3f lhs) {
    Vec3f_MultiplyAssignmentF(&lhs, -1.0f);
    return lhs;
}

/**
* @brief Stores and casts the Vec3i rhs into the Vec3f lhs.
* (Vec3f)lhs = (Vec3i)rhs;
**/
void Vec3f_FromVec3iAssignment(Vec3f* lhs, Vec3i* rhs) {
    lhs->x = (f32)(rhs->x);
    lhs->y = (f32)(rhs->y);
    lhs->z = (f32)(rhs->z);
}

/**
* @brief Stores and casts the Vec3s rhs into the Vec3f lhs.
* (Vec3f)lhs = (Vec3s)rhs;
**/
void Vec3f_FromVec3sAssignment(Vec3f* lhs, Vec3s* rhs) {
    lhs->x = (f32)(rhs->x);
    lhs->y = (f32)(rhs->y);
    lhs->z = (f32)(rhs->z);
}

/**
* @brief Returns the Vec3i lhs as a Vec3f.
**/
Vec3f Vec3f_FromVec3i(Vec3i* lhs) {
    Vec3f return_value;
    Vec3f_FromVec3iAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec3s lhs as a Vec3f.
**/
Vec3f Vec3f_FromVec3s(Vec3s* lhs) {
    Vec3f return_value;
    Vec3f_FromVec3sAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Return a point on a 3D Cylinder given yaw and pitch in euler degrees.
* Authored by: <Evan20k>
* @param radius The size of the cylinder's radius in units
* @param yaw The yaw (Y rotation) in degrees
* @param pitch The pitch (X rotation) in degrees
* @return 3D Vector
**/
Vec3f Vec3f_PointOnCylinder(f32 radius, f32 yaw, f32 pitch) {
    Vec3f return_value;
    return_value.x = VEC3F_X(radius, yaw, 0);
    return_value.y = VEC3F_Y(radius, 0, pitch);
    return_value.z = VEC3F_Z(radius, yaw, 0);
    return return_value;
}

/**
* @brief Return a point on a 3D Sphere given yaw and pitch in euler degrees.
* Authored by: <Evan20k>
* @param radius The size of the sphere's radius in units
* @param yaw The yaw (Y rotation) in degrees
* @param pitch The pitch (X rotation) in degrees
* @return 3D Vector
**/
Vec3f Vec3f_PointOnSphere(f32 radius, f32 yaw, f32 pitch) {
    Vec3f return_value;
    return_value.x = VEC3F_X(radius, yaw, pitch);
    return_value.y = VEC3F_Y(radius, yaw, pitch);
    return_value.z = VEC3F_Z(radius, yaw, pitch);
    return return_value;
}

/**
* @brief Adds theVec3i rhs to the Vec3i lhs and stores the result in lhs.
* (Vec3i)lhs += (Vec3i)rhs;
**/
void Vec3i_AddAssignment(Vec3i* lhs, Vec3i* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
}

/**
* @brief Subtracts the Vec3i rhs from the Vec3i lhs and stores the result in lhs.
* (Vec3i)lhs -= (Vec3i)rhs;
**/
void Vec3i_SubAssignment(Vec3i* lhs, Vec3i* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
    lhs->z -= rhs->z;
}

/**
* @brief Scales the Vec3i lhs to the Vec3i rhs and stores the result in lhs;
* (Vec3i)lhs *= (Vec3i)rhs;
**/
void Vec3i_MultiplyAssignment(Vec3i* lhs, Vec3i* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
    lhs->z *= rhs->z;
}

/**
* @brief Divide the Vec3i lhs by the Vec3i rhs and stores the result in lhs;
* (Vec3i)lhs /= (Vec3i)rhs;
**/
void Vec3i_DivideAssignment(Vec3i* lhs, Vec3i* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
    lhs->z /= rhs->z;
}

/**
* @brief Scales the Vec3i lhs to the int rhs and stores the result in lhs;
* (Vec3i)lhs *= (int)rhs;
**/
void Vec3i_MultiplyAssignmentF(Vec3i* lhs, s32 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
    lhs->z *= rhs;
}

/**
* @brief Divides the Vec3i lhs by the int rhs and stores the result in lhs;
* (Vec3i)lhs *= (int)rhs;
**/
void Vec3i_DivideAssignmentF(Vec3i* lhs, s32 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
    lhs->z /= rhs;
}

/**
* @brief Returns the sum of the Vec3i rhs and the Vec3i lhs as a Vec3i.
* v = ((Vec3i)lhs += (Vec3i)rhs);
**/
Vec3i Vec3i_Add(Vec3i lhs, Vec3i rhs) {
    Vec3i_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec3i lhs subtracted from the Vec3i rhs as a Vec3i.
* v = ((Vec3i)lhs -= (Vec3i)rhs);
**/
Vec3i Vec3i_Sub(Vec3i lhs, Vec3i rhs) {
    Vec3i_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec3i lhs scaled to the Vec3i rhs as a Vec3i.
* v = ((Vec3i)lhs *= (Vec3i)rhs);
**/
Vec3i Vec3i_Multiply(Vec3i lhs, Vec3i rhs) {
    Vec3i_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec3i lhs divided by the Vec3i rhs as a Vec3i.
* v = ((Vec3i)lhs *= (Vec3i)rhs);
**/
Vec3i Vec3i_Divide(Vec3i lhs, Vec3i rhs) {
    Vec3i_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec3i lhs scaled to the int rhs as a Vec3i.
* v = ((Vec3i)lhs *= (int)rhs);
**/
Vec3i Vec3i_MultiplyF(Vec3i lhs, s32 rhs) {
    Vec3i_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec3i lhs divided by the int rhs as a Vec3i.
* v = ((Vec3i)lhs *= (int)rhs);
**/
Vec3i Vec3i_DivideF(Vec3i lhs, s32 rhs) {
    Vec3i_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec3i lhs and the Vec3i rhs as a int.
* v = ((Vec3i)lhs • (Vec3i)rhs);
**/
s32 Vec3i_Dot(Vec3i* lhs, Vec3i* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z);
}

/**
* @brief Returns the cross product of the Vec3i lhs and the Vec3i rhs as a Vec3i.
* v = ((Vec3i)lhs • (Vec3i)rhs);
**/
Vec3i Vec3i_Cross(Vec3i* lhs, Vec3i* rhs) {
    Vec3i return_value;
    return_value.x = lhs->y * rhs->z - rhs->y * lhs->z;
    return_value.y = lhs->z * rhs->x - rhs->z * lhs->x;
    return_value.z = lhs->x * rhs->y - rhs->x * lhs->y;
    return return_value;
}

/**
* @brief Returns the square magnitude of the Vec3i lhs as a int.
* v = ((Vec3i)lhs^2)
**/
s32 Vec3i_SquareMagnitude(Vec3i lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y) + (lhs.z * lhs.z);
}

/**
* @brief Returns the magnitude of the Vec3i lhs as a int.
* v = √((Vec3i)lhs^2)
**/
s32 Vec3i_Magnitude(Vec3i lhs) {
    return sqrtf(Vec3i_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec3i lhs as a int.
* v = ((Vec3i)lhs^2)
**/
s32 Vec3i_SquareMagnitudePtr(Vec3i* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y) + (lhs->z * lhs->z);
}

/**
* @brief Returns the magnitude of the Vec3i lhs as a int.
* v = √((Vec3i)lhs^2)
**/
s32 Vec3i_MagnitudePtr(Vec3i* lhs) {
    return sqrtf(Vec3i_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec3i lhs into a unit vector.
**/
void Vec3i_NormalizeAssignment(Vec3i* lhs) {
    s32 magnitude = Vec3i_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = lhs->z = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
        lhs->z = (lhs->z / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec3i lhs as a Vec3i.
**/
Vec3i Vec3i_Normalize(Vec3i lhs) {
    Vec3i_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec3i lhs subtracted from the Vec3i rhs as a int.
**/
s32 Vec3i_Distance(Vec3i lhs, Vec3i rhs) {
    Vec3i_SubAssignment(&lhs, &rhs);
    return Vec3i_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec3i lhs.
**/
void Vec3i_InverseAssignment(Vec3i* lhs) {
    Vec3i_MultiplyAssignmentF(lhs, -1);
}

/**
* @brief Returns the inverse of the Vec3i lhs as a Vec3i.
**/
Vec3i Vec3i_Inverse(Vec3i lhs) {
    Vec3i_MultiplyAssignmentF(&lhs, -1);
    return lhs;
}

/**
* @brief Stores and casts the Vec3f rhs into the Vec3i lhs.
* (Vec3i)lhs = (Vec3f)rhs;
**/
void Vec3i_FromVec3fAssignment(Vec3i* lhs, Vec3f* rhs) {
    lhs->x = (s32)(rhs->x);
    lhs->y = (s32)(rhs->y);
    lhs->z = (s32)(rhs->z);
}

/**
* @brief Stores and casts the Vec3s rhs into the Vec3i lhs.
* (Vec3i)lhs = (Vec3s)rhs;
**/
void Vec3i_FromVec3sAssignment(Vec3i* lhs, Vec3s* rhs) {
    lhs->x = (s32)(rhs->x);
    lhs->y = (s32)(rhs->y);
    lhs->z = (s32)(rhs->z);
}

/**
* @brief Returns the Vec3f lhs as a Vec3i.
**/
Vec3i Vec3i_FromVec3f(Vec3f* lhs) {
    Vec3i return_value;
    Vec3i_FromVec3fAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec3s lhs as a Vec3i.
**/
Vec3i Vec3i_FromVec3s(Vec3s* lhs) {
    Vec3i return_value;
    Vec3i_FromVec3sAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec3s rhs to the Vec3s lhs and stores the result in lhs.
* (Vec3s)lhs += (Vec3s)rhs;
**/
void Vec3s_AddAssignment(Vec3s* lhs, Vec3s* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
}

/**
* @brief Subtracts the Vec3s rhs from the Vec3s lhs and stores the result in lhs.
* (Vec3s)lhs -= (Vec3s)rhs;
**/
void Vec3s_SubAssignment(Vec3s* lhs, Vec3s* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
    lhs->z -= rhs->z;
}

/**
* @brief Scales the Vec3s lhs to the Vec3s rhs and stores the result in lhs;
* (Vec3s)lhs *= (Vec3s)rhs;
**/
void Vec3s_MultiplyAssignment(Vec3s* lhs, Vec3s* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
    lhs->z *= rhs->z;
}

/**
* @brief Divide the Vec3s lhs by the Vec3s rhs and stores the result in lhs;
* (Vec3s)lhs /= (Vec3s)rhs;
**/
void Vec3s_DivideAssignment(Vec3s* lhs, Vec3s* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
    lhs->z /= rhs->z;
}

/**
* @brief Scales the Vec3s lhs to the short rhs and stores the result in lhs;
* (Vec3s)lhs *= (short)rhs;
**/
void Vec3s_MultiplyAssignmentF(Vec3s* lhs, s16 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
    lhs->z *= rhs;
}

/**
* @brief Divides the Vec3s lhs by the short rhs and stores the result in lhs;
* (Vec3s)lhs *= (short)rhs;
**/
void Vec3s_DivideAssignmentF(Vec3s* lhs, s16 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
    lhs->z /= rhs;
}

/**
* @brief Returns the sum of the Vec3s rhs and the Vec3s lhs as a Vec3s.
* v = ((Vec3s)lhs += (Vec3s)rhs);
**/
Vec3s Vec3s_Add(Vec3s lhs, Vec3s rhs) {
    Vec3s_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec3s lhs subtracted from the Vec3s rhs as a Vec3s.
* v = ((Vec3s)lhs -= (Vec3s)rhs);
**/
Vec3s Vec3s_Sub(Vec3s lhs, Vec3s rhs) {
    Vec3s_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec3s lhs scaled to the Vec3s rhs as a Vec3s.
* v = ((Vec3s)lhs *= (Vec3s)rhs);
**/
Vec3s Vec3s_Multiply(Vec3s lhs, Vec3s rhs) {
    Vec3s_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec3s lhs divided by the Vec3s rhs as a Vec3s.
* v = ((Vec3s)lhs *= (Vec3s)rhs);
**/
Vec3s Vec3s_Divide(Vec3s lhs, Vec3s rhs) {
    Vec3s_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec3s lhs scaled to the short rhs as a Vec3s.
* v = ((Vec3s)lhs *= (short)rhs);
**/
Vec3s Vec3s_MultiplyF(Vec3s lhs, s16 rhs) {
    Vec3s_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec3s lhs divided by the short rhs as a Vec3s.
* v = ((Vec3s)lhs *= (short)rhs);
**/
Vec3s Vec3s_DivideF(Vec3s lhs, s16 rhs) {
    Vec3s_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec3s lhs and the Vec3s rhs as a short.
* v = ((Vec3s)lhs • (Vec3s)rhs);
**/
s16 Vec3s_Dot(Vec3s* lhs, Vec3s* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z);
}

/**
* @brief Returns the cross product of the Vec3s lhs and the Vec3s rhs as a Vec3s.
* v = ((Vec3s)lhs • (Vec3s)rhs);
**/
Vec3s Vec3s_Cross(Vec3s* lhs, Vec3s* rhs) {
    Vec3s return_value;
    return_value.x = lhs->y * rhs->z - rhs->y * lhs->z;
    return_value.y = lhs->z * rhs->x - rhs->z * lhs->x;
    return_value.z = lhs->x * rhs->y - rhs->x * lhs->y;
    return return_value;
}

/**
* @brief Returns the square magnitude of the Vec3s lhs as a short.
* v = ((Vec3s)lhs^2)
**/
s16 Vec3s_SquareMagnitude(Vec3s lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y) + (lhs.z * lhs.z);
}

/**
* @brief Returns the magnitude of the Vec3s lhs as a short.
* v = √((Vec3s)lhs^2)
**/
s16 Vec3s_Magnitude(Vec3s lhs) {
    return sqrtf(Vec3s_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec3s lhs as a short.
* v = ((Vec3s)lhs^2)
**/
s16 Vec3s_SquareMagnitudePtr(Vec3s* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y) + (lhs->z * lhs->z);
}

/**
* @brief Returns the magnitude of the Vec3s lhs as a short.
* v = √((Vec3s)lhs^2)
**/
s16 Vec3s_MagnitudePtr(Vec3s* lhs) {
    return sqrtf(Vec3s_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec3s lhs shorto a unit vector.
**/
void Vec3s_NormalizeAssignment(Vec3s* lhs) {
    s16 magnitude = Vec3s_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = lhs->z = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
        lhs->z = (lhs->z / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec3s lhs as a Vec3s.
**/
Vec3s Vec3s_Normalize(Vec3s lhs) {
    Vec3s_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec3s lhs subtracted from the Vec3s rhs as a short.
**/
s16 Vec3s_Distance(Vec3s lhs, Vec3s rhs) {
    Vec3s_SubAssignment(&lhs, &rhs);
    return Vec3s_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec3s lhs.
**/
void Vec3s_InverseAssignment(Vec3s* lhs) {
    Vec3s_MultiplyAssignmentF(lhs, -1);
}

/**
* @brief Returns the inverse of the Vec3s lhs as a Vec3s.
**/
Vec3s Vec3s_Inverse(Vec3s lhs) {
    Vec3s_MultiplyAssignmentF(&lhs, -1);
    return lhs;
}

/**
* @brief Stores and casts the Vec3f rhs into the Vec3s lhs.
* (Vec3s)lhs = (Vec3f)rhs;
**/
void Vec3s_FromVec3fAssignment(Vec3s* lhs, Vec3f* rhs) {
    lhs->x = (s16)(rhs->x);
    lhs->y = (s16)(rhs->y);
    lhs->z = (s16)(rhs->z);
}

/**
* @brief Stores and casts the Vec3i rhs into the Vec3s lhs.
* (Vec3s)lhs = (Vec3i)rhs;
**/
void Vec3s_FromVec3iAssignment(Vec3s* lhs, Vec3i* rhs) {
    lhs->x = (s16)(rhs->x);
    lhs->y = (s16)(rhs->y);
    lhs->z = (s16)(rhs->z);
}

/**
* @brief Returns the Vec3f lhs as a Vec3s.
**/
Vec3s Vec3s_FromVec3f(Vec3f* lhs) {
    Vec3s return_value;
    Vec3s_FromVec3fAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec3i lhs as a Vec3s.
**/
Vec3s Vec3s_FromVec3i(Vec3i* lhs) {
    Vec3s return_value;
    Vec3s_FromVec3iAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec4f rhs to the Vec4f lhs and stores the result in lhs.
* (Vec4f)lhs += (Vec4f)rhs;
**/
void Vec4f_AddAssignment(Vec4f* lhs, Vec4f* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Subtracts the Vec4f rhs from the Vec4f lhs and stores the result in lhs.
* (Vec4f)lhs -= (Vec4f)rhs;
**/
void Vec4f_SubAssignment(Vec4f* lhs, Vec4f* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
    lhs->z -= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Scales the Vec4f lhs to the Vec4f rhs and stores the result in lhs;
* (Vec4f)lhs *= (Vec4f)rhs;
**/
void Vec4f_MultiplyAssignment(Vec4f* lhs, Vec4f* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
    lhs->z *= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Divide the Vec4f lhs by the Vec4f rhs and stores the result in lhs;
* (Vec4f)lhs /= (Vec4f)rhs;
**/
void Vec4f_DivideAssignment(Vec4f* lhs, Vec4f* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
    lhs->z /= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Scales the Vec4f lhs to the float rhs and stores the result in lhs;
* (Vec4f)lhs *= (float)rhs;
**/
void Vec4f_MultiplyAssignmentF(Vec4f* lhs, f32 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
    lhs->z *= rhs;
    lhs->w += rhs;
}

/**
* @brief Divides the Vec4f lhs by the float rhs and stores the result in lhs;
* (Vec4f)lhs *= (float)rhs;
**/
void Vec4f_DivideAssignmentF(Vec4f* lhs, f32 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
    lhs->z /= rhs;
    lhs->w += rhs;
}

/**
* @brief Returns the sum of the Vec4f rhs and the Vec4f lhs as a Vec4f.
* v = ((Vec4f)lhs += (Vec4f)rhs);
**/
Vec4f Vec4f_Add(Vec4f lhs, Vec4f rhs) {
    Vec4f_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec4f lhs subtracted from the Vec4f rhs as a Vec4f.
* v = ((Vec4f)lhs -= (Vec4f)rhs);
**/
Vec4f Vec4f_Sub(Vec4f lhs, Vec4f rhs) {
    Vec4f_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec4f lhs scaled to the Vec4f rhs as a Vec4f.
* v = ((Vec4f)lhs *= (Vec4f)rhs);
**/
Vec4f Vec4f_Multiply(Vec4f lhs, Vec4f rhs) {
    Vec4f_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec4f lhs divided by the Vec4f rhs as a Vec4f.
* v = ((Vec4f)lhs *= (Vec4f)rhs);
**/
Vec4f Vec4f_Divide(Vec4f lhs, Vec4f rhs) {
    Vec4f_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec4f lhs scaled to the float rhs as a Vec4f.
* v = ((Vec4f)lhs *= (float)rhs);
**/
Vec4f Vec4f_MultiplyF(Vec4f lhs, f32 rhs) {
    Vec4f_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec4f lhs divided by the float rhs as a Vec4f.
* v = ((Vec4f)lhs *= (float)rhs);
**/
Vec4f Vec4f_DivideF(Vec4f lhs, f32 rhs) {
    Vec4f_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec4f lhs and the Vec4f rhs as a float.
* v = ((Vec4f)lhs • (Vec4f)rhs);
**/
f32 Vec4f_Dot(Vec4f* lhs, Vec4f* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z) + (lhs->w * rhs->w);
}

/**
* @brief Returns the cross product of the Vec4f lhs and the Vec4f rhs as a Vec4f.
* v = ((Vec4f)lhs • (Vec4f)rhs);
**/
Vec4f Vec4f_Cross(Vec4f* lhs, Vec4f* rhs) {
    Vec4f return_value;
    return_value.x = lhs->y * rhs->z - rhs->y * lhs->z;
    return_value.y = lhs->z * rhs->x - rhs->z * lhs->x;
    return_value.z = lhs->x * rhs->y - rhs->x * lhs->y;
    return_value.w = 0;
    return return_value;
}

/**
* @brief Returns the square magnitude of the Vec4f lhs as a float.
* v = ((Vec4f)lhs^2)
**/
f32 Vec4f_SquareMagnitude(Vec4f lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y) + (lhs.z * lhs.z) + (lhs.w * lhs.w);
}

/**
* @brief Returns the magnitude of the Vec4f lhs as a float.
* v = √((Vec4f)lhs^2)
**/
f32 Vec4f_Magnitude(Vec4f lhs)
{
    return sqrtf(Vec4f_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec4f lhs as a float.
* v = ((Vec4f)lhs^2)
**/
f32 Vec4f_SquareMagnitudePtr(Vec4f* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y) + (lhs->z * lhs->z) + (lhs->w * lhs->w);
}

/**
* @brief Returns the magnitude of the Vec4f lhs as a float.
* v = √((Vec4f)lhs^2)
**/
f32 Vec4f_MagnitudePtr(Vec4f* lhs) {
    return sqrtf(Vec4f_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec4f lhs floato a unit vector.
**/
void Vec4f_NormalizeAssignment(Vec4f* lhs) {
    f32 magnitude = Vec4f_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = lhs->z = lhs->w = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
        lhs->z = (lhs->z / magnitude);
        lhs->w = (lhs->w / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec4f lhs as a Vec4f.
**/
Vec4f Vec4f_Normalize(Vec4f lhs) {
    Vec4f_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec4f lhs subtracted from the Vec4f rhs as a float.
**/
f32 Vec4f_Distance(Vec4f lhs, Vec4f rhs) {
    Vec4f_SubAssignment(&lhs, &rhs);
    return Vec4f_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec4f lhs.
**/
void Vec4f_InverseAssignment(Vec4f* lhs) {
    Vec4f_MultiplyAssignmentF(lhs, -1.0f);
}

/**
* @brief Returns the inverse of the Vec4f lhs as a Vec4f.
**/
Vec4f Vec4f_Inverse(Vec4f lhs) {
    Vec4f_MultiplyAssignmentF(&lhs, -1.0f);
    return lhs;
}

/**
* @brief Stores and casts the Vec4i rhs into the Vec4f lhs.
* (Vec4f)lhs = (Vec4i)rhs;
**/
void Vec4f_FromVec4iAssignment(Vec4f* lhs, Vec4i* rhs) {
    lhs->x = (f32)(rhs->x);
    lhs->y = (f32)(rhs->y);
    lhs->z = (f32)(rhs->z);
    lhs->w = (f32)(rhs->w);
}

/**
* @brief Stores and casts the Vec4s rhs into the Vec4f lhs.
* (Vec4f)lhs = (Vec4s)rhs;
**/
void Vec4f_FromVec4sAssignment(Vec4f* lhs, Vec4s* rhs) {
    lhs->x = (f32)(rhs->x);
    lhs->y = (f32)(rhs->y);
    lhs->z = (f32)(rhs->z);
    lhs->w = (f32)(rhs->w);
}

/**
* @brief Returns the Vec4i lhs as a Vec4f.
**/
Vec4f Vec4f_FromVec4i(Vec4i* lhs) {
    Vec4f return_value;
    Vec4f_FromVec4iAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec4s lhs as a Vec4f.
**/
Vec4f Vec4f_FromVec4s(Vec4s* lhs) {
    Vec4f return_value;
    Vec4f_FromVec4sAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec4i rhs to the Vec4i lhs and stores the result in lhs.
* (Vec4i)lhs += (Vec4i)rhs;
**/
void Vec4i_AddAssignment(Vec4i* lhs, Vec4i* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Subtracts the Vec4i rhs from the Vec4i lhs and stores the result in lhs.
* (Vec4i)lhs -= (Vec4i)rhs;
**/
void Vec4i_SubAssignment(Vec4i* lhs, Vec4i* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
    lhs->z -= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Scales the Vec4i lhs to the Vec4i rhs and stores the result in lhs;
* (Vec4i)lhs *= (Vec4i)rhs;
**/
void Vec4i_MultiplyAssignment(Vec4i* lhs, Vec4i* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
    lhs->z *= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Divide the Vec4i lhs by the Vec4i rhs and stores the result in lhs;
* (Vec4i)lhs /= (Vec4i)rhs;
**/
void Vec4i_DivideAssignment(Vec4i* lhs, Vec4i* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
    lhs->z /= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Scales the Vec4i lhs to the int rhs and stores the result in lhs;
* (Vec4i)lhs *= (int)rhs;
**/
void Vec4i_MultiplyAssignmentF(Vec4i* lhs, s32 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
    lhs->z *= rhs;
    lhs->w += rhs;
}

/**
* @brief Divides the Vec4i lhs by the int rhs and stores the result in lhs;
* (Vec4i)lhs *= (int)rhs;
**/
void Vec4i_DivideAssignmentF(Vec4i* lhs, s32 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
    lhs->z /= rhs;
    lhs->w += rhs;
}

/**
* @brief Returns the sum of the Vec4i rhs and the Vec4i lhs as a Vec4i.
* v = ((Vec4i)lhs += (Vec4i)rhs);
**/
Vec4i Vec4i_Add(Vec4i lhs, Vec4i rhs) {
    Vec4i_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec4i lhs subtracted from the Vec4i rhs as a Vec4i.
* v = ((Vec4i)lhs -= (Vec4i)rhs);
**/
Vec4i Vec4i_Sub(Vec4i lhs, Vec4i rhs) {
    Vec4i_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec4i lhs scaled to the Vec4i rhs as a Vec4i.
* v = ((Vec4i)lhs *= (Vec4i)rhs);
**/
Vec4i Vec4i_Multiply(Vec4i lhs, Vec4i rhs) {
    Vec4i_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec4i lhs divided by the Vec4i rhs as a Vec4i.
* v = ((Vec4i)lhs *= (Vec4i)rhs);
**/
Vec4i Vec4i_Divide(Vec4i lhs, Vec4i rhs) {
    Vec4i_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec4i lhs scaled to the int rhs as a Vec4i.
* v = ((Vec4i)lhs *= (int)rhs);
**/
Vec4i Vec4i_MultiplyF(Vec4i lhs, s32 rhs) {
    Vec4i_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec4i lhs divided by the int rhs as a Vec4i.
* v = ((Vec4i)lhs *= (int)rhs);
**/
Vec4i Vec4i_DivideF(Vec4i lhs, s32 rhs) {
    Vec4i_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec4i lhs and the Vec4i rhs as a int.
* v = ((Vec4i)lhs • (Vec4i)rhs);
**/
s32 Vec4i_Dot(Vec4i* lhs, Vec4i* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z) + (lhs->w * rhs->w);
}

/**
* @brief Returns the cross product of the Vec4i lhs and the Vec4i rhs as a Vec4i.
* v = ((Vec4i)lhs • (Vec4i)rhs);
**/
Vec4i Vec4i_Cross(Vec4i* lhs, Vec4i* rhs) {
    Vec4i return_value;
    return_value.x = lhs->y * rhs->z - rhs->y * lhs->z;
    return_value.y = lhs->z * rhs->x - rhs->z * lhs->x;
    return_value.z = lhs->x * rhs->y - rhs->x * lhs->y;
    return_value.w = 0;
    return return_value;
}

/**
* @brief Returns the square magnitude of the Vec4i lhs as a int.
* v = ((Vec4i)lhs^2)
**/
s32 Vec4i_SquareMagnitude(Vec4i lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y) + (lhs.z * lhs.z) + (lhs.w * lhs.w);
}

/**
* @brief Returns the magnitude of the Vec4i lhs as a int.
* v = √((Vec4i)lhs^2)
**/
s32 Vec4i_Magnitude(Vec4i lhs) {
    return sqrtf(Vec4i_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec4i lhs as a int.
* v = ((Vec4i)lhs^2)
**/
s32 Vec4i_SquareMagnitudePtr(Vec4i* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y) + (lhs->z * lhs->z) + (lhs->w * lhs->w);
}

/**
* @brief Returns the magnitude of the Vec4i lhs as a int.
* v = √((Vec4i)lhs^2)
**/
s32 Vec4i_MagnitudePtr(Vec4i* lhs) {
    return sqrtf(Vec4i_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec4i lhs into a unit vector.
**/
void Vec4i_NormalizeAssignment(Vec4i* lhs) {
    s32 magnitude = Vec4i_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = lhs->z = lhs->w = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
        lhs->z = (lhs->z / magnitude);
        lhs->w = (lhs->w / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec4i lhs as a Vec4i.
**/
Vec4i Vec4i_Normalize(Vec4i lhs) {
    Vec4i_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec4i lhs subtracted from the Vec4i rhs as a int.
**/
s32 Vec4i_Distance(Vec4i lhs, Vec4i rhs) {
    Vec4i_SubAssignment(&lhs, &rhs);
    return Vec4i_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec4i lhs.
**/
void Vec4i_InverseAssignment(Vec4i* lhs) {
    Vec4i_MultiplyAssignmentF(lhs, -1.0f);
}

/**
* @brief Returns the inverse of the Vec4i lhs as a Vec4i.
**/
Vec4i Vec4i_Inverse(Vec4i lhs) {
    Vec4i_MultiplyAssignmentF(&lhs, -1.0f);
    return lhs;
}

/**
* @brief Stores and casts the Vec4f rhs into the Vec4i lhs.
* (Vec4i)lhs = (Vec4f)rhs;
**/
void Vec4i_FromVec4fAssignment(Vec4i* lhs, Vec4f* rhs) {
    lhs->x = (s32)(rhs->x);
    lhs->y = (s32)(rhs->y);
    lhs->z = (s32)(rhs->z);
    lhs->w = (s32)(rhs->w);
}

/**
* @brief Stores and casts the Vec4s rhs into the Vec4i lhs.
* (Vec4i)lhs = (Vec4s)rhs;
**/
void Vec4i_FromVec4sAssignment(Vec4i* lhs, Vec4s* rhs) {
    lhs->x = (s32)(rhs->x);
    lhs->y = (s32)(rhs->y);
    lhs->z = (s32)(rhs->z);
    lhs->w = (s32)(rhs->w);
}

/**
* @brief Returns the Vec4f lhs as a Vec4i.
**/
Vec4i Vec4i_FromVec4f(Vec4f* lhs) {
    Vec4i return_value;
    Vec4i_FromVec4fAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec4s lhs as a Vec4i.
**/
Vec4i Vec4i_FromVec4s(Vec4s* lhs) {
    Vec4i return_value;
    Vec4i_FromVec4sAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Adds theVec4s rhs to the Vec4s lhs and stores the result in lhs.
* (Vec4s)lhs += (Vec4s)rhs;
**/
void Vec4s_AddAssignment(Vec4s* lhs, Vec4s* rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Subtracts the Vec4s rhs from the Vec4s lhs and stores the result in lhs.
* (Vec4s)lhs -= (Vec4s)rhs;
**/
void Vec4s_SubAssignment(Vec4s* lhs, Vec4s* rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
    lhs->z -= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Scales the Vec4s lhs to the Vec4s rhs and stores the result in lhs;
* (Vec4s)lhs *= (Vec4s)rhs;
**/
void Vec4s_MultiplyAssignment(Vec4s* lhs, Vec4s* rhs) {
    lhs->x *= rhs->x;
    lhs->y *= rhs->y;
    lhs->z *= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Divide the Vec4s lhs by the Vec4s rhs and stores the result in lhs;
* (Vec4s)lhs /= (Vec4s)rhs;
**/
void Vec4s_DivideAssignment(Vec4s* lhs, Vec4s* rhs) {
    lhs->x /= rhs->x;
    lhs->y /= rhs->y;
    lhs->z /= rhs->z;
    lhs->w += rhs->w;
}

/**
* @brief Scales the Vec4s lhs to the short rhs and stores the result in lhs;
* (Vec4s)lhs *= (short)rhs;
**/
void Vec4s_MultiplyAssignmentF(Vec4s* lhs, s16 rhs) {
    lhs->x *= rhs;
    lhs->y *= rhs;
    lhs->z *= rhs;
    lhs->w += rhs;
}

/**
* @brief Divides the Vec4s lhs by the short rhs and stores the result in lhs;
* (Vec4s)lhs *= (short)rhs;
**/
void Vec4s_DivideAssignmentF(Vec4s* lhs, s16 rhs) {
    lhs->x /= rhs;
    lhs->y /= rhs;
    lhs->z /= rhs;
    lhs->w += rhs;
}

/**
* @brief Returns the sum of the Vec4s rhs and the Vec4s lhs as a Vec4s.
* v = ((Vec4s)lhs += (Vec4s)rhs);
**/
Vec4s Vec4s_Add(Vec4s lhs, Vec4s rhs) {
    Vec4s_AddAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the difference of the Vec4s lhs subtracted from the Vec4s rhs as a Vec4s.
* v = ((Vec4s)lhs -= (Vec4s)rhs);
**/
Vec4s Vec4s_Sub(Vec4s lhs, Vec4s rhs) {
    Vec4s_SubAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec4s lhs scaled to the Vec4s rhs as a Vec4s.
* v = ((Vec4s)lhs *= (Vec4s)rhs);
**/
Vec4s Vec4s_Multiply(Vec4s lhs, Vec4s rhs) {
    Vec4s_MultiplyAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec4s lhs divided by the Vec4s rhs as a Vec4s.
* v = ((Vec4s)lhs *= (Vec4s)rhs);
**/
Vec4s Vec4s_Divide(Vec4s lhs, Vec4s rhs) {
    Vec4s_DivideAssignment(&lhs, &rhs);
    return lhs;
}

/**
* @brief Returns the product of the Vec4s lhs scaled to the short rhs as a Vec4s.
* v = ((Vec4s)lhs *= (short)rhs);
**/
Vec4s Vec4s_MultiplyF(Vec4s lhs, s16 rhs) {
    Vec4s_MultiplyAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the quotient of the Vec4s lhs divided by the short rhs as a Vec4s.
* v = ((Vec4s)lhs *= (short)rhs);
**/
Vec4s Vec4s_DivideF(Vec4s lhs, s16 rhs) {
    Vec4s_DivideAssignmentF(&lhs, rhs);
    return lhs;
}

/**
* @brief Returns the dot product of the Vec4s lhs and the Vec4s rhs as a short.
* v = ((Vec4s)lhs • (Vec4s)rhs);
**/
s16 Vec4s_Dot(Vec4s* lhs, Vec4s* rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y) + (lhs->z * rhs->z) + (lhs->w * rhs->w);
}

/**
* @brief Returns the cross product of the Vec4s lhs and the Vec4s rhs as a Vec4s.
* v = ((Vec4s)lhs • (Vec4s)rhs);
**/
Vec4s Vec4s_Cross(Vec4s* lhs, Vec4s* rhs) {
    Vec4s return_value;
    return_value.x = lhs->y * rhs->z - rhs->y * lhs->z;
    return_value.y = lhs->z * rhs->x - rhs->z * lhs->x;
    return_value.z = lhs->x * rhs->y - rhs->x * lhs->y;
    return_value.w = 0;
    return return_value;
}

/**
* @brief Returns the square magnitude of the Vec4s lhs as a short.
* v = ((Vec4s)lhs^2)
**/
s16 Vec4s_SquareMagnitude(Vec4s lhs) {
    return (lhs.x * lhs.x) + (lhs.y * lhs.y) + (lhs.z * lhs.z) + (lhs.w * lhs.w);
}

/**
* @brief Returns the magnitude of the Vec4s lhs as a short.
* v = √((Vec4s)lhs^2)
**/
s16 Vec4s_Magnitude(Vec4s lhs) {
    return sqrtf(Vec4s_SquareMagnitude(lhs));
}

/**
* @brief Returns the square magnitude of the Vec4s lhs as a short.
* v = ((Vec4s)lhs^2)
**/
s16 Vec4s_SquareMagnitudePtr(Vec4s* lhs) {
    return (lhs->x * lhs->x) + (lhs->y * lhs->y) + (lhs->z * lhs->z) + (lhs->w * lhs->w);
}

/**
* @brief Returns the magnitude of the Vec4s lhs as a short.
* v = √((Vec4s)lhs^2)
**/
s16 Vec4s_MagnitudePtr(Vec4s* lhs) {
    return sqrtf(Vec4s_SquareMagnitudePtr(lhs));
}

/**
* @brief Normalizes the Vec4s lhs shorto a unit vector.
**/
void Vec4s_NormalizeAssignment(Vec4s* lhs) {
    s16 magnitude = Vec4s_MagnitudePtr(lhs);
    if (magnitude == 0) {
        lhs->x = lhs->y = lhs->z = lhs->w = 0;
    }
    else {
        lhs->x = (lhs->x / magnitude);
        lhs->y = (lhs->y / magnitude);
        lhs->z = (lhs->z / magnitude);
        lhs->w = (lhs->w / magnitude);
    }
}

/**
* @brief Returns the unit vector of the Vec4s lhs as a Vec4s.
**/
Vec4s Vec4s_Normalize(Vec4s lhs) {
    Vec4s_NormalizeAssignment(&lhs);
    return lhs;
}

/**
* @brief Returns the difference of the magnitudes of the Vec4s lhs subtracted from the Vec4s rhs as a short.
**/
s16 Vec4s_Distance(Vec4s lhs, Vec4s rhs) {
    Vec4s_SubAssignment(&lhs, &rhs);
    return Vec4s_MagnitudePtr(&lhs);
}

/**
* @brief Inverts the Vec4s lhs.
**/
void Vec4s_InverseAssignment(Vec4s* lhs) {
    Vec4s_MultiplyAssignmentF(lhs, -1.0f);
}

/**
* @brief Returns the inverse of the Vec4s lhs as a Vec4s.
**/
Vec4s Vec4s_Inverse(Vec4s lhs) {
    Vec4s_MultiplyAssignmentF(&lhs, -1.0f);
    return lhs;
}

/**
* @brief Stores and casts the Vec4f rhs into the Vec4s lhs.
* (Vec4s)lhs = (Vec4f)rhs;
**/
void Vec4s_FromVec4fAssignment(Vec4s* lhs, Vec4f* rhs) {
    lhs->x = (s16)(rhs->x);
    lhs->y = (s16)(rhs->y);
    lhs->z = (s16)(rhs->z);
    lhs->w = (s16)(rhs->w);
}

/**
* @brief Stores and casts the Vec4i rhs into the Vec4s lhs.
* (Vec4s)lhs = (Vec4i)rhs;
**/
void Vec4s_FromVec4iAssignment(Vec4s* lhs, Vec4i* rhs) {
    lhs->x = (s16)(rhs->x);
    lhs->y = (s16)(rhs->y);
    lhs->z = (s16)(rhs->z);
    lhs->w = (s16)(rhs->w);
}

/**
* @brief Returns the Vec4f lhs as a Vec4s.
**/
Vec4s Vec4s_FromVec4f(Vec4f* lhs) {
    Vec4s return_value;
    Vec4s_FromVec4fAssignment(&return_value, lhs);
    return return_value;
}

/**
* @brief Returns the Vec4i lhs as a Vec4s.
**/
Vec4s Vec4s_FromVec4i(Vec4i* lhs) {
    Vec4s return_value;
    Vec4s_FromVec4iAssignment(&return_value, lhs);
    return return_value;
}

// Add the f32 rhs to the f32 w of QuatF lhs, storing the result in lhs (lhs.w += rhs)
void QuatF_AddWAssignment(QuatF* lhs, f32 rhs) {
    lhs->w += rhs;
}

// Subtract the f32 rhs to the f32 w of QuatF lhs, storing the result in lhs (lhs.w -= rhs)
void QuatF_SubWAssignment(QuatF* lhs, f32 rhs) {
    lhs->w -= rhs;
}

// returns the sum of the f32 w of QuatF lhs and the f32 rhs (v = lhs.w + rhs)
QuatF QuatF_AddW(QuatF lhs, f32 rhs) {
    QuatF_AddWAssignment(&lhs, rhs);
    return lhs;
}

// returns the f32 w of QuatF lhs Subtracted by the f32 rhs (v = lhs.w - rhs)
QuatF QuatF_SubW(QuatF lhs, f32 rhs) {
    QuatF_SubWAssignment(&lhs, rhs);
    return lhs;
}

// sets the QuatF lhs to its conjugate
void QuatF_ConjugateAssignment(QuatF* lhs) {
    lhs->x = -lhs->x;
    lhs->y = -lhs->y;
    lhs->z = -lhs->z;
}

// returns the conjugate of QuatF lhs
QuatF QuatF_Conjugate(QuatF lhs) {
    QuatF_ConjugateAssignment(&lhs);
    return lhs;
}

// sets the QuatF lhs to reslting axis angle of Vec3f axis and f32 angle
void QuatF_AxisAngleAssignment(QuatF* lhs, Vec3f* axis, f32 angle) {
    Vec3f norm = Vec3f_Normalize(*axis);
    f32 sina;

    angle *= 0.5f;
    sina = sinf(angle);

    lhs->x = norm.x * sina;
    lhs->y = norm.y * sina;
    lhs->z = norm.z * sina;
    lhs->w = cosf(angle);
}

// returns the resulting QuatF of the axis angle formula using Vec3f axis and f32 angle
QuatF QuatF_AxisAngle(QuatF lhs, Vec3f* axis, f32 angle) {
    QuatF_AxisAngleAssignment(&lhs, axis, angle);
    return lhs;
}

// sets the QuatF lhs from the euler angles in Vec3f rhs
void QuatF_FromEulerAssignment(QuatF* lhs, Vec3f* rhs) {
    Vec3f sinv;
    Vec3f cosv;
    Vec3f euler = Vec3f_Normalize(*rhs);

    Vec3f_MultiplyAssignmentF(&euler, 0.5f);

    sinv.x = sinf(euler.x);
    sinv.y = sinf(euler.y);
    sinv.z = sinf(euler.z);

    cosv.x = cosf(euler.x);
    cosv.y = cosf(euler.y);
    cosv.z = cosf(euler.z);

	lhs->x = sinv.x * cosv.y * cosv.z + cosv.x * sinv.y * sinv.z;
	lhs->y = cosv.x * sinv.y * cosv.z - sinv.x * cosv.y * sinv.z;
	lhs->z = cosv.x * cosv.y * sinv.z - sinv.x * sinv.y * cosv.z;
    lhs->w = cosv.x * cosv.y * cosv.z + sinv.x * sinv.y * sinv.z;
}

// returns the QuatF from the euler angles in Vec3f rhs
QuatF QuatF_FromEuler(Vec3f rhs) {
    QuatF return_value;
    QuatF_FromEulerAssignment(&return_value, &rhs);
    return return_value;
}

// sets the Vec3f axis and f32 angle from the QuatF lhs
void QuatF_ToAngleAxisAssignment(QuatF* lhs, Vec3f* axis, f32* angle) {
    f32 sina;

    *angle = acosf(lhs->w);
    sina = sinf(*angle);

    if (fabsf(sina) > 1e-8f && sina != 0) {
        sina = 1.0f / sina;

        axis->x = lhs->x * sina;
        axis->y = lhs->y * sina;
        axis->z = lhs->z * sina;

        *angle *= 2.0f;
    }
    else {
        *angle = 0.0f;
        axis->x = 1.0f;
        axis->y = 0.0f;
        axis->z = 0.0f;
    }
}

// @brief Returns the Vec3f axis from the QuatF lhs, storing the f32 angle in angle
Vec3f QuatF_ToAngleAxis(QuatF* lhs, Vec3f axis, f32* angle) {
    QuatF_ToAngleAxisAssignment(lhs, &axis, angle);
    return axis;
}

// sets the QuatF lhs to the look rotation from Vec3f look_at and Vec3f up
void QuatF_FromLookRotationAssignment(QuatF* lhs, Vec3f* look_at, Vec3f* up) {
    Vec3f forward, right;
    f32 recip;

    forward = Vec3f_Normalize(*look_at);
    right = Vec3f_Cross(&forward, &right);

    lhs->w = sqrtf(1.0f + right.x + up->y + forward.z) * 0.5f;
    if (lhs->w) recip = 1.0f / (4.0f * lhs->w);
    else recip = 0;

    lhs->x = (up->z - forward.y) * recip;
    lhs->y = (forward.x - right.z) * recip;
    lhs->z = (right.y - up->x) * recip;
}

// returns the QuatF from the look rotation from Vec3f look_at and Vec3f up
QuatF QuatF_FromLookRotation(Vec3f* look_at, Vec3f* up) {
    QuatF return_value;
    QuatF_FromLookRotationAssignment(&return_value, look_at, up);
    return return_value;
}

void QuatF_ToMatrixAssignment(f32 matrix[4][4], QuatF lhs) {
    f32 mag, norm;
    mag = QuatF_MagnitudePtr(&lhs);

    if (mag == 0) {
        matrix[0][0] = 1.0f;
        matrix[0][1] = 0.0f;
        matrix[0][2] = 0.0f;
        matrix[0][3] = 0.0f;
        matrix[1][0] = 0.0f;
        matrix[1][1] = 1.0f;
        matrix[1][2] = 0.0f;
        matrix[1][3] = 0.0f;
        matrix[2][0] = 0.0f;
        matrix[2][1] = 0.0f;
        matrix[2][2] = 1.0f;
        matrix[2][3] = 0.0f;
        matrix[3][3] = 1.0f;
    }
    else {
        norm = 1.0f / QuatF_MagnitudePtr(&lhs);
        QuatF_MultiplyAssignmentF(&lhs, norm);

        matrix[0][0] = 1.0f - 2.0f * lhs.y * lhs.y - 2.0f * lhs.z * lhs.z;
        matrix[0][1] = 2.0f * lhs.x * lhs.y - 2.0f * lhs.z * lhs.w;
        matrix[0][2] = 2.0f * lhs.x * lhs.z + 2.0f * lhs.y * lhs.w;
        matrix[0][3] = 0.0f;
        matrix[1][0] = 2.0f * lhs.x * lhs.y + 2.0f * lhs.z * lhs.w;
        matrix[1][1] = 1.0f - 2.0f * lhs.x * lhs.x - 2.0f * lhs.z * lhs.z;
        matrix[1][2] = 2.0f * lhs.y * lhs.z - 2.0f * lhs.x * lhs.w;
        matrix[1][3] = 0.0f;
        matrix[2][0] = 2.0f * lhs.x * lhs.z - 2.0f * lhs.y * lhs.w;
        matrix[2][1] = 2.0f * lhs.y * lhs.z + 2.0f * lhs.x * lhs.w;
        matrix[2][2] = 1.0f - 2.0f * lhs.x * lhs.x - 2.0f * lhs.y * lhs.y;
        matrix[2][3] = 0.0f;
        matrix[3][3] = 1.0f;
    }
}
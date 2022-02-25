#ifndef LIBAXIS_VECTOR_H
#define LIBAXIS_VECTOR_H

typedef struct {
    short x, y;
} Vec2s;

typedef struct {
    int x, y;
} Vec2i;

#ifdef __LA_STANDALONE__
typedef struct {
    float x, y;
} Vec2f;

typedef struct {
    short x, y, z;
} Vec3s;

typedef struct {
    int x, y, z;
} Vec3i;

typedef struct {
    float x, y, z;
} Vec3f;
#endif

typedef struct {
    short x, y, z, w;
} Vec4s;

typedef struct {
    int x, y, z, w;
} Vec4i;

typedef struct {
    float x, y, z, w;
} Vec4f, QuatF;

#define VEC_OVERRIDE(_1, _2, _3, _4, N, ...) N
#define VEC2F_NEW(x, y) (Vec2f){(x), (y)}
#define VEC3F_NEW(x, y, z) (Vec3f){(x), (y), (z)}
#define VEC4F_NEW(x, y, z, w) (Vec4f){(x), (y), (z), (w)}
#define VEC2I_NEW(x, y) (Vec2i){(x), (y)}
#define VEC3I_NEW(x, y, z) (Vec3i){(x), (y), (z)}
#define VEC4I_NEW(x, y, z, w) (Vec4i){(x), (y), (z), (w)}
#define VEC2S_NEW(x, y) (Vec2s){(x), (y)}
#define VEC3S_NEW(x, y, z) (Vec3s){(x), (y), (z)}
#define VEC4S_NEW(x, y, z, w) (Vec4s){(x), (y), (z), (w)}
#define VEC3F_X(r, p, y) ((r) * (sinf(DTOR(y))) * (cosf(DTOR(p))))
#define VEC3F_Y(r, p, y) ((r) * (cosf(DTOR(y))) * (sinf(DTOR(p))))
#define VEC3F_Z(r, p, y) ((r) * (cosf(DTOR(y))) * (cosf(DTOR(p))))

#define VEC_NEW(...) (VEC_OVERRIDE(__VA_ARGS__, VEC4F_NEW, VEC3F_NEW, VEC2F_NEW)(__VA_ARGS__))
#define VECF_NEW(...) (VEC_OVERRIDE(__VA_ARGS__, VEC4F_NEW, VEC3F_NEW, VEC2F_NEW)(__VA_ARGS__))
#define VECI_NEW(...) (VEC_OVERRIDE(__VA_ARGS__, VEC4I_NEW, VEC3I_NEW, VEC2I_NEW)(__VA_ARGS__))
#define VECS_NEW(...) (VEC_OVERRIDE(__VA_ARGS__, VEC4S_NEW, VEC3S_NEW, VEC2S_NEW)(__VA_ARGS__))
#define QUATF_NEW(...) VEC4F_NEW(...)
#define QUATI_NEW(...) VEC4I_NEW(...)
#define QUATS_NEW(...) VEC4S_NEW(...)

static const Vec2f Vec2f_Right    = VEC_NEW(1.0f, 0.0f);
static const Vec2f Vec2f_Up       = VEC_NEW(0.0f, 1.0f);
static const Vec2f Vec2f_Left     = VEC_NEW(-1.0f, 0.0f);
static const Vec2f Vec2f_Down     = VEC_NEW(0.0f, -1.0f);
static const Vec2f Vec2f_Zero     = VEC_NEW(0.0f, 0.0f);

static const Vec3f Vec3f_Right    = VEC_NEW(1.0f, 0.0f, 0.0f);
static const Vec3f Vec3f_Up       = VEC_NEW(0.0f, 1.0f, 0.0f);
static const Vec3f Vec3f_Forward  = VEC_NEW(0.0f, 0.0f, 1.0f);
static const Vec3f Vec3f_Left     = VEC_NEW(-1.0f, 0.0f, 0.0f);
static const Vec3f Vec3f_Down     = VEC_NEW(0.0f, -1.0f, 0.0f);
static const Vec3f Vec3f_Backward = VEC_NEW(0.0f, 0.0f, -1.0f);
static const Vec3f Vec3f_Zero     = VEC_NEW(0.0f, 0.0f, 0.0f);

static const Vec4f Vec4f_Right    = VEC_NEW(1.0f, 0.0f, 0.0f, 0.0f);
static const Vec4f Vec4f_Up       = VEC_NEW(0.0f, 1.0f, 0.0f, 0.0f);
static const Vec4f Vec4f_Forward  = VEC_NEW(0.0f, 0.0f, 1.0f, 0.0f);
static const Vec4f Vec4f_Identity = VEC_NEW(0.0f, 0.0f, 0.0f, 1.0f);
static const Vec4f Vec4f_Left     = VEC_NEW(-1.0f, 0.0f, 0.0f, 0.0f);
static const Vec4f Vec4f_Down     = VEC_NEW(0.0f, -1.0f, 0.0f, 0.0f);
static const Vec4f Vec4f_Backward = VEC_NEW(0.0f, 0.0f, -1.0f, 0.0f);
static const Vec4f Vec4f_Ndentity = VEC_NEW(0.0f, 0.0f, 0.0f, -1.0f);
static const Vec4f Vec4f_Zero     = VEC_NEW(0.0f, 0.0f, 0.0f, 0.0f);

static const Vec2i Vec2i_Right    = VECI_NEW(1, 0);
static const Vec2i Vec2i_Up       = VECI_NEW(0, 1);
static const Vec2i Vec2i_Left     = VECI_NEW(-1, 0);
static const Vec2i Vec2i_Down     = VECI_NEW(0, -1);
static const Vec2i Vec2i_Zero     = VECI_NEW(0, 0);

static const Vec3i Vec3i_Right    = VECI_NEW(1, 0, 0);
static const Vec3i Vec3i_Up       = VECI_NEW(0, 1, 0);
static const Vec3i Vec3i_Forward  = VECI_NEW(0, 0, 1);
static const Vec3i Vec3i_Left     = VECI_NEW(-1, 0, 0);
static const Vec3i Vec3i_Down     = VECI_NEW(0, -1, 0);
static const Vec3i Vec3i_Backward = VECI_NEW(0, 0, -1);
static const Vec3i Vec3i_Zero     = VECI_NEW(0, 0, 0);

static const Vec4i Vec4i_Right    = VECI_NEW(1, 0, 0, 0);
static const Vec4i Vec4i_Up       = VECI_NEW(0, 1, 0, 0);
static const Vec4i Vec4i_Forward  = VECI_NEW(0, 0, 1, 0);
static const Vec4i Vec4i_Identity = VECI_NEW(0, 0, 0, 1);
static const Vec4i Vec4i_Left     = VECI_NEW(-1, 0, 0, 0);
static const Vec4i Vec4i_Down     = VECI_NEW(0, -1, 0, 0);
static const Vec4i Vec4i_Backward = VECI_NEW(0, 0, -1, 0);
static const Vec4i Vec4i_Ndentity = VECI_NEW(0, 0, 0, -1);
static const Vec4i Vec4i_Zero     = VECI_NEW(0, 0, 0, 0);

static const Vec2s Vec2s_Right    = VECS_NEW(1, 0);
static const Vec2s Vec2s_Up       = VECS_NEW(0, 1);
static const Vec2s Vec2s_Left     = VECS_NEW(-1, 0);
static const Vec2s Vec2s_Down     = VECS_NEW(0, -1);
static const Vec2s Vec2s_Zero     = VECS_NEW(0, 0);

static const Vec3s Vec3s_Right    = VECS_NEW(1, 0, 0);
static const Vec3s Vec3s_Up       = VECS_NEW(0, 1, 0);
static const Vec3s Vec3s_Forward  = VECS_NEW(0, 0, 1);
static const Vec3s Vec3s_Left     = VECS_NEW(-1, 0, 0);
static const Vec3s Vec3s_Down     = VECS_NEW(0, -1, 0);
static const Vec3s Vec3s_Backward = VECS_NEW(0, 0, -1);
static const Vec3s Vec3s_Zero     = VECS_NEW(0, 0, 0);

static const Vec4s Vec4s_Right    = VECS_NEW(1, 0, 0, 0);
static const Vec4s Vec4s_Up       = VECS_NEW(0, 1, 0, 0);
static const Vec4s Vec4s_Forward  = VECS_NEW(0, 0, 1, 0);
static const Vec4s Vec4s_Identity = VECS_NEW(0, 0, 0, 1);
static const Vec4s Vec4s_Left     = VECS_NEW(-1, 0, 0, 0);
static const Vec4s Vec4s_Down     = VECS_NEW(0, -1, 0, 0);
static const Vec4s Vec4s_Backward = VECS_NEW(0, 0, -1, 0);
static const Vec4s Vec4s_Ndentity = VECS_NEW(0, 0, 0, -1);
static const Vec4s Vec4s_Zero     = VECS_NEW(0, 0, 0, 0);

#define QuatF_Xhat      Vec4f_Right
#define QuatF_Yhat      Vec4f_Up
#define QuatF_Zhat      Vec4f_Forward
#define QuatF_Identity  Vec4f_Identity
#define QuatF_Xnhat     Vec4f_Left
#define QuatF_Ynhat     Vec4f_Down
#define QuatF_Znhat     Vec4f_Backward
#define QuatF_Ndentity  Vec4f_Ndentity
#define QuatF_AddAssignment             Vec4f_AddAssignment
#define QuatF_SubAssignment             Vec4f_SubAssignment
#define QuatF_MultiplyAssignment        Vec4f_MultiplyAssignment
#define QuatF_DivideAssignment          Vec4f_DivideAssignment
#define QuatF_MultiplyAssignmentF       Vec4f_MultiplyAssignmentF
#define QuatF_DivideAssignmentF         Vec4f_DivideAssignmentF
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

#define  Vec2_Equals(lhs, rhs) (lhs.x == rhs.x && lhs.y == rhs.y)
#define  Vec3_Equals(lhs, rhs) (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
#define  Vec4_Equals(lhs, rhs) (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w)

#endif /* LIBAXIS_VECTOR_H */
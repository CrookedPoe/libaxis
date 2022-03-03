#ifndef LIBAXIS_MATRIX_H
#define LIBAXIS_MATRIX_H

typedef union Matrix22 {
    float mf[2][2];
    struct {
        float xx, xy;
        float yx, yy;
    };
} Mtx2F_t, mtx2f_t;

typedef union Matrix33 {
    float mf[3][3];
    struct {
        float xx, xy, xz;
        float yx, yy, yz;
        float zx, zy, zz;
    };
} Mtx3F_t, mtx3f_t;

typedef union Matrix44 {
    float mf[4][4];
    struct {
        float xx, xy, xz, xw;
        float yx, yy, yz, yw;
        float zx, zy, zz, zw;
        float wx, wy, wz, ww;
    };
} Mtx4F_t, mtx4f_t;

/* Sequestered from glankk/n64/gbi.h */
typedef int32_t Mtx44_t[4][4];
typedef union {
    _Alignas(8)
    Mtx44_t         m;
    int32_t         l[16];
    struct {
        int16_t     i[16];
        uint16_t    f[16];
    };
} Mtx44;

typedef int32_t   qs1616_t;
#define qs1616(n)                     ((qs1616_t)((n)*0x00010000))

#define gdSPDefMtx(xx,xy,xz,xw,     \
                   yx,yy,yz,yw,     \
                   zx,zy,zz,zw,     \
                   wx,wy,wz,ww)       ((Mtx44)                                  \
                                       {.i={(qs1616(xx)>>16)&0x0000FFFF,      \
                                            (qs1616(xy)>>16)&0x0000FFFF,      \
                                            (qs1616(xz)>>16)&0x0000FFFF,      \
                                            (qs1616(xw)>>16)&0x0000FFFF,      \
                                            (qs1616(yx)>>16)&0x0000FFFF,      \
                                            (qs1616(yy)>>16)&0x0000FFFF,      \
                                            (qs1616(yz)>>16)&0x0000FFFF,      \
                                            (qs1616(yw)>>16)&0x0000FFFF,      \
                                            (qs1616(zx)>>16)&0x0000FFFF,      \
                                            (qs1616(zy)>>16)&0x0000FFFF,      \
                                            (qs1616(zz)>>16)&0x0000FFFF,      \
                                            (qs1616(zw)>>16)&0x0000FFFF,      \
                                            (qs1616(wx)>>16)&0x0000FFFF,      \
                                            (qs1616(wy)>>16)&0x0000FFFF,      \
                                            (qs1616(wz)>>16)&0x0000FFFF,      \
                                            (qs1616(ww)>>16)&0x0000FFFF},     \
                                        .f={qs1616(xx)&0x0000FFFF,            \
                                            qs1616(xy)&0x0000FFFF,            \
                                            qs1616(xz)&0x0000FFFF,            \
                                            qs1616(xw)&0x0000FFFF,            \
                                            qs1616(yx)&0x0000FFFF,            \
                                            qs1616(yy)&0x0000FFFF,            \
                                            qs1616(yz)&0x0000FFFF,            \
                                            qs1616(yw)&0x0000FFFF,            \
                                            qs1616(zx)&0x0000FFFF,            \
                                            qs1616(zy)&0x0000FFFF,            \
                                            qs1616(zz)&0x0000FFFF,            \
                                            qs1616(zw)&0x0000FFFF,            \
                                            qs1616(wx)&0x0000FFFF,            \
                                            qs1616(wy)&0x0000FFFF,            \
                                            qs1616(wz)&0x0000FFFF,            \
                                            qs1616(ww)&0x0000FFFF}})

static const mtx2f_t mtx2f_identity = (mtx2f_t){
      1.0f, 0.0f
    , 0.0f, 1.0f
};

static const mtx3f_t mtx3f_identity = (mtx3f_t){
      1.0f, 0.0f, 0.0f
    , 0.0f, 1.0f, 0.0f
    , 0.0f, 0.0f, 1.0f
};

static const mtx4f_t mtx4f_identity = (mtx4f_t){
      1.0f, 0.0f, 0.0f, 0.0f
    , 0.0f, 1.0f, 0.0f, 0.0f
    , 0.0f, 0.0f, 1.0f, 0.0f
    , 0.0f, 0.0f, 0.0f, 1.0f
};


/* #include <string.h> // For memcpy
static inline void* matrix_set_identity(void* out, int dim)
{
    if (dim < 2)
        return out;
    float mtx[dim][dim];
    int i, j;
    
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            mtx[i][j] = (i == j) ? 1.0f : 0.0f;
    
    memcpy(out, mtx, dim * dim * sizeof(float));
    return out;
} */

#endif /* LIBAXIS_MATRIX_H */ 
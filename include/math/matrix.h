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
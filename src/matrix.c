/**
 * @file: matrix.c
 * @author: CrookedPoe (https://github.com/CrookedPoe)
 * 
 * @brief Matrix transformations.
**/

#include "../include/libaxis.h"

void LibAxis_Matrix44_IdentityF(float mf[4][4]) {
	int32_t i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			mf[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

void LibAxis_Matrix44_TranslateF(float mf[4][4], float x, float y, float z) {
	LibAxis_Matrix44_IdentityF(mf);
	mf[3][0] = x;
	mf[3][1] = y;
	mf[3][2] = z;
}

void LibAxis_Matrix44_ScaleF(float mf[4][4], float x, float y, float z) {
	LibAxis_Matrix44_IdentityF(mf);
	mf[0][0] = x;
	mf[1][1] = y;
	mf[2][2] = z;
	mf[3][3] = 1.0f;
}

void LibAxis_Matrix44_RotateF(float mf[4][4], float roll, float pitch, float heading) {
	static float dtor = 3.1415926f / 180.0f;
	float sinr, sinp, sinh;
	float cosr, cosp, cosh;

	roll *= dtor;
	pitch *= dtor;
	heading *= dtor;
	sinr = sinf(roll);
	cosr = cosf(roll);
	sinp = sinf(pitch);
	cosp = cosf(pitch);
	sinh = sinf(heading);
	cosh = cosf(heading);

	LibAxis_Matrix44_IdentityF(mf);

	mf[0][0] = cosp * cosh;
	mf[0][1] = cosp * sinh;
	mf[0][2] = -sinp;

	mf[1][0] = sinr * sinp * cosh - cosr * sinh;
	mf[1][1] = sinr * sinp * sinh + cosr * cosh;
	mf[1][2] = sinr * cosp;

	mf[2][0] = cosr * sinp * cosh + sinr * sinh;
	mf[2][1] = cosr * sinp * sinh - sinr * cosh;
	mf[2][2] = cosr * cosp;
}

void LibAxis_Matrix44_MultiplyF(float mf_a[4][4], float mf_b[4][4], float mf[4][4]) {
	float rx, ry, rz, rw;
	float cx, cy, cz, cw;

	/* Column 0 */
	cx = mf_b[0][0];
	cy = mf_b[1][0];
	cz = mf_b[2][0];
	cw = mf_b[3][0];

	rx = mf_a[0][0];
	ry = mf_a[0][1];
	rz = mf_a[0][2];
	rw = mf_a[0][3];
	mf[0][0] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[1][0];
	ry = mf_a[1][1];
	rz = mf_a[1][2];
	rw = mf_a[1][3];
	mf[1][0] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[2][0];
	ry = mf_a[2][1];
	rz = mf_a[2][2];
	rw = mf_a[2][3];
	mf[2][0] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[3][0];
	ry = mf_a[3][1];
	rz = mf_a[3][2];
	rw = mf_a[3][3];
	mf[3][0] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	/* Column 1 */
	cx = mf_b[0][1];
	cy = mf_b[1][1];
	cz = mf_b[2][1];
	cw = mf_b[3][1];

	rx = mf_a[0][0];
	ry = mf_a[0][1];
	rz = mf_a[0][2];
	rw = mf_a[0][3];
	mf[0][1] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[1][0];
	ry = mf_a[1][1];
	rz = mf_a[1][2];
	rw = mf_a[1][3];
	mf[1][1] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[2][0];
	ry = mf_a[2][1];
	rz = mf_a[2][2];
	rw = mf_a[2][3];
	mf[2][1] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[3][0];
	ry = mf_a[3][1];
	rz = mf_a[3][2];
	rw = mf_a[3][3];
	mf[3][1] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	/* Column 2 */
	cx = mf_b[0][2];
	cy = mf_b[1][2];
	cz = mf_b[2][2];
	cw = mf_b[3][2];

	rx = mf_a[0][0];
	ry = mf_a[0][1];
	rz = mf_a[0][2];
	rw = mf_a[0][3];
	mf[0][2] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[1][0];
	ry = mf_a[1][1];
	rz = mf_a[1][2];
	rw = mf_a[1][3];
	mf[1][2] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[2][0];
	ry = mf_a[2][1];
	rz = mf_a[2][2];
	rw = mf_a[2][3];
	mf[2][2] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[3][0];
	ry = mf_a[3][1];
	rz = mf_a[3][2];
	rw = mf_a[3][3];
	mf[3][2] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	/* Column 3 */
	cx = mf_b[0][3];
	cy = mf_b[1][3];
	cz = mf_b[2][3];
	cw = mf_b[3][3];

	rx = mf_a[0][0];
	ry = mf_a[0][1];
	rz = mf_a[0][2];
	rw = mf_a[0][3];
	mf[0][3] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[1][0];
	ry = mf_a[1][1];
	rz = mf_a[1][2];
	rw = mf_a[1][3];
	mf[1][3] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[2][0];
	ry = mf_a[2][1];
	rz = mf_a[2][2];
	rw = mf_a[2][3];
	mf[2][3] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

	rx = mf_a[3][0];
	ry = mf_a[3][1];
	rz = mf_a[3][2];
	rw = mf_a[3][3];
	mf[3][3] = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);
}
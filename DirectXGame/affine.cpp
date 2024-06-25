#include "affine.h"
#include <math.h>

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 ret = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				ret.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
			}
		}
	}
	return ret;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	Vector3 dm = scale;

	Matrix4x4 RotateMatY = {cosf(rot.y), 0, -sinf(rot.y), 0, 0, 1, 0, 0, sinf(rot.y), 0, cosf(rot.y), 0, 0, 0, 0, 1};

	Matrix4x4 TranslateMat = {

	    1, 0, 0, 0,           0,           1,           0, 0, 0,
	    0, 1, 0, translate.x, translate.y, translate.z, 1

	};

	Matrix4x4 ansMat = Multiply(RotateMatY, TranslateMat);
	return ansMat;
}
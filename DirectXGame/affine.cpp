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


Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 result = {};

	result.mat[0][0] = scale.x;
	result.mat[1][1] = scale.y;
	result.mat[2][2] = scale.z;
	result.mat[3][3] = 1.0f;

	return result;
}

Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 result = {};

	result.mat[0][0] = 1.0f;
	result.mat[1][1] = 1.0f;
	result.mat[2][2] = 1.0f;
	result.mat[3][3] = 1.0f;
	result.mat[3][0] = translate.x;
	result.mat[3][1] = translate.y;
	result.mat[3][2] = translate.z;

	return result;
}

Matrix4x4 MakeRotateMatrix(const Vector3& rotate) {

	Matrix4x4 rotateX = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, cosf(rotate.x), sinf(rotate.x), 0.0f, 0.0f, -sinf(rotate.x), cosf(rotate.x), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateY = {cosf(rotate.y), 0.0f, -sinf(rotate.y), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, sinf(rotate.y), 0.0f, cosf(rotate.y), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	Matrix4x4 rotateZ = {cosf(rotate.z), -sinf(rotate.z), 0.0f, 0.0f, -sinf(rotate.z), cosf(rotate.z), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
	return Multiply(Multiply(rotateX, rotateY), rotateZ);
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 ScaleM = MakeScaleMatrix(scale);
	Matrix4x4 RotateM = MakeRotateMatrix(rotate);
	Matrix4x4 TransM = MakeTranslateMatrix(translate);

	return Multiply(Multiply(TransM, RotateM), ScaleM);
}
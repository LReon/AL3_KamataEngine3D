#include "affine.h"

struct Matrix4x4 {
	float mat[4][4];
};

Matrix4x4 MatrixMultiply(Matrix4x4 matrix1, Matrix4x4 matrix2) {
	Matrix4x4 ret = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				ret.mat[i][j] += matrix1.mat[i][k] * matrix2.mat[k][j];
			}
		}
	}
	return ret;
}

Matrix4x4 MakeTranslateMatrix(Vector3 translate) {
	
}



Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {

	

}

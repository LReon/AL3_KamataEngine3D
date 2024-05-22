#pragma once
#include "GameScene.h"

Matrix4x4 MatrixMultiply(Matrix4x4& matrix1, Matrix4x4 matrix2);

Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

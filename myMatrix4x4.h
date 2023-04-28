#pragma once

#include <Vector3.h>
/// <summary>
/// 4x4çsóÒ
/// </summary>
struct Matrix4x4 final {
	float m[4][4];
};

Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

class Matrix4x4Ex {
public:
	static void VectorScreenPrintf(int x, int y, Vector3& vector, const char* label);
	static void MatrixScreenPrintf(int x, int y, Matrix4x4& matrix, const char* label);
};

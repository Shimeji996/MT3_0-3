#include <Matrix4x4.h>
#include <Novice.h>
#include <cmath>
#include <cassert>

// 1. ���s�ړ��s��
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {

	return Matrix4x4{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translate.x,translate.y,translate.z,1
	};

}
// 2. �g��k���s��
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {

	return Matrix4x4{
		scale.x,0,0,0,
		0,scale.y,0,0,
		0,0,scale.z,0,
		0,0,0,1,
	};

}
// 3. ���W�ϊ�

// ���W�ϊ�
Vector3 Transform(const Vector3& v, const Matrix4x4& m) {
	Vector3 result;
	result.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + 1.0f * m.m[3][0];
	result.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + 1.0f * m.m[3][1];
	result.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + 1.0f * m.m[3][2];
	float w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + 1.0f * m.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

/// 3�����x�N�g���̐��l�\��
	/// <summary>
void Matrix4x4Ex::VectorScreenPrintf(int x, int y, Vector3& vector, const char* label) {

	// ���x���̕\��
	Novice::ScreenPrintf(x, y, "%s", label);

	// 3�����x�N�g���̕\��
	Novice::ScreenPrintf(x, y + 20, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + 80, y + 20, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + 160, y + 20, "%6.02f", vector.z);

}

/// 4x4�s��̐��l�\��
void Matrix4x4Ex::MatrixScreenPrintf(int x, int y, Matrix4x4& matrix, const char* label) {

	// ���x���̕\��
	Novice::ScreenPrintf(x, y, "%s", label);

	// �s��̐��l��\��

	// Y���W����
	for (int h = 0; h < 4; h++) {
		// X���W����
		for (int w = 0; w < 4; w++) {

			Novice::ScreenPrintf(x + 80 * w, (y + 20 * h) + 20, "%6.02f", matrix.m[h][w]);

		}
	}

}
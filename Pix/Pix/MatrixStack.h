#pragma once

#include "Vector3.h"
#include "Matrix4.h"
#include <vector>

using namespace std;

class MatrixStack
{
public:
	static MatrixStack* Get();

	void OnNewFrame();

	void PushTranslation(const Vector3& d);
	void PushRotationX(float radians);
	void PushRotationY(float radians);
	void PushRotationZ(float radians);
	void PushScaling(const Vector3& s);
	void PopMatrix();

	const Matrix4& GetTransform() const;

private:
	vector<Matrix4> mMatrices;
	Matrix4 mCombinedTransform;
};
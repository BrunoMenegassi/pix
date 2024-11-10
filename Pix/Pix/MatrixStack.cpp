#include "MatrixStack.h"
#include "MathHelper.h"

MatrixStack* MatrixStack::Get()
{
	static MatrixStack sInstance;
	return &sInstance;
}

void MatrixStack::OnNewFrame()
{
	mCombinedTransform = Matrix4::Identity();
	mMatrices.clear();
}

void MatrixStack::PushTranslation(const Vector3& d)
{
	Matrix4 translationMatrix = Matrix4::Transtation(d);
	mMatrices.push_back(translationMatrix);
	mCombinedTransform = translationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationX(float radians)
{
	Matrix4 rotationMatrix = Matrix4::RotationX(radians);
	mMatrices.push_back(rotationMatrix);
	mCombinedTransform = rotationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationY(float radians)
{
	Matrix4 rotationMatrix = Matrix4::RotationY(radians);
	mMatrices.push_back(rotationMatrix);
	mCombinedTransform = rotationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationZ(float radians)
{
	Matrix4 rotationMatrix = Matrix4::RotationZ(radians);
	mMatrices.push_back(rotationMatrix);
	mCombinedTransform = rotationMatrix * mCombinedTransform;
}

void MatrixStack::PushScaling(const Vector3& s)
{
	Matrix4 scalingMatrix = Matrix4::Scaling(s);
	mMatrices.push_back(scalingMatrix);
	mCombinedTransform = scalingMatrix * mCombinedTransform;
}

void MatrixStack::PopMatrix()
{
	if (!mMatrices.empty())
	{
		Matrix4 matrix = mMatrices.back();
		mMatrices.pop_back();
		mCombinedTransform = MathHelper::Inverse(matrix) * mCombinedTransform;
	}
}

const Matrix4& MatrixStack::GetTransform() const
{
	return mCombinedTransform;
}

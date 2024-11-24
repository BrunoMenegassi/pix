#include "LightTypes.h"
#include "MathHelper.h"
#include "Camera.h"
#include "MaterialManager.h"

X::Color DirectionalLight::ComputeLightColor(const Vector3& pos, const Vector3& norm)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	// get the ambient color Ca
	X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

	// get the diffuse color Cd
	Vector3 dirToLight = -mDirection;
	float dot = MathHelper::Dot(dirToLight, norm);
	X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * X::Math::Max(dot, 0.0f);

	//get the specular color Cs
	Vector3 dirToEye = MathHelper::Normalize(camera->GetPosition() - pos);
	Vector3 half = MathHelper::Normalize(dirToLight + dirToEye);
	float fallOff = pow(MathHelper::Dot(half, norm), mm->GetMaterialShininess());
	X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * X::Math::Max(fallOff, 0.0f);

	return colorAmbient + colorDiffuse + colorSpecular;
}

void DirectionalLight::SetDirection(const Vector3& direction)
{
	mDirection = MathHelper::Normalize(direction);
}

X::Color PointLight::ComputeLightColor(const Vector3& pos, const Vector3& norm)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();
	
	Vector3 dirToLight = mPosition - pos;
	float distance = MathHelper::Magnitude(dirToLight);
	dirToLight = dirToLight / distance;

	float atten = 1.0f / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance * distance));
	float il = X::Math::Clamp(atten, 0.0f, 1.0f);

	// get the ambient color Ca
	X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();

	// get the diffuse color Cd
	float dot = MathHelper::Dot(dirToLight, norm);
	X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * X::Math::Max(dot, 0.0f) * il;

	//get the specular color Cs
	Vector3 dirToEye = MathHelper::Normalize(camera->GetPosition() - pos);
	Vector3 half = MathHelper::Normalize(dirToLight + dirToEye);
	float fallOff = pow(MathHelper::Dot(half, norm), mm->GetMaterialShininess());
	X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * X::Math::Max(fallOff, 0.0f);

	return colorAmbient + colorDiffuse + colorSpecular;
}

void PointLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}

void PointLight::SetAttenuation(float constant, float linear, float quadratic)
{
	mAttenConst = constant;
	mAttenLinear = linear;
	mAttenQuad = quadratic;
}

X::Color SpotLight::ComputeLightColor(const Vector3& pos, const Vector3& norm)
{
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	Vector3 dirToLight = mPosition - pos;
	float distance = MathHelper::Magnitude(dirToLight);
	dirToLight = dirToLight / distance;

	// get the ambient color Ca
	X::Color colorAmbient = mAmbient * mm->GetMaterialAmbient();
	Vector3 lightDirection = -dirToLight;
	float dirDot = MathHelper::Dot(lightDirection, mDirection);
	if (dirDot < mCosAngle)
	{
		return colorAmbient;
	}

	float spot = pow(dirDot, mDecay);
	float atten = spot / (mAttenConst + (mAttenLinear * distance) + (mAttenQuad * distance * distance));
	float il = X::Math::Clamp(atten, 0.0f, 1.0f);

	// get the diffuse color Cd
	float dot = MathHelper::Dot(dirToLight, norm);
	X::Color colorDiffuse = mDiffuse * mm->GetMaterialDiffuse() * X::Math::Max(dot, 0.0f) * il;

	//get the specular color Cs
	Vector3 dirToEye = MathHelper::Normalize(camera->GetPosition() - pos);
	Vector3 half = MathHelper::Normalize(dirToLight + dirToEye);
	float fallOff = pow(MathHelper::Dot(half, norm), mm->GetMaterialShininess());
	X::Color colorSpecular = mSpecular * mm->GetMaterialSpecular() * X::Math::Max(fallOff, 0.0f);

	return colorAmbient + colorDiffuse + colorSpecular;
}

void SpotLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}

void SpotLight::SetDirection(const Vector3& direction)
{
	mDirection = MathHelper::Normalize(direction);
}

void SpotLight::SetAttenuation(float constant, float linear, float quadratic)
{
	mAttenConst = constant;
	mAttenLinear = linear;
	mAttenQuad = quadratic;
}

void SpotLight::SetAngle(float angle)
{
	mCosAngle = cos(angle);
}

void SpotLight::SetDecay(float decay)
{
	mDecay = decay;
}
#include "LightManager.h"
#include "MaterialManager.h"
#include "LightTypes.h"

LightManager* LightManager::Get()
{
	static LightManager sInstance;
	return &sInstance;
}

void LightManager::OnNewFrame()
{
	mLights.clear();
	mAmbient = X::Colors::White;
	mDiffuse = X::Colors::White;
	mSpecular = X::Colors::White;
}

void LightManager::SetLightingAmbient(const X::Color& color)
{
	mAmbient = color;
}

void LightManager::SetLightingDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void LightManager::SetLightingSpecular(const X::Color& color)
{
	mSpecular = color;
}

void LightManager::AddDirectionalLight(const Vector3& direction)
{
	auto light = make_unique<DirectionalLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetDirection(direction);
	mLights.emplace_back(move(light));
}

void LightManager::AddPointLight(const Vector3& position, float constant, float linear, float quadratic)
{
	auto light = make_unique<PointLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetPosition(position);
	light->SetAttenuation(constant, linear, quadratic);
	mLights.emplace_back(move(light));
}

void LightManager::AddSpotLight(const Vector3& position, const Vector3& direction, float constant, float linear, float quadratic, float angle, float decay)
{
	auto light = make_unique<SpotLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetPosition(position);
	light->SetDirection(direction);
	light->SetAttenuation(constant, linear, quadratic);
	light->SetAngle(angle);
	light->SetDecay(decay);
	mLights.emplace_back(move(light));
}

X::Color LightManager::ComputeLightColor(const Vector3& pos, const Vector3& norm) const
{
	X::Color color = MaterialManager::Get()->GetMaterialEmissive();
	for (auto& light : mLights)
	{
		color += light->ComputeLightColor(pos, norm);
	}
	return color;
}

#include "CmdCamera.h"
#include "VariableCache.h"
#include "Camera.h"

using namespace std;

bool CmdSetCameraPosition::Execute(const vector<string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);

	Camera::Get()->SetPosition({ x, y, z });
	return true;
}

bool CmdSetCameraDirection::Execute(const vector<string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);

	Camera::Get()->SetDirection({ x, y, z });
	return true;
}

bool CmdSetCameraNear::Execute(const vector<string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	float value = VariableCache::Get()->GetFloat(params[0]);
	Camera::Get()->SetNearPlane(value);

	return true;
}

bool CmdSetCameraFar::Execute(const vector<string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	float value = VariableCache::Get()->GetFloat(params[0]);
	Camera::Get()->SetFarPlane(value);

	return true;
}
bool CmdSetCameraFov::Execute(const vector<string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	float value = VariableCache::Get()->GetFloat(params[0]);
	Camera::Get()->SetFOV(value * 3.141592 / 100.0f);

	return true;
}
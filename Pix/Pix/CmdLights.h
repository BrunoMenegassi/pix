#pragma once

#include "Command.h"

using namespace std;

class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightAmbient";
	}
	const char* GetDescription() override
	{
		return
			"SetLightAmbient(r, g, b)\n"
			"\n"
			"- sets ambient color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdSetLightDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightDiffuse";
	}
	const char* GetDescription() override
	{
		return
			"SetLightDiffuse(r, g, b)\n"
			"\n"
			"- sets diffuse color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdSetLightSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightSpecular";
	}
	const char* GetDescription() override
	{
		return
			"SetLightSpecular(r, g, b)\n"
			"\n"
			"- sets specular color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdAddDirectionalLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddDirectionalLight";
	}
	const char* GetDescription() override
	{
		return
			"AddDirectionalLight(r, g, b)\n"
			"\n"
			"- adds directional light to the scene";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdAddPointLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddPointLight";
	}
	const char* GetDescription() override
	{
		return
			"AddPointLight(x, y, z, <constant>, <linear>, <quadratic>)\n"
			"\n"
			"- adds point light to the scene";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdAddSpotLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddSpotLight";
	}
	const char* GetDescription() override
	{
		return
			"AddSpotLight(Px, Py, Pz, Dx, Dy, Dz,  <constant>, <linear>, <quadratic>, <angle>, <decay>)\n"
			"\n"
			"- adds point light to the scene";
	}
	bool Execute(const vector<string>& params) override;
};
#pragma once

#include "Command.h"

using namespace std;

class CmdSetMaterialAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialAmbient";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialAmbient(r, g, b)\n"
			"\n"
			"- sets ambient color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdSetMaterialDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialDiffuse";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialDiffuse(r, g, b)\n"
			"\n"
			"- sets diffuse color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdSetMaterialSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialSpecular";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialSpecular(r, g, b)\n"
			"\n"
			"- sets specular color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdSetMaterialEmissive : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialEmissive";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialEmissive(r, g, b)\n"
			"\n"
			"- sets emissive color for light";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdSetMaterialShininess : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialShininess";
	}
	const char* GetDescription() override
	{
		return
			"SetMaterialShininess(r, g, b)\n"
			"\n"
			"- sets shininess color for light";
	}
	bool Execute(const vector<string>& params) override;
};
#pragma once

#include "Command.h"

using namespace std;

class CmdSetCameraPosition : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraPosition";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraPosition(x, y, z)\n"
			"\n"
			"- sets camera position (x, y, z)";
	}

	bool Execute(const vector<string>& params) override;
};

class CmdSetCameraDirection : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraDirection";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraDirection(x, y, z)\n"
			"\n"
			"- sets camera direction (x, y, z)";
	}
	
	bool Execute(const vector<string>& params) override;
};

class CmdSetCameraNear : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraNear";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraNear(x, y, z)\n"
			"\n"
			"- sets camera near (x, y, z)";
	}

	bool Execute(const vector<string>& params) override;
};

class CmdSetCameraFar : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFar";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraFar(x, y, z)\n"
			"\n"
			"- sets camera far (x, y, z)";
	}

	bool Execute(const vector<string>& params) override;
};

class CmdSetCameraFov : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFov";
	}

	const  char* GetDescription() override
	{
		return
			"SetCameraFov(x, y, z)\n"
			"\n"
			"- sets camera fov (x,  y, z)";
	}

	bool Execute(const vector<string>& params) override;
};
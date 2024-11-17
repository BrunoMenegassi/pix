#pragma once

#include "Command.h"

using namespace std;

class CmdSetCullMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetCullMode";
	}

	const char* GetDescription() override
	{
		return
			"SetCullMode(cullmode)\n"
			"\n"
			"- Sets the cull mode of the rendering(<none>, <back>, <front>).\n";
	}

	bool Execute(const vector<string>& params) override;
};
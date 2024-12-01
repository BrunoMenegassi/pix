#pragma once

#include "Command.h"

using namespace std;

class CmdSetShadeMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetShadeMode";
	}

	const char* GetDescription() override
	{
		return
			"SetShadeMode(shadeMode)\n"
			"\n"
			"- Sets the shade mode of the rendering(<none>, <back>, <front>).\n";
	}

	bool Execute(const vector<string>& params) override;
};
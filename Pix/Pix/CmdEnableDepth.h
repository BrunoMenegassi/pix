#pragma once

#include "Command.h"

using namespace std;

class CmdEnableDepth : public Command
{
public:
	const char* GetName() override
	{
		return "EnableDepth";
	}

	const char* GetDescription() override
	{
		return
			"EnableDepth(enable)\n"
			"\n"
			"- Enables/Disables depth buffer rendering.\n";
	}

	bool Execute(const vector<string>& params) override;
};

#pragma once

#include "Command.h"

using namespace std;

class CmdSetClipping : public Command
{
public:
	const char* GetName() override
	{
		return "SetClipping";
	}

	const char* GetDescription() override
	{
		return
			"SetClipping(clip)\n"
			"\n"
			"- Enable/Disable clipping objects whithin the viewport.";
	}

	bool Execute(const vector<string>& params) override;
};
#pragma once

#include "Command.h"

using namespace std;

class CmdBeginDraw : public Command
{
public:
	const char* GetName() override
	{
		return "BeginDraw";
	}

	const char* GetDescription() override
	{
		return
			"BeginDraw(topology)\n"
			"\n"
			"- Begins storing vertices to draw a specified topology";
	}

	bool Execute(const vector<string>& params) override;
};
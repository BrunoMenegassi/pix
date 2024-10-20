#pragma once

#include "Command.h"

using namespace std;

class CmdEndDraw : public Command
{
public:
	const char* GetName() override
	{
		return "EndDraw";
	}

	const char* GetDescription() override
	{
		return
			"EndDraw()\n"
			"\n"
			"- Sumits the vertices to draw the primitive.";
	}

	bool Execute(const vector<string>& params) override;
};
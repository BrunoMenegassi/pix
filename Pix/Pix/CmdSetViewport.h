#pragma once

#include "Command.h"

class CmdSetViewport : public Command
{
public:
	const char* GetName() override
	{
		return "SetViewport";
	}

	const char* GetDescription() override
	{
		return
			"SetViewport(x, y, width, height, <show>)\n"
			"\n"
			"- Sets the size of a viewport to display within.\n"
			"- Optional: Show (true or false) if viewport should be displayed.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

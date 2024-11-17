#pragma once

#include "Command.h"

using namespace std;

class CmdVarInt : public Command
{
public:
	const char* GetName() override
	{
		return "int";
	}

	const char* GetDescription() override
	{
		return
			"Declares a int variable. Can optionally specify a drag speed, min, and max.\n"
			"\n"
			"syntax: int $<name> = <value>, <speed>, <min>, <max>\n"
			"\n"
			"e.g.\n"
			"  int $angle = 3.14\n"
			"  int $color = 0.47, 0.01, 0, 1\n";
	}

	bool Execute(const vector<string>& params) override;
};

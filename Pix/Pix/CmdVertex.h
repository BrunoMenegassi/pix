#pragma once

#include "Command.h"

using namespace std;

class CmdVertex : public Command
{
public: 
	const char* GetName() override
	{
		return "Vertex";
	}

	const char* GetDescription() override
	{
		return
			"Vertex(x, y)\n"
			"Vertex(x, y, z)\n"
			"Vertex(x, y, r, g, b)\n"
			"Vertex(x, y, z, r, g, b)\n"
			"\n"
			"- Adds a vertex to the primitives manager.";
	}

	bool Execute(const vector<string>& params) override;
};
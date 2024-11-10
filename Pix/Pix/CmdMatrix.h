#pragma once

#include "Command.h"

using namespace std;

class CmdPushTranslation : public Command
{
public:
	const char* GetName() override
	{
		return "PushTranslation";
	}

	const char* GetDescription() override
	{
		return
			"PushTranslation(<pos>)\n"
			"\n"
			"- pushes a translation into the matrix stack";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdPushRotationX : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationX";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationX(<pos>)\n"
			"\n"
			"- pushes a rotation in the x axis into the matrix stack";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdPushRotationY : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationY";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationY(<pos>)\n"
			"\n"
			"- pushes a rotation in the y axis into the matrix stack";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdPushRotationZ : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationZ";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationZ(<pos>)\n"
			"\n"
			"- pushes a rotation in the z axis into the matrix stack";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdPushScaling : public Command
{
public:
	const char* GetName() override
	{
		return "PushScaling";
	}

	const char* GetDescription() override
	{
		return
			"PushScaling(<scale>)\n"
			"\n"
			"- pushes a scale matrix into the matrix stack";
	}
	bool Execute(const vector<string>& params) override;
};

class CmdPopMatrix : public Command
{
public:
	const char* GetName() override
	{
		return "PopMatrix";
	}

	const char* GetDescription() override
	{
		return
			"PopMatrix(<pos>)\n"
			"\n"
			"- removes the last matrix from the matrix stack";
	}
	bool Execute(const vector<string>& params) override;
};
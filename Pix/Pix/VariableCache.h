#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

struct Variable;

class VariableCache
{
public:
	static VariableCache* Get();

public:
	void Clear();

	bool IsVarName(const string& name) const;

	void AddFloat(const string& name, float value, float speed = 0.01f, float min = -FLT_MAX, float max = FLT_MAX);
	float GetFloat(const string& param);

	void AddInt(const string& name, int value, int speed = 1, int min = INT32_MIN, int max = INT32_MAX);
	int GetInt(const string& param);

	void AddBool(const string& name, bool value);
	bool GetBool(const string& param);

	void ShowEditor();

private:
	vector<unique_ptr<Variable>> mVariables;
};

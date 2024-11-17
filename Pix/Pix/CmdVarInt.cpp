#include "CmdVarInt.h"

#include "VariableCache.h"

using namespace std;

bool CmdVarInt::Execute(const vector<string>& params)
{
	// Need at leaset 3 params for name, =, value
	if (params.size() < 3)
		return false;

	auto vc = VariableCache::Get();
	if (!vc->IsVarName(params[0]) || params[1] != "=")
		return false;

	const int value = stoi(params[2]);
	const int speed = params.size() > 3 ? stoi(params[3]) : 0.01f;
	const int min = params.size() > 4 ? stoi(params[4]) : -FLT_MAX;
	const int max = params.size() > 5 ? stoi(params[5]) : FLT_MAX;

	// Register variable
	vc->AddInt(params[0], value, speed, min, max);
	return true;
}

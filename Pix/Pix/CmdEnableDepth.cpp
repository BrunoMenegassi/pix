#include "CmdEnableDepth.h"
#include "DepthBuffer.h"
#include "VariableCache.h"

using namespace std;

bool CmdEnableDepth::Execute(const vector<string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	bool enable = VariableCache::Get()->GetBool(params[0]);
	DepthBuffer::Get()->SetEnabled(enable);
	return true;
}
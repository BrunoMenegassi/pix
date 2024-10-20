#include "CmdEndDraw.h"
#include "PrimitivesManager.h"

using namespace std;

bool CmdEndDraw::Execute(const vector<string>& params)
{
	if (params.size() > 0)
	{
		return false;
	}

	PrimitivesManager::Get()->EndDraw();
	return true;
}
#include "CmdBeginDraw.h"
#include "PrimitivesManager.h"

using namespace std;

bool CmdBeginDraw::Execute(const vector<string>& params) 
{
	if (params.size() < 1)
	{
		return false;
	}

	Topology topology = Topology::Point;
	if (params[0] == "point") { topology = Topology::Point; }
	else if (params[0] == "line") { topology = Topology::Line; }
	else if (params[0] == "triangle") { topology = Topology::Triangle; }
	else { return false; }

	bool applyTransform = params.size() > 1 && params[1] == "true";
	PrimitivesManager::Get()->BeginDraw(topology, applyTransform);
	return true;
}
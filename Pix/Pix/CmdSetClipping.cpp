#include "CmdSetClipping.h"
#include "Clipper.h"

using namespace std;

bool CmdSetClipping::Execute(const vector<string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	bool clip = params[0] == "true";
	Clipper::Get()->SetClipping(clip);
	return true;
}
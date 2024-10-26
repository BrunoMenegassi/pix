#pragma once

#include "Vertex.h"

using namespace std;

class Clipper
{
public:
	static Clipper* Get();

	void OnNewFrame();

	bool ClipPoint(const Vertex& v);
	bool ClipLine(Vertex& a, Vertex& b);
	bool ClipTriangle(vector<Vertex>& vertices);

	bool IsClipping() const;
	void SetClipping(bool clip);

private:
	Clipper();

	bool mIsClipping = false;
};
#pragma once

#include "Vertex.h"

using namespace std;

class Model
{
public:
	void Load(const string& fileName);

	const string& GetFileName() const;
	const Vertex& GetVertex(int index) const;
	int GetVertexCount() const;

private:
	string mFileName;
	vector<Vertex> mVertices;
};
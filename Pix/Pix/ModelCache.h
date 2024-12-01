#pragma once

#include "Model.h"

class ModelCache
{
public:
	static ModelCache* Get();

	void Clear();
	const Model* GetModel(const string& fileName);

private:
	vector<unique_ptr<Model>> mModels;
};
#pragma once

#include <memory>

using namespace std;

class DepthBuffer
{
public:
	static DepthBuffer* Get();

	void OnNewFrame();

	void Initialize(int width, int height);

	void SetEnabled(bool enabled);
	bool CheckDepthBuffer(int x, int y, float depth);

private:
	unique_ptr<float[]> mDepthBuffer;
	int mWidth = 0;
	int mHeight = 0;
	bool mEnabled = false;
};
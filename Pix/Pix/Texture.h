#pragma once

#include <XEngine.h>

using namespace std;

enum class AddressMode
{
	Border,
	Clamp,
	Mirror,
	Wrap
};

class Texture // it'll only load 24 bit bmps
{
public:
	void Load(const string& fileName);
	const string& GetFileName() const;
	X::Color GetPixel(float u, float v, AddressMode mode) const;
	X::Color GetPixel(int u, int v) const;

	int GetWidth() const;
	int GetHeight() const;
private:
	string mFileName;
	unique_ptr<X::Color[]> mPixels;
	int mWidth = 0;
	int mHeight = 0;
};
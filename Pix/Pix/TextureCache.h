#pragma once

#include "Texture.h"

class TextureCache
{
public:
	static TextureCache* Get();

	void Clear();
	void SetTexture(const string& fileName);
	void SetAddressMode(AddressMode mode);

	X::Color SampleColor(const X::Color& uv) const;
private:
	vector<unique_ptr<Texture>> mTextures;
	const Texture* mCurrentTexture = nullptr;
	AddressMode mAddressMode = AddressMode::Clamp;
};
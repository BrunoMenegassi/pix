#include "TextureCache.h"

TextureCache* TextureCache::Get()
{
	static TextureCache sInstance;
	return &sInstance;
}

void TextureCache::Clear()
{
	mTextures.clear();
	mCurrentTexture = nullptr;
}

void TextureCache::SetTexture(const string& fileName)
{
	auto iter = find_if(mTextures.begin(), mTextures.end(),
		[fileName](auto& texture)
		{
			return texture->GetFileName() == fileName;
		});
	if (iter != mTextures.end())
	{
		mCurrentTexture = iter->get();
	}
	else
	{
		auto& texture = mTextures.emplace_back(make_unique<Texture>());
		texture->Load(fileName);
		mCurrentTexture = texture.get();
	}
}

void TextureCache::SetAddressMode(AddressMode mode)
{
	mAddressMode = mode;
}

void TextureCache::SetUseFilter(bool useFilter)
{
	mUseFilter = useFilter;
}

X::Color TextureCache::SampleColor(const X::Color& uv) const
{
	X::Color color = uv;
	if (mCurrentTexture != nullptr && uv.z < 0.0f)
	{
		float u = uv.x / uv.w;
		float v = uv.y / uv.w;
		color = mCurrentTexture->GetPixel(u, v, mAddressMode, mUseFilter);
	}
	return color;
}
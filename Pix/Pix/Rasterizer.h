#pragma once

#include "Vertex.h"
#include <XEngine.h>

enum class FillMode
{
	Solid,
	WireFrame
};

class Rasterizer
{
public:
	static Rasterizer* Get();

	void SetFillMode(FillMode fillMode);

	void SetColor(X::Color color);
	void DrawPoint(int x, int y);

	void DrawPoint(const Vertex& v);
	void DrawLine(const Vertex& a, const Vertex& b);
	void DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c);

private:
	void DrawFilledTriangle(const Vertex& a, const Vertex& b, const Vertex& c);

	X::Color mColor = X::Colors::White;
	FillMode mfillMode = FillMode::WireFrame;
};
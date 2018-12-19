#pragma once
#include "Renderer.h"
#include "../dep/inc/mtdl/mtdl.h"

class Button
{
private:
	std::string texture;
	std::string hoverTexture;
	mtdl::Rect rect;
	bool isHover;

public:
	Button();
	Button(std::string t, mtdl::Vector2 pos, mtdl::Color normal, mtdl::Color hovered);
	void Update(mtdl::Vector2 mousePosition);
	bool isPressed(mtdl::Vector2 mousePosition, bool p);
	void Draw();
};


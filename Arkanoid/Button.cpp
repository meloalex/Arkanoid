#include "Button.h"

Button::Button()
{
}

Button::Button(std::string t, mtdl::Vector2 pos, mtdl::Color normal, mtdl::Color hovered)
{
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text(t, normal, t + "_button"));
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text(t, hovered, t + "_button_hover"));
	texture = t + "_button";
	hoverTexture = t +"_button_hover";
	mtdl::Vector2 wh = Renderer::Instance()->GetTextureSize(t + "_button");
	rect = mtdl::Rect(pos, wh);
	isHover = false;
}

void Button::Update(mtdl::Vector2 mousePosition)
{
	if (mtdl::VectorRectCollision(mousePosition, rect)) isHover = true;
	else isHover = false;
}

bool Button::isPressed(mtdl::Vector2 mousePosition, bool p) {
	return mtdl::VectorRectCollision(mousePosition, rect) && p;
}

void Button::Draw()
{
	if (isHover) Renderer::Instance()->PushImage(hoverTexture, rect);
	else Renderer::Instance()->PushImage(texture, rect);
}


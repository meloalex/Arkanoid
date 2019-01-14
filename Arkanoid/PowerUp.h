#pragma once
#include "Renderer.h"
#include "../dep/inc/mtdl/mtdl.h"

#define POWERUP_WIDTH 15
#define POWERUP_HEIGHT 15
#define POWERUP_SPEED 2

class PowerUp
{
private:
	std::string texture;

public:
	mtdl::Rect position;
	mtdl::Vector2 speed;
	enum Type{EXTRALENGHT, MINILENGHT, SPEED};
	Type type;

	PowerUp();
	PowerUp(int v, mtdl::Vector2 p);
	int Update(mtdl::Rect p1, mtdl::Rect p2);
	void Draw();
};


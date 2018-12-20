#pragma once
#include "Renderer.h"
#include "../dep/inc/mtdl/mtdl.h"

#define BALL_WIDTH 15
#define BALL_HEIGHT 15
#define BALL_SPEED_X 2
#define BALL_SPEED_Y 2

class Ball
{

private:
	std::string texture;

public:
	mtdl::Rect position;
	mtdl::Vector2 speed;
	int lastPlayer;

	Ball();
	~Ball();
	int Update(mtdl::Rect f, mtdl::Rect p1, mtdl::Rect p2);
	void WallBounce();
	void PlayerBounce();
	void ResetBall(int pos, int vx, int vy);
	void Draw();
};


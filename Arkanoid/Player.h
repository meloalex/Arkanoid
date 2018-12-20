#pragma once
#include "Renderer.h"
#include "../dep/inc/mtdl/mtdl.h"

#define PLAYER_WIDTH Renderer::Instance()->GetTextureSize("player").y
#define PLAYER_HEIGHT Renderer::Instance()->GetTextureSize("player").x

class Player
{
private:
	std::string texture;
	mtdl::Rect position;

public:
	mtdl::Rect colPosition;
	int lives;
	int points;
	int speed;

	Player();
	Player(int _x);
	~Player();
	void Update(bool _up, bool _down);
	void Draw();
	void AddPoints(int i);
	void ResetPlayer(int _x);
};


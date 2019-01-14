#pragma once
#include "Renderer.h"
#include "Time.h"
#include "../dep/inc/mtdl/mtdl.h"

#define PLAYER_WIDTH Renderer::Instance()->GetTextureSize("player").y
#define PLAYER_HEIGHT Renderer::Instance()->GetTextureSize("player").x
#define PLAYER_SPEED 10



class Player
{
private:
	std::string texture;
	mtdl::Rect position;

public:
	mtdl::Rect colPositionStandar;
	mtdl::Rect colPosition;
	int lives;
	int points;
	int speed;
	enum Boost { NONE, EXTRALENGHT, MINILENGHT, SPEED };
	Boost boost;
	float timer;
	clock_t lastTime;
	float deltaTime;

	Player();
	Player(int _x);
	~Player();
	void Update(bool _up, bool _down);
	void Draw();
	void AddPoints(int i);
	void ResetPlayer(int _x);
};


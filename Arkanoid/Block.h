#pragma once
#include "../dep/inc/mtdl/mtdl.h"
#include "Renderer.h"
#include "Ball.h"
#include "Player.h"
#include <time.h>
#include <iostream>

#define BLOCK_WIDTH Renderer::Instance()->GetTextureSize("bricks").x/5
#define BLOCK_HEIGHT Renderer::Instance()->GetTextureSize("bricks").y/3
enum class BlockType { NONE, NORMAL, HEAVY, FIX };

class Block
{
private:
	BlockType type;
	std::string texture;

	//Time
	float timer;
	clock_t lastTime;
	float deltaTime;
public:
	mtdl::Vector2 gridPosition;
	mtdl::Rect position;
	mtdl::Rect colPosition;
	mtdl::Rect spritePosition;
	bool givesPowerUp;
	int value;
	int broken;

	Block(mtdl::Vector2 pos, BlockType type, int val);
	~Block();

	void Update(Ball &ball, Player &playerOne, Player &plaeyrTwo);
	void Draw();
	void DestroyBlock();
};


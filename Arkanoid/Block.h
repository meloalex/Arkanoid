#pragma once
#include "../dep/inc/mtdl/mtdl.h"

enum class BlockType { NONE, NORMAL, HEAVY, FIX };

class Block
{
private:
	BlockType type;
	std::string texture;
public:
	mtdl::Vector2 position;
	bool givesPowerUp;
	int value;

	Block(mtdl::Vector2 pos, BlockType type, int val);
	~Block();

	void Update();
	void Draw();
};


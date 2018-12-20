#include "Block.h"



Block::Block(mtdl::Vector2 pos, BlockType t, int v)
{
	//Assign settings
	position = pos;
	type = t;
	value = v;

	switch (type)
	{
	case BlockType::NORMAL:
		//texture = 
		break;
	case BlockType::HEAVY:
		//texture = 
		break;
	case BlockType::FIX:
		//texture =
		break;
	}
}


Block::~Block()
{
}

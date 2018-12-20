#include "Block.h"

Block::Block(mtdl::Vector2 pos, BlockType t, int v)
{
	//Assign settings
	gridPosition = pos;
	position = mtdl::Rect(gridPosition.y * BLOCK_HEIGHT + (SCREEN_WIDTH / 2 - BLOCK_HEIGHT * 7) + 12, gridPosition.x * BLOCK_WIDTH + 48 - 11, BLOCK_WIDTH, BLOCK_HEIGHT);
	colPosition = mtdl::RotateRect90(position);
	colPosition.position.x += 12;
	colPosition.position.y -= 11;
	texture = "bricks";
	type = t;
	value = v;

	switch (type)
	{
	case BlockType::NORMAL:
		spritePosition = mtdl::Rect(0, 0, BLOCK_WIDTH, BLOCK_HEIGHT);
		broken = 1;
		break;
	case BlockType::HEAVY:
		spritePosition = mtdl::Rect(0, BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT);
		broken = 3;
		break;
	case BlockType::FIX:
		spritePosition = mtdl::Rect(0, BLOCK_HEIGHT * 2, BLOCK_WIDTH, BLOCK_HEIGHT);
		broken = -1;
		break;
	}
}

Block::~Block()
{
}

void Block::Update(Ball &ball, Player &playerOne, Player &playerTwo)
{
	if (mtdl::RectRectCollision(ball.position, colPosition) && type != BlockType::FIX && broken > 0) {
		broken--;
		ball.PlayerBounce();

		if (broken == 0) {
			DestroyBlock();
			switch (ball.lastPlayer) {
			case 1:
				playerOne.AddPoints(value);
				break;
			case 2:
				playerTwo.AddPoints(value);
				break;
			default:
				break;
			}
		}
	}
}

void Block::Draw()
{
	if(broken != 0) Renderer::Instance()->PushRotatedSprite(texture, spritePosition, position, 90);
}

void Block::DestroyBlock()
{
	spritePosition.position.x += BLOCK_WIDTH;
	spritePosition.position.y += BLOCK_HEIGHT;
}

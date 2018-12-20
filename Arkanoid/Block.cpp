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
		broken = 10;
		break;
	}

	//Time
	timer = 0.2;
	deltaTime = 0;
	lastTime = clock();
}

Block::~Block()
{
}

void Block::Update(Ball &ball, Player &playerOne, Player &playerTwo)
{
	if (mtdl::RectRectCollision(ball.position, colPosition) && broken > 0) {
		ball.PlayerBounce();

		if (type != BlockType::FIX)
		{
			broken--;

			if (broken == 0) {
				//Anim
				deltaTime = (clock() - lastTime);
				lastTime = clock();
				deltaTime /= CLOCKS_PER_SEC;
				timer -= deltaTime;

				if (timer < 0.0)
				{
					timer = 0.2;
					deltaTime = 0;
					lastTime = clock();
					std::cout << "Tiempo\n";
					if (spritePosition.position.x != Renderer::Instance()->GetTextureSize("bricks").x - BLOCK_WIDTH) spritePosition.position.x += BLOCK_WIDTH;
					else DestroyBlock();
				}

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
}

void Block::Draw()
{
	if (type != BlockType::NONE) Renderer::Instance()->PushRotatedSprite(texture, spritePosition, position, 90);
}

void Block::DestroyBlock()
{
	type = BlockType::NONE;
}

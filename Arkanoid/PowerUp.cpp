#include "PowerUp.h"

PowerUp::PowerUp()
{
	texture = "ball";
	position = mtdl::Rect(70, 250, POWERUP_WIDTH, POWERUP_HEIGHT);
	speed = mtdl::Vector2(POWERUP_SPEED, 0);
	int random = rand() % 3;
	type = static_cast<Type>(random);
}

PowerUp::PowerUp(int v, mtdl::Vector2 p)
{
	texture = "ball";
	position = mtdl::Rect(p.x, p.y, POWERUP_WIDTH, POWERUP_HEIGHT);
	speed = mtdl::Vector2(v, 0);
	int random = rand() % 3;
	type = static_cast<Type>(random);
}

int PowerUp::Update(mtdl::Rect p1, mtdl::Rect p2)
{
	position.position.x += speed.x;
	if ((position.position.x > SCREEN_WIDTH + POWERUP_WIDTH) || (position.position.x < 0 - POWERUP_WIDTH))
		return 1;
	if (mtdl::RectRectCollision(position, p1))
		return 2;
	if (mtdl::RectRectCollision(position, p2))
		return 3;
	return 0;
}

void PowerUp::Draw()
{
	Renderer::Instance()->PushImage(texture, position);
}

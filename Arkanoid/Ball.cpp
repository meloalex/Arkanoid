#include "Ball.h"

Ball::Ball()
{
	lastPlayer = 1;
	texture = "ball";
	position = mtdl::Rect(70, 250, BALL_WIDTH, BALL_HEIGHT);
	speed = mtdl::Vector2(BALL_SPEED_X, BALL_SPEED_Y);
}

Ball::~Ball()
{
}

int Ball::Update(mtdl::Rect f, mtdl::Rect p1, mtdl::Rect p2)
{
	int isPoint = 0;
	if (!mtdl::RectRectCollision(position, f)) {
		if (position.position.x < 26) {
			isPoint = 2;
			PlayerBounce();
		}
		else if (position.position.x > 26 + 747) {
			isPoint = 1;
			PlayerBounce();
		}
		WallBounce();
	}
	else {
		if (mtdl::RectRectVerticalCollision(position, p1)) {
			lastPlayer = 1;
			PlayerBounce();
		} 
		else if (mtdl::RectRectHorizontalCollision(position, p1)) {
			lastPlayer = 1;
			WallBounce();
		}
		else if (mtdl::RectRectVerticalCollision(position, p2)) {
			lastPlayer = 2;
			PlayerBounce();
		}
		else if (mtdl::RectRectHorizontalCollision(position, p2)) {
			lastPlayer = 2;
			WallBounce();
		}
	}

	position.position.x += speed.x;
	position.position.y += speed.y;
	return isPoint;
}

void Ball::WallBounce() {
	speed.y *= -1;
}

void Ball::PlayerBounce()
{
	speed.x *= -1;
}

void Ball::ResetBall(int pos, int vx, int vy)
{
	position.position.x = pos;
	position.position.y = 250;
	
}

void Ball::Draw()
{
	Renderer::Instance()->PushImage(texture, position);
}

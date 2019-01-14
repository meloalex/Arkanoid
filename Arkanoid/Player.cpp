#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::Player(int _x)
{
	points = 0;
	lives = 3;
	texture = "player";
	position = mtdl::Rect(_x, (355 / 2 + 37) + PLAYER_HEIGHT / 2, PLAYER_HEIGHT, PLAYER_WIDTH);
	colPosition = mtdl::RotateRect90(position);
	colPosition.position.x += 20;
	colPosition.position.y -= 20;
	colPositionStandar = colPosition;
	speed = PLAYER_SPEED;
	boost = Boost::NONE;
}


Player::~Player()
{
}

void Player::Update(bool _up, bool _down)
{
	switch (boost) {
	case Boost::NONE:
		position = mtdl::Rect(position.position.x, position.position.y, PLAYER_HEIGHT, PLAYER_WIDTH);
		colPosition.h = colPositionStandar.h;
		speed = PLAYER_SPEED;
		break;
	case Boost::EXTRALENGHT:
		position = mtdl::Rect(position.position.x, position.position.y, PLAYER_HEIGHT*2, PLAYER_WIDTH);
		colPosition.h = colPositionStandar.h*2;
		speed = PLAYER_SPEED;
		deltaTime = (clock() - lastTime);
		lastTime = clock();
		deltaTime /= CLOCKS_PER_SEC;
		std::cout << timer << std::endl;
		timer -= deltaTime;
		if (timer < 0.0)
		{
			boost = Boost::NONE;
		}
		break;
	case Boost::MINILENGHT:
		position = mtdl::Rect(position.position.x, position.position.y, PLAYER_HEIGHT/2, PLAYER_WIDTH);
		colPosition.h = colPositionStandar.h/2;
		speed = PLAYER_SPEED;
		break;
	case Boost::SPEED:
		position = mtdl::Rect(position.position.x, position.position.y, PLAYER_HEIGHT, PLAYER_WIDTH);
		colPosition.h = colPositionStandar.h;
		speed = PLAYER_SPEED * 2;
		break;
	default:
		break;
	}

	if (_up && !_down) {
		if (position.position.y >= 48) {
			position.position.y -= speed;
			colPosition.position.y -= speed;
		};
	}
	else if (!_up && _down) {
		if (position.position.y <= 420) {
			position.position.y += speed;
			colPosition.position.y += speed;
		}
	}
}

void Player::Draw()
{
	Renderer::Instance()->PushRotatedSprite(texture, mtdl::Rect(0, 0, PLAYER_HEIGHT, PLAYER_WIDTH), position, 90);
}

void Player::ResetPlayer(int _x)
{
	position = mtdl::Rect(_x, (355 / 2 + 37) + PLAYER_HEIGHT / 2, PLAYER_HEIGHT, PLAYER_WIDTH);
	colPosition = mtdl::RotateRect90(position);
	colPosition.position.x += 20;
	colPosition.position.y -= 20;
}

void Player::AddPoints(int i)
{
	points += i;
}

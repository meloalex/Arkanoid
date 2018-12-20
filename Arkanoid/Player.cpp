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
	speed = 10;
}


Player::~Player()
{
}

void Player::Update(bool _up, bool _down)
{
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

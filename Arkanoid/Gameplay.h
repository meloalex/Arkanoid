#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Ball.h"
#include "Player.h"

#include <iostream>

class Gameplay :
	public Scene
{
public:
	std::string backgroundTexture;
	Ball ball;
	Player playerOne;
	Player playerTwo;

	Gameplay();
	~Gameplay();

	void Update(InputManager inputManager);
	void Draw();
};


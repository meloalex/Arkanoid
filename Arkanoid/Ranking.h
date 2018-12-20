#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"

class Ranking :
	public Scene
{
public:
	std::string backgroundTexture;
	Button* returnButton;

	Ranking();
	~Ranking();

	void Update(InputManager inputManager);
	void Draw();
};


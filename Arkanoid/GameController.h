#pragma once
#include "InputManager.h"
#include "Scene.h"

class GameController
{
private:
	enum class GameState { EXIT, SPLASH_SCREEN, MENU, GAMEPLAY, RANKING };
	GameState gameState;
	Scene* currentScene;
	InputManager inputManager;

public:
	bool isRunning;

	GameController();
	~GameController();
	void Update();
};


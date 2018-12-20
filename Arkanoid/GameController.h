#pragma once
#include "InputManager.h"
#include "Scene.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Ranking.h"

enum class GameState { EXIT, SPLASH_SCREEN, MENU, GAMEPLAY, RANKING };

class GameController
{
private:
	
	GameState gameState;
	Scene* currentScene;
	InputManager inputManager;

public:
	bool isRunning;

	GameController();
	~GameController();
	void Update();
};


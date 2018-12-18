#pragma once
#include "Scene.h"

class GameController
{
public:
	enum class GameState{EXIT, SPLASH_SCREEN, MENU, GAMEPLAY, RANKING};
	bool isRunning;
	GameState gameState;
	Scene* currentScene;

	GameController();
	~GameController();
	void Update();
};


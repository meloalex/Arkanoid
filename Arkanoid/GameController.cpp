#include "GameController.h"
#include "SplashScreen.h"

GameController::GameController()
{
	isRunning = true;
	gameState = GameState::SPLASH_SCREEN;
}

GameController::~GameController()
{
}

void GameController::Update() {
	switch (gameState) {
	case GameState::EXIT:
		isRunning = false;
		break;
	case GameState::SPLASH_SCREEN:
		currentScene = new SplashScreen(); 
		break;
	case GameState::MENU:
		//goto splash screen;
		break;
	case GameState::GAMEPLAY:
		//goto splash screen;
		break;
	case GameState::RANKING:
		//goto splash screen;
		break;
	}
}
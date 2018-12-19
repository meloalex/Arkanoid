#include "GameController.h"
#include "SplashScreen.h"
#include "Menu.h"

GameController::GameController()
{
	isRunning = true;
	gameState = GameState::SPLASH_SCREEN;
	currentScene = new SplashScreen();
}

GameController::~GameController()
{
	delete(currentScene);
}

void GameController::Update() {
	if (inputManager.input.quit) gameState = GameState::EXIT;

	switch (gameState) {
	case GameState::SPLASH_SCREEN:
		if (currentScene->sceneFinished)
		{
			gameState = GameState::MENU;
			delete(currentScene);
			currentScene = new Menu();
		}
		break;
	case GameState::EXIT:
		isRunning = false;
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

	inputManager.Update();
	currentScene->Update(inputManager);
	currentScene->Draw();
}
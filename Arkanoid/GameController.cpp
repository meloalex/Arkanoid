#include "GameController.h"

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
			if (currentScene->GetStatus().finished)
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
			if (currentScene->GetStatus().finished)
			{
				switch (currentScene->GetStatus().status)
				{
				case 0: //Play button pressed
					gameState = GameState::GAMEPLAY;
					delete(currentScene);
					currentScene = new Gameplay();
					break;

				case 1: //Ranking button pressed
					gameState = GameState::RANKING;
					delete(currentScene);
					currentScene = new Ranking();
					break;

				case 2: //Exit button pressed
					gameState = GameState::EXIT;
					break;
				}
			}
			break;

		case GameState::GAMEPLAY:
			if (currentScene->GetStatus().finished)
			{
				switch (currentScene->GetStatus().status)
				{
				case 0: //Play button pressed
					gameState = GameState::MENU;
					delete(currentScene);
					currentScene = new Menu();
					break;

				case 1: //Ranking button pressed
					gameState = GameState::RANKING;
					delete(currentScene);
					currentScene = new Ranking();
					break;

				case 2: //Exit button pressed
					gameState = GameState::EXIT;
					break;
				}
			}
			break;

		case GameState::RANKING:
			//goto splash screen;
			break;
	}

	inputManager.Update();
	currentScene->Update(inputManager);
	currentScene->Draw();
}
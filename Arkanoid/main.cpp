#include<iostream>
#include "GameController.h"
#include "Renderer.h"

int main(int, char*[]) {
	GameController gameController;
	
	while (gameController.isRunning) {
		gameController.Update();
	}

	return 0;
}
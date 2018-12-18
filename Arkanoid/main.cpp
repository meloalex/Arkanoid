#include<iostream>
#include "GameController.h"

int main() {
	GameController gameController;

	while (gameController.isRunning) {
		gameController.Update();
	}

	return 0;
}
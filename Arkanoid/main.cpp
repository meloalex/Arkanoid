#include "GameController.h"

int main(int, char*[]) {
	GameController gameController;
	
	while (gameController.isRunning) {
		gameController.Update();
	}

	return 0;
}
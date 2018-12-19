#pragma once
#include <SDL.h>
#include "../dep/inc/mtdl/mtdl.h"

class InputManager
{
public:
	struct Inputs {
		mtdl::Vector2 mousePosition;
		bool mousePressed;
		bool escPressed;
		bool spacePressed;
		bool pPressed;
		bool wPressed;
		bool sPressed;
		bool upPressed;
		bool downPressed;
		bool quit;

		Inputs() {
			mousePosition.x = 0;
			mousePosition.y = 0;
			mousePressed = false;
			escPressed = false;
			spacePressed = false;
			wPressed = false;
			sPressed = false;
			upPressed = false;
			downPressed = false;
			quit = false;
		}
	};
	Inputs input;
	SDL_Event event;

	InputManager();
	void Update();
};


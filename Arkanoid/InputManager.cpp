#include "InputManager.h"

InputManager::InputManager()
{
}

void InputManager::Update()
{
	while (SDL_PollEvent(&event)) {
		input.mousePressed = false;
		switch (event.type) {
		case SDL_QUIT:
			input.quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			input.mousePressed = true;
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_ESCAPE) input.escPressed = true;
			if(event.key.keysym.sym == SDLK_SPACE) input.spacePressed = true;
			if(event.key.keysym.sym == SDLK_p) input.pPressed = true;
			if(event.key.keysym.sym == SDLK_w) input.wPressed = true;
			if(event.key.keysym.sym == SDLK_s) input.sPressed = true;
			if(event.key.keysym.sym == SDLK_UP) input.upPressed = true;
			if(event.key.keysym.sym == SDLK_DOWN) input.downPressed = true;
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE) input.escPressed = false;
			if (event.key.keysym.sym == SDLK_SPACE) input.spacePressed = false;
			if (event.key.keysym.sym == SDLK_p) input.pPressed = false;
			if (event.key.keysym.sym == SDLK_w) input.wPressed = false;
			if (event.key.keysym.sym == SDLK_s) input.sPressed = false;
			if (event.key.keysym.sym == SDLK_UP) input.upPressed = false;
			if (event.key.keysym.sym == SDLK_DOWN) input.downPressed = false;
			break;
		case SDL_MOUSEMOTION:
			input.mousePosition.x = event.motion.x;
			input.mousePosition.y = event.motion.y;
			break;
		default:
			break;
		}
	}
}

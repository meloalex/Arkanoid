#include "InputManager.h"

InputManager::InputManager()
{
}

void InputManager::Update()
{
	input.escPressed = false;
	input.spacePressed = false;
	input.pPressed = false;
	input.wPressed = false;
	input.sPressed = false;
	input.upPressed = false;
	input.downPressed = false;
	input.mousePressed = false;
	while (SDL_PollEvent(&event)) {
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
		case SDL_MOUSEMOTION:
			input.mousePosition.x = event.motion.x;
			input.mousePosition.y = event.motion.y;
			break;
		default:
			break;
		}
	}
}

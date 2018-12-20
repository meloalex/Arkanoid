#pragma once
#include <iostream>
#include "Scene.h"
#include <time.h>
#include "Renderer.h"
#include "../dep/inc/mtdl/mtdl.h"

class SplashScreen :
	public Scene
{
private:
	float timer;
	clock_t lastTime;
	float deltaTime;

public:
	SplashScreen();
	~SplashScreen();
	void Update(InputManager inputManager);
	void Draw();
};


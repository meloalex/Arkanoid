#pragma once
#include "Scene.h"

class SplashScreen :
	public Scene
{
private:
	int timer;
public:
	bool timeGone;

	SplashScreen();
	~SplashScreen();
};


#pragma once
#include "Scene.h"
class Ranking :
	public Scene
{
public:
	Ranking();
	~Ranking();

	void Update(InputManager inputManager);
	void Draw();
};


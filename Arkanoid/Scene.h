#pragma once
#include "InputManager.h"
#include "../dep/inc/mtdl/mtdl.h"

class Scene
{
public:
	bool sceneFinished = false;
	Scene();
	~Scene();
	virtual void Update(InputManager inputManager) = 0;
	virtual void Draw() = 0;
};


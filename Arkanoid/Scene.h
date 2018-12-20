#pragma once
#include "InputManager.h"
#include "../dep/inc/mtdl/mtdl.h"

struct SceneStatus
{
	bool finished = false;
	int status;
};

class Scene
{
protected:
	SceneStatus status;
public:
	
	Scene();
	~Scene();
	virtual void Update(InputManager inputManager) = 0;
	virtual void Draw() = 0;

	SceneStatus GetStatus();
};


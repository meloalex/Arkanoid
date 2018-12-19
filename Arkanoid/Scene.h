#pragma once
#include "../dep/inc/mtdl/mtdl.h"

class Scene
{
	std::string backgroundTexture;

public:
	bool sceneFinished = false;
	Scene();
	~Scene();
	virtual void Update() = 0;
	virtual void Draw() = 0;
};


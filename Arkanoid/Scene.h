#pragma once
#include "../dep/inc/mtdl/mtdl.h"

class Scene
{
	std::string backgroundTexture;
	mtdl::Rect backgroundRect;

public:
	Scene();
	~Scene();
	virtual void Update() = 0;
	virtual void Draw() = 0;
};


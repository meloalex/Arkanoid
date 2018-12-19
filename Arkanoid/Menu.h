#pragma once
#include "Scene.h"
#include <iostream>

class Menu :
	public Scene
{
public:
	Menu();
	~Menu();
	void Update();
	void Draw();
};


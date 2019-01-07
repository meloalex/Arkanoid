#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Button.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

class Ranking :
	public Scene
{
private:
	std::vector<mtdl::PlayerRanking> ranking;
public:
	Button* returnButton;

	Ranking();
	~Ranking();

	void Update(InputManager inputManager);
	void Draw();
	void LoadRanking();
	void Fill();
};


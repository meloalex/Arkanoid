#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Ball.h"
#include "Player.h"
#include "Block.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#include "../dep/inc/xml/rapidxml.hpp"
#include "../dep/inc/xml/rapidxml_iterators.hpp"
#include "../dep/inc/xml/rapidxml_print.hpp"
#include "../dep/inc/xml/rapidxml_utils.hpp"

enum class GameplayState { START_GAME, RUNNING, PAUSED, GAME_OVER };

struct BlockConfig
{
	int normalMin, normalMax;
	int heavyMin, heavyMax;
};

class Gameplay :
	public Scene
{
private:
	GameplayState gameplayState;
	BlockConfig blockConfig;
	std::vector<Block> blocks;
public:
	std::string backgroundTexture;
	Ball ball;
	Player playerOne;
	Player playerTwo;

	Gameplay();
	~Gameplay();

	void Update(InputManager inputManager);
	void Draw();
};


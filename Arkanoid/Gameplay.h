#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Ball.h"
#include "Button.h"
#include "Player.h"
#include "Block.h"
#include "../dep/inc/mtdl/mtdl.h"

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
	mtdl::Rect field;
	mtdl::Rect playerOneLives[3];
	mtdl::Rect playerTwoLives[3];
	mtdl::Rect startGameTextRect;
	mtdl::Rect pressSpaceTextRect;
	mtdl::Rect pauseTextRect;
	mtdl::Rect pl1TextRect;
	mtdl::Rect pl1PointsTextRect;
	mtdl::Rect pl2TextRect;
	mtdl::Rect pl2PointsTextRect;

	Button* soundOffButton;
	Button* soundOnButton;
	Button* toggleSoundButton;
	bool sound;

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


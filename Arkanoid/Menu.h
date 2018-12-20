#pragma once
#include "Scene.h"
#include "Button.h"
#include <iostream>

class Menu :
	public Scene
{
private:
	std::string backgroundTexture;

	Button* playButton;
	Button* rankingButton;
	Button* soundOffButton;
	Button* soundOnButton;
	Button* toggleSoundButton;
	Button* exitButton;

	bool sound;

public:
	Menu();
	~Menu();
	void Update(InputManager inputManager);
	void Draw();
};


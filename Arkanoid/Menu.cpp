#include "Menu.h"
#include "Renderer.h"

Menu::Menu()
{
	//Buttons
	playButton = new Button("Play", mtdl::Vector2(80, 50), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");
	rankingButton = new Button("Ranking", mtdl::Vector2(80, 100), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");
	soundOffButton = new Button("Sound Off", mtdl::Vector2(80, 150), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");
	soundOnButton = new Button("Sound On", mtdl::Vector2(80, 150), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");
	toggleSoundButton = soundOffButton;
	exitButton = new Button("Exit", mtdl::Vector2(80, 200), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");

	status.finished = false;
	sound = true;
	backgroundTexture = "background_menu";
}

Menu::~Menu()
{
	delete(playButton);
	delete(rankingButton);
	delete(soundOffButton);
	delete(soundOnButton);
	delete(exitButton);
}

void Menu::Update(InputManager inputManager) {

	//Update buttons
	playButton->Update(inputManager.input.mousePosition);
	rankingButton->Update(inputManager.input.mousePosition);
	toggleSoundButton->Update(inputManager.input.mousePosition);
	exitButton->Update(inputManager.input.mousePosition);

	#pragma region Buttons
	//Sound On/Off
	if (sound && toggleSoundButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed)) {
		sound = !sound;
		toggleSoundButton = soundOnButton;
	}
	else if (toggleSoundButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed)) {
		sound = !sound;
		toggleSoundButton = soundOffButton;
	}

	//Play button
	if (playButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed))
	{
		status.status = 0;
		status.finished = true;
	}

	//Ranking button
	if (rankingButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed))
	{
		status.status = 1;
		status.finished = true;
	}

	//Exit button
	if (exitButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed))
	{
		status.status = 2;
		status.finished = true;
	}
	#pragma endregion
}

void Menu::Draw() {
	Renderer::Instance()->Clear();

	//Push background texture
	Renderer::Instance()->PushImage(backgroundTexture, mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	//Draw each button
	playButton->Draw();
	rankingButton->Draw();
	toggleSoundButton->Draw();
	exitButton->Draw();

	Renderer::Instance()->Render();
}

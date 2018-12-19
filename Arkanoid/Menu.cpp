#include "Menu.h"
#include "Renderer.h"

Menu::Menu()
{
	sound = true;
	playButton = new Button("Play", mtdl::Vector2(10, 0), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255));
	rankingButton = new Button("Ranking", mtdl::Vector2(10, 50), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255));
	soundOffButton = new Button("Sound Off", mtdl::Vector2(10, 100), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255));
	soundOnButton = new Button("Sound On", mtdl::Vector2(10, 100), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255));
	toggleSoundButton = soundOffButton;
	exitButton = new Button("Exit", mtdl::Vector2(10, 150), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255));
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
	playButton->Update(inputManager.input.mousePosition);
	rankingButton->Update(inputManager.input.mousePosition);
	if (sound) { 
		if (toggleSoundButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed)) {
			sound = !sound;
			toggleSoundButton = soundOnButton;
		}
	}
	else {
		if (toggleSoundButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed)) {
			sound = !sound;
			toggleSoundButton = soundOffButton;
		}
	}
	toggleSoundButton->Update(inputManager.input.mousePosition);
	exitButton->Update(inputManager.input.mousePosition);
}

void Menu::Draw() {
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(backgroundTexture, mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	playButton->Draw();
	rankingButton->Draw();
	toggleSoundButton->Draw();
	exitButton->Draw();
	Renderer::Instance()->Render();
}

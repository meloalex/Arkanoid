#include "Gameplay.h"



Gameplay::Gameplay()
{
	std::cout << "Gameplay\n";
	backgroundTexture = "background_menu";
}


Gameplay::~Gameplay()
{
}

void Gameplay::Update(InputManager inputManager) {

}

void Gameplay::Draw() {
	Renderer::Instance()->Clear();

	//Push background texture
	Renderer::Instance()->PushImage(backgroundTexture, mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	Renderer::Instance()->Render();
}
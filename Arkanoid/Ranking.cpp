#include "Ranking.h"



Ranking::Ranking()
{
	backgroundTexture = "background_menu";
	returnButton = new Button("Back", mtdl::Vector2(600, 400), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");
}


Ranking::~Ranking()
{
	delete(returnButton);
}

void Ranking::Update(InputManager inputManager) {
	returnButton->Update(inputManager.input.mousePosition);

	//Buttons
	if (returnButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed))
	{
		status.status = 0;
		status.finished = true;
	}
}

void Ranking::Draw() {
	Renderer::Instance()->Clear();

	//Push background texture
	Renderer::Instance()->PushImage(backgroundTexture, mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	returnButton->Draw();

	Renderer::Instance()->Render();
}

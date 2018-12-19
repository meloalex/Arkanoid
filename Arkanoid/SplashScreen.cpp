#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	backgroundTexture = "background_splashscreen";
	timer = 3;
	deltaTime = 0;
	lastTime = clock();
	std::cout << "SplashScreen\n";
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update(InputManager inputManager) {
	deltaTime = (clock() - lastTime);
	lastTime = clock();
	deltaTime /= CLOCKS_PER_SEC;
	std::cout << timer << std::endl;
	timer -= deltaTime;

	if (timer < 0.0)
	{
		sceneFinished = true;
	}
}

void SplashScreen::Draw() {
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(backgroundTexture, mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	Renderer::Instance()->Render();
}

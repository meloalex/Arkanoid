#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	timer = 3;
	deltaTime = 0;
	lastTime = clock();
	std::cout << "SplashScreen\n";
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update() {
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
	Renderer::Instance()->PushImage("background_splashscreen", mtdl::Rect(0, 0, 800, 800));
	Renderer::Instance()->Render();
}

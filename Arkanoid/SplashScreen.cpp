#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	timeGone = false;
	timer = 3;
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::Update() {
	if (timer <= 0) timeGone = true;
}

void SplashScreen::Draw() {

}

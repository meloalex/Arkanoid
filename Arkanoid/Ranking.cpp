#include "Ranking.h"

Ranking::Ranking()
{
	backgroundTexture = "background_menu";
	returnButton = new Button("Back", mtdl::Vector2(600, 400), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");
	LoadRanking();
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

void Ranking::LoadRanking() {
	try
	{
		//Open file
		std::ifstream rankingFile("../res/files/ranking.bin", std::ios::in | std::ios::binary);

		//Read
		for (int i = 0; i < 10; i++)
		{
			mtdl::PlayerRanking* p = new mtdl::PlayerRanking();

			//Read Name
			size_t len;
			rankingFile.read(reinterpret_cast<char*>(&len), sizeof(size_t)); //read string size
			char* tmp = new char[len + 1]; //create char array of string size
			rankingFile.read(tmp, len); //read string
			tmp[len] = '\0'; //add end in last pos
			p->name = tmp; //save info into player
			delete[]tmp; //free memory

			//Read score
			rankingFile.read(reinterpret_cast<char*>(&p->score), sizeof(p->score));

			//Add player to vector
			ranking.push_back(*p);

			delete(p);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Ranking::Fill() {
	//Open file
	std::ofstream fexit("../res/files/ranking.bin", std::ios::out | std::ios::binary);

	char s[10] = "AlexMario";
	int stringSize = 10, score = 0;

	for (int i = 0; i < 10; i++)
	{
		fexit.write(reinterpret_cast<char*>(&stringSize), sizeof(stringSize));
		fexit.write(s, sizeof(s));
		fexit.write(reinterpret_cast<char*>(&score), sizeof(score));
	}

	fexit.close();
}
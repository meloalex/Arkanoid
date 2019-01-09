#include "Ranking.h"

Ranking::Ranking()
{
	backgroundTexture = "background_menu";
	returnButton = new Button("Back", mtdl::Vector2(600, 400), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "38");

	LoadRanking();
	DrawRanking();
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

	// i = id, j = rect
	for (int i = 0, j = 0; i < 10; i++, j +=3)
	{
		Renderer::Instance()->PushImage("num" + std::to_string(i), *rects[j]);
		Renderer::Instance()->PushImage("player_name" + static_cast<char>(i), *rects[j + 1]);
		Renderer::Instance()->PushImage("player_score" + static_cast<char>(i), *rects[j + 2]);
	}

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

void Ranking::DrawRanking() {
	mtdl::Rect* r;
	int x = 100, y = 50;
	int numOffset = 20, scoreOffset = 50;

	for (int i = 0; i < 10; i++)
	{
		
		//Number
		Renderer::Instance()->LoadTextureText("sunspire38", mtdl::Text(std::to_string(i + 1), mtdl::Color(255, 255, 255, 255), "num" + std::to_string(i)));
		r = new mtdl::Rect(x - Renderer::Instance()->GetTextureSize("num" + std::to_string(i)).x - numOffset, y, Renderer::Instance()->GetTextureSize("num" + std::to_string(i)));
		rects.push_back(r);
		
		//Name
		Renderer::Instance()->LoadTextureText("sunspire38", mtdl::Text(ranking[i].name, mtdl::Color(255, 255, 255, 255), "player_name" + static_cast<char>(i)));
		r = new mtdl::Rect(x, y, Renderer::Instance()->GetTextureSize("player_name" + static_cast<char>(i)));
		rects.push_back(r);

		//Score
		Renderer::Instance()->LoadTextureText("sunspire38", mtdl::Text(std::to_string(ranking[i].score), mtdl::Color(255, 255, 255, 255), "player_score" + static_cast<char>(i)));
		r = new mtdl::Rect(x + Renderer::Instance()->GetTextureSize("player_score" + static_cast<char>(i)).x + scoreOffset, y, Renderer::Instance()->GetTextureSize("player_score" + static_cast<char>(i)));
		rects.push_back(r);
		
		y += Renderer::Instance()->GetTextureSize("player_name" + static_cast<char>(i)).y;
	}
}
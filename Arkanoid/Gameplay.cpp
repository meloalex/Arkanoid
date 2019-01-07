#include "Gameplay.h"

Gameplay::Gameplay()
{
	std::cout << "Gameplay\n";
	status.finished = false;
	gameplayState = GameplayState::START_GAME; 

	//Load background
	backgroundTexture = "background_menu";

	//Text Load
	Renderer::Instance()->LoadTextureText("sunspire38", mtdl::Text("START GAME", mtdl::Color(255, 255, 255, 255), "start_game"));
	startGameTextRect = mtdl::Rect(SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize("start_game").x / 2, 200, Renderer::Instance()->GetTextureSize("start_game"));
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text("PRESS SPACE BAR", mtdl::Color(255, 255, 255, 255), "press_space"));
	pressSpaceTextRect = mtdl::Rect(SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize("press_space").x / 2, 250, Renderer::Instance()->GetTextureSize("press_space"));
	Renderer::Instance()->LoadTextureText("sunspire38", mtdl::Text("PAUSE", mtdl::Color(255, 255, 255, 255), "pause"));
	pauseTextRect = mtdl::Rect(SCREEN_WIDTH / 2 - Renderer::Instance()->GetTextureSize("pause").x / 2, 200, Renderer::Instance()->GetTextureSize("pause"));
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text("PL1:", mtdl::Color(255, 0, 0, 255), "pl1"));
	pl1TextRect = mtdl::Rect(95, 510, Renderer::Instance()->GetTextureSize("pl1"));
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text("PL2:", mtdl::Color(255, 0, 0, 255), "pl2"));
	pl2TextRect = mtdl::Rect(475, 510, Renderer::Instance()->GetTextureSize("pl2"));

	//Sound
	soundOffButton = new Button("Sound Off", mtdl::Vector2(80, 400), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "24");
	soundOnButton = new Button("Sound On", mtdl::Vector2(80, 400), mtdl::Color(255, 255, 255, 255), mtdl::Color(255, 0, 0, 255), "24");
	toggleSoundButton = soundOffButton;
	sound = true;

	//Instantiate elements
	field = mtdl::Rect(26 + BALL_WIDTH, 26 + BALL_HEIGHT, 747 - BALL_WIDTH * 2, 444 - BALL_HEIGHT * 2);
	ball = Ball();
	playerOne = Player(20);
	for (int i = 0; i < playerOne.lives; i++) {
		playerOneLives[i].position.x = 95 + i * 80;
		playerOneLives[i].position.y = 550;
		playerOneLives[i].h = PLAYER_WIDTH;
		playerOneLives[i].w = PLAYER_HEIGHT;
	}
	playerTwo = Player(SCREEN_WIDTH - 80);
	for (int i = 0; i < playerTwo.lives; i++) {
		playerTwoLives[i].position.x = 475 + i * 80;
		playerTwoLives[i].position.y = 550;
		playerTwoLives[i].h = PLAYER_WIDTH;
		playerTwoLives[i].w = PLAYER_HEIGHT;
	}

	//read xml
	try {
		rapidxml::xml_document<> doc;
		std::ifstream file("../res/files/config.xml");
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());
		doc.parse<0>(&content[0]);

		rapidxml::xml_node<> *pRoot = doc.first_node();

		//Get general information
		rapidxml::xml_node<> *pBrickInfo = pRoot->first_node("BrickInfo");

		//Read and store min/max values for Normal and Heavy blocks
		for (rapidxml::xml_node<> *pNode = pBrickInfo->first_node(); pNode; pNode = pNode->next_sibling()) {
			std::string node = pNode->name();
			rapidxml::xml_attribute<> *pAttr = pNode->first_attribute();

			if (node.compare("Normal") == 0) {
				//Normal
				blockConfig.normalMin = std::stoi(pAttr->value()); //Reads normal min value
				pAttr = pAttr->next_attribute(); //Changes to next attribute
				blockConfig.normalMax = std::stoi(pAttr->value()); //Reads normal max value
			}
			else if (node.compare("Heavy") == 0) {
				//Heavy
				blockConfig.heavyMin = std::stoi(pAttr->value()); //Reads heavy min value
				pAttr = pAttr->next_attribute(); //Changes to next attribute
				blockConfig.heavyMax = std::stoi(pAttr->value()); //Reads heavy max value
			}
		}

		//generate blocks	
		for (rapidxml::xml_node<> *pNode = pRoot->first_node("Level")->first_node(); pNode; pNode = pNode->next_sibling()) {

			for (rapidxml::xml_attribute<> *pAttr = pNode->first_attribute(); pAttr; pAttr = pAttr->next_attribute()) {
				//Get name for comparison
				std::string attr = pAttr->name();

				//Vars to store info
				mtdl::Vector2 pos;
				BlockType type = BlockType::NONE;
				int val = 0;

				if (attr.compare("i") == 0)
				{
					pos.x = std::stoi(pAttr->value());
				}
				else if (attr.compare("j") == 0)
				{
					pos.y = std::stoi(pAttr->value());
				}
				else
				{
					std::string typeName = pAttr->value();

					if (typeName.compare("N") == 0)
					{
						type = BlockType::NORMAL;
					}
					else if (typeName.compare("H") == 0)
					{
						type = BlockType::HEAVY;
					}
					else if (typeName.compare("F") == 0)
					{
						type = BlockType::FIX;
					}

					/* initialize random seed: */
					srand(time(NULL));

					//Generate random value
					if (type == BlockType::NORMAL)
						val = rand() % blockConfig.normalMax + blockConfig.normalMax;
					else if (type == BlockType::HEAVY)
						val = rand() % blockConfig.heavyMax + blockConfig.heavyMax;

					//Add block
					blocks.push_back(Block(pos, type, val));
				}
			}
		}
	} 	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}


Gameplay::~Gameplay()
{
}

void Gameplay::Update(InputManager inputManager) {
	std::string pl1Points = std::to_string(playerOne.points);
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text(pl1Points, mtdl::Color(255, 0, 0, 255), "pl1Points"));
	pl1PointsTextRect = mtdl::Rect(150, 510, Renderer::Instance()->GetTextureSize("pl1Points"));
	std::string pl2Points = std::to_string(playerTwo.points);
	Renderer::Instance()->LoadTextureText("sunspire24", mtdl::Text(pl2Points, mtdl::Color(255, 0, 0, 255), "pl2Points"));
	pl2PointsTextRect = mtdl::Rect(540, 510, Renderer::Instance()->GetTextureSize("pl2Points"));

	switch (gameplayState) {
	case GameplayState::START_GAME:
		if (playerOne.lives <= 0 || playerTwo.lives <= 0) gameplayState = GameplayState::GAME_OVER;
		if (inputManager.input.escPressed) {
			status.status = 0;
			status.finished = true;
		}
		if (inputManager.input.spacePressed) gameplayState = GameplayState::RUNNING;
		break;
	case GameplayState::RUNNING:
		if(inputManager.input.escPressed || inputManager.input.pPressed) gameplayState = GameplayState::PAUSED;

		//Player
		playerOne.Update(inputManager.input.wPressed, inputManager.input.sPressed);
		playerTwo.Update(inputManager.input.upPressed, inputManager.input.downPressed);

		//Ball
		switch (ball.Update(field, playerOne.colPosition, playerTwo.colPosition)) {
		case 0:
			break;
		case 1:
			ball.ResetBall(SCREEN_WIDTH - 130, BALL_SPEED_X, BALL_SPEED_Y);
			playerOne.ResetPlayer(20);
			playerTwo.ResetPlayer(SCREEN_WIDTH - 80);
			playerTwo.lives--;
			playerTwo.points -= 50;
			playerOne.points += 100;
			gameplayState = GameplayState::START_GAME;
			break;
		case 2:
			ball.ResetBall(70, BALL_SPEED_X*(-1), BALL_SPEED_Y*(-1));
			playerOne.ResetPlayer(20);
			playerTwo.ResetPlayer(SCREEN_WIDTH - 80);
			playerOne.lives--;
			playerOne.points -= 50;
			playerTwo.points += 100;
			gameplayState = GameplayState::START_GAME;
			break;
		default:
			break;
		}

		//Blocks
		for (std::vector<Block>::size_type i = 0; i != blocks.size(); i++) {
			blocks[i].Update(ball, playerOne, playerTwo);
		}
		break;
	case GameplayState::PAUSED:
		if (inputManager.input.escPressed) {
			status.status = 0;
			status.finished = true;
		}
		if (inputManager.input.spacePressed) gameplayState = GameplayState::RUNNING;
		if (sound && toggleSoundButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed)) {
			sound = !sound;
			toggleSoundButton = soundOnButton;
		}
		else if (toggleSoundButton->isPressed(inputManager.input.mousePosition, inputManager.input.mousePressed)) {
			sound = !sound;
			toggleSoundButton = soundOffButton;
		}
		toggleSoundButton->Update(inputManager.input.mousePosition);
		break;
	case GameplayState::GAME_OVER:
		//ask for user input
		
		//Save
		LoadRanking();
		Save("Heya", 1000);

		status.status = 0;
		status.finished = true;
		break;
	default:
		break;
	}

	if (playerOne.points < 0) playerOne.points = 0;
	if (playerTwo.points < 0) playerOne.points = 0;
}

void Gameplay::Draw() {
	Renderer::Instance()->Clear();

	//Push background texture
	Renderer::Instance()->PushImage(backgroundTexture, mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	//Players
	playerOne.Draw();
	playerTwo.Draw();
	Renderer::Instance()->PushImage("pl1", pl1TextRect);
	Renderer::Instance()->PushImage("pl2", pl2TextRect);
	Renderer::Instance()->PushImage("pl1Points", pl1PointsTextRect);
	Renderer::Instance()->PushImage("pl2Points", pl2PointsTextRect);
	playerTwo.Draw();
	for (int i = 0; i < playerOne.lives; i++) Renderer::Instance()->PushImage("player", playerOneLives[i]);
	for (int i = 0; i < playerTwo.lives; i++) Renderer::Instance()->PushImage("player", playerTwoLives[i]);

	//Ball
	ball.Draw();

	//Blocks
	for (std::vector<Block>::size_type i = 0; i != blocks.size(); i++) {
		blocks[i].Draw();
	}

	switch (gameplayState) {
	case GameplayState::START_GAME:
		Renderer::Instance()->PushImage("bTrans", mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
		Renderer::Instance()->PushImage("start_game", startGameTextRect);
		Renderer::Instance()->PushImage("press_space", pressSpaceTextRect);
		break;
	case GameplayState::RUNNING:
		break;
	case GameplayState::PAUSED:
		Renderer::Instance()->PushImage("bTrans", mtdl::Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
		Renderer::Instance()->PushImage("pause", pauseTextRect);
		toggleSoundButton->Draw();
		break;
	case GameplayState::GAME_OVER:
		break;
	default:
		break;
	}

	Renderer::Instance()->Render();
}

void Gameplay::Save(std::string name, int score) {
	try
	{
		//Check if player made it to the to 10
		
		//Check if he made it
		//Iterate through vector, if score of player in position is less, then add new player in this pos.
		for (int i = 0; i < 10; i++)
		{
			if (ranking[i].score < score)
			{
				ranking.insert(ranking.begin() + i, mtdl::PlayerRanking(name, score));
				break;
			}
		}
		
		std::cout << "______________________________________________" << std::endl;

		for (int i = 0; i < 10; i++)
		{
			std::cout << i << "  -  " << ranking[i].name << "  " << ranking[i].score << std::endl;
		}

		//save ranking
		
		//Open file
		std::ofstream fexit("../res/files/ranking.bin", std::ios::out | std::ios::binary);
		
		int stringSize = 10;
		
		//Write to file
		for (int i = 0; i < 10; i++)
		{
			//convert string to char arr
			char nameC[10];
			strcpy(nameC, ranking[i].name.c_str());

			//Store string lenght
			fexit.write(reinterpret_cast<char*>(&stringSize), sizeof(stringSize));

			//Store name
			fexit.write(nameC, sizeof(nameC));

			//Store score
			fexit.write(reinterpret_cast<char*>(&ranking[i].score), sizeof(ranking[i].score));
		}
		
		fexit.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Gameplay::LoadRanking() {

	ranking.clear();

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

	for (int i = 0; i < ranking.size() ; i++)
	{
		std::cout << i << "  -  " << ranking[i].name << "  " << ranking[i].score << std::endl;
	}
}
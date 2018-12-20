#include "Gameplay.h"



Gameplay::Gameplay()
{
	std::cout << "Gameplay\n";
	gameplayState = GameplayState::START_GAME;

	//Load background
	backgroundTexture = "background_menu";

	//Instantiate elements
	//ball = new Ball();
	//playerOne = new Player();
	//playerTwo = new Player();

	//read xml ***/FALTA CONTROLAR ERROR /***
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
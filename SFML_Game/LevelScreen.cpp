#include "LevelScreen.h"
#include "Game.h"
#include "Platform.h"
#include <iostream>

LevelScreen LevelScreen::m_LevelScreen;
std::vector <Level> LevelScreen::roomList;

LevelScreen::LevelScreen()
{
	roomList.push_back(Level("Levels\\Level1.png"));
}


LevelScreen::~LevelScreen()
{
}

void LevelScreen::addLevel()
{
	/**
	sf::Image LevelLayout;
	std::string text = "Level_";
	text += std::to_string(currentLevel);
	LevelLayout.loadFromFile(text);
	roomList.push_back(Level(LevelLayout));
	*/
}
void LevelScreen::Init()
{
	roomList.push_back(Level("Levels\\Level1.png"));
}
void LevelScreen::render(Game * game)
{
	//Rendering process
	roomList[currentLevel - 1].render(&(game->window_));
	game->window_.draw(game->player_1->getSprite());
}

void LevelScreen::handleInput(Game * game)
{
	if (roomList.size() == 0) Init();
	game->player_1->update(roomList[currentLevel - 1].platforms);
	//Input Handling
}

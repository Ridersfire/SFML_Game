#include "LevelScreen.h"
#include "Game.h"
#include "Platform.h"

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
void LevelScreen::render(Game * game)
{
	//Rendering process
	roomList[currentLevel - 1].render(&(game->window_));
	game->window_.draw(game->player_1.getSprite());
}

void LevelScreen::handleInput(Game * game)
{
	game->player_1.update(roomList[currentLevel - 1].platforms);
	//Input Handling
}
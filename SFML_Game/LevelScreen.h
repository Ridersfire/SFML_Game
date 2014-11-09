#pragma once
#include "Screen.h"
#include "Level.h"

class LevelScreen : public Screen
{
public:

	LevelScreen();
	~LevelScreen();
	std::vector <Level> roomList;
	int currentLevel;
	void addLevel();
	int currentLevel = 1;
	void render(sf::RenderWindow & window);
	void handleInput(sf::RenderWindow & window);
};


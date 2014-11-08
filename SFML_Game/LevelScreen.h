#pragma once
#include "Screen.h"
#include "Level.h"

class LevelScreen : public Screen
{
public:
	LevelScreen();
	~LevelScreen();
	std::vector <Level> roomList;
	void addLevel();
	int currentLevel = 1;
	void render(sf::RenderWindow & window);
	void handleInput();
};


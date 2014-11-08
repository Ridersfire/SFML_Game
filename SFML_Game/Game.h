#pragma once
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "LevelScreen.h"
#include "StartScreen.h"
#include "PlayerChar.h"

class Level;


class Game
{
public:
	Game();
	int currentLevel;
	std::vector < Screen > screens;
	PlayerChar player_1;
	//not sure if addlevel is needed here
	void addLevel(sf::Image);
	void renderGame();
	void run();
	~Game();
private:
	//sf::RenderWindow window_;
	void handleInput();	
	const int STARTSCREEN = 0;
	const int GAMESCREEN = 1;
	const int OPTIONSCREEN = 2;
	bool isGameRunning = true;
	bool onStartScreen = true;
	bool gotoOptionScreen = false;
	
};


#pragma once
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "LevelScreen.h"
#include "StartScreen.h"
#include "OptionScreen.h"
#include "PlayerChar.h"

class Level;


class Game
{
public:
	Game();
	int currentLevel;
	PlayerChar player_1;
	//moved addlevel to levelScreen
	void renderGame();
	void run();
	~Game();
	sf::RenderWindow window_;

private:

	void handleInput();	
	const int STARTSCREEN = 0;
	const int GAMESCREEN = 1;
	const int OPTIONSCREEN = 2;
	bool isGameRunning = true;
	bool onStartScreen = true;
	bool gotoOptionScreen = false;
	StartScreen startScreen;
	LevelScreen levelScreen;
	OptionScreen optionScreen;
	
};


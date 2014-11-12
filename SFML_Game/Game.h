
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
	/**
		The game class holds the player character, the render window,
		and the (currently) 3 types of screens used in this game
	*/
	Game();
	
	PlayerChar* player_1;
	//moved addlevel to levelScreen
	void renderGame();
	void run();
	~Game();
	sf::RenderWindow window_;
	void startGame(int charSelect = 0);
	void addScreen(Screen* newScreen);
	void removeScreen();
	bool isGameRunning;
	bool mouseClicked = false;
	bool mouseClick_Buffer = false;

private:

	void handleInput();	
	std::vector <Screen*> screenz;
	//OptionScreen optionScreen;
	
};


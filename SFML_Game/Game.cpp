#include "Game.h"
#include "Level.h"
#include "PlayerChar.h"
#include "StartScreen.h"
#include "OptionScreen.h"

Game::Game()
{
	PlayerChar a(1);
	player_1 = a;
	screens.push_back(StartScreen());
	screens.push_back(LevelScreen());
	screens.push_back(OptionScreen());
}

void Game::run()
{
	/**
	//Start with main menu
	//once hit start, go into running through level

	while (isGameRunning)
	{
		while (onStartScreen)
		{
			//screens[STARTSCREEN].render(window_);
			//screens[STARTSCREEN].handleInput();
			//show start screen
			
			display start screen

			click on start button ->
			set onStartScreen = false
			set gotoOptionScreen = false
			click on option button ->
			set onStartScreen = false
			set gotoOptionScreen = true
			
		}
		while (!onStartScreen && !gotoOptionScreen)
		{
			//render the game levels
		}
		while (!onStartScreen && gotoOptionScreen)
		{
			//render options menu
		}
	}
	*/
}
void Game::addLevel(sf::Image LevelLayout)
{
	//roomList.push_back(Level(LevelLayout));
}

void Game::renderGame()
{
	//roomList[currentLevel].renderLevel();
	//player_1.renderChar
}

void Game::handleInput()
{
	
}

Game::~Game()
{
}


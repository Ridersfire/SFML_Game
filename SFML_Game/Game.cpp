#include "Game.h"
#include "Level.h"
#include "PlayerChar.h"
#include "StartScreen.h"
#include "OptionScreen.h"

Game::Game() 
	: window_(sf::VideoMode(800, 600), "GAME")
{
	player_1 = PlayerChar(1);
	
	screens.push_back(StartScreen());
	screens.push_back(LevelScreen());
	screens.push_back(OptionScreen());
}
/**
	This function is the heart of the program,
	it uses 'isGameRunning' 'onStartScreen' and 'gotoOptionScreen'
	to decide which screens to display
*/
void Game::run()
{
	//Start with main menu
	//once hit start, go into running through level

	while (isGameRunning)
	{
		while (onStartScreen)
		{
			screens[STARTSCREEN].render(window_);
			screens[STARTSCREEN].handleInput();
			//show start screen
			/**
			display start screen

			click on start button ->
			set onStartScreen = false
			set gotoOptionScreen = false
			click on option button ->
			set onStartScreen = false
			set gotoOptionScreen = true
			*/

			
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
}

void Game::handleInput()
{
	
}

Game::~Game()
{
}


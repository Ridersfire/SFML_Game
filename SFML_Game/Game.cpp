
#include "Game.h"


/**
	Initializes Game with a renderwindow of 800x600 as well as
	the player
*/
Game::Game()
	: window_(sf::VideoMode(800, 600), "GAME"),
	startScreen(), levelScreen(), player_1(1)//, optionScreen()
{
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
		window_.clear();
		sf::Event event;
		window_.setFramerateLimit(60);

		//allows user to hit x button and close window
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
		}
		//displays start screen
		if (onStartScreen)
		{
			startScreen.render(this);
			startScreen.handleInput(this);
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
		//displays the game
		else if (!gotoOptionScreen)
		{
			levelScreen.render(this);
			levelScreen.handleInput(this);
			//render the game levels
		}
		//displays the option screen
		else
		{
			//render options menu
		}
		window_.display();

	}
}

void Game::handleInput()
{
	
}
void Game::startGame()
{
	onStartScreen = false;
	gotoOptionScreen = false;
}
Game::~Game()
{
}


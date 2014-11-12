
#include "Game.h"


/**
	Initializes Game with a renderwindow of 800x600 as well as
	the player
*/
Game::Game()
	: window_(sf::VideoMode(800, 600), "GAME")
{
	screenz.push_back(new StartScreen());
	isGameRunning = true;
}
/**
	This function is the heart of the program,
	it uses 'isGameRunning' 'onStartScreen' and 'gotoOptionScreen'
	to decide which screens to display
*/
void Game::run()
{
	LevelScreen::Instance()->Init();
	//Start with main menu
	//once hit start, go into running through level
	player_1 = new PlayerChar(1);
	while (isGameRunning)
	{
		window_.clear();
		sf::Event event;
		window_.setFramerateLimit(60);

		mouseClicked = false;
		//allows user to hit x button and close window
		bool isMouseClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (isMouseClicked && !mouseClick_Buffer)
		{
			mouseClicked = true;
			mouseClick_Buffer = true;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouseClick_Buffer = false;
		}
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
		}
		screenz.back()->render(this);
		screenz.back()->handleInput(this);

		window_.display();

	}
}

void Game::addScreen(Screen* newScreen)
{
	screenz.push_back(newScreen);
}
void Game::removeScreen()
{
	screenz.pop_back();
}
/**
begins game by changing loop to run the levelScreen
also initializes player character given an input value charSelect
default value is 0, or green character
*/
void Game::startGame(int charSelect)
{
	player_1 = new PlayerChar(charSelect);
}
Game::~Game()
{
}


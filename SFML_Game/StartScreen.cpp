#include "StartScreen.h"
#include "CharScreen.h"
#include "Game.h"
#include <iostream>

StartScreen::StartScreen()
{
	//Sets up a set of rectangles used to hold the button coords
	buttons["exit"] = new Button("startscreen\\exitSprite", sf::Vector2f(302.f, 420.f));
	buttons["start"] = new Button("StartScreen\\startSprite", sf::Vector2f(278.f, 258.f));
	buttons["exit"]->centerOnWindow();
	buttons["start"]->centerOnWindow();
	mouseBounds_.height = 1.f;
	mouseBounds_.width = 1.f;
	//options_button.setSize(sf::Vector2f(235.f, 48.f));
	//options_button.setPosition(sf::Vector2f(243.f, 338.f));
	backgroundImage.loadFromFile("startscreen\\StartScreen.png");
	background.setTexture(&backgroundImage);
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(sf::Vector2f(0, 0));


}
/**
Renders the current items in the start screen using a reference
to a Game to draw on the window
*/
void StartScreen::render(Game * game)
{
	game->window_.draw(background);
	for (auto button : buttons)
	{
		if (button.second->isActive())
			game->window_.draw(button.second->getSprite());
	}
}

StartScreen::~StartScreen()
{
}

void StartScreen::setMain(bool state)
{
	buttons["exit"]->setIfActive(state);
	buttons["start"]->setIfActive(state);

}

/**
	Handles the mouse input for the start screen
	Takes an input of game so that it can start the game and such
*/
void StartScreen::handleInput(Game * game)
{
	mouseBounds_.top = sf::Mouse::getPosition(game->window_).y;
	mouseBounds_.left = sf::Mouse::getPosition(game->window_).x;
	for (auto button : buttons)
	{
		if (button.second->isActive())
		{
			if ((button.second)->getBounds().intersects(mouseBounds_))
			{
				if (game->mouseClicked)
				{
					std::cout << "Clicked " << button.first << std::endl;
					if (button.first == "exit") game->window_.close();
					if (button.first == "start")
					{
						game->startGame();
						game->addScreen(CharScreen::Instance());
						//game->startGame();
					}
				}
				else
				{
					button.second->hoverOver(true);
				}
			}
			else
			{
				button.second->hoverOver(false);
			}
		}
	}
}
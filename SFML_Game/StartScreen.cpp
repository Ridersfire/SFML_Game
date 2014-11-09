#include "StartScreen.h"
#include "Game.h"
#include <iostream>

StartScreen::StartScreen()
{
	//Sets up a set of rectangles used to hold the button coords
	buttons["exit"] = Button("startscreen\\exitSprite.png", sf::Vector2f(302.f, 420.f));
	buttons["start"] = Button("StartScreen\\startSprite.png", sf::Vector2f(278.f, 258.f));
	mouseBounds_.height = 1.f;
	mouseBounds_.width = 1.f;
	//options_button.setSize(sf::Vector2f(235.f, 48.f));
	//options_button.setPosition(sf::Vector2f(243.f, 338.f));
	backgroundImage.loadFromFile("startscreen\\StartScreen.png");
	background.setTexture(&backgroundImage);
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(sf::Vector2f(0, 0));


}

void StartScreen::render(Game * game)
{
	game->window_.draw(background);

}

StartScreen::~StartScreen()
{
}

void StartScreen::handleInput(Game * game)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseBounds_.top = sf::Mouse::getPosition(game->window_).y;
		mouseBounds_.left = sf::Mouse::getPosition(game->window_).x;
		for (auto button : buttons)
		{
			if ((button.second).getBounds().intersects(mouseBounds_))
			{
				std::cout << "Clicked " << button.first << std::endl;
				if (button.first == "exit") game->window_.close();
				if (button.first == "start")
				{
					game->startGame();
				}
			}
		}
	}

}
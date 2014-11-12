#include "CharScreen.h"
#include "Game.h"
CharScreen CharScreen::m_CharScreen;

CharScreen::CharScreen()
{
	buttons_["back"] = new Button("charscreen\\backSprite", sf::Vector2f(302.f, 420.f));
	buttons_["start"] = new Button("charScreen\\startSprite", sf::Vector2f(278.f, 258.f));
	buttons_["char_1"] = new Button("charScreen\\char_1", sf::Vector2f(150.f, 100.f));
	buttons_["char_2"] = new Button("charScreen\\char_2", sf::Vector2f(250.f, 100.f));

	mouseBounds_.height = 1.f;
	mouseBounds_.width = 1.f;
	backgroundImage.loadFromFile("charscreen\\bg.png");
	background.setTexture(&backgroundImage);
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(sf::Vector2f(0, 0));
	selectionNotifier.setFillColor(sf::Color::Black);
	selectionNotifier.setSize(sf::Vector2f(5, 5));
	selectionNotifier.setPosition(sf::Vector2f(-100, -100));
}


CharScreen::~CharScreen()
{
}

void CharScreen::render(Game * game)
{
	game->window_.draw(background);
	for (auto button : buttons_)
	{
		game->window_.draw(button.second->getSprite());
	}
	if (charSelect_ != -1) game->window_.draw(selectionNotifier);
}
void CharScreen::handleInput(Game * game)
{
	mouseBounds_.top = sf::Mouse::getPosition(game->window_).y;
	mouseBounds_.left = sf::Mouse::getPosition(game->window_).x;
	for (auto button : buttons_)
	{
		if (button.second->isActive())
		{
			if ((button.second)->getBounds().intersects(mouseBounds_))
			{
				if (game->mouseClicked)
				{
					//std::cout << "Clicked " << button.first << std::endl;
					if (button.first == "char_1")
					{
						charSelect_ = 0;
						selectionNotifier.setPosition(150 + 20, 90);
					}
					if (button.first == "char_2")
					{
						charSelect_ = 1;
						selectionNotifier.setPosition(250 + 20, 90);
					}
					if (button.first == "back")
					{
						charSelect_ = -1;
						game->removeScreen();
						break;
					}
					if (button.first == "start" && charSelect_ != -1)
					{
						game->startGame(charSelect_);
						game->addScreen(LevelScreen::Instance());
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
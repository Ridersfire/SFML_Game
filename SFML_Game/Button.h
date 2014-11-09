#pragma once
#include <SFML\Graphics.hpp>
//#include <string>

class Button
{
public:
	Button();
	Button(std::string spriteName, sf::Vector2f position = sf::Vector2f(0, 0));
	~Button();
	sf::FloatRect getBounds();
	sf::Sprite sprite_;
	sf::Texture texture_;
};


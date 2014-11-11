#pragma once
#include <SFML\Graphics.hpp>
//#include <string>

class Button
{
public:
	Button();
	Button(std::string spriteName, sf::Vector2f position = sf::Vector2f(0, 0));
	void Button::hoverOver(bool newState);
	sf::Sprite getSprite();
	~Button();
	bool isActive();
	void toggleActive();
	bool enabled;
	bool mouseOver = false;
	bool canHover;
	sf::FloatRect getBounds();
private:
	sf::Texture texture_;
	sf::Texture texture_mouseOver;
	sf::Sprite sprite_;
};


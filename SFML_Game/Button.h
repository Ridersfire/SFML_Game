#pragma once
#include <SFML\Graphics.hpp>
//#include <string>

class Button
{
public:
	Button();
	Button(std::string spriteName, sf::Vector2f position = sf::Vector2f(0, 0));
	void hoverOver(bool newState);
	void centerOnWindow();
	sf::Sprite getSprite();
	~Button();
	bool isActive();
	void setIfActive(bool newSetting);
	bool enabled;
	bool mouseOver = false;
	sf::FloatRect getBounds();
private:
	sf::Texture texture_;
	sf::Texture texture_mouseOver;
	sf::Sprite sprite_;
};


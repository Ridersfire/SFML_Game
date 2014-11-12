#pragma once
#include "Screen.h"

class CharScreen : public Screen
{
public:
	CharScreen();
	~CharScreen();
	void render(Game * game);
	void handleInput(Game * game);
	int charSelect_ = -1;
	std::map <std::string, Button*> buttons_;
	sf::FloatRect mouseBounds_;
	sf::RectangleShape selectionNotifier;
	static CharScreen* Instance(){
		return &m_CharScreen;
	}
private:
	static CharScreen m_CharScreen;
};


#pragma once
#include <SFML\Graphics.hpp>

/**
	This thing is where I keep the details of the level, for example
	the platforms, the spawn location, and later the exit location, and
	probably the enemies
*/

class Platform;

class Level
{
public:
	Level();
	Level(std::string);
	void render(sf::RenderWindow * window);
	~Level();
	int spawnLocX = 0;
	int spawnLocY = 0;
	std::vector <Platform> platforms;
	sf::Color spawnSpot = sf::Color(255,0,0,255);

	//std::vector <Enemy> enemy_List;





};


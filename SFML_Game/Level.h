#pragma once
#include <SFML\Graphics.hpp>

//using namespace sf;

class Platform;

class Level
{
public:
	Level();
	Level(sf::Image);
	~Level();
	std::vector <Platform> platforms;
	sf::Color spawnSpot = sf::Color(255,0,0,255);





};


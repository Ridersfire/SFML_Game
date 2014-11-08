#pragma once
#include "Screen.h"

class LevelScreen : public Screen
{
public:
	LevelScreen();
	~LevelScreen();
	std::vector <Level> roomList;
};


#pragma once

#include "Screen.h"
#include "Level.h"


class LevelScreen : public Screen
{
public:
	void Init();
	LevelScreen();
	~LevelScreen();
	static std::vector <Level> roomList;
	void addLevel();
	int currentLevel = 1;
	void render(Game * game);
	void handleInput(Game * game);


	static LevelScreen* Instance() {
		return &m_LevelScreen;
	}

private:
	static LevelScreen m_LevelScreen;

};


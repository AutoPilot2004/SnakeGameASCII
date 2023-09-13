#pragma once
#include <vector>
#include <string>

#include "Player.h"
#include "Fruit.h"

class Map
{
public:
	Map();

	void runGame(const std::string &fileName);

private:
	void loadMap(const std::string &fileName);
	void printMap();
	bool updateMap();

	bool updateEach(int newX, int newY);

	void swapTiles(int posX, int posY, int newPosX, int newPosY, int currentTailNum);

	void updateScore();

private:
	std::vector<std::string> m_map;

	std::vector<Player> m_player;

	Fruit m_fruit;

	int m_score = 0;
	int m_highScore;

	int m_speed = 100;
};


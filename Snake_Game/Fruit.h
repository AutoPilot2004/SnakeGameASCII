#pragma once
#include <vector>
#include <string>

class Fruit
{
public:
	Fruit();

	void putFruitOnMap(std::vector<std::string> &map);

	//Getters
	int getFruitPosX() const { return m_posX; }
	int getFruitPosY() const { return m_posY; }

	char getFruit() const { return m_fruit; }

private:
	//Takes the X, Y size of the 2D array
	void generateFruitPos(int maxX, int maxY);

private:
	int m_posX = 0, m_posY = 0;

	char m_fruit = '@';
};


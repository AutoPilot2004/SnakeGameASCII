#include "Fruit.h"

#include <random>
#include <iostream>

Fruit::Fruit()
{
	srand(time(NULL));
}

void Fruit::generateFruitPos(int maxX, int maxY)
{
		m_posX = (rand() % (maxX - 2)) + 1;
		m_posY = (rand() % (maxY - 2)) + 1;
}

void Fruit::putFruitOnMap(std::vector<std::string> &map)
{
	if (map[m_posY][m_posX] != m_fruit) {
		do {
			generateFruitPos(map[0].size(), map.size());
		} while (map[m_posY][m_posX] != ' ');

		map[m_posY][m_posX] = m_fruit;
	}
}
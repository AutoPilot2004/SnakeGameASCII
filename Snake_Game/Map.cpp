#include "Map.h"

#include <fstream>
#include <iostream>
#include <conio.h>

#include "Utils.h"

Map::Map()
{
	std::ifstream highScore("highScore.txt");

	if (!highScore.fail()) {
		highScore >> m_highScore;
	}
	else {
		m_highScore = m_score;
	}

	highScore.close();
}

void Map::runGame(const std::string &fileName)
{
	loadMap(fileName);

	bool gameEnded = false;

	while (!gameEnded) {
		Utils::clearScreen();
		m_player[0].updateDir();
		gameEnded = updateMap();
		printMap();
		Sleep(m_speed);
	}

	if (m_score > m_highScore) {
		std::ofstream highScore("highScore.txt");

		highScore << m_score;

		highScore.close();
	}
}

void Map::loadMap(const std::string &fileName)
{
	//Load level into m_map and assign Player
	std::ifstream file(fileName);

	if (file.fail()) {
		perror(fileName.c_str());
		char g = _getch();
		exit(1);
	}

	std::string tmp;

	while (std::getline(file, tmp)) {
		m_map.push_back(tmp);
	}

	file.close();

	int playerX = (rand() % (m_map[0].size() - 2)) + 1;
	int playerY = (rand() % (m_map.size() - 2)) + 1;

	m_map[playerY][playerX] = 'O';
	m_player.push_back(Player('O', playerX, playerY));
}

void Map::printMap()
{
	printf("Score: %d, High Score: %d\n\n", m_score, m_highScore);

	for (int i = 0; i < m_map.size(); i++) {
		printf("%s\n", m_map[i].c_str());
	}
}

bool Map::updateMap()
{
	int posX;
	int posY;

	bool gameOver = false;

	m_player[0].getPos(posX, posY);

	switch (m_player[0].getCurrentDir()) {
	case Player::UP:
		gameOver = updateEach(posX, posY - 1);
		break;
	case Player::DOWN:
		gameOver = updateEach(posX, posY + 1);
		break;
	case Player::LEFT:
		gameOver = updateEach(posX - 1, posY);
		break;
	case Player::RIGHT:
		gameOver = updateEach(posX + 1, posY);
		break;
	}

	m_fruit.putFruitOnMap(m_map);

	return gameOver;
}

bool Map::updateEach(int newX, int newY)
{
	if (m_map[newY][newX] == m_fruit.getFruit()) {
		int tailX;
		int tailY;

		Player::getPosForNewTail(m_map, m_player.back(), tailX, tailY);
		m_player.push_back(Player('o', tailX, tailY));

		updateScore();
	}
	else {
		for (int i = 1; i < m_player.size(); i++) {
			if (m_map[newY][newX] == m_player[i].getSymbol()) return true;
		}
	}

	int posX, posY;
	int pos2X, pos2Y;

	m_player[0].getPos(posX, posY);

	m_player[0].setPos(newX, newY);

	swapTiles(posX, posY, m_player[0].getPosX(), m_player[0].getPosY(), 0);

	for (int i = 1; i < m_player.size(); i++) {
		m_player[i].getPos(pos2X, pos2Y);
		m_player[i].setPos(posX, posY);
		swapTiles(pos2X, pos2Y, m_player[i].getPosX(), m_player[i].getPosY(), i);
		posX = pos2X;
		posY = pos2Y;
	}

	return false;
}

void Map::swapTiles(int posX, int posY, int newPosX, int newPosY, int currentTailNum)
{
	m_map[posY][posX] = ' ';

	if (newPosX < 1) {
		m_player[currentTailNum].setPos(m_map[0].size() - 2, newPosY);
		m_map[newPosY][m_map[0].size() - 2] = m_player[currentTailNum].getSymbol();
	}
	else if (newPosX > m_map[0].size() - 2) {
		m_player[currentTailNum].setPos(1, newPosY);
		m_map[newPosY][1] = m_player[currentTailNum].getSymbol();
	}
	else if (newPosY > m_map.size() - 2) {
		m_player[currentTailNum].setPos(newPosX, 1);
		m_map[1][newPosX] = m_player[currentTailNum].getSymbol();
	}
	else if (newPosY < 1) {
		m_player[currentTailNum].setPos(newPosX, m_map.size() - 2);
		m_map[m_map.size() - 2][newPosX] = m_player[currentTailNum].getSymbol();
	}
	else {
		m_map[newPosY][newPosX] = m_player[currentTailNum].getSymbol();
	}
}

void Map::updateScore()
{
	m_score++;

	if (m_score % 5 == 0 && m_score != 0 && m_speed > 5) m_speed -= 5;
}
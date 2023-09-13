#pragma once
#include <vector>
#include <string>

class Player
{
public:
	Player(char symbol, int posX, int posY);

	enum currentDir { NOT_MOVING, UP, DOWN, LEFT, RIGHT };

	void updateDir();

	static void getPosForNewTail(const std::vector<std::string> &map, const Player &lastTail, int &posX, int &posY);

	//Setters
	void setPos(int x, int y) { m_posX = x; m_posY = y; }

	//Getters
	void getPos(int &x, int &y) { x = m_posX; y = m_posY; }
	int getPosX() const { return m_posX; }
	int getPosY() const { return m_posY; }

	char getSymbol() const { return m_symbol; }

	currentDir getCurrentDir() const { return m_currentDir; }

private:
	int m_posX, m_posY;

	char m_symbol;

	currentDir m_currentDir = NOT_MOVING;
};


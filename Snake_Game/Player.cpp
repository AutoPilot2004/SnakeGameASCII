#include "Player.h"

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

Player::Player(char symbol, int posX, int posY) : m_symbol(symbol), m_posX(posX), m_posY(posY)
{
	//empty
}

void Player::updateDir()
{
	if (GetAsyncKeyState('W') & 0x1) {
		if (m_currentDir != DOWN) m_currentDir = UP;
	}
	else if (GetAsyncKeyState('S') & 0x1) {
		if (m_currentDir != UP) m_currentDir = DOWN;
	}
	else if (GetAsyncKeyState('A') & 0x1) {
		if (m_currentDir != RIGHT) m_currentDir = LEFT;
	}
	else if (GetAsyncKeyState('D') & 0x1) {
		if (m_currentDir != LEFT) m_currentDir = RIGHT;
	}
}

void Player::getPosForNewTail(const std::vector<std::string> &map, const Player &lastTail, int &posX, int &posY)
{
	if (map[lastTail.m_posY + 1][lastTail.m_posX] == ' ') {
		posX = lastTail.m_posX;
		posY = lastTail.m_posY + 1;
	}
	else if (map[lastTail.m_posY - 1][lastTail.m_posX] == ' ') {
		posX = lastTail.m_posX;
		posY = lastTail.m_posY - 1;
	}
	else if (map[lastTail.m_posY][lastTail.m_posX + 1] == ' ') {
		posX = lastTail.m_posX + 1;
		posY = lastTail.m_posY;
	}
	else if (map[lastTail.m_posY][lastTail.m_posX - 1] == ' ') {
		posX = lastTail.m_posX - 1;
		posY = lastTail.m_posY;
	}
}
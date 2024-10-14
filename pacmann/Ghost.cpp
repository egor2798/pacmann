
#include <iostream>
#include <Windows.h>
#include "map.h"
#include "Ghost.h" // класс призраков
#include "Player.h"// класс игрока 

#include "Check.h"
const char SYMBOL_EMPTY = ' ';
const char SYMBOL_PLAYER = '@';
const char SYMBOL_GHOST = 'G';
const char SYMBOL_WALL = '#';
const char SYMBOL_FOOD = '*';
const int MapDx = 31;
const int MapDy = 29;
const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
const int DOWN = 4;

bool moveGhost(Ghost& ghost, int x, int y)//функци€ дл€ движени€ призрака
{
	if (!isValidPos(x, y))
	{
		return false;
	}

	char ch = map[x][y];
	int x1 = x;
	int y1 = y;
	if (isValidPos(ghost.x, ghost.y))
	{
		if (ch == SYMBOL_EMPTY)// услови€ чтоб призрак не ел еду и оставл€л пустые €чейки пустыми
		{
			map[ghost.x][ghost.y] = SYMBOL_EMPTY;
		}
		
		if (ch == SYMBOL_FOOD)
		{
			map[ghost.x][ghost.y] = SYMBOL_FOOD;
		}
	}

	if ((ch != SYMBOL_EMPTY) && (ch != SYMBOL_FOOD))
	{
		return false;
	}

	ghost.x = x; ghost.y = y;
	map[ghost.x][ghost.y] = SYMBOL_GHOST;

	return true;
}
bool isValidPos(int x, int y)// функци€ дл€ того, чтобы персонажи не выходили за рамки пол€
{
	return (x >= 0 && x < MapDx && y >= 0 && y < MapDy);
}
void GhostAI(Ghost& ghost) // функци€ дл€ определени€ вектора движени€ призраков
{
	srand(time(0));
	int r = rand() % 4;
	if (r == 1)
	{
		if (map[ghost.x][ghost.y - 1] != SYMBOL_WALL)
		{
			ghost.direction = LEFT;
		}
		else if (map[ghost.x][ghost.y + 1] != SYMBOL_WALL) {
			ghost.direction = RIGHT;
		}
		else if (map[ghost.x - 1][ghost.y] != SYMBOL_WALL) {
			ghost.direction = UP;
		}
	}
	if (r == 2)
	{
		if (map[ghost.x][ghost.y + 1] != SYMBOL_WALL)
		{
			ghost.direction = RIGHT;
		}
		else if (map[ghost.x][ghost.y - 1] != SYMBOL_WALL) {
			ghost.direction = LEFT;
		}
		else if (map[ghost.x + 1][ghost.y] != SYMBOL_WALL) {
			ghost.direction = DOWN;
		}
	}
	if (r == 3)
	{
		if (map[ghost.x - 1][ghost.y] != SYMBOL_WALL)
		{
			ghost.direction = UP;
		}
		else if (map[ghost.x][ghost.y - 1] != SYMBOL_WALL) {
			ghost.direction = LEFT;
		}
		else if (map[ghost.x + 1][ghost.y] != SYMBOL_WALL) {
			ghost.direction = DOWN;
		}
	}
	if (r == 4)
	{
		if (map[ghost.x - 1][ghost.y] != SYMBOL_WALL)
		{
			ghost.direction = UP;
		}
		else if (map[ghost.x + 1][ghost.y] != SYMBOL_WALL) {
			ghost.direction = DOWN;
		}
		else if (map[ghost.x][ghost.y - 1] != SYMBOL_WALL) {
			ghost.direction = LEFT;
		}
	}
}


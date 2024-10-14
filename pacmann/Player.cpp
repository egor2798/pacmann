#include <iostream>
#include <Windows.h>
#include "map.h"
#include "Ghost.h" // класс призраков
#include "Player.h"// класс игрока 
#include "Check.h"
using namespace std;

const char SYMBOL_EMPTY = ' ';
const char SYMBOL_PLAYER = '@';
const char SYMBOL_FOOD = '*';

const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
const int DOWN = 4;

int ScoringPoints = 0;
void CountScore() {
	ScoringPoints += 1;
	
}
bool movePlayer(Player& player, int x, int y)// функция для движения игрока
{
	if (!isValidPos(x, y))
	{
		return false;
	}

	char ch = map[x][y];

	if ((ch != SYMBOL_EMPTY) && (ch != SYMBOL_FOOD))
	{
		return false;
	}

	if (isValidPos(player.x, player.y))
	{
		if (ch == SYMBOL_FOOD)// условия для счёта 
		{
			
			CountScore();
		}
		map[player.x][player.y] = SYMBOL_EMPTY;
	}
	player.x = x; player.y = y;
	map[player.x][player.y] = SYMBOL_PLAYER;
	return true;
}
void showPlayerScore(Player& player)// функция вывода счёта игрока
{
	cout << "score:" << ScoringPoints << endl;
}

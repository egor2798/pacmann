#include <iostream>
#include <Windows.h>
#include "map.h"// файл карты
#include "Ghost.h" // файл призрака
#include "Player.h"// файл игрока
#include "Check.h"// файл функций для проверок
#include"Game.h"// файл самой игры
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	amountFood();
	Game();
}
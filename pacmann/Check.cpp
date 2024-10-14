#include <iostream>
#include <Windows.h>
#include "map.h"
#include "Ghost.h" // класс призраков
#include "Player.h"// класс игрока 
using namespace std;
const char SYMBOL_PLAYER = '@';

void CheckProgressGame(Player& player, Ghost& ghost) {// функция для определения проигрыша или выигрыша
	if ((SYMBOL_PLAYER == map[ghost.x][ghost.y - 1]) || (SYMBOL_PLAYER == map[ghost.x][ghost.y + 1]) || (SYMBOL_PLAYER == map[ghost.x - 1][ghost.y]) || (SYMBOL_PLAYER == map[ghost.x + 1][ghost.y])) {
		system("cls");
		cout << "вы проиграли" << endl;
		cout << "количество очков = " << ScoringPoints << endl;
		TerminateProcess(GetCurrentProcess(), 0);
	}
	if (ScoringPoints == AmountFoods) {
		cout << "вы выиграли" << endl;
		cout << "количество очков = " << ScoringPoints << endl;
		TerminateProcess(GetCurrentProcess(), 0);
	}
}
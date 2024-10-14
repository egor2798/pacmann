#include <iostream>
#include <Windows.h>
#include "map.h"
#include "Ghost.h" // ����� ���������
#include "Player.h"// ����� ������ 
using namespace std;
const char SYMBOL_PLAYER = '@';

void CheckProgressGame(Player& player, Ghost& ghost) {// ������� ��� ����������� ��������� ��� ��������
	if ((SYMBOL_PLAYER == map[ghost.x][ghost.y - 1]) || (SYMBOL_PLAYER == map[ghost.x][ghost.y + 1]) || (SYMBOL_PLAYER == map[ghost.x - 1][ghost.y]) || (SYMBOL_PLAYER == map[ghost.x + 1][ghost.y])) {
		system("cls");
		cout << "�� ���������" << endl;
		cout << "���������� ����� = " << ScoringPoints << endl;
		TerminateProcess(GetCurrentProcess(), 0);
	}
	if (ScoringPoints == AmountFoods) {
		cout << "�� ��������" << endl;
		cout << "���������� ����� = " << ScoringPoints << endl;
		TerminateProcess(GetCurrentProcess(), 0);
	}
}
#include <iostream>
#include <Windows.h>
#include "map.h"
#include "Ghost.h" // ����� ���������
#include "Player.h"// ����� ������ 
#include "Check.h"

using namespace std;

const char SYMBOL_EMPTY = ' ';
const char SYMBOL_PLAYER = '@';
const char SYMBOL_GHOST = 'G';
const char SYMBOL_WALL = '#';
const char SYMBOL_FOOD = '*';
const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
const int DOWN = 4;
int GameSpeed = 100;
int directions;
void Game() {// ������� ����� ����
	int com;
	cout << "PacMan" << endl;
	cout << "�������� �������" << endl;
	cout << "1.������ ����" << endl;
	cout << "2.��������� ����" << endl;
	cout << "�������� �������->";
	cin >> com;
	if (com == 1)
	{
		Player player;
		Ghost ghosts[3];
		moveGhost(ghosts[0], 14, 11);
		moveGhost(ghosts[1], 14, 12);
		moveGhost(ghosts[2], 14, 14);
		movePlayer(player, 1, 2);
		while (true)
		{
			CheckProgressGame(player, ghosts[0]);
			CheckProgressGame(player, ghosts[1]);
			CheckProgressGame(player, ghosts[2]);
			system("cls");
			showMap();
			showPlayerScore(player);
			if (GetAsyncKeyState(VK_UP))// ������� ��� ����������� ������� 
			{
				directions = UP;
			}
			else if (GetAsyncKeyState(VK_DOWN))// ������� ��� ����������� ������� 
			{
				directions = DOWN;
			}
			else if (GetAsyncKeyState(VK_LEFT))// ������� ��� ����������� ������� 
			{
				directions = LEFT;
			}
			else if (GetAsyncKeyState(VK_RIGHT))// ������� ��� ����������� ������� 
			{
				directions = RIGHT;
			}
			switch (directions)
			{
			case UP:
				movePlayer(player, player.x - 1, player.y); 
				break;
			case DOWN:
				movePlayer(player, player.x + 1, player.y);
				break;
			case LEFT:
				movePlayer(player, player.x, player.y - 1);
				break;
			case RIGHT:
				movePlayer(player, player.x, player.y + 1);
				break;
			}
			for (int ghost = 0; ghost < 3; ghost++)// ���� ��� �������� �� ���� ��������� 
			{
				GhostAI(ghosts[ghost]);
				switch (ghosts[ghost].direction)
				{
				case UP:
					moveGhost(ghosts[ghost], ghosts[ghost].x - 1, ghosts[ghost].y);
					break;
				case DOWN:
					moveGhost(ghosts[ghost], ghosts[ghost].x + 1, ghosts[ghost].y);
					break;
				case LEFT:
					moveGhost(ghosts[ghost], ghosts[ghost].x, ghosts[ghost].y - 1);
					break;
				case RIGHT:
					moveGhost(ghosts[ghost], ghosts[ghost].x, ghosts[ghost].y + 1);
					break;
				}
			}
			Sleep(GameSpeed);
		}
	}
	if (com == 2) {
		TerminateProcess(GetCurrentProcess(), 0);
	}
}
#include <iostream>
#include <Windows.h>

using namespace std;
const int MapDx = 31;
const int MapDy = 29;
const char SYMBOL_FOOD = '*';
int AmountFoods = -1;

extern char map[MapDx][MapDy] = {
			"############################",
			"#************##************#",
			"#*####*#####*##*#####*####*#",
			"#*####*#####*##*#####*####*#",
			"#*####*#####*##*#####*####*#",
			"#**************************#",
			"#*####*##*########*##*####*#",
			"#*####*##*########*##*####*#",
			"#******##****##****##******#",
			"######*##### ## #####*######",
			"######*##### ## #####*######",
			"######*##          ##*######",
			"######*## ###  ### ##*######",
			"######*## #      # ##*######",
			"######*   #      #   *######",
			"######*## #      # ##*######",
			"######*## ######## ##*######",
			"######*##          ##*######",
			"######*## ######## ##*######",
			"######*## ######## ##*######",
			"#************##************#",
			"#*####*#####*##*#####*####*#",
			"#*####*#####*##*#####*####*#",
			"#***##****************##***#",
			"###*##*##*########*##*##*###",
			"###*##*##*########*##*##*###",
			"#******##****##****##******#",
			"#*##########*##*##########*#",
			"#*##########*##*##########*#",
			"#**************************#",
			"############################"
};
void showMap()//������� ��� ������ ����� � �������
{
	for (int x = 0; x < MapDx; x++)
	{
		cout << map[x] << endl;
	}
}
void amountFood()// ������� �������� ���-�� ��� �� �����
{
	for (int i = 0; i < MapDx; i++)
	{
		for (int j = 0; j < MapDy; j++)
		{
			if (map[i][j] == SYMBOL_FOOD)
			{
				AmountFoods += 1;
			}
		}
	}
}


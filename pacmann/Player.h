#pragma once

class Player
{
public:
	int x, y;
	Player()
	{
		x = -1;
		y = -1;
	}
};
bool movePlayer(Player& player, int x, int y);
void showPlayerScore(Player& player);
void CountScore();
extern int ScoringPoints;

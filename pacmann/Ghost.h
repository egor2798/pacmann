#pragma once

class Ghost// класс призрака
{
public:
	int x, y, direction;
	Ghost()
	{
		x = -1;
		y = -1;
		direction = 1;
	}
};
bool moveGhost(Ghost& ghost, int x, int y);
bool isValidPos(int x, int y);
void GhostAI(Ghost& ghost);

#include "wall.h"




wall::wall(int ix1, int iy1, int iw1, int ih1, wall * mpnext) : obst(ix1, iy1, iw1, ih1)
{
	this->pnext = mpnext;
}

bool wall::collision(Character *& player, int charx, int chary, int charw, int charh, char dir)
{
	if (dir == 'L')
	{
		if (charx > 0 && !(((charx - 10) > getx() && ((charx - 10) < getx() + getw())) && (((chary + 10)>gety()) && (((chary + 10) < gety() + geth()) || (chary)>gety()) && ((chary) < gety() + geth()))))
		{
			return false;
		}
	}
	if (dir == 'R')
	{
		if (charx + 10 < 400 && !(((charx + charw + 10) > getx() && ((charx + charw + 10) < getx() + getw())) && ((((chary + 10) > gety()) && ((chary + 10) < gety() + geth()) || (chary) > gety()) && ((chary) < gety() + h))))
		{
			cout << "t";
			return false;
		}
	}

	if (dir == 'D')
	{
		if (chary < 200 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx > x && (charx < getx() + getw()))) && (((chary + charh + 10)>gety()) && ((chary + charh + 10) < gety() + geth()))))
		{
			cout << "t";
			return false;
		}
	}
	if (dir == 'U')
	{
		if (chary > 0 && !(((charx + 10 > getx() && (charx + 10 < getx() + getw())) || (charx > getx() && (charx < getx() + getw()))) && (((chary - 10)>gety()) && ((chary - 10) < gety() + geth()))))
		{
			cout << "t";
			return false;
		}
	}

	cout << 'x';

	return true;
}
//Brandon T.
#pragma once

#include "obst.h"
#include "Player.h"

class wall : public obst
{
public:

	wall(int ix1 = 0, int iy1 = 0, int iw1 = 0, int ih1 = 0, wall * mpnext = nullptr);

	~wall() {  }

	bool collision(Character *& player, int charx, int chary, int charw, int charh, char dir);

	wall * getnext() { return pnext; }

	void setnext(wall* newn) { pnext = newn; }

private:
	wall * pnext;
};



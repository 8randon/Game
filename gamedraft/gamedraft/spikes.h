//Brandon T.
#pragma once

#include "wall.h"

class spikes : public obst
{
public:
	spikes(int ix = 0, int iy = 0, int iw = 0, int ih = 0, spikes * pnext = nullptr) : obst(ix, iy, iw, ih) {}

	~spikes() { }

	bool collision(Character *& player, int charx, int chary, int charw, int charh, char dir);

	spikes * getnext() { return pnext; }

	void setnext(spikes* newn) { pnext = newn; }

private:
	spikes * pnext;
};


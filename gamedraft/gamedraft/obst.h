//Brandon T.
#ifndef OBST_H
#define OBST_H

#include <iostream>
#include "Character.h"


using std::cout;

class obst
{
public:
	obst(int ix=0, int iy=0, int iw=0, int ih=0)
		: x(ix), y(iy), w(iw), h(ih)
	{}

	~obst() { }

	virtual bool collision(Character *&player, int charx, int chary, int charw, int charh, char dir) = 0;


	int getx() { return x; }
	int gety() { return y; }
	int getw() { return w; }
	int geth() { return h; }

	void setx(int newx) { x = newx; }
	void sety(int newy) { y = newy; }
	void setw(int neww) { w = neww; }
	void seth(int newh) { h = newh; }

//test
protected:
	int x;
	int y;
	int w;
	int h;
};

#endif
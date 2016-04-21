#ifndef OBST_H
#define OBST_H

#include "stdfx.h"

using std::cout;

class obst
{
public:
	obst(int ix, int iy, int iw, int ih);
	~obst();

	bool collision(int charx, int chary, int charw, int charh, char dir);

	int getx() { return x; }
	int gety() { return y; }
	int getw() { return w; }
	int geth() { return h; }

//test
private:
	int x;
	int y;
	int w;
	int h;
};

#endif
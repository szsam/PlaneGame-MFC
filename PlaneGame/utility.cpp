#include "stdafx.h"

#include "utility.h"
#include <cstdlib>

//Dir c2d(char c)
//{
//	c = tolower(c);
//	switch (c)
//	{
//		case 'a': return LEFT;
//		case 'd': return RIGHT;
//		case 's': return DOWN;
//		case 'w': return UP;
//		default: return NODIR;
//	}
//}

//在[a, b)之间产生一个随机整数
int random(int a, int b)
{
	return (rand() % (a - b)) + a;
}

//COORD random(COORD a, COORD b)
//{
//	int x = random(a.X, b.X);
//	int y = random(a.Y, b.Y);
//	COORD c = { x, y };
//	return c;
//}
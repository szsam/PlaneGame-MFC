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

//��[a, b)֮�����һ���������
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
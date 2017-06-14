#include "stdafx.h"

#include "PlaneEnemy.h"
#include "utility.h"

CImage PlaneEnemy::image;


PlaneEnemy::PlaneEnemy(int x, int y, int h, int w, int s, int hp) :
	GameObject(CPoint(x, y), h, w, DOWN, s), health(hp)
{
}

// 减去一点血量后，若血量仍大于0， 则返回true，否则返回false
bool PlaneEnemy::decreaseHP()
{
	return --health > 0;
}

void PlaneEnemy::initImage()
{
	image.Load(_T("..\\Image\\Enemy.png"));
	make_transparent(image);
}

#include "stdafx.h"

#include "PlaneEnemy.h"
#include "utility.h"

CImage PlaneEnemy::image;


PlaneEnemy::PlaneEnemy(int x, int y, int h, int w, int s) :
	GameObject(CPoint(x, y), h, w, DOWN, s)
{
}

void PlaneEnemy::initImage()
{
	image.Load(_T("..\\Image\\Enemy.png"));
}

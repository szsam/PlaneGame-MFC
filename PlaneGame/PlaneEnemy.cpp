#include "stdafx.h"

#include "PlaneEnemy.h"
#include "utility.h"

CImage PlaneEnemy::image;


PlaneEnemy::PlaneEnemy(int x, int y, int h, int w, int s) :
	GameObject(CPoint(x, y), h, w, DOWN, s)
{
}

void PlaneEnemy::draw(CDC *pDC)
{
	if (!image.IsNull())
	{
		image.Draw(pDC->GetSafeHdc(), pos.x, pos.y, width, height);
	}
}

void PlaneEnemy::init_image()
{
	image.Load(_T("..\\Image\\Enemy.png"));
}

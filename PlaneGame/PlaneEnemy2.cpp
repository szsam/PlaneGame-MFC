#include "stdafx.h"

#include "PlaneEnemy2.h"

CImage PlaneEnemy2::image;


PlaneEnemy2::PlaneEnemy2(int x, int y, int h, int w, int s, int hp) :
	PlaneEnemy(x, y, h, w, s, hp)
{
}


void PlaneEnemy2::initImage()
{
	image.Load(_T("..\\Image\\Enemy2.png"));
	make_transparent(image);
}

#include "stdafx.h"

#include "PlaneEnemy3.h"

CImage PlaneEnemy3::image;


PlaneEnemy3::PlaneEnemy3(int x, int y, int h, int w, int s, int hp) :
	PlaneEnemy(x, y, h, w, s, hp)
{
}


void PlaneEnemy3::initImage()
{
	if (image.Load(_T("..\\Image\\Enemy3.png")) != S_OK)
	{
		AfxMessageBox(_T("Error in loading Enemy3.png"));
	}
	make_transparent(image);
}

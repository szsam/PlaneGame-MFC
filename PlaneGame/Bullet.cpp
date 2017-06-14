#include "stdafx.h"

#include "Bullet.h"

CImage Bullet::image;

Bullet::Bullet(int x, int y, int h, int w, int s) : 
	GameObject(CPoint(x, y), h, w, UP, s)
{
}

void Bullet::initImage()
{
	image.Load(_T("..\\Image\\Bullet.png"));
	make_transparent(image);
}

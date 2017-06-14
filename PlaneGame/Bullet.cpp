#include "stdafx.h"

#include "Bullet.h"

CImage Bullet::image;

Bullet::Bullet(int x, int y, int h, int w, int s) : 
	GameObject(CPoint(x, y), h, w, UP, s)
{
}

void Bullet::draw(CDC *pDC)
{
	if (!image.IsNull())
	{
		image.Draw(pDC->GetSafeHdc(), pos.x, pos.y, width, height);
	}
}

void Bullet::init_image()
{
	image.Load(_T("..\\Image\\Bullet.png"));
}

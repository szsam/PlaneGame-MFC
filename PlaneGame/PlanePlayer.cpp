#include "stdafx.h"

#include "PlanePlayer.h"

// GameObject(CPoint(x, y), UP, 30, 160, 90)
PlanePlayer::PlanePlayer(int x, int y, int h, int w, int s) : 
	GameObject(CPoint(x, y), h, w, UP, s)
{
	image.Load(_T("..\\Image\\PlanePlayer.png"));
}

void PlanePlayer::draw(CDC *pDC)
{
	if (!image.IsNull())
	{
		image.Draw(pDC->GetSafeHdc(), pos.x, pos.y, width, height);
	}
}


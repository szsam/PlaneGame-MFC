#include "stdafx.h"

#include "GameObject.h"

GameObject::GameObject(CPoint p, int h, int w, Dir d, int s) :
	pos(p), dir(d), speed(s), height(h), width(w)
{
	//image.Load(path);
}

//void GameObject::draw(CDC *pDC)
//{
//	if (!image.IsNull())
//	{
//		image.Draw(pDC->GetSafeHdc(), pos.x, pos.y, width, height);
//	}
//}

bool GameObject::move(int cliHeight, int cliWidth)
{
	switch (dir)
	{
		case UP:
			if (pos.y - speed >= 0)
			{
				pos.y -= speed;
				return true;
			}
			else {
				pos.y = 0;
				return false;
			}
			break;
		case LEFT:
			if (pos.x - speed >= 0)
			{
				pos.x -= speed;
				return true;
			}
			else {
				pos.x = 0;
				return false;
			}

			break;
		case DOWN:
			if (pos.y + height + speed <= cliHeight)
			{
				pos.y += speed;
				return true;
			}
			else
			{
				pos.y = cliHeight - height;
				return false;
			}

			break;
		case RIGHT:
			if (pos.x + width + speed <= cliWidth)
			{
				pos.x += speed;
				return true;
			}
			else {
				pos.x = cliWidth - width;
				return false;
			}

			break;
		default:
			break;
	}
	return false;
}

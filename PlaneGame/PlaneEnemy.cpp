#include "stdafx.h"

#include "PlaneEnemy.h"
#include "utility.h"

CImage PlaneEnemy::image;


PlaneEnemy::PlaneEnemy(int x, int y, int h, int w, int s, int hp) :
	GameObject(CPoint(x, y), h, w, DOWN, s), health(hp)
{
}

// ��ȥһ��Ѫ������Ѫ���Դ���0�� �򷵻�true�����򷵻�false
bool PlaneEnemy::decreaseHP()
{
	return --health > 0;
}

void PlaneEnemy::initImage()
{
	image.Load(_T("..\\Image\\Enemy.png"));
	make_transparent(image);
}

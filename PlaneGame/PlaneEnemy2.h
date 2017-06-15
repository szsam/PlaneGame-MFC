#pragma once
#include "PlaneEnemy.h"

class PlaneEnemy2 : public PlaneEnemy
{
	//friend class GameCtrl;
public:
	PlaneEnemy2(int x, int y, int h, int w, int s, int hp);
	const CImage &getImage() const override { return image; }
private:

// static members
public:
	static void initImage();
private:
	static CImage image;
	
};
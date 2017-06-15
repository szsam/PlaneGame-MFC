#pragma once
#include "PlaneEnemy.h"

class PlaneEnemy3 : public PlaneEnemy
{
	// friend class GameCtrl;
public:
	PlaneEnemy3(int x, int y, int h, int w, int s, int hp);
	virtual ~PlaneEnemy3() = default;

	const CImage &getImage() const override { return image; }
private:

// static members
public:
	static void initImage();
private:
	static CImage image;
	
};
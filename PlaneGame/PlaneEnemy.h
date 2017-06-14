#pragma once
#include "GameObject.h"

class PlaneEnemy : public GameObject
{
	friend class GameCtrl;
public:
	PlaneEnemy(int x, int y, int h, int w, int s);
	const CImage &getImage() const override { return image; }

	static void initImage();
private:
	static CImage image;

};
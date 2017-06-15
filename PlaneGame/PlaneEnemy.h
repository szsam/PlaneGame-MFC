#pragma once
#include "GameObject.h"

class PlaneEnemy : public GameObject
{
	//friend class GameCtrl;
public:
	PlaneEnemy(int x, int y, int h, int w, int s, int hp);
	const CImage &getImage() const override { return image; }
	bool decreaseHP();
private:
	int health;

// static members
public:
	static void initImage();
private:
	static CImage image;
	
};
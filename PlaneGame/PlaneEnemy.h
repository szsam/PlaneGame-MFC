#pragma once
#include "GameObject.h"

class PlaneEnemy : public GameObject
{
	friend class GameCtrl;
public:
	PlaneEnemy(int x, int y, int h, int w, int s);
	void draw(CDC *) override;

	static void init_image();
private:
	static CImage image;

};
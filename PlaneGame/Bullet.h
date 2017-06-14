#pragma once
#include "GameObject.h"

class Bullet : GameObject
{
	friend class GameCtrl;
public:
	Bullet(int x, int y, int h, int w, int s);
	void draw(CDC *) override;

	static void init_image();
private:
	static CImage image;
};
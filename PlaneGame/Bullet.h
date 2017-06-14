#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
	friend class GameCtrl;
public:
	Bullet(int x, int y, int h, int w, int s);
	const CImage &getImage() const override { return image; }
	static void initImage();
private:
	static CImage image;
};
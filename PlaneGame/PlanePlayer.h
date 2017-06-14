#pragma once

#include "GameObject.h"

class PlanePlayer : public GameObject
{
	friend class GameCtrl;
public:
	PlanePlayer(int x, int y, int h, int w, int s);
	void draw(CDC *) override;
	void set_dir(Dir d) { dir = d; }
private:
	CImage image;
};
#pragma once

#include "GameObject.h"

class PlanePlayer : public GameObject
{
	//friend class GameCtrl;
public:
	PlanePlayer(int x, int y, int h, int w, int s);
	virtual ~PlanePlayer() = default;

	void setDir(Dir d) { dir = d; }
	const CImage &getImage() const override { return image; }
private:
	CImage image;
};
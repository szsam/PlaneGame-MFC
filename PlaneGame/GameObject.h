#pragma once

#include "utility.h"

class GameObject
{
	friend class GameCtrl;
public:
	bool move(int, int);
	virtual void draw(CDC *) = 0;
	int getHeight() { return height; }
	int getWidth() { return width; }
	//virtual const CImage &getImage() const = 0;
	//virtual void loadImage();
//private:
//	CImage image;

protected:
	// methods
	GameObject(CPoint p, int h, int w, Dir d, int s);

	// attributes
	//int x, y;
	CPoint pos;
	int height, width;	
	Dir dir;
	int speed;
};
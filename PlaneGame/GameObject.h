#pragma once

#include "utility.h"

class GameObject
{
	//friend class GameCtrl;
public:
	GameObject(CPoint p, int h, int w, Dir d, int s);
	virtual ~GameObject() = default;

	bool move(int, int);
	//virtual void draw(CDC *) = 0;
	int getHeight() const { return height; }
	int getWidth() const { return width; }
	int getX() const { return pos.x; }
	int getY() const { return pos.y; }
	virtual const CImage &getImage() const = 0;
	//virtual void loadImage();
//private:
//	CImage image;

protected:
	// methods
	

	// attributes
	//int x, y;
	CPoint pos;
	int height, width;	
	Dir dir;
	int speed;
};
#ifndef __SHRAPNEL_H__
#define __SHRAPNEL_H__

#include "Gameobject.h"


class Shrapnel : public Gameobject {
private:
	SDL_Surface *mBigbullet;
	
	float mSpeedX;
	float mSpeedY;

public:
	Shrapnel(float x, float y, float sx, float sy);
	~Shrapnel();

	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

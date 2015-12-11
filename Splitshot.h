#ifndef __SPLITSHOT_H__
#define __SPLITSHOT_H__

#include "Gameobject.h"


class Splitshot : public Gameobject {
private:
	SDL_Surface *mBigbullet;
	
	float mSpeedX;
	float mSpeedY;
	float mShipX;
	float mShipY;

public:
	Splitshot(float x, float y, float xs, float shipx, float shipy);
	~Splitshot();

	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
	void Detonate();
};

#endif

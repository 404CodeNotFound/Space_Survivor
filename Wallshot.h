#ifndef __WALLSHOT_H__
#define __WALLSHOT_H__

#include "Gameobject.h"


class Wallshot : public Gameobject {
private:
	SDL_Surface *mBigbullet;
	
	float mSpeedX;
	float mSpeedY;

public:
	Wallshot(float x, float y, float sx, float sy);
	~Wallshot();

	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

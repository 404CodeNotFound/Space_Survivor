#ifndef __PROJECTILE_BOSS_H__
#define __PROJECTILE_BOSS_H__

#include "Gameobject.h"

//struct SDL_Surface;

class ProjectileBoss : public Gameobject {
private:
	SDL_Surface *mBigbullet;
	
	float mSpeedX;
	float mSpeedY;

public:
	ProjectileBoss(float x, float y, float sx, float sy);
	~ProjectileBoss();
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

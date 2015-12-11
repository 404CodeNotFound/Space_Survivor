#ifndef __PROJECTILE_SPACESHIP_H__
#define __PROJECTILE_SPACESHIP_H__

#include "Gameobject.h"


class ProjectileSpaceship : public Gameobject {
private:
	SDL_Surface *mBigbullet;
	
	float mSpeedX;
	float mSpeedY;


public:
	ProjectileSpaceship(float x, float y, float sy);
	~ProjectileSpaceship();

	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif


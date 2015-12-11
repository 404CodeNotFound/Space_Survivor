#ifndef __PROJECTILE_ENEMY_H__
#define __PROJECTILE_ENEMY_H__

#include "Gameobject.h"


class ProjectileEnemy : public Gameobject {
private:
	SDL_Surface *mBigbullet;
	
	float mSpeedX;
	float mSpeedY;

public:
	ProjectileEnemy(float x, float y, float sx, float sy);
	~ProjectileEnemy();

	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

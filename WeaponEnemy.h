#ifndef __WEAPONENEMY_H__
#define __WEAPONENEMY_H__

#include "Enemy.h"
#include "Res.h"


class WeaponEnemy : public Enemy {
private:
	SDL_Surface *mUfoSurface;

	float mSpeedX;
	float mSpeedY;

	int counter;
	int mFirerate;
	int mFiredelay;
	int health;



public:
	WeaponEnemy(float y);
	~WeaponEnemy();

	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

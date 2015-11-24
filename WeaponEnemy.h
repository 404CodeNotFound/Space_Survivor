#ifndef __WEAPONENEMY_H__
#define __WEAPONENEMY_H__

#include "Enemy.h"
#include "Res.h"

struct SDL_Surface;

class WeaponEnemy : public Enemy {
private:
	// Ansiktsbild.
	SDL_Surface *mUfoSurface;

	float mSpeedX;
	float mSpeedY;

	//int w;
	//int h;
	int counter;
	int mFirerate;
	int mFiredelay;
	int health;



public:
	WeaponEnemy(float y) : Enemy(y), mUfoSurface{ UFO_SURFACE }, mSpeedX{ -1.0 }, mSpeedY{ -1.0}, health{ 3 } {}
	~WeaponEnemy();

	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobejct);
};

#endif


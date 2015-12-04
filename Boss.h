#ifndef __BOSS_H__
#define __BOSS_H__

#include "Enemy.h"
#include "Res.h"

//struct SDL_Surface;

class Boss : public Enemy {
private:
	// Ansiktsbild.
	SDL_Surface *mBossSurface;

	float mSpeedX;
	float mSpeedY;

	//int w;
	//int h;
	int counter;
	int mFirerate;
	int mFiredelay;
	int health;
	int mHole;

	bool mWallmode;
	bool mWidemode;
	bool mSplitmode;



public:
	//WeaponEnemy(float y) : Enemy(y), mUfoSurface{ UFO_SURFACE }, mSpeedX{ -1.0 }, mSpeedY{ -1.0}, health{ 3 } {}
	Boss(float y);
	~Boss();

	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Fire();
	void FireWall();
	void FireSplit();
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

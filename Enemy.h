#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Gameobject.h"

//struct SDL_Surface;

class Enemy : public Gameobject {
private:
	SDL_Surface *mFaceSurface;

	float mSpeedX;
	float mSpeedY;
	
	int mFirerate; 
	int mFiredelay; 
	int health;



public:
	Enemy(float y);
	~Enemy();

	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobejct);
};

#endif


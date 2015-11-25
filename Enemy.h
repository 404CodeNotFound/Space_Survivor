#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Gameobject.h"

class Enemy : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mFaceSurface;

	float mSpeedX;
	float mSpeedY;
	
	//int w;
	//int h;
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
	virtual void Overlap(Gameobject * gameobject);
};

#endif


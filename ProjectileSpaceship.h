#ifndef __PROJECTILE_SPACESHIP_H__
#define __PROJECTILE_SPACESHIP_H__

#include "Gameobject.h"

class ProjectileSpaceship : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mBigbullet;
	//SDL_Surface *mBGSurface;

	// Position för ansikte.
	//float mX;
	//float mY;
	// Hastighet för ansikte.
	//int w;
	//int h;
	// Position för bakgrund.
	//float mBGX;


public:
	ProjectileSpaceship(float x, float y);
	~ProjectileSpaceship();
	virtual void Update();
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif


#ifndef __PROJECTILE_ENEMY_H__
#define __PROJECTILE_ENEMY_H__

#include "Gameobject.h"

class ProjectileEnemy : public Gameobject {
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
	ProjectileEnemy(float x, float y);
	~ProjectileEnemy();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif


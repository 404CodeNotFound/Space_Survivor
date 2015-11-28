#ifndef __PROJECTILE_ENEMY_H__
#define __PROJECTILE_ENEMY_H__

#include "Gameobject.h"

class ProjectileEnemy : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mBigbullet;
	//SDL_Surface *mBGSurface;

	// Position f�r ansikte.
	//float mX;
	//float mY;
	// Hastighet f�r ansikte.
	//int w;
	//int h;
	// Position f�r bakgrund.
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


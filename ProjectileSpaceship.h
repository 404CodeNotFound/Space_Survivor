#ifndef __PROJECTILE_SPACESHIP_H__
#define __PROJECTILE_SPACESHIP_H__

#include "Gameobject.h"

class ProjectileSpaceship : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mBigbullet;
	//SDL_Surface *mBGSurface;

	// Position f�r ansikte.
	//float mX;
	//float mY;
	// Hastighet f�r ansikte.
	float mSpeedX;
	float mSpeedY;
	//int w;
	//int h;
	// Position f�r bakgrund.
	//float mBGX;


public:
	ProjectileSpaceship(float x, float y);
	~ProjectileSpaceship();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif


#ifndef __PROJECTILE_BOSS_H__
#define __PROJECTILE_BOSS_H__

#include "Gameobject.h"

//struct SDL_Surface;

class ProjectileBoss : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mBigbullet;
	//SDL_Surface *mBGSurface;

	// Position för ansikte.
	//float mX;
	//float mY;
	// Hastighet för ansikte.
	float mSpeedX;
	float mSpeedY;
	//int w;
	//int h;
	// Position för bakgrund.
	//float mBGX;


public:
	ProjectileBoss(float x, float y, float sx, float sy);
	~ProjectileBoss();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Gameobject.h"

struct SDL_Surface;

class Enemy : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mFaceSurface;
	SDL_Surface *mBGSurface;

	// Position för ansikte.
	float mX;
	float mY;
	// Hastighet för ansikte.
	float mSpeedX;
	float mSpeedY;
	// Position för bakgrund.
	//float mBGX;


public:
	Enemy();
	~Enemy();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
};

#endif


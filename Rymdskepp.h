#ifndef __RYMD_SKEPP_H__
#define __RYMD_SKEPP_H__

#include "Gameobject.h"

struct SDL_Surface;

class Rymdskepp : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mFaceSurface;
	SDL_Surface *mBGSurface;

	// Position f�r ansikte.
	float mX;
	float mY;
	// Hastighet f�r ansikte.
	float mSpeedX;
	float mSpeedY;
	// Position f�r bakgrund.
	//float mBGX;


public:
	Rymdskepp();
	~Rymdskepp();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
};

#endif


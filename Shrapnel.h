#ifndef __SHRAPNEL_H__
#define __SHRAPNEL_H__

#include "Gameobject.h"

//struct SDL_Surface;

class Shrapnel : public Gameobject {
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
	Shrapnel(float x, float y, float sx, float sy);
	~Shrapnel();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

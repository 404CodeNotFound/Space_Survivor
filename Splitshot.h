#ifndef __SPLITSHOT_H__
#define __SPLITSHOT_H__

#include "Gameobject.h"

//struct SDL_Surface;

class Splitshot : public Gameobject {
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
	float mShipX;
	float mShipY;
	//int w;
	//int h;
	// Position för bakgrund.
	//float mBGX;


public:
	Splitshot(float x, float y, float xs, float shipx, float shipy);
	~Splitshot();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
	void Detonate();
};

#endif

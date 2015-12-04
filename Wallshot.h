#ifndef __WALLSHOT_H__
#define __WALLSHOT_H__

#include "Gameobject.h"

//struct SDL_Surface;

class Wallshot : public Gameobject {
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
	Wallshot(float x, float y, float sx, float sy);
	~Wallshot();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeed(float SpeedX, float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobejct);
};

#endif

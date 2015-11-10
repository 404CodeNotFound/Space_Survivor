#ifndef __TEST_SCREEN_H__
#define __TEST_SCREEN_H__

#include "Screen.h"

struct SDL_Surface;

class TestScreen : public Screen {
private:
	// Ansiktsbild.
	SDL_Surface *mFaceSurface;
	SDL_Surface *mBGSurface;

	// Position för ansikte.
	int mFaceX;
	int mFaceY;
	// Hastighet för ansikte.
	int mFaceSpeedX;
	int mFaceSpeedY;
	// Position för bakgrund.
	float mBGX;


public:
	TestScreen();
	~TestScreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
};

#endif


#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "Screen.h"

class Gameobject;
struct SDL_Surface;

class Gamescreen : public Screen {
private:
	// Ansiktsbild.
	//SDL_Surface *mFaceSurface;
	SDL_Surface *mBGSurface;

	// Position för ansikte.
	//int mFaceX;
	//int mFaceY;
	// Hastighet för ansikte.
	//int mFaceSpeedX;
	//int mFaceSpeedY;
	// Position för bakgrund.
	float mBGX;

	//pekare till rymdskepp
	Gameobject *mGameobject;
	Gameobject *mEnemy;

public:
	Gamescreen();
	~Gamescreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	void SetGameobject(Gameobject *gameobject);
	
};

#endif


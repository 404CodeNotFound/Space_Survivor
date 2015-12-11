#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "Screen.h"


struct SDL_Surface;

class Gameover : public Screen {
private:
	SDL_Surface *mGameoverSurface;

	float mBGX;
	int counter;
	int mPoints;


public:
	Gameover(int points);
	~Gameover();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	
};

#endif


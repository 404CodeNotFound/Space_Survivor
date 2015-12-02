#ifndef __INSTRUCTION_SCREEN_H__
#define __INSTRUCTION_SCREEN_H__

#include "Screen.h"
#include "SDL.h"

class Instructions : public Screen {

public:
	Instructions();
	~Instructions();


	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Draw(Graphics *g);
	virtual void Update();

	void KeyEvent();

private:
	SDL_Surface *mInstrSurface;
	SDL_Surface *mButton;

	float mBGX;
	float mButtonX;
	float mButtonY;

	bool mReturn;
	bool mPressed;

};

#endif
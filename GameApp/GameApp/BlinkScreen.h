#ifndef __BLINK_SCREEN_H__
#define __BLINK_SCREEN_H__

#include "Screen.h"

class BlinkScreen : public Screen {
private:
	int mCounter;
	int mRed;
	int mGreen;
	int mBlue;

public:
	BlinkScreen();
	~BlinkScreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
};

#endif


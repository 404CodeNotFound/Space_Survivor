#ifndef __START_SCREEN_H__
#define __START_SCREEN_H__

#include "Screen.h"
#include "SDL.h"
#include "GameApp.h"

//struct SDL_Surface;

class Startscreen : public Screen {
public:
	Startscreen();
	~Startscreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Draw(Graphics *g);
	virtual void Update();

	void KeyEvent(); // Check if any key is pressed

private:
	SDL_Surface *mMenuSurface;
	//SDL_Surface *mHighscrSurface;
	SDL_Surface *mButtonPointer;
	SDL_Surface *mButton;
	SDL_Surface *mButton1;
	SDL_Surface *mButton2;
	SDL_Surface *mButton3;
	SDL_Surface *mButton4;

	int mX;
	int mY;
	int width;
	int height;
	int mPoints;

	float mBGX;
	float mBPX;
	float mBPY;

	// Position for "button pointer"
	float mBuX;
	float mBuY1;
	float mBuY2;
	float mBuY3;
	float mBuY4;

	bool mUp;
	bool mDown;
	bool mReturn;

	bool mGame;
	bool mHighScr;
	bool mInstr;
	bool mQuit;

};

#endif
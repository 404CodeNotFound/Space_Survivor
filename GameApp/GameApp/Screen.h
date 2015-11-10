#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "SDL.h"

class GameApp;
class Graphics;

class Screen {
private:
	GameApp *mGameApp;

public:
	Screen() {};
	virtual ~Screen() {};

	virtual void KeyDown(SDL_Keycode keyCode) {}
	virtual void KeyUp(SDL_Keycode keyCode) {}

	virtual void Update() {}
	virtual void Draw(Graphics *g) {}

	void SetGameApp(GameApp *gameApp) {mGameApp = gameApp;}
	GameApp *GameApp() {return mGameApp;}

};

#endif
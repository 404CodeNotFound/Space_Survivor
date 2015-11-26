#ifndef __GAME_APP_H__
#define __GAME_APP_H__

#include "SDL.h"

class Screen;
class Graphics;

class GameApp {
private:
	SDL_Window *mWindow;
	SDL_Surface *mWindowSurface;

	// Fönsterattribut.
	int mWidth;
	int mHeight;
	const char *mTitle;

	// Flagga för om spelet skall avslutas.
	bool mShouldTerminate;

	int mUpdatesPerSecond;
	int mMaxUpdates;

	Screen *mScreen;
	Screen *mNewScreen;

	Graphics *mGraphics;

protected:
	void SetSize(int width, int height);
	void SetTitle(const char *title);

public:
	GameApp();
	virtual ~GameApp();

	void SetScreen(Screen *screen);

	bool Run();

private:
	
	int GetUpdateFrame();
};

#endif
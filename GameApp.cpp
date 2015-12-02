#include "GameApp.h"
#include "Screen.h"
#include "Graphics.h"
#include "SDL.h"
//#include "SDL_ttf.h"
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
GameApp::GameApp() {
	mWindow = 0;
	mWindowSurface = 0;
	//mWidth = 640;
	//mWidth = 1024;
	mWidth = 800;
	//mHeight = 480;
	//mHeight = 768;
	mHeight = 600;
	mTitle = "GameApp";
	mShouldTerminate = false;
	mScreen = 0;
	mNewScreen = 0;
	mGraphics = 0;

	mUpdatesPerSecond = 100;
	mMaxUpdates = 6;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void GameApp::SetSize(int width, int height) {
	mWidth = width;
	mHeight = height;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void GameApp::SetTitle(const char *title) {
	mTitle = title;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
GameApp::~GameApp() {
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
bool GameApp::Run() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	
	mWindow = SDL_CreateWindow(mTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN);
	if (mWindow == 0) {
		SDL_Quit();
		return false;
	}
	else {
		mWindowSurface = SDL_GetWindowSurface(mWindow);
		mGraphics = new Graphics(mWindowSurface, mWidth, mHeight);
	}

	int currentUpdate = GetUpdateFrame();
	int nextUpdate = currentUpdate;

	while (!mShouldTerminate) {
		// Vänta.
		while (nextUpdate == currentUpdate) {
			nextUpdate = GetUpdateFrame();
            SDL_Delay(1);
        }
		// Uppdatera.
        int frames = nextUpdate - currentUpdate;
		if (frames > mMaxUpdates) frames = mMaxUpdates;
		while (frames--) {
			if (mNewScreen) {
				delete mScreen;
				mScreen = mNewScreen;
				mNewScreen = 0;
			}
			if (mScreen) {
				mScreen->Update();
			}
		}
		currentUpdate = nextUpdate;

		// Events ligger i en kö.
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0 ) {
			if (e.type == SDL_QUIT ) {
				mShouldTerminate = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				if (mScreen && !mNewScreen) {
					mScreen->KeyDown(e.key.keysym.sym);
				}
			}
			else if (e.type == SDL_KEYUP) {
				if (mScreen && !mNewScreen) {
					mScreen->KeyUp(e.key.keysym.sym);
				}
			}
		}	

		// Rita.
		if (mScreen && !mNewScreen) {
			mScreen->Draw(mGraphics);
		}
		SDL_UpdateWindowSurface(mWindow);
	}

	delete mScreen;
	delete mNewScreen;
	delete mGraphics;

	SDL_FreeSurface(mWindowSurface);
	mWindowSurface = 0;
	SDL_DestroyWindow(mWindow);
	mWindow = 0;
	SDL_Quit();
	//TTF_Quit();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void GameApp::SetScreen(Screen *screen) {
	if (screen) screen->SetGameApp(this);
	if (mScreen == 0) {
		mScreen = screen;
	}
	else {
		mNewScreen = screen;
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
int GameApp::GetUpdateFrame() {
	return (int)(SDL_GetTicks()/(1000/mUpdatesPerSecond));
}

////////////////////
void GameApp::SetTerminate() {
	mShouldTerminate = true;
}
/////////////////////////
void GameApp::QuitGame() {
	SetTerminate();
}

#include "Startscreen.h"
#include "Res.h"
#include "Graphics.h"
#include "audiere.h"
#include "GameApp.h"
#include "Gamescreen.h"
#include "Highscore.h"
#include "Instructions.h"

Startscreen::Startscreen() {
	sStartmusic->play();
	sStartmusic->setRepeat(true);
	mMenuSurface = START_SURFACE;

	mButton1 = GAME_BUTTON_SURFACE;
	mButton2 = INSTR_BUTTON_SURFACE;
	mButton3 = HIGH_SCORE_BUTTON_SURFACE;
	mButton4 = QUIT_BUTTON_SURFACE;
	mButtonPointer = SHIP_SURFACE;
	mBGX = 0.0f;
	mBPX = 231.0f;
	mBPY = 177.0f;
	
	mX = 301.0f;
	mY = 159.0f; 

	mBuX = 301.0f;
	mBuY1 = 159.0f;
	mBuY2 = 260.0f;
	mBuY3 = 366.0f;
	mBuY4 = 477.0f;

	mUp = false;
	mDown = false;
	mReturn = false;
	// Pressed button images
	mGame = true;
	mHighScr = false;
	mInstr = false;
	mQuit = false;

	mPoints = 1;  //satt till 0??
}

Startscreen::~Startscreen() {
	sStartmusic->stop();
	printf("Startscreen destroyd \n");
}

void Startscreen::KeyEvent() {
	SDL_Event keyEvent;
	while (SDL_PollEvent(&keyEvent) != 0) {
		if (keyEvent.type == SDL_KEYDOWN) {
			KeyDown(keyEvent.key.keysym.sym);
		}

		else if (keyEvent.type == SDL_KEYUP) {
			KeyUp(keyEvent.key.keysym.sym);
		}

	}
}

void Startscreen::Draw(Graphics *g) {
	g->DrawImage(mMenuSurface, (int)mBGX, 0);
	g->DrawImage(SHIP_SURFACE, (int)mBPX, mBPY);

	if (mGame) {
		g->DrawImage(GAME_BUTTON_SURFACE, (int)mBuX, mBuY1);
	}
	
	else if (mInstr) {
		g->DrawImage(INSTR_BUTTON_SURFACE, (int)mBuX, mBuY2);
	}

	else if (mHighScr) {
		g->DrawImage(HIGH_SCORE_BUTTON_SURFACE, (int)mBuX-1, mBuY3);
	}

	else if (mQuit) {
		g->DrawImage(QUIT_BUTTON_SURFACE, (int)mBuX, mBuY4);
	}
}

void Startscreen::KeyDown(SDL_Keycode keyCode) {
	if (keyCode == SDLK_DOWN) {
		mDown = true;
	}

	else if (keyCode == SDLK_UP){
		mUp = true;
	}

	else if (keyCode == SDLK_RETURN) {
		mReturn = true;
	}
}

void Startscreen::KeyUp(SDL_Keycode keyCode) {
	if (keyCode == SDLK_DOWN) {
		if (mY == mBuY1) {
			mDown = false;
			mY = mBuY2;
			mBPY = (mBuY2 + 5);
			mGame = false;
			mInstr = true;
		}

		else if (mY == mBuY2) {
			mDown = false;
			mY = mBuY3;
			mBPY = (mBuY3 + 10);
			mInstr = false;
			mHighScr = true;
		}

		else if (mY == mBuY3) {
			mDown = false;
			mY = mBuY4;
			mBPY = (mBuY4 + 20);
			mHighScr = false;
			mQuit = true;
		}

		else if (mY == mBuY4) {
			mDown = false;
			mY = mY;
			mQuit = true;
		}
	}

	if (keyCode == SDLK_UP) {
		if (mY == mBuY1) {
			mUp = false;
			mY = mY;
			mGame = true;
		}

		else if (mY == mBuY2) {
			mUp = false;
			mY = mBuY1;
			mBPY = (mBuY1 + 25);
			mGame = true;
		}

		else if (mY == mBuY3) {
			mUp = false;
			mY = mBuY2;
			mBPY = (mBuY2 + 10);
			mInstr = true;
		}

		else if (mY == mBuY4) {
			mUp = false;
			mY = mBuY3;
			mBPY = (mBuY3 + 15);
			mHighScr = true;
		}
	}

	if (keyCode == SDLK_RETURN) {
		mReturn = false;
	}
}

void Startscreen::Update() {
	if (mReturn) {
		if (mY == mBuY1) {
			GameApp()->SetScreen(new Gamescreen());
		}

		else if (mY == mBuY2) {
			GameApp()->SetScreen(new Instructions());
		}

		else if (mY == mBuY3) {
			GameApp()->SetScreen(new Highscore(mPoints));
		}

		else if (mY == mBuY4) {
			GameApp()->QuitGame();
		}
	}
}
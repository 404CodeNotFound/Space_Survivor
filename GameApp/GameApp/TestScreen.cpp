#include "TestScreen.h"
#include "BlinkScreen.h"
#include "GameApp.h"
#include "Graphics.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
TestScreen::TestScreen() {
	// L�s in en bild av ett ansikte.
	mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));

	mBGSurface = SDL_LoadBMP("assets/background.bmp");


	// Ansiktets position och hastighet.
	mFaceX = 100;
	mFaceY = 100;
	mFaceSpeedX = 0;
	mFaceSpeedY = 0;

	mBGX = 0.0f;


}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
TestScreen::~TestScreen() {
	// Frig�r bild.
	SDL_FreeSurface(mFaceSurface);
	SDL_FreeSurface(mBGSurface);
	printf("Testscreen destroyed\n");
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void TestScreen::KeyDown(SDL_Keycode keyCode) {
	// S�tt hastighet f�r ansiktet.
	if (keyCode == SDLK_LEFT) {
		mFaceSpeedX = -10;
	}
	else if (keyCode == SDLK_RIGHT) {
		mFaceSpeedX = 10;
	}
	else if (keyCode == SDLK_UP) {
		mFaceSpeedY = -10;
	}
	else if (keyCode == SDLK_DOWN) {
		mFaceSpeedY = 10;
	}
	else if (keyCode == SDLK_ESCAPE) {
		GameApp()->SetScreen(new BlinkScreen());
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void TestScreen::KeyUp(SDL_Keycode keyCode) {
	if (keyCode == SDLK_LEFT || keyCode == SDLK_RIGHT) {
		mFaceSpeedX = 0;
	}
	else if (keyCode == SDLK_UP || keyCode == SDLK_DOWN) {
		mFaceSpeedY = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Anropas 100 g�nger per sekund. Utf�r all logik h�r. 
////////////////////////////////////////////////////////////////////////////////
void TestScreen::Update() {
	// Flytta ansiktet.
	mFaceX += mFaceSpeedX;
	mFaceY += mFaceSpeedY;

	mBGX = mBGX - 5.5f;
	if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utf�r all utritning h�r.
////////////////////////////////////////////////////////////////////////////////
void TestScreen::Draw(Graphics *g) {
	// Rensa sk�rmen.
	//g->Clear(RGB(255, 255, 255));
	g->DrawImage(mBGSurface, (int)mBGX, 0);
	g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	g->DrawImage(mFaceSurface, mFaceX, mFaceY);
}

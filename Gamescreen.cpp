#include "Gamescreen.h"
#include "BlinkScreen.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Rymdskepp.h"
#include "Res.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gamescreen::Gamescreen() {

	mGameobject = 0;	

	// Läs in en bild av ett ansikte.
	//mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	//SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));

	//Läs in bakgrundsbild

	//mBGSurface = SDL_LoadBMP("assets/background.bmp");
	mBGSurface = BG_SURFACE;


	// Ansiktets position och hastighet.
	//mFaceX = 100;
	//mFaceY = 100;
	//mFaceSpeedX = 0;
	//mFaceSpeedY = 0;

	//Bakgrundens position

	mBGX = 0.0f;

	//skapa rymdskepp

	SetGameobject(new Rymdskepp());


}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gamescreen::~Gamescreen() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	printf("Gamescreen destroyed\n");
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::KeyDown(SDL_Keycode keyCode) {
	// Sätt hastighet för ansiktet.
	if (keyCode == SDLK_LEFT) {
		//mFaceSpeedX = -1;
		mGameobject->SetSpeed(-1.0, 0.0);
	}
	else if (keyCode == SDLK_RIGHT) {
		//mFaceSpeedX = 1;
		mGameobject->SetSpeed(1.0, 0.0);
	}
	else if (keyCode == SDLK_UP) {
		//mFaceSpeedY = -1;
		mGameobject->SetSpeed(0.0, -1.0);
	}
	else if (keyCode == SDLK_DOWN) {
		//mFaceSpeedY = 1;
		mGameobject->SetSpeed(0.0, 1.0);
	}
	else if (keyCode == SDLK_ESCAPE) {
		GameApp()->SetScreen(new BlinkScreen());
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::KeyUp(SDL_Keycode keyCode) {
	if (keyCode == SDLK_LEFT || keyCode == SDLK_RIGHT) {
		//mFaceSpeedX = 0;
		mGameobject->SetSpeed(0.0, 0.0);
	}
	else if (keyCode == SDLK_UP || keyCode == SDLK_DOWN) {
		//mFaceSpeedY = 0;
		mGameobject->SetSpeed(0.0, 0.0);
	}
}

////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::Update() {
	// Flytta ansiktet.
	//mFaceX += mFaceSpeedX;
	//mFaceY += mFaceSpeedY;

	mBGX = mBGX - 3.0f;
	if (mBGX < -640.0) mBGX += 640.0;

	mGameobject->Update();
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::Draw(Graphics *g) {
	// Rensa skärmen.
	//g->Clear(RGB(255, 255, 255));
	g->DrawImage(mBGSurface, (int)mBGX, 0);
	g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	//g->DrawImage(mFaceSurface, mFaceX, mFaceY);
	mGameobject->Draw(g);


}
///////////////////////////////
void Gamescreen::SetGameobject(Gameobject *gameobject) {
	if (gameobject) gameobject->SetGamescreen(this);
	if (mGameobject == 0) {
		mGameobject = gameobject;
	}
/*	else {
		mNewScreen = screen;
	}*/
}
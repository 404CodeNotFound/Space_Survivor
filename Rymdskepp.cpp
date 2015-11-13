#include "Rymdskepp.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include <stdio.h>
#include <math.h>
#include "Screen.h"
#include "Gamescreen.h"


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::Rymdskepp() {
	// Läs in en bild av ett ansikte.
	//mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	//SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));
	mFaceSurface = FACE_SURFACE;

	//mBGSurface = SDL_LoadBMP("assets/background.bmp");


	// Ansiktets position och hastighet.
	mX = 100;
	mY = 100;
	mSpeedX = 0;
	mSpeedY = 0;

	//mBGX = 0.0f;

	w = mFaceSurface->w;
	printf("bredd = %d\n", w);
	h = mFaceSurface->h;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::~Rymdskepp() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	printf("Testscreen destroyed\n");
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Rymdskepp::Update() {
	// Flytta ansiktet.
	mX += mSpeedX;
	if (mX < 0)
		mX = 0;
	else if (mX > (640.0 - w))
		mX = 640.0 - w;
	mY += mSpeedY;
	if (mY < 0)
		mY = 0;
	else if (mY > 480.0 - h)
		mY = 480.0 - h;

	if (mFiredelay > 0)
		mFiredelay--;
	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Rymdskepp::Draw(Graphics *g) {
	// Rensa skärmen.
	//g->Clear(RGB(255, 255, 255));
	//g->DrawImage(mBGSurface, (int)mBGX, 0);
	//g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	g->DrawImage(mFaceSurface, mX, mY);


}
////////////////////////////////7
void Rymdskepp::SetSpeed(float SpeedX, float SpeedY){
	mSpeedX = SpeedX;
	mSpeedY = SpeedY;
}


void Rymdskepp::Fire()
{
	if (mFiredelay == 0)
	{
		mGamescreen->GenerateProjectileSpaceship(mX, mY);
		mFiredelay = mFirerate;
	}
}

void Rymdskepp::Overlap(Gameobject *gameobject)
{
	
}




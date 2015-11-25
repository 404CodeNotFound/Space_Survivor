#include "Rymdskepp.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::Rymdskepp() {
	// Läs in en bild av ett ansikte.
	//mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	//SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));
	mShipSurface = SHIP_SURFACE;

	//mBGSurface = SDL_LoadBMP("assets/background.bmp");


	// Ansiktets position och hastighet.
	//mX = 100;
	//mY = 100;
	//mX = 160;
	//mY = 160;
	mX = 125;
	mY = 125;
	mSpeedX = 0;
	mSpeedY = 0;

	//mBGX = 0.0f;

	w = mShipSurface->w;
	printf("bredd = %d\n", w);
	h = mShipSurface->h;
	mFirerate = 20; 
	mFiredelay = 0; 
	mHealth = 100;
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
	else if (mX > (800.0 - w))
		mX = 800.0 - w;
	/*else if (mX > (1024.0 - w))
		mX = 1024.0 - w;*/
	mY += mSpeedY;
	if (mY < 40.0)
		mY = 40.0;
	else if (mY > 600.0 - h)
		mY = 600.0 - h;
	/*else if (mY > 768.0 - h)
		mY = 768.0 - h;*/
	if (mFiredelay > 0)
		mFiredelay--;
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
	g->DrawImage(mShipSurface, mX, mY);


}
////////////////////////////////7
void Rymdskepp::SetSpeedX(float SpeedX){
	mSpeedX = SpeedX;
}
////////////////////////////
void Rymdskepp::SetSpeedY(float SpeedY){
	mSpeedY = SpeedY;
}
/////////////////////////7
void Rymdskepp::Fire() { 
	if (mFiredelay == 0) { 
		mGamescreen->GenerateProjectileSpaceship(mX, mY); 
		mFiredelay = mFirerate; 
 	} 
 } 
///////////////////////
void Rymdskepp::Overlap(Gameobject *gameobject){
	if (!shield)
	{
		mHealth = mHealth - 10;
		printf("Livnivå=%d\n", mHealth);
	}
	if (mHealth <= 0)
		mGamescreen->KillSpaceship();
}

///////////////////////
int Rymdskepp::GetHealth() {
	return mHealth;
}
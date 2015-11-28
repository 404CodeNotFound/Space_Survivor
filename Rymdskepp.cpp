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
	
	mShipSurface = SHIP_SURFACE;

	
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
	h = mShipSurface->h;
	mFirerate = 20; 
	mFiredelay = 0; 
	mHealth = 100;
	shield = false;
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
	if (!shield) {
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
//////////////
void Rymdskepp::SetHealth(int l) {
	mHealth = mHealth + l;
}
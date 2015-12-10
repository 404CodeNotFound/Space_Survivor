#include "Splitshot.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Gamescreen.h"
#include "Res.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Splitshot::Splitshot(float x, float y, float xs, float shipx, float shipy) {
	// Läs in en bild av ett ansikte.
	//mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	//SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));
	mBigbullet = ROUND_BULLET;
	mShipX = shipx;
	mShipY = shipy;
	//mBGSurface = SDL_LoadBMP("assets/background.bmp");

	float temph = x - shipx;
	float tempw = shipy - y;

	mX = x;
	mY = y + 40;
	mSpeedX = xs;
	mSpeedY = (tempw / temph) * -xs;

	w = mBigbullet->w;
	h = mBigbullet->h;
	//printf("bredd = %d\n", w);

	//mBGX = 0.0f;


}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Splitshot::~Splitshot() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	//printf("Herobullet destroyed\n");
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
void Splitshot::Update() {
	// Flytta ansiktet.
	mX += mSpeedX;
	mY += mSpeedY;
	/*if() {
		mGamescreen->KillObject(this);
	}*/
	if (mX <= mShipX)
	{
		Detonate();
	}
	if (mX<0) {
		mGamescreen->KillObject(this);
	}

	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Splitshot::Draw(Graphics *g) {
	// Rensa skärmen.
	//g->Clear(RGB(255, 255, 255));
	//g->DrawImage(mBGSurface, (int)mBGX, 0);
	//g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	g->DrawImage(mBigbullet, mX, mY);


}
////////////////////////////////7
void Splitshot::SetSpeed(float SpeedX, float SpeedY){
	mSpeedX = SpeedX;
	mSpeedY = SpeedY;
}
////////////////////////////////////
void Splitshot::Overlap(Gameobject *gameobject) {
	mGamescreen->KillObject(this);
	//printf("Projektil dödad pga kollision!\n");
}
void Splitshot::Detonate()
{
	mGamescreen->GenerateShrapnel(mX, mY, -1.5, 0);
	mGamescreen->GenerateShrapnel(mX, mY, 1.5, 0);
	mGamescreen->GenerateShrapnel(mX, mY, 0, -1.5);
	mGamescreen->GenerateShrapnel(mX, mY, 0, 1.5);
	mGamescreen->GenerateShrapnel(mX, mY, 0.75, 0.75);
	mGamescreen->GenerateShrapnel(mX, mY, -0.75, 0.75);
	mGamescreen->GenerateShrapnel(mX, mY, 0.75, -0.75);
	mGamescreen->GenerateShrapnel(mX, mY, -0.75, -0.75);

	mGamescreen->KillObject(this);
	
}
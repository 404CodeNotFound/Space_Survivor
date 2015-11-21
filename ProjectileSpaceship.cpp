#include "ProjectileSpaceship.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Gamescreen.h"
#include "Res.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
ProjectileSpaceship::ProjectileSpaceship(float x, float y) {
	// Läs in en bild av ett ansikte.
	//mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	//SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));
	mBigbullet = BIGBULLET_SURFACE;

	//mBGSurface = SDL_LoadBMP("assets/background.bmp");


	// Ansiktets position och hastighet.
	mX = x + 60;
	mY = y + 30;
	mSpeedX = 3.0;
	mSpeedY = 0;

	w = mBigbullet->w;
	h = mBigbullet->h;
	//printf("bredd = %d\n", w);

	//mBGX = 0.0f;


}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
ProjectileSpaceship::~ProjectileSpaceship() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	printf("Herobullet destroyed\n");
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
void ProjectileSpaceship::Update() {
	// Flytta ansiktet.
	mX += mSpeedX;
	mY += mSpeedY;
	/*if(mX>640) {
		mGamescreen->KillObject(this);
	}*/
	if(mX>1024) {
		mGamescreen->KillObject(this);
	}

	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void ProjectileSpaceship::Draw(Graphics *g) {
	// Rensa skärmen.
	//g->Clear(RGB(255, 255, 255));
	//g->DrawImage(mBGSurface, (int)mBGX, 0);
	//g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	g->DrawImage(mBigbullet, mX, mY);


}
////////////////////////////////7
void ProjectileSpaceship::SetSpeed(float SpeedX, float SpeedY){
	mSpeedX = SpeedX;
	mSpeedY = SpeedY;
}
////////////////////////////////////
void ProjectileSpaceship::Overlap(Gameobject *gameobject) {
	mGamescreen->KillObject(this);
	printf("Projektil dödad pga kollision!\n");
}
#include "ProjectileEnemy.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Gamescreen.h"
#include "Res.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
ProjectileEnemy::ProjectileEnemy(float x, float y) : Gameobject(x,y,-3.0,0) {

	mBigbullet = BIGBULLET_SURFACE;
	/*mX = x + 60;
	mY = y + 30;
	mSpeedX = -3.0;
	mSpeedY = 0;*/

	Setw(mBigbullet->w);
	Seth(mBigbullet->h);
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
ProjectileEnemy::~ProjectileEnemy() {
	// Frig�r bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	//printf("Herobullet destroyed\n");
}

////////////////////////////////////////////////////////////////////////////////
// Anropas 100 g�nger per sekund. Utf�r all logik h�r. 
////////////////////////////////////////////////////////////////////////////////
void ProjectileEnemy::Update() {
	// Flytta ansiktet.
	SetPosX(GetPosX() + GetSpeedX());
	SetPosY(GetPosY() + GetSpeedY());
	/*if(mX>640) {
	mGamescreen->KillObject(this);
	}*/
	if (GetPosY()<40.0)
		SetPosY(40.0);
	if (GetPosX()<0) {
		mGamescreen->KillObject(this);
	}

	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utf�r all utritning h�r.
////////////////////////////////////////////////////////////////////////////////
void ProjectileEnemy::Draw(Graphics *g) {
	// Rensa sk�rmen.
	//g->Clear(RGB(255, 255, 255));
	//g->DrawImage(mBGSurface, (int)mBGX, 0);
	//g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	g->DrawImage(mBigbullet, GetPosX() , GetPosY());


}
////////////////////////////////////
void ProjectileEnemy::Overlap(Gameobject *gameobject) {
	mGamescreen->KillObject(this);
	//printf("Projektil d�dad pga kollision!\n");
}
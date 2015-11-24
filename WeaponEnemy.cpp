#include "WeaponEnemy.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Rymdskepp.h"
#include "Gamescreen.h"
#include "audiere.h"
#include <stdio.h>
#include <math.h>
#include <typeinfo>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
/*
WeaponEnemy::WeaponEnemy(float y) {
	Enemy(y);

	
	mFaceSurface = FACE_SURFACE;

	
	// Ansiktets position och hastighet.
	//mX = 640;
	mX = 1024;
	mY = y;
	mSpeedX = -2.0;
	mSpeedY = 0;

	//mBGX = 0.0f;

	w = mFaceSurface->w;
	//printf("bredd = %d\n", w);
	h = mFaceSurface->h;
	mFirerate = 20;
	mFiredelay = 0;
	health = 3;
	
}*/

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
WeaponEnemy::~WeaponEnemy() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	//printf("Enemy destroyed\n");
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void WeaponEnemy::Update() {
	// Flytta ansiktet.
	mX += mSpeedX;

	if (counter % 230 == 0){
		//randy = rand()%416;
		Fire();
	}



	/*if (mX < 0)
	mX = 0;
	else if (mX > (640.0 - w))
	mX = 640.0 - w;
	mY += mSpeedY;
	if (mY < 0)
	mY = 0;
	else if (mY > 480.0 - h)
	mY = 480.0 - h;
	if (mFiredelay > 0)
	mFiredelay--;*/
	if (mX < 0) {
		mGamescreen->KillObjectEnemy(this);
	}
	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
	counter++;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void WeaponEnemy::Draw(Graphics *g) {

	g->DrawImage(mUfoSurface, mX, mY);

}
////////////////////////////////7
void WeaponEnemy::SetSpeedX(float SpeedX){
	mSpeedX = SpeedX;
}
////////////////////////////
void WeaponEnemy::SetSpeedY(float SpeedY){
	mSpeedY = SpeedY;
}
/////////////////////////7
void WeaponEnemy::Fire() {
//	if (mFiredelay == 0) {
		mGamescreen->GenerateProjectileEnemy(mX, mY);
	//	mFiredelay = mFirerate;
//	}
}
/////////////////////////////
void WeaponEnemy::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
		mGamescreen->KillObjectEnemy(this);
		sExplosionSound->play();
		//printf("AJ!\n");
	}
	if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
		health = health - 1;
		if (health == 0) {
			mGamescreen->PointsToPlayer();
			mGamescreen->KillObjectEnemy(this);
			// audiere.
			sExplosionSound->play();
		}
	}
}
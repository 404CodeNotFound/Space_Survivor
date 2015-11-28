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
//WeaponEnemy(float y) : Enemy(y), mUfoSurface{ UFO_SURFACE }, mSpeedX{ -1.0 }, mSpeedY{ -1.0}, health{ 3 } {}
WeaponEnemy::WeaponEnemy(float y,float xs, float ys) : Enemy(800, y, xs, ys) {
	mUfoSurface = UFO_SURFACE;

	Setw(mUfoSurface->w);
	Seth(mUfoSurface->h);
	health = 3;
	
}

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
	SetPosX(GetPosX() + GetSpeedX());
	SetPosY(GetPosY() + GetSpeedY());

	if (counter % 210 == 0)
	{
		SetSpeedY(-GetSpeedY());
	}

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
	if (GetPosY()<40.0)
		SetPosY(40.0);
	if (GetPosX() < 0) {
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

	g->DrawImage(mUfoSurface, GetPosX(), GetPosY());

}
////////////////////////////////7
/*void WeaponEnemy::SetSpeedX(float SpeedX){
	SetSpeedX(SpeedX);
}
////////////////////////////
void WeaponEnemy::SetSpeedY(float SpeedY){
	mSpeedY = SpeedY;
}*/
/////////////////////////7
void WeaponEnemy::Fire() {
//	if (mFiredelay == 0) {
		mGamescreen->GenerateProjectileEnemy(GetPosX(), GetPosY());
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
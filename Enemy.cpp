#include "Enemy.h"
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
Enemy::Enemy(float x, float y, float xs, float ys) : Gameobject(x, y, xs, ys) {
	
	mFaceSurface = FACE_SURFACE;


	// Ansiktets position och hastighet.
	/*mX = 800;
	mY = y; 
	mSpeedX = -2.0;
	mSpeedY = 0;*/

	Setw(mFaceSurface->w);
	Seth(mFaceSurface->h);
	mFirerate = 20; 
	mFiredelay = 0; 
	health = 3;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Enemy::~Enemy() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	//printf("Enemy destroyed\n");
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Enemy::Update() {
	// Flytta ansiktet.
	SetPosX(GetPosX() + GetSpeedX());
	if (GetPosY()<40.0)
		SetPosY(40.0);
	if (GetPosY() < 0) {
		mGamescreen->KillObjectEnemy(this);
	}
	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Enemy::Draw(Graphics *g) {

	g->DrawImage(mFaceSurface, GetPosX(), GetPosY());

}
////////////////////////////////7
/*void Enemy::SetSpeedX(float SpeedX){
	SetSpeedX(SpeedX);
}
////////////////////////////
void Enemy::SetSpeedY(float SpeedY){
	SetSpeedY(SpeedY);
}*/
/////////////////////////7
void Enemy::Fire() { 
	if (mFiredelay == 0) { 
		mGamescreen->GenerateProjectileSpaceship(GetPosX(), GetPosY()); 
		mFiredelay = mFirerate; 
 	} 
 } 
/////////////////////////////
void Enemy::Overlap(Gameobject * gameobject) {
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
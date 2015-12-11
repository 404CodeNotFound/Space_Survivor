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
Enemy::Enemy(float y) {
	
	mFaceSurface = FACE_SURFACE;

	mX = 800;
	mY = y;
	mSpeedX = -2.0;
	mSpeedY = 0;

	w = mFaceSurface->w;
	h = mFaceSurface->h;
	mFirerate = 20; 
	mFiredelay = 0; 
	health = 3;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Enemy::~Enemy() {
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Enemy::Update() {
	mX += mSpeedX;
	
	if (mY<40.0)
		mY = 40.0;
	if(mX < 0) {
		mGamescreen->KillObjectEnemy(this);
	}
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Enemy::Draw(Graphics *g) {

	g->DrawImage(mFaceSurface, mX, mY);

}
////////////////////////////////7
void Enemy::SetSpeedX(float SpeedX){
	mSpeedX = SpeedX;
}
////////////////////////////
void Enemy::SetSpeedY(float SpeedY){
	mSpeedY = SpeedY;
}
/////////////////////////7
void Enemy::Fire() { 
	if (mFiredelay == 0) { 
		mGamescreen->GenerateProjectileSpaceship(mX, mY, 0); 
		mFiredelay = mFirerate; 
 	} 
 } 
/////////////////////////////
void Enemy::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
		mGamescreen->KillObjectEnemy(this);
		sExplosionSound->play();
	}
	if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
		health = health - 1;
		if (health == 0) {
			mGamescreen->PointsToPlayer(10);
			mGamescreen->KillObjectEnemy(this);
			// audiere.
			sExplosionSound->play();
		}
	}
}
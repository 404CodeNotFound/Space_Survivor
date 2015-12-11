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
WeaponEnemy::WeaponEnemy(float y) : Enemy(y) {
	mUfoSurface = UFO_SURFACE;
	counter = 0;
	
	mX = 800;
	mY = y;
	mSpeedX = -1.0;
	if (y < 247)
		mSpeedY = -1.0;
	else
		mSpeedY = 1.0;

	w = mUfoSurface->w;
	h = mUfoSurface->h;
	health = 3;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
WeaponEnemy::~WeaponEnemy() {
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void WeaponEnemy::Update() {
	mX += mSpeedX;
	mY += mSpeedY;

	if (counter % 210 == 0)
	{
		mSpeedY = -mSpeedY;
	}

	if (counter % 230 == 0){
		Fire();
	}

	if (mY<40.0)
		mY = 40.0;
	if (mX < 0) {
		mGamescreen->KillObjectEnemy(this);
	}
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
		mGamescreen->GenerateProjectileEnemy(mX, mY, -3.0, 0);
}
/////////////////////////////
void WeaponEnemy::Overlap(Gameobject *gameobject) {
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
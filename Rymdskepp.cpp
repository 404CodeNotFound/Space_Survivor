#include "Rymdskepp.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "Wideshot.h"
#include "Splitshot.h"
#include "Wallshot.h"
#include "ProjectileBoss.h"
#include "Shrapnel.h"
#include "WeaponEnemy.h"
#include "audiere.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::Rymdskepp() {
	
	mShipSurface = SHIP_SURFACE;
	mShieldShadow = FAT_SHIELD;
	mSpeedIcon = SPEED_ICON;
	mWeaponIcon = WEAPON_ICON;
	mWideshotIcon = WIDESHOT_ICON;
	
	mX = 125;
	mY = 125;
	mSpeedX = 0;
	mSpeedY = 0;

	w = mShipSurface->w;
	h = mShipSurface->h;
	mFirerate = 20; 
	mFiredelay = 0; 
	mHealth = 100;
	shield = false;
	mShieldDur = 0;
	speed = false;
	mSpeedDur = 0;
	weapon = false;
	mWeaponDur = 0;
	wideshot = false;
	mWideshotDur = 0;
	mHeartbeat = 0;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::~Rymdskepp() {
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

	mY += mSpeedY;
	if (mY < 40.0)
		mY = 40.0;
	else if (mY > 600.0 - h)
		mY = 600.0 - h;

	if (mFiredelay > 0)
		mFiredelay--;
	if (mShieldDur > 0) {
		mShieldDur--;
		if (mShieldDur == 0)
			shield = false;
	}
	if (mSpeedDur > 0) {
		mSpeedDur--;
		if (mSpeedDur == 0)
			speed = false;
	}
	if (mWeaponDur > 0) {
		mWeaponDur--;
		if (mWeaponDur == 0)
			weapon = false;
	}
	if (mWideshotDur > 0) {
		mWideshotDur--;
		if (mWideshotDur == 0)
			wideshot = false;
	}
	if (mHealth <= 10 && mHeartbeat == 0) {
		sHeart->setVolume(0.2);
		sHeart->play();
		printf("Spelar hjärtljud\n");
		mHeartbeat = 100;
	}
	if (mHeartbeat > 0)
		mHeartbeat--;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Rymdskepp::Draw(Graphics *g) {

	if (shield) {
		g->DrawImage(mShieldShadow, mX-6, mY-7);
	}
	g->DrawImage(mShipSurface, mX, mY);

	if (weapon) {
		g->DrawImage(mWeaponIcon, 630, 5);
	}
	if (speed) {
		g->DrawImage(mSpeedIcon, 590, 5);
	}
	if (wideshot) {
		g->DrawImage(mWideshotIcon, 550, 5);
	}


}
////////////////////////////////7
void Rymdskepp::SetSpeedX(float SpeedX){
	if (speed)
		mSpeedX = SpeedX * 2;
	else
		mSpeedX = SpeedX;
}
////////////////////////////
void Rymdskepp::SetSpeedY(float SpeedY){
	if (speed)
		mSpeedY = SpeedY * 2;
	else
		mSpeedY = SpeedY;
}
/////////////////////////7
void Rymdskepp::Fire() { 
	if (mFiredelay == 0) { 
		if (wideshot){
			mGamescreen->GenerateProjectileSpaceship(mX, mY, 1.0);
			mGamescreen->GenerateProjectileSpaceship(mX, mY, -1.0);
		}
		mGamescreen->GenerateProjectileSpaceship(mX, mY, 0); 
		if (weapon)
			mFiredelay = 8;
		else
			mFiredelay = mFirerate; 
 	} 
 } 
///////////////////////
void Rymdskepp::Overlap(Gameobject *gameobject){
	if (!shield) {
		if (typeid(*gameobject) == typeid(Enemy)||
			typeid(*gameobject) == typeid(WeaponEnemy)||
			typeid(*gameobject) == typeid(ProjectileEnemy)||
			typeid(*gameobject) == typeid(Wallshot)||
			typeid(*gameobject) == typeid(Splitshot) ||
			typeid(*gameobject) == typeid(ProjectileBoss) ||
			typeid(*gameobject) == typeid(Shrapnel)) {
			mHealth = mHealth - 10;
			sLostLife->play();
			printf("Livnivå=%d\n", mHealth);
		}
	}
	if (typeid(*gameobject) == typeid(Wideshot)) {
			wideshot = true;
			mWideshotDur = 600;
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
	if (mHealth < 100) {
		mHealth = mHealth + l;
	}
}

void Rymdskepp::setshield(int d) {
	shield = true;
	mShieldDur = d;
}

void Rymdskepp::SetPowerSpeed(int v) {
	speed = true;
	mSpeedDur = v;
}
void Rymdskepp::SetWeapon(int g) {
	weapon = true;
	mWeaponDur = g;
}
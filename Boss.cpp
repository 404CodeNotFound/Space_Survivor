#include "Boss.h"
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
Boss::Boss(float y) : Enemy(y) {
	//Enemy(y);
	counter = 0;
	mBossSurface = BOSS_SURFACE;
	// Ansiktets position och hastighet.
	//mX = 640;
	mX = 800;
	mY = y;
	mSpeedX = -0.2;
	mSpeedY = 0;

	mWallmode = false;
	mWidemode = true;
	mSplitmode = false;
	//mBGX = 0.0f;

	w = mBossSurface->w;
	//printf("bredd = %d\n", w);
	h = mBossSurface->h;
	//mFirerate = 20;
	//mFiredelay = 0;
	health = 100;

}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Boss::~Boss() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	//printf("Enemy destroyed\n");
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Boss::Update() {
	// Flytta ansiktet.
	mX += mSpeedX;
	mY += mSpeedY;
	counter++;
	if (mX <= 700 && mSpeedX != 0)
	{
		mSpeedX = 0;
		mSpeedY = -0.5;
	}



	if (mWallmode)
		{
			if (mY > 245 && mY < 249)
			{
				mSpeedY = 0;
				if (counter % 230 == 0)
					FireWall();
			}
			else
			{
				if (mSpeedY < 0)
					mSpeedY = -3;
				else
					mSpeedY = 3;
			}

		}
		else if ( mWidemode) 
		{
			if(counter % 130 == 0)
				Fire();
		}
		else if (mSplitmode)
		{
			if (counter % 130 == 0)
				FireSplit();
		}


		if (mY <= 80 || mY >= 490)
		{
			mSpeedY = -mSpeedY;
		}

	if (counter % 1500 == 0)
	{

		if (mWallmode)
		{
			printf("split\n");
			mSpeedY = -1;
			mSplitmode = true;
			mWallmode = false;
		}
		else if (mSplitmode)
		{
			printf("wide\n");
			mSpeedY = -0.5;
			mWidemode = true;
			mSplitmode = false;
		}
		else if (mWidemode)
		{
			printf("wall\n");
			mWallmode = true;
			mWidemode = false;
		}
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
	if (mY<40.0)
		mY = 40.0;
	if (mX < 0) {
		mGamescreen->KillObjectEnemy(this);
	}
	//mBGX = mBGX - 5.5f;
	//if (mBGX < -640.0) mBGX += 640.0;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Boss::Draw(Graphics *g) {

	g->DrawImage(mBossSurface, mX, mY);

}
////////////////////////////////7
void Boss::SetSpeedX(float SpeedX){
	mSpeedX = SpeedX;
}
////////////////////////////
void Boss::SetSpeedY(float SpeedY){
	mSpeedY = SpeedY;
}
/////////////////////////7
void Boss::Fire() {
	//	if (mFiredelay == 0) {
	mGamescreen->GenerateProjectileEnemy(mX, mY, -1.4, -0.9);
	mGamescreen->GenerateProjectileEnemy(mX, mY, -1.6, -0.6);
	mGamescreen->GenerateProjectileEnemy(mX, mY, -1.8, -0.3);
	mGamescreen->GenerateProjectileEnemy(mX, mY, -2, 0);
	mGamescreen->GenerateProjectileEnemy(mX, mY, -1.8, 0.3);
	mGamescreen->GenerateProjectileEnemy(mX, mY, -1.6, 0.6);
	mGamescreen->GenerateProjectileEnemy(mX, mY, -1.4, 0.9);
	//	mFiredelay = mFirerate;
	//	}
}
void Boss::FireWall() {
	//	if (mFiredelay == 0) {
	mHole = rand() % 7;

	if (mHole != 0)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, -3.0);
	if (mHole != 0)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, -2.5);
	if (mHole != 1)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, -2.0);
	if (mHole != 1)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, -1.5);
	if (mHole != 2)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, -1.0);
	if (mHole != 2)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, -0.5);

		mGamescreen->GenerateWallshot(mX, mY, -2.0, 0);
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 0.5);

	if (mHole != 3)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 1.0);
	if (mHole != 3)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 1.5);
	if (mHole != 4)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 2.0);
	if (mHole != 4)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 2.5);
	if (mHole != 5)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 3.0);
	if (mHole != 5)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 3.5);
	if (mHole != 6)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 4.0);
	if (mHole != 6)
		mGamescreen->GenerateWallshot(mX, mY, -2.0, 4.5);
	
	//	mFiredelay = mFirerate;
	//	}
}
void Boss::FireSplit()
{
	mGamescreen->GenerateSplitshot(mX, mY, -3.2);
}
/////////////////////////////
void Boss::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
		mGamescreen->KillObjectEnemy(this);
		sExplosionSound->play();
		mGamescreen->PointsToPlayer(100);
		mGamescreen->DisableBoss();
		//printf("AJ!\n");
	}
	if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
		health = health - 1;
		if (health == 0) {
			mGamescreen->PointsToPlayer(100);
			mGamescreen->KillObjectEnemy(this);
			mGamescreen->DisableBoss();
			// audiere.
			sExplosionSound->play();
		}
	}
}
#include "Rymdskepp.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Gamescreen.h"
#include <stdio.h>
#include <math.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::Rymdskepp() : Gameobject(125,125,0,0){
	mShipSurface = SHIP_SURFACE;

	Setw(mShipSurface->w);
	Seth(mShipSurface->h);
	mFirerate = 20; 
	mFiredelay = 0; 
	mHealth = 100;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Rymdskepp::~Rymdskepp() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
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
	SetPosX(GetPosX() + GetSpeedX()); 
	if ( GetPosY() < 0)
		SetPosY(0.0);
	else if (GetPosX() > (800.0 - Getw()))
		SetPosX(800.0 - Getw());
	/*else if (mX > (1024.0 - w))
		mX = 1024.0 - w;*/
	SetPosY(GetPosY() + GetSpeedY());
	if (GetPosY() < 40.0)
		SetPosY(40.0);
	else if (GetPosY() > 600.0 - Geth())
		SetPosY(600.0 - Geth());
	/*else if (mY > 768.0 - h)
		mY = 768.0 - h;*/
	if (mFiredelay > 0)
		mFiredelay--;
	if (mDur > 0)
		mDur--;
	if (mDur == 0 && shield)
		shield = false; // removeshield(); ?

}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Rymdskepp::Draw(Graphics *g) {
	// Rensa skärmen.
	//g->Clear(RGB(255, 255, 255));
	//g->DrawImage(mBGSurface, (int)mBGX, 0);
	//g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	g->DrawImage(mShipSurface, GetPosX(), GetPosY());


}
////////////////////////////////7
/*void Rymdskepp::SetSpeedX(float SpeedX){
	SetSpeedX(SpeedX);
}
////////////////////////////
void Rymdskepp::SetSpeedY(float SpeedY){
	SetSpeedY(SpeedY);
}*/
/////////////////////////7
void Rymdskepp::Fire() { 
	if (mFiredelay == 0) { 
		mGamescreen->GenerateProjectileSpaceship(GetPosX(), GetPosY()); 
		mFiredelay = mFirerate; 
 	} 
 } 
///////////////////////
void Rymdskepp::Overlap(Gameobject *gameobject){
	
	if (typeid(*gameobject) != typeid(Shield)) // typeid(powerup) behöver bara en ifsats... optimera?
		if (!shield)
		{
			mHealth = mHealth - 10;
			printf("Livnivå=%d\n", mHealth);
		}
	if (mHealth <= 0)
		mGamescreen->KillSpaceship();
}

///////////////////////
int Rymdskepp::GetHealth() {
	return mHealth;
}
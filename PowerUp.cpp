#include "PowerUp.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Rymdskepp.h"
#include "audiere.h"
#include <stdio.h>
#include <math.h>
#include <typeinfo>


PowerUp::PowerUp(float y, float xs)
{
	//mPowerSurface = powPic;
	// Ansiktets position och hastighet.
	mX = 800;
	//mX = 1024;
	mY = y;
	mSpeedX = xs;
	mSpeedY = 0;

	//mBGX = 0.0f;

	//w = mPowerSurface->w;
	//printf("bredd = %d\n", w);
	//h = mPowerSurface->h;

}


PowerUp::~PowerUp()
{

}
void PowerUp::Update()
{
	mX += mSpeedX;
	if (mX < 0) {
		mGamescreen->KillObjectPowerUp(this);
		printf("Här borde powerup dödas!");
	}
}

void PowerUp::Draw(Graphics *g) {
}

void PowerUp::Overlap(Gameobject *gameobject) {
}
#include "Speed.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"



Speed::Speed(float y, float xs) : PowerUp(y, xs) {
	mSpeedSurface = SPEED_PU_SURFACE;
	w = mSpeedSurface->w;
	h = mSpeedSurface->h;
}



Speed::~Speed() {
}

void Speed::Draw(Graphics *g)
{
	g->DrawImage(mSpeedSurface, mX, mY);
}

void Speed::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
			mGamescreen->BoostSpeed(700);
			mGamescreen->KillObjectPowerUp(this);
			//sExplosionSound->play();
			printf("Kollision med Speed!\n");
		}
		if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
			mHealth -= 10;
			if (mHealth <= 0){
				mGamescreen->KillObjectPowerUp(this);
				sBabyAouch->play();
			}
		}
	}

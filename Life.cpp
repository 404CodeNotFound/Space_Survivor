#include "Life.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"


Life::Life(float y, float xs) : PowerUp(y, xs) {
	mLifeSurface = LIFE_PU_SURFACE;
	w = mLifeSurface->w;
	h = mLifeSurface->h;
}


Life::~Life() {
}

void Life::Draw(Graphics *g)
{
	g->DrawImage(mLifeSurface, mX, mY);
}

void Life::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
			mGamescreen->BoostLife(20);
			mGamescreen->KillObjectPowerUp(this);
			printf("Kollision med Life!\n");
		}
		if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
			mHealth -= 10;
			if (mHealth <= 0){
				mGamescreen->KillObjectPowerUp(this);
				sBabyAouch->play();
			}
		}
	}
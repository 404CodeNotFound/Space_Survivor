#include "Shield.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"


Shield::Shield(float y, float xs) : PowerUp(y, xs) {
	mShieldSurface = SHIELD_PU_SURFACE;
	w = mShieldSurface->w;
	h = mShieldSurface->h;
}



Shield::~Shield() {
}

void Shield::Draw(Graphics *g)
{
	g->DrawImage(mShieldSurface, mX, mY);
}

void Shield::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
			mGamescreen->BoostShield(500);
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

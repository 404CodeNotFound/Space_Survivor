#include "Shield.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"



/*Shield::Shield(float x, float y , float xs)
WeaponEnemy::WeaponEnemy(float y) : Enemy(y) {*/
Shield::Shield(float y, float xs) : PowerUp(y, xs) {
	mShieldSurface = SHIELD_PU_SURFACE;
	w = mShieldSurface->w;
	h = mShieldSurface->h;
	//PowerUp(x,y,xs);
	//mFaceSurface = FACE_SURFACE;
}



Shield::~Shield() {
}

void Shield::Draw(Graphics *g)
{
	g->DrawImage(mShieldSurface, mX, mY);
}

void Shield::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
			mGamescreen->BoostShield(300);
			mGamescreen->KillObjectPowerUp(this);
			sExplosionSound->play();
			printf("Kollision med Life!\n");
		}
		if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
			mGamescreen->KillObjectPowerUp(this);
			sExplosionSound->play();
		}
	}

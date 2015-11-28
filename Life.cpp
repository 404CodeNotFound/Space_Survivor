#include "Life.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"


/*Shield::Shield(float x, float y , float xs)
WeaponEnemy::WeaponEnemy(float y) : Enemy(y) {*/
Life::Life(float y, float xs) : PowerUp(800, y, xs, 0, 0) {
	mLifeSurface = LIFE_PU_SURFACE;
	Setw(mLifeSurface->w);
	Seth(mLifeSurface->h);
	//PowerUp(x,y,xs);
	//mFaceSurface = FACE_SURFACE;
}


Life::~Life() {
}

void Life::Draw(Graphics *g)
{
	g->DrawImage(mLifeSurface, GetPosX(), GetPosY());
}

void Life::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
			mGamescreen->BoostLife(20);
			mGamescreen->KillObjectPowerUp(this);
			sExplosionSound->play();
			printf("Kollision med Life!\n");
		}
		if (typeid(*gameobject) == typeid(ProjectileSpaceship)) {
			mGamescreen->KillObjectPowerUp(this);
			sExplosionSound->play();
		}
	}
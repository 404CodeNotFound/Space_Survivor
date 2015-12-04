#include "Weapon.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"



Weapon::Weapon(float y, float xs) : PowerUp(y, xs) {
	mWeaponSurface = WEAPON_PU_SURFACE;
	w = mWeaponSurface->w;
	h = mWeaponSurface->h;
}



Weapon::~Weapon() {
}

void Weapon::Draw(Graphics *g)
{
	g->DrawImage(mWeaponSurface, mX, mY);
}

void Weapon::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
			mGamescreen->BoostWeapon(300);
			mGamescreen->KillObjectPowerUp(this);
			sExplosionSound->play();
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

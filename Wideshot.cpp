#include "Wideshot.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"



Wideshot::Wideshot(float y, float xs) : PowerUp(y, xs) {
	mWideshotSurface = WIDESHOT_PU_SURFACE;
	w = mWideshotSurface->w;
	h = mWideshotSurface->h;
}



Wideshot::~Wideshot() {
}

void Wideshot::Draw(Graphics *g)
{
	g->DrawImage(mWideshotSurface, mX, mY);
}

void Wideshot::Overlap(Gameobject *gameobject) {
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
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

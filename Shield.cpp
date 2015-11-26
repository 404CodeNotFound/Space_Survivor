#include "Shield.h"

/*Shield::Shield(float x, float y , float xs)
{
	//mShieldSurface = SHIELD_SURFACE;
	//PowerUp(x,y,xs);
}*/


Shield::~Shield()
{
}

void Shield::GainShield(Rymdskepp * spaceship)
{
	spaceship->setshield();
}
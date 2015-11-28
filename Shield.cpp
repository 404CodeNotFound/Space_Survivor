#include "Shield.h"

Shield::Shield(float x, float y, float xs, float ys, int dur) : PowerUp(x,y,xs,ys,dur)
{
	mShieldSurface = SHIELD_SURFACE;
	Setw(mShieldSurface->w);
	Seth(mShieldSurface->h);

}

Shield::~Shield()
{

}

void Shield::GainShield(Rymdskepp * spaceship)
{
	spaceship->Setshield(GetDuration());
}
void Shield::Overlap(Gameobject * gameobject)
{
	if (typeid(*gameobject) == typeid(Rymdskepp)) {
	
		Rymdskepp * rptr = dynamic_cast<Rymdskepp*>(gameobject); // casta tillbaka?
		GainShield(rptr);
		sExplosionSound->play();
		mGamescreen->KillObjectPowerUp(this);
		printf("SHIELD!\n");
	}
}
void Shield::Update()
{
	SetPosX(GetPosX() + GetSpeedX());
	if (GetPosX() < 0) {
		mGamescreen->KillObjectPowerUp(this);
	}
}

void Shield::Draw(Graphics * g)
{
	g->DrawImage(mShieldSurface, GetPosX(), GetPosY());
}
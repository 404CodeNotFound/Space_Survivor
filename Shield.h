#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"

class Shield : public PowerUp
{
public:
	Shield(float x, float y, float xs) : PowerUp(x, y, xs) {};
	~Shield();
	void GainShield(Rymdskepp * spaceship);
private:
	SDL_Surface * mShieldSurface;
};


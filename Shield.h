#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Gameobject.h"

class Shield : public PowerUp
{
private:
	SDL_Surface * mShieldSurface;

public:
	Shield(float y, float xs);
	~Shield();
	void Draw(Graphics *g);
	void Overlap(Gameobject *gameobject);
	void GainShield(Rymdskepp *spaceship);

};

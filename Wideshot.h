#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Gameobject.h"

class Wideshot : public PowerUp
{
private:
	SDL_Surface * mWeaponSurface;

public:
	Wideshot(float y, float xs);
	~Wideshot();
	void Draw(Graphics *g);
	void Overlap(Gameobject *gameobject);

};

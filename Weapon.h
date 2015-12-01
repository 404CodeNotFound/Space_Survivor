#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Gameobject.h"

class Weapon : public PowerUp
{
private:
	SDL_Surface * mWeaponSurface;

public:
	Weapon(float y, float xs);
	~Weapon();
	void Draw(Graphics *g);
	void Overlap(Gameobject *gameobject);

};

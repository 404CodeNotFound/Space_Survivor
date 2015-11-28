#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Gameobject.h"

class Life : public PowerUp
{
private:
	SDL_Surface * mLifeSurface;
public:
	Life(float y, float xs);
	~Life();
	void Draw(Graphics *g);
	void Overlap(Gameobject *gameobject);
	//void GainShield(Rymdskepp *spaceship);

};


#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Gameobject.h"

class Life : public PowerUp
{
private:
	SDL_Surface * mLifeSurface;
public:
	//Shield(float x, float y, float xs) : PowerUp(x, y, xs) {};
	Life(float y, float xs);
	~Life();
	void Draw(Graphics *g);
	void Overlap(Gameobject *gameobject);
	//void GainShield(Rymdskepp *spaceship);

};


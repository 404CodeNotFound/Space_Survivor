#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Gameobject.h"

class Speed : public PowerUp
{
private:
	SDL_Surface * mSpeedSurface;

public:
	Speed(float y, float xs);
	~Speed();
	void Draw(Graphics *g);
	void Overlap(Gameobject *gameobject);

};

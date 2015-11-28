#pragma once
#include "PowerUp.h"
#include "Rymdskepp.h"
#include "Graphics.h"
#include "Gamescreen.h"
#include "Res.h"
#include <typeinfo>

class Shield : public PowerUp
{
public:
	Shield() = delete;
	Shield(float x, float y, float xs, float ys, int dur);
	virtual ~Shield();
	void GainShield(Rymdskepp * spaceship);
	virtual void Draw(Graphics * g);
	virtual void Update();
	void virtual Overlap(Gameobject * gameobject);
private:
	SDL_Surface * mShieldSurface;
};
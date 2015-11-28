#pragma once
#include "GameObject.h"

class PowerUp : public Gameobject {
private:
	//SDL_Surface * mPowerSurface; bara de konkreta powerupsen har bilder
	
	int mDuration;

public:
	//PowerUp();
	PowerUp(float y, float xs);
	virtual ~PowerUp();
	virtual void Update();
	void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobject);

};

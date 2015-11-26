#pragma once
#include "GameObject.h"

class PowerUp : public Gameobject
{

public:
	PowerUp();
	PowerUp(float x, float y, float xs);
	~PowerUp();
	virtual void Update();
	virtual void Draw(Graphics * g);
	//virtual void Overlap(Gameobject * gameobject);
private:
	SDL_Surface * mPowerSurface;
	
	//float mSpeedX;
	int mDuration;

};

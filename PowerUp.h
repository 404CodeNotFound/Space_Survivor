#pragma once
#include "GameObject.h"

<<<<<<< HEAD
class PowerUp : public Gameobject
{

public:
	PowerUp() = delete;
	virtual ~PowerUp() = default;
	virtual void Update() = 0;
	virtual void Draw(Graphics * g) = 0;
	virtual void Overlap(Gameobject * gameobject) = 0;
	int GetDuration() { return mDuration; }
protected:
	PowerUp(float x, float y, float xs, float ys, int dur) : Gameobject(x, y, xs, ys), mDuration{ dur } {}
private:
	int mDuration;
=======
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

>>>>>>> 61818227934c5c08efaf6855c29030dca1d090e4
};

#pragma once
#include "GameObject.h"

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
};

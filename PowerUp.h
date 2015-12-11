#pragma once
#include "GameObject.h"

class PowerUp : public Gameobject {
private:
	int mDuration;
protected:
	int mHealth;

public:
	PowerUp(float y, float xs);
	virtual ~PowerUp();
	virtual void Update();
	void Draw(Graphics *g);
	virtual void Overlap(Gameobject *gameobject);

};

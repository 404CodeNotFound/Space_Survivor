#ifndef __RYMD_SKEPP_H__
#define __RYMD_SKEPP_H__

#include "Gameobject.h"
#include "Res.h"

class Rymdskepp : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mShipSurface;

	// Position f�r ansikte.
	//float mX;
	//float mY;
	// Hastighet f�r ansikte.
	// Position f�r bakgrund.
	//float mBGX;
	//int w;
	//int h;
	int mFirerate; 
	int mFiredelay; 
	int mHealth;
	int mDur = 0;
	bool shield = false;



public:
	Rymdskepp();
	~Rymdskepp();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	int GetHealth();
	void setshield(int dur) { shield = true; setDur(dur); mShipSurface = SMILEY_SURFACE; }
	void setDur(int dur) { mDur = dur; }
	virtual void Update();
	//virtual void SetSpeedX(float SpeedX);
	//virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics * g);
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobject);
};

#endif


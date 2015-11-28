#ifndef __RYMD_SKEPP_H__
#define __RYMD_SKEPP_H__

#include "Gameobject.h"
#include "Res.h"

//struct SDL_Surface;

class Rymdskepp : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mShipSurface;

	// Position för ansikte.
	//float mX;
	//float mY;
	// Hastighet för ansikte.
	// Position för bakgrund.
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
	void SetHealth(int);
	void Setshield(int dur) { shield = true; SetDur(dur); mShipSurface = SMILEY_SURFACE; }
	void SetDur(int dur) { mDur = dur; }
	virtual void Draw(Graphics * g);
	virtual void Update();
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobject);

};

#endif


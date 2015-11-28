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
<<<<<<< HEAD
	int mDur = 0;
	bool shield = false;
=======
	bool shield;

>>>>>>> 61818227934c5c08efaf6855c29030dca1d090e4



public:
	Rymdskepp();
	~Rymdskepp();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
<<<<<<< HEAD
	int GetHealth();
	void setshield(int dur) { shield = true; setDur(dur); mShipSurface = SMILEY_SURFACE; }
	void setDur(int dur) { mDur = dur; }
	virtual void Update();
	//virtual void SetSpeedX(float SpeedX);
	//virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics * g);
=======
	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
>>>>>>> 61818227934c5c08efaf6855c29030dca1d090e4
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobject);
	int GetHealth();
	void SetHealth(int);
	void setshield() { shield = true; }
};

#endif


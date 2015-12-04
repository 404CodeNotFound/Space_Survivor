#ifndef __RYMD_SKEPP_H__
#define __RYMD_SKEPP_H__

#include "Gameobject.h"

//struct SDL_Surface;

class Rymdskepp : public Gameobject {
private:
	// Ansiktsbild.
	SDL_Surface *mShipSurface;
	SDL_Surface *mShieldShadow;
	SDL_Surface *mSpeedIcon;
	SDL_Surface *mWeaponIcon;
	SDL_Surface *mWideshotIcon;

	// Position för ansikte.
	//float mX;
	//float mY;
	// Hastighet för ansikte.
	float mSpeedX;
	float mSpeedY;
	// Position för bakgrund.
	//float mBGX;
	//int w;
	//int h;
	int mFirerate; 
	int mFiredelay; 
	int mHealth;
	bool shield;
	int mShieldDur;
	bool speed;
	int mSpeedDur;
	bool weapon;
	int mWeaponDur;
	bool wideshot;
	int mWideshotDur;



public:
	Rymdskepp();
	~Rymdskepp();

	//virtual void KeyDown(SDL_Keycode keyCode);
	//virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Fire();
	virtual void Overlap(Gameobject *gameobject);
	int GetHealth();
	void SetHealth(int);
	void setshield(int);
	void SetPowerSpeed(int);
	void SetWeapon(int);
};

#endif


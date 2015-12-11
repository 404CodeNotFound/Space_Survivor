#ifndef __RYMD_SKEPP_H__
#define __RYMD_SKEPP_H__

#include "Gameobject.h"


class Rymdskepp : public Gameobject {
private:
	SDL_Surface *mShipSurface;
	SDL_Surface *mShieldShadow;
	SDL_Surface *mSpeedIcon;
	SDL_Surface *mWeaponIcon;
	SDL_Surface *mWideshotIcon;

	float mSpeedX;
	float mSpeedY;
	
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
	int mHeartbeat;


public:
	Rymdskepp();
	~Rymdskepp();

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


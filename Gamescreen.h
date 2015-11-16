#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "Screen.h"
#include <list>

class Gameobject;
class ProjectileSpaceship;
struct SDL_Surface;

class Gamescreen : public Screen {
private:
	// Ansiktsbild.
	//SDL_Surface *mFaceSurface;
	SDL_Surface *mBGSurface;

	// Position för ansikte.
	//int mFaceX;
	//int mFaceY;
	// Hastighet för ansikte.
	//int mFaceSpeedX;
	//int mFaceSpeedY;
	// Position för bakgrund.
	float mBGX;
	bool mSpace = false;
	bool mDown = false;
	bool mUp = false;
	//pekare till rymdskepp
	Gameobject *mGameobject;
	//lista med pekare till rymdskeppets projektiler
	std::list<ProjectileSpaceship*> herobullets;
	std::list<ProjectileSpaceship*> killedherobullets;


public:
	Gamescreen();
	~Gamescreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	void SetGameobject(Gameobject *gameobject);
	void GenerateProjectileSpaceship(float x, float y);
	void KillObject(ProjectileSpaceship *projectile);
	void FinalKill();
	
};

#endif


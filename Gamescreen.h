#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "Screen.h"
#include <list>

class Gameobject;
class ProjectileSpaceship;
class Enemy;
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
	int counter;
	int randy;
	bool gameover;

	//pekare till rymdskepp
	Gameobject *mGameobject;
	//lista med pekare till rymdskeppets projektiler
	std::list<ProjectileSpaceship*> herobullets;
	std::list<ProjectileSpaceship*> killedherobullets;
	std::list<Enemy*> enemies;
	std::list<Enemy*> killedenemies;


public:
	Gamescreen();
	~Gamescreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	void SetGameobject(Gameobject *gameobject);
	void GenerateProjectileSpaceship(float x, float y);
	void GenerateEnemy(float y);
	void KillObject(ProjectileSpaceship *projectile);
	void KillObjectEnemy(Enemy *enemy);
	void KillSpaceship();
	void FinalKill();
	void CheckOverlapSpaceship(Gameobject *gameobject, std::list<Enemy*> enemies); 
	void CheckOverlapHerobullets(std::list<ProjectileSpaceship*> herobullets, std::list<Enemy*> enemies);
	
};

#endif


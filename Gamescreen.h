#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "Screen.h"
#include <list>

class Gameobject;
class ProjectileSpaceship;
class ProjectileEnemy;
class Enemy;
class PowerUp;
<<<<<<< HEAD
class Shield;
enum class mPower{SHIELD,HEALTH,WEAPON,BOOST};
=======
>>>>>>> 61818227934c5c08efaf6855c29030dca1d090e4
struct SDL_Surface;

class Gamescreen : public Screen {
private:
	// Ansiktsbild.
	//SDL_Surface *mFaceSurface;
	SDL_Surface *mBGSurface;
	SDL_Surface *mTio;
	SDL_Surface *mNio;
	SDL_Surface *mÅtta;
	SDL_Surface *mSju;
	SDL_Surface *mSex;
	SDL_Surface *mFem;
	SDL_Surface *mFyra;
	SDL_Surface *mTre;
	SDL_Surface *mTvå;
	SDL_Surface *mEtt;

	// Position för ansikte.
	int mLifeX;
	int mLifeY;
	int mScoreX;
	int mScoreY;
	// Position för bakgrund.
	float mBGX;
	int counter;
	int randy;
	bool gameover;
	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;
	bool mSpace;
	int points;
	int life;

	//pekare till rymdskepp
	Gameobject *mGameobject;
	//lista med pekare till rymdskeppets projektiler
	/*std::list<ProjectileSpaceship*> herobullets;
	std::list<ProjectileSpaceship*> killedherobullets;
	std::list<ProjectileEnemy*> enemybullets;
	std::list<ProjectileEnemy*> killedenemybullets;*/
	std::list<Gameobject*> herobullets;
	std::list<Gameobject*> killedherobullets;
	std::list<Gameobject*> enemybullets;
	std::list<Gameobject*> killedenemybullets;
	std::list<Enemy*> enemies;
	std::list<Enemy*> killedenemies;
	std::list<PowerUp*> powerup;
	std::list<PowerUp*> killedpowerups;


public:
	Gamescreen();
	~Gamescreen();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	void SetGameobject(Gameobject *gameobject);
	void GenerateProjectileSpaceship(float x, float y);
	void GenerateProjectileEnemy(float x, float y);
	void GenerateEnemy(float x, float y, float xs, float ys);
	void GenerateWeaponEnemy(float y);
<<<<<<< HEAD
	void GeneratePowerUp(float x, float y, float xs, float ys, int dur, mPower power);
	//void KillObject(ProjectileSpaceship *projectile);
	void KillObject(Gameobject *gameobject);
	void KillObjectEnemy(Enemy *enemy);
	void KillObjectPowerUp(PowerUp * powerup);
	void KillSpaceship();
	void FinalKill();
	void CheckOverlapSpaceship(/*Gameobject *gameobject, std::list<Enemy*> enemies, std::list<Gameobject*> enemybullets*/); 
=======
	void GenerateShield(float x, float y, float xs);
	void GenerateLife(float y, float xs);
	//void KillObject(ProjectileSpaceship *projectile);
	void KillObject(Gameobject *gameobject);
	void KillObjectEnemy(Enemy *enemy);
	void KillObjectPowerUp(PowerUp *powerup);
	void KillSpaceship();
	void FinalKill();
	void CheckOverlapSpaceship(Gameobject *gameobject, std::list<Enemy*> enemies, std::list<Gameobject*> enemybullets, std::list<PowerUp*> powerup); 
>>>>>>> 61818227934c5c08efaf6855c29030dca1d090e4
	//void CheckOverlapHerobullets(std::list<ProjectileSpaceship*> herobullets, std::list<Enemy*> enemies);
	void CheckOverlapHerobullets(std::list<Gameobject*> herobullets, std::list<Enemy*> enemies, std::list<PowerUp*> powerup);
	void PointsToPlayer();
<<<<<<< HEAD
=======
	void KillAll();
	void BoostLife(int);
>>>>>>> 61818227934c5c08efaf6855c29030dca1d090e4
	
};

#endif


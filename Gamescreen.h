#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "Screen.h"
#include <list>

class Gameobject;
class ProjectileSpaceship;
class ProjectileEnemy;
class Enemy;
class PowerUp;
struct SDL_Surface;
class Font;

class Gamescreen : public Screen {
private:
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

	Font *mMyFont;

	// Position för score och lifebar.
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
	bool mBossMode;
	int points;
	int life;

	//pekare till rymdskepp
	Gameobject *mGameobject;
	//listor med pekare till övriga gameobjects
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
	void GenerateProjectileSpaceship(float x, float y, float sy);
	void GenerateProjectileEnemy(float x, float y, float sx, float sy);
	void GenerateProjectileBoss(float x, float y, float sx, float sy);
	void GenerateShrapnel(float x, float y, float sx, float sy);
	void GenerateWallshot(float x, float y, float sx, float sy);
	void GenerateSplitshot(float x, float y, float sx);
	void GenerateEnemy(float y);
	void GenerateWeaponEnemy(float y);
	void GenerateBoss(float y);
	void GenerateShield(float y, float xs);
	void GenerateLife(float y, float xs);
	void GenerateSpeed(float y, float xs);
	void GenerateWeapon(float y, float xs);
	void GenerateWideshot(float y, float xs);
	void KillObject(Gameobject *gameobject);
	void KillObjectEnemy(Enemy *enemy);
	void KillObjectPowerUp(PowerUp *powerup);
	void KillSpaceship();
	void FinalKill();
	void CheckOverlapSpaceship(Gameobject *gameobject, std::list<Enemy*> enemies, std::list<Gameobject*> enemybullets, std::list<PowerUp*> powerup); 
	void CheckOverlapHerobullets(std::list<Gameobject*> herobullets, std::list<Enemy*> enemies, std::list<PowerUp*> powerup);
	void PointsToPlayer(int);
	void KillAll();
	void BoostLife(int);
	void BoostShield(int);
	void BoostSpeed(int);
	void BoostWeapon(int);
	void DisableBoss();
	
};

#endif


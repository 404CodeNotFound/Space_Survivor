#ifndef __BOSS_H__
#define __BOSS_H__

#include "Enemy.h"
#include "Res.h"

//struct SDL_Surface;
class Font;

class Boss : public Enemy {
private:
	SDL_Surface *mBossSurface;
	Font *mMyFont;

	float mSpeedX;
	float mSpeedY;

	int counter;
	int mFirerate;
	int mFiredelay;
	int health;
	int mHole;

	bool mWallmode;
	bool mWidemode;
	bool mSplitmode;



public:
	Boss(float y);
	~Boss();

	virtual void Update();
	virtual void SetSpeedX(float SpeedX);
	virtual void SetSpeedY(float SpeedY);
	virtual void Draw(Graphics *g);
	virtual void Fire();
	void FireWall();
	void FireSplit();
	virtual void Overlap(Gameobject *gameobejct);
	int GetBossHealth();
};

#endif

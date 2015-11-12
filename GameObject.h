#pragma once

class Graphics;
class Gamescreen;

class Gameobject {
protected:
	float mX;
	float mY;
	float mSpeedX;
	float mSpeedY;

private:
protected:
	Gamescreen *mGamescreen;

public:
	Gameobject() {};
	//GameObject(float xpos, float ypos, float xspeed, float yspeed) : mX(xpos), mY(ypos), mSpeedX(xspeed), mSpeedY(yspeed)  {}
	virtual ~Gameobject() {};

	virtual void Update() {}
	virtual void Draw(Graphics *g) {}

	virtual void SetSpeed(float SpeedX, float SpeedY) {}
	void SetGamescreen(Gamescreen *gamescreen) {mGamescreen = gamescreen;}
	Gamescreen *Gamescreen() {return mGamescreen;}
	float GetPosX() {return mX;}
	float GetPosY () {return mY;}

	/*void SetGameApp(GameApp *gameApp) {mGameApp = gameApp;}
	GameApp *GameApp() {return mGameApp;}*/

	bool Overlap(Gameobject *gameobject);

};
#pragma once

class Graphics;
class Gamescreen;

class GameObject {
protected:
	float mY;
	float mX;
	float mSpeedY;
	float mSpeedX;

private:
	Gamescreen *mGamescreen; 

public:
	GameObject() : mY(320), mX(100), mSpeedY(2), mSpeedX(2) {}
	GameObject(float ypos, float xpos, float yspeed, float xspeed) : mY(ypos), mX(xpos), mSpeedY(yspeed), mSpeedX(xspeed)  {}
	virtual ~GameObject() {};

	virtual void Update() {}
	virtual void Draw(Graphics *g) {}

	virtual void SetSpeed(float SpeedX, float SpeedY) {}
	void SetGamescreen(Gamescreen *gamescreen) {mGamescreen = gamescreen;}
	Gamescreen *Gamescreen() {return mGamescreen;}

	/*void SetGameApp(GameApp *gameApp) {mGameApp = gameApp;}
	GameApp *GameApp() {return mGameApp;}*/

	bool Overlap(GameObject *gameobject);

};
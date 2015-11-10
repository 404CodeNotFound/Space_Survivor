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
	Gamescreen *mGamescreen;

public:
	Gameobject() {};
	virtual ~Gameobject() {};

	virtual void Update() {}
	virtual void Draw(Graphics *g) {}

	virtual void SetSpeed(float SpeedX, float SpeedY) {}
	void SetGamescreen(Gamescreen *gamescreen) {mGamescreen = gamescreen;}
	Gamescreen *Gamescreen() {return mGamescreen;}

	/*void SetGameApp(GameApp *gameApp) {mGameApp = gameApp;}
	GameApp *GameApp() {return mGameApp;}*/

	bool Overlap(Gameobject *gameobject);

};
#pragma once

class Graphics;
class Gamescreen;
struct SDL_Surface;

class Gameobject {
protected:
	Gameobject(float xpos, float ypos, float xspeed, float yspeed) : mX{ xpos }, mY{ ypos }, mSpeedX{ xspeed }, mSpeedY{ yspeed }  {}
	Gamescreen *mGamescreen;
private:
	float mX;
	float mY;
	float mSpeedX;
	float mSpeedY;
	int w;
	int h;
public:
	Gameobject() = delete;
	virtual ~Gameobject() {};

	virtual void Update() {}
	virtual void Draw(Graphics *g) {}
	virtual void SetSpeedX(float SpeedX) { mSpeedX = SpeedX; }
	virtual void SetSpeedY(float SpeedY) { mSpeedY = SpeedY; }
	virtual float GetSpeedX() { return mSpeedX; }
	virtual float GetSpeedY() { return mSpeedY; }
	void SetGamescreen(Gamescreen * gamescreen) {mGamescreen = gamescreen;}
	Gamescreen *Gamescreen() {return mGamescreen;}
	virtual float GetPosX() {return mX;}
	virtual float GetPosY() {return mY;}
	virtual void SetPosX(float x) { mX = x; }
	virtual void SetPosY(float y) { mY = y; }
	void Setw(int mWidth) { w = mWidth; }
	void Seth(int mHeight) { h = mHeight; }
	int Getw() {return w;}
	int Geth() {return h;}
	virtual void Fire() {}

	/*void SetGameApp(GameApp *gameApp) {mGameApp = gameApp;}
	GameApp *GameApp() {return mGameApp;}*/

	virtual void Overlap(Gameobject *gameobject) {}

};
#pragma once

class Graphics;
class Gamescreen;
struct SDL_Surface;

class Gameobject {
protected:
	float mX;
	float mY;
	float mSpeedX;
	float mSpeedY;
	int w;
	int h;

private:
protected:
	Gamescreen *mGamescreen;

public:
	Gameobject() {};
	virtual ~Gameobject() {};

	virtual void Update() {}
	virtual void Draw(Graphics *g) {}

	virtual void SetSpeedX(float SpeedX) {}
	virtual void SetSpeedY(float SpeedY) {}
	void SetGamescreen(Gamescreen *gamescreen) {mGamescreen = gamescreen;}
	Gamescreen *Gamescreen() {return mGamescreen;}
	float GetPosX() {return mX;}
	float GetPosY () {return mY;}
	int Getw() {return w;}
	int Geth() {return h;}
	virtual void Fire() {}
	virtual void Overlap(Gameobject *gameobject) {}

};
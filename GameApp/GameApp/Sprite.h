#pragma once

class Graphics;

class Sprite {
protected:
	float mX;
	float mY;
	float mDX;
	float mDY;

public:
	Sprite();
	~Sprite();

	virtual void Update();
	virtual void Draw(Graphics *g);

	bool Overlap(Sprite *sprite);

};
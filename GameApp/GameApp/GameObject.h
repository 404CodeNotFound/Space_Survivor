#pragma once

class Graphics;

class GameObject {
protected:
	float xpos_;
	float ypos_;
	float xspeed_;
	float yspeed_;
	//GameScreen* screen;

public:
	GameObject(float xpos, float ypos, float xspeed, float yspeed) : 
		xpos_(xpos), ypos_(ypos), xspeed_(xspeed), yspeed_(yspeed){}

	~GameObject();

	virtual void Update();
	virtual void Draw(Graphics *g, float xpos, float ypos);

	virtual void Overlap(GameObject* go);

};
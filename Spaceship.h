#pragma once

enum class Gun_ {STANDARD, DOUBLE, WIDE, LASER};

class Spaceship //: public GameObject
{
public:
	Spaceship(); // DEFAULT
	Spaceship(float ypos, float xpos, float yspeed, float xspeed, float health, float fireRate, Gun_ weaponType);
	~Spaceship();
	void fire();
	void update(); //override?
	void setX();
	void setY();
	void draw(Graphics g);
private:
	float ypos_;
	float xpos_;
	float yspeed_;
	float xspeed_;
	int health_;
	int fireRate_;
	int fireDelay_;
	Gun_ weaponType_;
};

#include "Gamescreen.h"
#include "Gameover.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Rymdskepp.h"
#include "Res.h"
#include "ProjectileSpaceship.h"
#include "ProjectileEnemy.h"
#include "Enemy.h"
#include "WeaponEnemy.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include "audiere.h"
#include "Font.h"
#include "PowerUp.h"
#include "Shield.h"
#include "Life.h"
#include "Speed.h"
#include "Weapon.h"
#include "Wideshot.h"
#include "Boss.h"
#include "Splitshot.h"
#include "Wallshot.h"
#include "ProjectileBoss.h"
#include "Shrapnel.h"

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gamescreen::Gamescreen() {

	// audiere.
	sMusic->play();
	sMusic->setRepeat(true);
	//

	mGameobject = 0;	

	//bilder

	mBGSurface = BG_SURFACE;
	mTio = TIO;
	mNio = NIO;
	mÅtta = ÅTTA;
	mSju = SJU;
	mSex = SEX;
	mFem = FEM;
	mFyra = FYRA;
	mTre = TRE;
	mTvå = TVÅ;
	mEtt = ETT;

	mMyFont = new Font("assets/font_fire.bmp");

	mUp = false; 
	mDown = false; 
	mLeft = false; 
	mRight = false; 
	mSpace = false; 


	//Bakgrundens position

	mBGX = 0.0f;
	mLifeX = 670;
	mLifeY = 5;
	mScoreX = 5;
	mScoreY = 5;
	mBossMode = false;

	//skapa rymdskepp

	mGameobject = new Rymdskepp();
	mGameobject->SetGamescreen(this);
	counter = 0;
	gameover = false;
	points = 0;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gamescreen::~Gamescreen() {
	printf("Gamescreen destroyed\n");

	delete mMyFont;
	// audiere.
	sMusic->stop();
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::KeyDown(SDL_Keycode keyCode) {
	if (keyCode == SDLK_LEFT) {
		mLeft = true;
	}
	else if (keyCode == SDLK_RIGHT) {
		mRight = true;
	}
	if (keyCode == SDLK_UP) {
		mUp = true;
	}
	else if (keyCode == SDLK_DOWN) {
		mDown = true;
	}
	if (keyCode == SDLK_SPACE) {
		mSpace = true;
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::KeyUp(SDL_Keycode keyCode) {
	if (keyCode == SDLK_LEFT) {
		mLeft = false;
		mGameobject->SetSpeedX(0.0);
	}
	else if (keyCode == SDLK_RIGHT) {
		mRight = false;
		mGameobject->SetSpeedX(0.0);
	}

	if (keyCode == SDLK_UP) {
		mUp = false;
		mGameobject->SetSpeedY(0.0);
	}
	else if (keyCode == SDLK_DOWN) {
		mDown = false;
		mGameobject->SetSpeedY(0.0);
	}
	if (keyCode == SDLK_SPACE) {
		mSpace = false;
	}
	if (keyCode == SDLK_q) {
		GameApp()->SetScreen(new Gameover(points)); 
	} 

}

////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::Update() {

	mBGX = mBGX - 0.5f;
	if (mBGX < -800.0) 
		mBGX += 800.0;

	if (points != 0 && points%1000 == 0 && !mBossMode)
	{
		GenerateBoss(247);
		mBossMode = true;
		printf("Boss Mode Engaged! ITS ON!\n");
	}
	else if (!mBossMode)
	{
		if (counter < 1500 && counter % 200 == 0){
			randy = rand() % 493 + 40;
			GenerateEnemy(randy);
		}
		else if (counter >= 1500 && counter < 3000 && counter % 150 == 0) {
			randy = rand() % 493 + 40;
			GenerateWeaponEnemy(randy);
		}
			else if (counter >= 3000 && counter < 4500 && counter % 100 == 0) {
			randy = rand() % 493 + 40;
			if (counter % 200 == 0)
				GenerateWeaponEnemy(randy);
			else
				GenerateEnemy(randy);
		}
		else if (counter >= 4500 && counter < 5000 && counter % 50 == 0) { //Zombie Wave
					randy = rand() % 493 + 40;
				GenerateEnemy(randy);
					randy = rand() % 493 + 40;
			
				GenerateEnemy(randy);
		}
		else if (counter >= 5000 && counter < 6500 && counter % 80 == 0) {
			randy = rand() % 493 + 40;
			if (counter % 160 == 0)
				GenerateWeaponEnemy(randy);
			else
				GenerateEnemy(randy);
		}
		else if (counter >= 6500 && counter < 8000 && counter % 60 == 0) {
			randy = rand() % 493 + 40;
			if (counter % 120 == 0)
				GenerateWeaponEnemy(randy);
			else
				GenerateEnemy(randy);
		}
		else if (counter < 8500 && counter % 8000 == 0) { 
			randy = rand() % 493 + 40;
			GenerateShield(randy, -1.0);
			randy = rand() % 493 + 40;
			GenerateWideshot(randy, -1.0);
		}

		else if (counter >= 8500 && counter < 9000 && counter % 100 == 0) { // Ufo Wave
			GenerateWeaponEnemy(50);
			GenerateWeaponEnemy(200);
			GenerateWeaponEnemy(350);
			GenerateWeaponEnemy(500);
		}
		else if (counter >= 9000 && counter % 50 == 0) {
			randy = rand() % 493 + 40;
			if (counter % 100 == 0)
				GenerateWeaponEnemy(randy);
			else
				GenerateEnemy(randy);
		}
	}

	if (life <= 50 && points >=100 && counter%800 == 0) {
		randy = rand()%493 + 40;
		if (counter % 1600 == 0)
			GenerateLife(randy, -1.0);
		else
			GenerateShield(randy, -1.0);
	}

	if (life <= 30 && points >= 100 && counter % 1000 == 0){
		randy = rand() % 493 + 40;
		GenerateLife(randy, -1.0);
	}

	if (points >=150 && counter%1000 == 0) {
		randy = rand()%493 + 40;
		if (counter%3000 == 0)
			GenerateSpeed(randy, -1.0);
		else if (counter%2000 == 0)
			GenerateWideshot(randy, -1.0);
		else
			GenerateWeapon(randy, -1.0);
	}


	CheckOverlapSpaceship(mGameobject, enemies, enemybullets, powerup); 
	CheckOverlapHerobullets(herobullets, enemies, powerup);

	mGameobject->Update();
	
	for (std::list<Gameobject*>::iterator it = herobullets.begin(); it != herobullets.end(); ++it) {
		(*it)->Update();
	}
	for (std::list<Gameobject*>::iterator it = enemybullets.begin(); it != enemybullets.end(); ++it) {
		(*it)->Update();
	}
	for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
		(*it)->Update();
	}

	for (std::list<PowerUp*>::iterator it = powerup.begin(); it != powerup.end(); ++it) { 
  		(*it)->Update(); 
  	} 

	for (std::list<Gameobject*>::iterator it=killedherobullets.begin(); it != killedherobullets.end(); ++it) {
			herobullets.remove(*it);	
			enemybullets.remove(*it);
		delete *it;
	}
	for (std::list<Enemy*>::iterator it=killedenemies.begin(); it != killedenemies.end(); ++it) {
		enemies.remove(*it);
		delete *it;
	}
	for (std::list<PowerUp*>::iterator it = killedpowerups.begin(); it != killedpowerups.end(); ++it) { 
  		powerup.remove(*it); 
  		delete *it; 
  	} 

	killedherobullets.clear();
	killedenemies.clear();
	killedpowerups.clear();
	if (mUp)
		mGameobject->SetSpeedY(-2.0);
	if (mDown)
		mGameobject->SetSpeedY(2.0);
	if (mLeft)
		mGameobject->SetSpeedX(-2.0);
	if (mRight)
		mGameobject->SetSpeedX(2.0);
	if (mSpace)
		mGameobject->Fire();
	if (gameover) {
		KillAll();
		delete mGameobject;
		printf("GAME OVER!!!\n");
		GameApp()->SetScreen(new Gameover(points));
	}
	counter = counter + 1;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::Draw(Graphics *g) {
	
	g->DrawImage(mBGSurface, (int)mBGX, 0);
	g->DrawImage(mBGSurface, (int)(mBGX + 800.0), 0);
	
	mGameobject->Draw(g);

	Rymdskepp *rp = dynamic_cast<Rymdskepp*>(mGameobject);

	life = rp->GetHealth();
	if (life >= 100)
		g->DrawImage(mTio, mLifeX, mLifeY);
	else if (life == 90)
		g->DrawImage(mNio, mLifeX, mLifeY);
	else if (life == 80)
		g->DrawImage(mÅtta, mLifeX, mLifeY);		
	else if (life == 70)
		g->DrawImage(mSju, mLifeX, mLifeY);
	else if (life == 60)
		g->DrawImage(mSex, mLifeX, mLifeY);
	else if (life == 50)
		g->DrawImage(mFem, mLifeX, mLifeY);
	else if (life == 40)
		g->DrawImage(mFyra, mLifeX, mLifeY);
	else if (life == 30)
		g->DrawImage(mTre, mLifeX, mLifeY);
	else if (life == 20)
		g->DrawImage(mTvå, mLifeX, mLifeY);
	else if (life == 10)
		g->DrawImage(mEtt, mLifeX, mLifeY);

	
	char tmp[64];
	sprintf(tmp, "SCORE: %d", points);
	mMyFont->WriteString(g, tmp, 10, 5);
	

	for (std::list<Gameobject*>::iterator it = herobullets.begin(); it != herobullets.end(); ++it) {
		(*it)->Draw(g);
	}
	for (std::list<Gameobject*>::iterator it = enemybullets.begin(); it != enemybullets.end(); ++it) {
		(*it)->Draw(g);
	}
	for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
		(*it)->Draw(g);
	}
	for (std::list<PowerUp*>::iterator it = powerup.begin(); it != powerup.end(); ++it) { 
  		(*it)->Draw(g); 
	} 

}
///////////////////////////////
void Gamescreen::SetGameobject(Gameobject *gameobject) {
	if (gameobject) gameobject->SetGamescreen(this);
	if (mGameobject == 0) {
		mGameobject = gameobject;
	}
}
//////////////////
void Gamescreen::GenerateProjectileSpaceship(float x, float y, float sy) {
	ProjectileSpaceship *tempbullet = new ProjectileSpaceship(x, y, sy);
	tempbullet->SetGamescreen(this);
	herobullets.push_back(tempbullet);
	// audiere.
	sShootSound->play();
}
///////////////////////
void Gamescreen::GenerateProjectileEnemy(float x, float y, float sx, float sy) {
	ProjectileEnemy *tempbullet = new ProjectileEnemy(x, y, sx, sy);
	tempbullet->SetGamescreen(this);
	enemybullets.push_back(tempbullet);
	// audiere.
	sShootSound->play();
}

void Gamescreen::GenerateProjectileBoss(float x, float y, float sx, float sy) {
	ProjectileBoss *tempbullet = new ProjectileBoss(x, y, sx, sy);
	tempbullet->SetGamescreen(this);
	enemybullets.push_back(tempbullet);
	// audiere.
	sShootSound->play();
}
void Gamescreen::GenerateShrapnel(float x, float y, float sx, float sy) {
	Shrapnel *tempbullet = new Shrapnel(x, y, sx, sy);
	tempbullet->SetGamescreen(this);
	enemybullets.push_back(tempbullet);
	// audiere.
	sShootSound->play();
}


void Gamescreen::GenerateWallshot(float x, float y, float sx, float sy) {
	Wallshot *tempbullet = new Wallshot(x, y, sx, sy);
	tempbullet->SetGamescreen(this);
	enemybullets.push_back(tempbullet);
}
void Gamescreen::GenerateSplitshot(float x, float y, float sx) {
	Splitshot *tempbullet = new Splitshot(x, y, sx, mGameobject->GetPosX(), mGameobject->GetPosY());
	tempbullet->SetGamescreen(this);
	enemybullets.push_back(tempbullet);
}
/////////////////////////////
void Gamescreen::KillObject(Gameobject *gameobject) {
	auto result = std::find(killedherobullets.begin(), killedherobullets.end(), gameobject);
	if (result == killedherobullets.end())
		killedherobullets.push_back(gameobject);

}
//////////////////////////////
void Gamescreen::KillObjectEnemy(Enemy *enemy) {
	auto result = std::find(killedenemies.begin(), killedenemies.end(), enemy);
	if (result == killedenemies.end()) {
		killedenemies.push_back(enemy);
	}
}
/////////////////////////////
void Gamescreen::KillSpaceship() {
	gameover = true;
	// audiere.
	sExplosionSound->play();
}
////////////////////////////
void Gamescreen::KillObjectPowerUp(PowerUp *powerup) {
	auto result = std::find(killedpowerups.begin(), killedpowerups.end(), powerup); 
	if (result == killedpowerups.end()) { 
  		killedpowerups.push_back(powerup); 
  	} 
} 

////////////////////////////////7
void Gamescreen::GenerateEnemy(float y) {
	Enemy *tempenemy = new Enemy(y);
	tempenemy->SetGamescreen(this);
	enemies.push_back(tempenemy);
}
//////////////////////////////////
void Gamescreen::GenerateWeaponEnemy(float y) {
	WeaponEnemy *tempenemy = new WeaponEnemy(y);
	tempenemy->SetGamescreen(this);
	enemies.push_back(tempenemy);
}

void Gamescreen::GenerateBoss(float y) {
	Enemy *tempenemy = new Boss(y);
	tempenemy->SetGamescreen(this);
	enemies.push_back(tempenemy);
}
/////////////////////////////////
void Gamescreen::GenerateShield(float y, float xs) { 
  	PowerUp *tempPowerUp = new Shield(y,xs); 
  	tempPowerUp->SetGamescreen(this); 
  	powerup.push_back(tempPowerUp); 
} 
/////////////////////////////////
void Gamescreen::GenerateLife(float y, float xs) { 
  	PowerUp *tempPowerUp = new Life(y,xs); 
  	tempPowerUp->SetGamescreen(this); 
  	powerup.push_back(tempPowerUp); 
} 
/////////////////////////////////
void Gamescreen::GenerateSpeed(float y, float xs) { 
  	PowerUp *tempPowerUp = new Speed(y,xs); 
  	tempPowerUp->SetGamescreen(this); 
  	powerup.push_back(tempPowerUp); 
} 
/////////////////////////////////
void Gamescreen::GenerateWeapon(float y, float xs) { 
  	PowerUp *tempPowerUp = new Weapon(y,xs); 
  	tempPowerUp->SetGamescreen(this); 
  	powerup.push_back(tempPowerUp); 
} 

void Gamescreen::GenerateWideshot(float y, float xs) {
	PowerUp *tempPowerUp = new Wideshot(y, xs);
	tempPowerUp->SetGamescreen(this);
	powerup.push_back(tempPowerUp);
}

/////////////////////////////7

void Gamescreen::CheckOverlapSpaceship(Gameobject *gameobject, std::list<Enemy*> enemies, std::list<Gameobject*> enemybullets, std::list<PowerUp*> powerup) {
	for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
		if ((mGameobject->GetPosX()+ mGameobject->Getw()) < (*it)->GetPosX() || (mGameobject->GetPosX() > ((*it)->GetPosX() + (*it)->Getw())))
			printf("");
		else if ((mGameobject->GetPosY()+ mGameobject->Geth()) < (*it)->GetPosY() || (mGameobject->GetPosY() > ((*it)->GetPosY() + (*it)->Geth())))
			printf("");
		else {
			mGameobject->Overlap(*it);
			(*it)->Overlap(mGameobject);
		}
	}

	for (std::list<Gameobject*>::iterator it = enemybullets.begin(); it != enemybullets.end(); ++it) {
		if ((mGameobject->GetPosX() + mGameobject->Getw()) < (*it)->GetPosX() || (mGameobject->GetPosX() > ((*it)->GetPosX() + (*it)->Getw())))
			printf("");
		else if ((mGameobject->GetPosY() + mGameobject->Geth()) < (*it)->GetPosY() || (mGameobject->GetPosY() > ((*it)->GetPosY() + (*it)->Geth())))
			printf("");
		else {
			mGameobject->Overlap(*it);
			(*it)->Overlap(mGameobject);
		}
	}
	for (std::list<PowerUp*>::iterator it = powerup.begin(); it != powerup.end(); ++it) { 
  		if ((mGameobject->GetPosX() + mGameobject->Getw()) < (*it)->GetPosX() || (mGameobject->GetPosX() > ((*it)->GetPosX() + (*it)->Getw()))) 
  				printf(""); 
  		else if ((mGameobject->GetPosY() + mGameobject->Geth()) < (*it)->GetPosY() || (mGameobject->GetPosY() > ((*it)->GetPosY() + (*it)->Geth()))) 
  				printf(""); 
  		else { 
  			mGameobject->Overlap(*it); 
  			(*it)->Overlap(mGameobject); 
  		} 
  	} 

}
//////////////////////////////////

void Gamescreen::CheckOverlapHerobullets(std::list<Gameobject*> herobullets, std::list<Enemy*> enemies, std::list<PowerUp*> powerup) {
	for (std::list<Gameobject*>::iterator hbit = herobullets.begin(); hbit != herobullets.end(); ++hbit) {
		for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
			if (((*hbit)->GetPosX()+ (*hbit)->Getw()) < (*it)->GetPosX() || ((*hbit)->GetPosX() > ((*it)->GetPosX() + (*it)->Getw())))
				printf("");
			else if (((*hbit)->GetPosY()+ (*hbit)->Geth()) < (*it)->GetPosY() || ((*hbit)->GetPosY() > ((*it)->GetPosY() + (*it)->Geth())))
				printf("");
			else {
				(*hbit)->Overlap(*it);
				(*it)->Overlap(*hbit);
			}
		}
	for (std::list<PowerUp*>::iterator it = powerup.begin(); it != powerup.end(); ++it) { 
  		if (((*hbit)->GetPosX() + (*hbit)->Getw()) < (*it)->GetPosX() || ((*hbit)->GetPosX() > ((*it)->GetPosX() + (*it)->Getw()))) 
  				printf(""); 
  		else if (((*hbit)->GetPosY() + (*hbit)->Geth()) < (*it)->GetPosY() || ((*hbit)->GetPosY() > ((*it)->GetPosY() + (*it)->Geth()))) 
  				printf(""); 
  		else { 
  			(*hbit)->Overlap(*it); 
  			(*it)->Overlap(*hbit); 
  			} 
  		} 
	}
}
///////////////////////////////
void Gamescreen::PointsToPlayer(int p) {
	points = points + p;
	printf("Points=%d\n", points);
}
////////////////////7
void Gamescreen::KillAll() {
	for (std::list<Gameobject*>::iterator it = herobullets.begin(); it != herobullets.end(); ++it) {
		delete *it;
	}
	for (std::list<Gameobject*>::iterator it = enemybullets.begin(); it != enemybullets.end(); ++it) {
		delete *it;
	}
	for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
		delete *it;
	}
	for (std::list<PowerUp*>::iterator it=powerup.begin(); it != powerup.end(); ++it) {
		delete *it;
	}
}
///////////////////7
void Gamescreen::BoostLife(int h) {
	Rymdskepp *rp = dynamic_cast<Rymdskepp*>(mGameobject);
	rp->SetHealth(h);
}

void Gamescreen::BoostShield(int d) {
	Rymdskepp *rp = dynamic_cast<Rymdskepp*>(mGameobject);
	rp->setshield(d);
}

void Gamescreen::BoostSpeed(int p) {
	Rymdskepp *rp = dynamic_cast<Rymdskepp*>(mGameobject);
	rp->SetPowerSpeed(p);
}
void Gamescreen::BoostWeapon(int g) {
	Rymdskepp *rp = dynamic_cast<Rymdskepp*>(mGameobject);
	rp->SetWeapon(g);
}
void Gamescreen::DisableBoss(){
	mBossMode = false;
}
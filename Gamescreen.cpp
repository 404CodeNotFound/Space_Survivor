#include "Gamescreen.h"
#include "BlinkScreen.h"
#include "Gameover.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Rymdskepp.h"
#include "Res.h"
#include "ProjectileSpaceship.h"
#include "Enemy.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gamescreen::Gamescreen() {

	mGameobject = 0;	

	// Läs in en bild av ett ansikte.
	//mFaceSurface = SDL_LoadBMP("assets/face.bmp");
	//SDL_SetColorKey(mFaceSurface, SDL_TRUE, RGB(255, 0, 255));

	//Läs in bakgrundsbild

	//mBGSurface = SDL_LoadBMP("assets/background.bmp");
	mBGSurface = BG_SURFACE;


	// Ansiktets position och hastighet.
	//mFaceX = 100;
	//mFaceY = 100;
	//mFaceSpeedX = 0;
	//mFaceSpeedY = 0;

	//Bakgrundens position

	mBGX = 0.0f;

	//skapa rymdskepp

	//SetGameobject(new Rymdskepp());
	mGameobject = new Rymdskepp();
	mGameobject->SetGamescreen(this);
	counter = 0;
	gameover = false;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gamescreen::~Gamescreen() {
	// Frigör bild.
	//SDL_FreeSurface(mFaceSurface);
	//SDL_FreeSurface(mBGSurface);
	printf("Gamescreen destroyed\n");
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::KeyDown(SDL_Keycode keyCode) {
	// Sätt hastighet för rymdskeppet.
	if (keyCode == SDLK_LEFT) {
		mGameobject->SetSpeedX(-2.0);
	}
	else if (keyCode == SDLK_RIGHT) {
		mGameobject->SetSpeedX(2.0);
	}
	if (keyCode == SDLK_UP) {
		mGameobject->SetSpeedY(-2.0);
	}
	else if (keyCode == SDLK_DOWN) {
		mGameobject->SetSpeedY(2.0);
	}
	if (keyCode == SDLK_SPACE) {
		//GenerateProjectileSpaceship(mGameobject->GetPosX(), mGameobject->GetPosY());
		mGameobject->Fire();
	}
	/*else if (keyCode == SDLK_ESCAPE) {
		GameApp()->SetScreen(new BlinkScreen());
	}*/
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::KeyUp(SDL_Keycode keyCode) {
	if (keyCode == SDLK_LEFT || keyCode == SDLK_RIGHT) {
		//mFaceSpeedX = 0;
		mGameobject->SetSpeedX(0.0);
	}
	else if (keyCode == SDLK_UP || keyCode == SDLK_DOWN) {
		//mFaceSpeedY = 0;
		mGameobject->SetSpeedY(0.0);
	}
}

////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::Update() {

	mBGX = mBGX - 1.0f;
	if (mBGX < -640.0) mBGX += 640.0;

	if (counter < 3000 && counter%200 == 0){
		randy = rand()%416;
		GenerateEnemy(randy);
		//printf("Counter = %d\n", counter);
	}
	else if (counter >= 3000 && counter < 6000 && counter%100 == 0) {
		randy = rand()%416;
		GenerateEnemy(randy);
		//printf("Counter = %d\n", counter);
		//printf("bredd = %d\n", w);
	}
	else if (counter >= 6000 && counter%50 == 0) {
		randy = rand()%416;
		GenerateEnemy(randy);
		//printf("Counter = %d\n", counter);
		//printf("bredd = %d\n", w);
	}

	CheckOverlapSpaceship(mGameobject, enemies); 
	CheckOverlapHerobullets(herobullets, enemies);

	mGameobject->Update();
	for (std::list<ProjectileSpaceship*>::iterator it=herobullets.begin(); it != herobullets.end(); ++it) {
		(*it)->Update();
	}
	for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
		(*it)->Update();
	}
	for (std::list<ProjectileSpaceship*>::iterator it=killedherobullets.begin(); it != killedherobullets.end(); ++it) {
		herobullets.remove(*it);
		//printf("Finally killed projectile!\n");
		delete *it;
	}
	for (std::list<Enemy*>::iterator it=killedenemies.begin(); it != killedenemies.end(); ++it) {
		enemies.remove(*it);
		delete *it;
		//printf("Finally killed enemy!\n");
	}
	killedherobullets.clear();
	killedenemies.clear();
	if (gameover) {
		delete mGameobject;
		printf("GAME OVER!!!\n");
		GameApp()->SetScreen(new Gameover());
	}
	counter = counter + 1;
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Gamescreen::Draw(Graphics *g) {
	// Rensa skärmen.
	//g->Clear(RGB(255, 255, 255));
	g->DrawImage(mBGSurface, (int)mBGX, 0);
	g->DrawImage(mBGSurface, (int)(mBGX + 640.0), 0);
	// Rita ut ansikte.
	//g->DrawImage(mFaceSurface, mFaceX, mFaceY);
	mGameobject->Draw(g);
	/*for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
    std::cout << ' ' << *it;
	std::list<ProjectileSpaceship*> herobullets;
	*/
	for (std::list<ProjectileSpaceship*>::iterator it=herobullets.begin(); it != herobullets.end(); ++it) {
		(*it)->Draw(g);
	}
	for (std::list<Enemy*>::iterator it=enemies.begin(); it != enemies.end(); ++it) {
		(*it)->Draw(g);
	}


}
///////////////////////////////
void Gamescreen::SetGameobject(Gameobject *gameobject) {
	if (gameobject) gameobject->SetGamescreen(this);
	if (mGameobject == 0) {
		mGameobject = gameobject;
	}
/*	else {
		mNewScreen = screen;
	}*/
}
//////////////////
void Gamescreen::GenerateProjectileSpaceship(float x, float y) {
	ProjectileSpaceship *tempbullet = new ProjectileSpaceship(x, y);
	tempbullet->SetGamescreen(this);
	herobullets.push_back(tempbullet);
	//printf("Gave birth to projectile!\n");
}
/////////////////////////////
void Gamescreen::KillObject(ProjectileSpaceship *projectile) {
	killedherobullets.push_back(projectile);
	//printf("Killed projectile!\n");
}
//////////////////////////////
void Gamescreen::KillObjectEnemy(Enemy *enemy) {
	killedenemies.push_back(enemy);
	//printf("Killed enemy!\n");
}
/////////////////////////////
void Gamescreen::KillSpaceship() {
	gameover = true;
	//delete mGameobject;
	//printf("GAME OVER!!!\n");
}
////////////////////////////
void Gamescreen::GenerateEnemy(float y) {
	Enemy *tempenemy = new Enemy(y);
	tempenemy->SetGamescreen(this);
	enemies.push_back(tempenemy);
	//printf("Gave birth to enemy!\n");
}
//////////////////////////////////7
void Gamescreen::CheckOverlapSpaceship(Gameobject *gameobject, std::list<Enemy*> enemies) {
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
}
//////////////////////////////////
void Gamescreen::CheckOverlapHerobullets(std::list<ProjectileSpaceship*> herobullets, std::list<Enemy*> enemies) {
	for (std::list<ProjectileSpaceship*>::iterator hbit=herobullets.begin(); hbit != herobullets.end(); ++hbit) {
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
	}
}
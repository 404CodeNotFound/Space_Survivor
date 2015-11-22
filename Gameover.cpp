#include "Gameover.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "audiere.h"
#include <stdio.h>


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gameover::Gameover() {

	//L�s in bakgrundsbild

	mGameoverSurface = GAME_OVER_SURFACE;
	//audiere
	sDarth->play();
	sDarth->setRepeat(false);

	//Bakgrundens position

	mBGX = 0.0f;
	counter = 0;
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Gameover::~Gameover() {
	
	// audiere.
	sDarth->stop();
	printf("Gameover destroyed\n");
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 g�nger per sekund. Utf�r all logik h�r. 
////////////////////////////////////////////////////////////////////////////////
void Gameover::Update() {

	if (counter == 800) {
		GameApp()->SetScreen(new Gamescreen());
	}
	counter = counter + 1;
}

////////////////////////////////////////////////////////////////////////////////
// Utf�r all utritning h�r.
////////////////////////////////////////////////////////////////////////////////
void Gameover::Draw(Graphics *g) {
	g->DrawImage(mGameoverSurface, (int)mBGX, 0);
}
//////////////////////7
void Gameover::KeyDown(SDL_Keycode keyCode) {
}

void Gameover::KeyUp(SDL_Keycode keyCode) {
}


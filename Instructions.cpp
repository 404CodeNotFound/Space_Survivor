#include "Instructions.h"
#include "GameApp.h"
#include "audiere.h"
#include "Startscreen.h"
#include "Res.h"
#include "Graphics.h"

Instructions::Instructions() {
	mInstrSurface = INSTRUCTION_SURFACE;
	sMusic->play();
	sMusic->setRepeat(true);
	mBGX = 0.0f;

	mButtonX = 23.0f;
	mButtonY = 533.0f;

	mButton = false;
	mPressed = false;
}

Instructions::~Instructions() {
	sMusic->stop();
}

void Instructions::Draw(Graphics *g) {
	g->DrawImage(INSTRUCTION_SURFACE, (int)mBGX, 0);

	if (mPressed) {
		g->DrawImage(BACK_BUTTON, (int)mButtonX, mButtonY);

	}

}

void Instructions::KeyEvent() {
	SDL_Event keyEvent;

	while (SDL_PollEvent(&keyEvent) != 0) {
		if (keyEvent.type == SDL_KEYDOWN) {
			KeyDown(keyEvent.key.keysym.sym);
		}

		else if (keyEvent.type == SDL_KEYUP) {
			KeyUp(keyEvent.key.keysym.sym);
		}

	}

}

void Instructions::KeyDown(SDL_Keycode keyCode) {
	// Om man trycker ner knappen, då ska knappen lysa. 
	// dvs läsa in "pressed button"
	if (keyCode == SDLK_LEFT) {
		mPressed = true;
		//  läsa in "pressed button"
	}
}

void Instructions::KeyUp(SDL_Keycode keyCode) {
	// Om man släpper knappen, då ska man flyttas till startscreen
	if (keyCode == SDLK_LEFT) {
		mReturn = true;
		mPressed = false;
	}
}

void Instructions::Update() {
	if (mReturn) {
		GameApp()->SetScreen(new Startscreen());
	}

}
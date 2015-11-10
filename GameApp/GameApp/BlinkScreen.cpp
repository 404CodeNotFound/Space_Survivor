#include "BlinkScreen.h"
#include "Graphics.h"
#include <stdlib.h>

BlinkScreen::BlinkScreen() {
	mCounter = 0;
	mRed = 0;
	mGreen = 0;
	mBlue = 0;
}

BlinkScreen::~BlinkScreen() {
}

void BlinkScreen::KeyDown(SDL_Keycode keyCode) {
}

void BlinkScreen::KeyUp(SDL_Keycode keyCode) {
}

void BlinkScreen::Update() {
	mCounter = (mCounter + 1)%100;
	if (mCounter == 0) {
		mRed = rand()%256;
		mGreen = rand()%256;
		mBlue = rand()%256;
	}
}

void BlinkScreen::Draw(Graphics *g) {
	g->Clear(RGB(mRed, mGreen, mBlue));
}

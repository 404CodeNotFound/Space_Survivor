#include "Font.h"
#include "Graphics.h"
#include "SDL.h"
#include <cstring>

Font::Font(char *filename) {
	// Läs in bild.
	mSurface = SDL_LoadBMP(filename);
	if (mSurface) {
		SDL_SetColorKey(mSurface, SDL_TRUE, RGB(255, 0, 255)); 
		// Beräkna storleken för varje tecken.
		mCelWidth = mSurface->w/8;
		mCelHeight = mSurface->h/8;

		// mChar är index för en "ruta" i bilden. -1 för ett tecken
		// betyder att tecknet inte finns.
		for (int i = 0; i < 256; i++) {
			mChars[i] = -1;
		}
		// Sätt alla tecken.
		mChars['0'] = 0;
		mChars['1'] = 1;
		mChars['2'] = 2;
		mChars['3'] = 3;
		mChars['4'] = 4;
		mChars['5'] = 5;
		mChars['6'] = 6;
		mChars['7'] = 7;
		mChars['8'] = 8;
		mChars['9'] = 9;

		mChars['A'] = 10;
		mChars['B'] = 11;
		mChars['C'] = 12;
		mChars['D'] = 13;
		mChars['E'] = 14;
		mChars['F'] = 15;
		mChars['G'] = 16;
		mChars['H'] = 17;
		mChars['I'] = 18;
		mChars['J'] = 19;
		mChars['K'] = 20;
		mChars['L'] = 21;
		mChars['M'] = 22;
		mChars['N'] = 23;
		mChars['O'] = 24;
		mChars['P'] = 25;
		mChars['Q'] = 26;
		mChars['R'] = 27;
		mChars['S'] = 28;
		mChars['T'] = 29;
		mChars['U'] = 30;
		mChars['V'] = 31;
		mChars['W'] = 32;
		mChars['X'] = 33;
		mChars['Y'] = 34;
		mChars['Z'] = 35;
		mChars['.'] = 36;
		mChars[','] = 37;
		mChars[':'] = 38;
		mChars[' '] = 63;
	}
}

Font::~Font() {
	SDL_FreeSurface(mSurface);
}

void Font::WriteString(Graphics *g, const char *txt, int x, int y) {
	int l = (int)strlen(txt);
	
	for (int i = 0; i < l; i++) {
		// Rita ut tecknet om det finns.
		int c = mChars[txt[i]];
		if (c >= 0) {
			int charX, charY;
			charX = (c%8)*mCelWidth;
			charY = (c/8)*mCelHeight;
			//g->DrawImage(mSurface, x, y, charX, charY, mCelWidth, mCelHeight);
			x += mCelWidth;
		}
	}
}


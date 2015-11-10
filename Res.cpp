#include "Res.h"
#include "SDL.h"
#include "Graphics.h"
#include <stdio.h>

// Skriv s�h�r f�r alla bilder.
SDL_Surface *FACE_SURFACE = 0;
SDL_Surface *BG_SURFACE = 0;

bool LoadResources() {
	// Skriv s�h�r f�r alla bilder.

	FACE_SURFACE = SDL_LoadBMP("assets/face.bmp");
	// G�r f�rgen rosa transparent.
	SDL_SetColorKey(FACE_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	BG_SURFACE = SDL_LoadBMP("assets/background.bmp");

	printf("FACE %p   BG %p\n", FACE_SURFACE, BG_SURFACE);

	printf("BG STORLEK %d %d\n", BG_SURFACE->w, BG_SURFACE->h);

	return true;
}

void DeleteResources() {
	// Skriv s�h�r f�r alla bilder.
	SDL_FreeSurface(FACE_SURFACE);
	SDL_FreeSurface(BG_SURFACE);
}

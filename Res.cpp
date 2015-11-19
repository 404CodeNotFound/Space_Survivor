#include "Res.h"
#include "SDL.h"
#include "Graphics.h"
#include <stdio.h>

// Skriv såhär för alla bilder.
SDL_Surface *SHIP_SURFACE = 0;
SDL_Surface *FACE_SURFACE = 0;
SDL_Surface *BG_SURFACE = 0;
SDL_Surface *BIGBULLET_SURFACE = 0;
SDL_Surface *BULLET_SURFACE = 0;


bool LoadResources() {
	// Skriv såhär för alla bilder.

	FACE_SURFACE = SDL_LoadBMP("assets/face.bmp");

	SHIP_SURFACE = SDL_LoadBMP("assets/small_ship_2x.bmp");

	//FACE_SURFACE = SDL_LoadBMP("assets/Spaceship.bmp");
	// Gör färgen rosa transparent.
	SDL_SetColorKey(FACE_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(SHIP_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	//BG_SURFACE = SDL_LoadBMP("assets/background.bmp");

	BG_SURFACE = SDL_LoadBMP("assets/GamescreenBG2_2.bmp");

	printf("FACE %p   BG %p\n", FACE_SURFACE, BG_SURFACE);

	//printf("BG STORLEK %d %d\n", BG_SURFACE->w, BG_SURFACE->h);
	
	BULLET_SURFACE = SDL_LoadBMP("assets/bullet.bmp");
	SDL_SetColorKey(BULLET_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	BIGBULLET_SURFACE = SDL_LoadBMP("assets/bullet_2x.bmp");
	SDL_SetColorKey(BIGBULLET_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	return true;
}

void DeleteResources() {
	// Skriv såhär för alla bilder.
	SDL_FreeSurface(FACE_SURFACE);
	SDL_FreeSurface(BG_SURFACE);
}

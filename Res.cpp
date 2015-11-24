#include "Res.h"
#include "SDL.h"
#include "Graphics.h"
#include "audiere.h"
#include <stdio.h>

// Skriv såhär för alla bilder.
SDL_Surface *SHIP_SURFACE = 0;
SDL_Surface *FACE_SURFACE = 0;
SDL_Surface *UFO_SURFACE = 0;
SDL_Surface *BG_SURFACE = 0;
SDL_Surface *BIGBULLET_SURFACE = 0;
SDL_Surface *BULLET_SURFACE = 0;
SDL_Surface *GAME_OVER_SURFACE = 0;

// två ljudeffekter.
audiere::SoundEffectPtr sShootSound = 0;
audiere::SoundEffectPtr sExplosionSound = 0;
// musik.
audiere::OutputStreamPtr sMusic = 0;
audiere::OutputStreamPtr sDarth = 0;


bool LoadResources() {
	// Skriv såhär för alla bilder.

	FACE_SURFACE = SDL_LoadBMP("assets/zombie_enemy.bmp");
	UFO_SURFACE = SDL_LoadBMP("assets/ufo.bmp");

	SHIP_SURFACE = SDL_LoadBMP("assets/Spaceship_2.bmp");

	//FACE_SURFACE = SDL_LoadBMP("assets/Spaceship.bmp");
	// Gör färgen rosa transparent.
	SDL_SetColorKey(FACE_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(UFO_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(SHIP_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	//BG_SURFACE = SDL_LoadBMP("assets/background.bmp");

	//BG_SURFACE = SDL_LoadBMP("assets/GamescreenBG2_2.bmp");
	BG_SURFACE = SDL_LoadBMP("assets/GamescreenBG_BIG.bmp");

	printf("FACE %p   BG %p\n", FACE_SURFACE, BG_SURFACE);

	//printf("BG STORLEK %d %d\n", BG_SURFACE->w, BG_SURFACE->h);
	
	BULLET_SURFACE = SDL_LoadBMP("assets/bullet.bmp");
	SDL_SetColorKey(BULLET_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	BIGBULLET_SURFACE = SDL_LoadBMP("assets/bullet_2x.bmp");
	SDL_SetColorKey(BIGBULLET_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	//GAME_OVER_SURFACE = SDL_LoadBMP("assets/Game_Over_2.bmp");
	GAME_OVER_SURFACE = SDL_LoadBMP("assets/Game_Over_BIG.bmp");

	// audio device.
	audiere::AudioDevicePtr sAudioDevice;
	// audiere.
	sAudioDevice = audiere::OpenDevice();
	// ljudeffekter.
	sShootSound = audiere::OpenSoundEffect(sAudioDevice, "assets/shoot.wav", audiere::SINGLE);
	sExplosionSound = audiere::OpenSoundEffect(sAudioDevice, "assets/explosion.wav", audiere::SINGLE);
	// musik.
	sMusic = audiere::OpenSound(sAudioDevice, "assets/music.mp3", false);
	sDarth = audiere::OpenSound(sAudioDevice, "assets/gameover.mp3", false);

	return true;
}

void DeleteResources() {
	// Skriv såhär för alla bilder.
	SDL_FreeSurface(FACE_SURFACE);
	SDL_FreeSurface(BG_SURFACE);
}

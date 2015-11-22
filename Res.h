#ifndef __RES_H__
#define __RES_H__

struct SDL_Surface;
#include "audiere.h"

extern SDL_Surface *EN_BILD;
extern SDL_Surface *EN_ANNAN_BILD;
// Skriv s�h�r f�r alla bilder.
extern SDL_Surface *SHIP_SURFACE;
extern SDL_Surface *FACE_SURFACE;
extern SDL_Surface *BG_SURFACE;
extern SDL_Surface *BULLET_SURFACE;
extern SDL_Surface *BIGBULLET_SURFACE;
extern SDL_Surface *GAME_OVER_SURFACE;

// tv� ljudeffekter.
extern audiere::SoundEffectPtr sShootSound;
extern audiere::SoundEffectPtr sExplosionSound;
// musik.
extern audiere::OutputStreamPtr sMusic;
extern audiere::OutputStreamPtr sDarth;

bool LoadResources();
void DeleteResources();

#endif
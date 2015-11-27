#ifndef __RES_H__
#define __RES_H__

struct SDL_Surface;
#include "audiere.h"

extern SDL_Surface *EN_BILD;
extern SDL_Surface *EN_ANNAN_BILD;
// Skriv såhär för alla bilder.
extern SDL_Surface *SHIP_SURFACE;
extern SDL_Surface *FACE_SURFACE;
extern SDL_Surface *BG_SURFACE;
extern SDL_Surface *BULLET_SURFACE;
extern SDL_Surface *BIGBULLET_SURFACE;
extern SDL_Surface *GAME_OVER_SURFACE;
extern SDL_Surface *UFO_SURFACE;
extern SDL_Surface *TIO;
extern SDL_Surface *NIO;
extern SDL_Surface *ÅTTA;
extern SDL_Surface *SJU;
extern SDL_Surface *SEX;
extern SDL_Surface *FEM;
extern SDL_Surface *FYRA;
extern SDL_Surface *TRE;
extern SDL_Surface *TVÅ;
extern SDL_Surface *ETT;
extern SDL_Surface *HIGH_SCORE_SURFACE;

// två ljudeffekter.
extern audiere::SoundEffectPtr sShootSound;
extern audiere::SoundEffectPtr sExplosionSound;
// musik.
extern audiere::OutputStreamPtr sMusic;
extern audiere::OutputStreamPtr sDarth;

bool LoadResources();
void DeleteResources();

#endif
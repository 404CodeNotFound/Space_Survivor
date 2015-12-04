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
extern SDL_Surface *LIFE_PU_SURFACE;
extern SDL_Surface *SHIELD_PU_SURFACE;
extern SDL_Surface *WEAPON_PU_SURFACE;
extern SDL_Surface *SPEED_PU_SURFACE;

extern SDL_Surface *START_SURFACE;
extern SDL_Surface *GAME_BUTTON_SURFACE;
extern SDL_Surface *INSTR_BUTTON_SURFACE;
extern SDL_Surface *HIGH_SCORE_BUTTON_SURFACE;
extern SDL_Surface *QUIT_BUTTON_SURFACE;

extern SDL_Surface *INSTRUCTION_SURFACE;
extern SDL_Surface *BACK_BUTTON;

extern SDL_Surface *ENEMY_BULLET;
extern SDL_Surface *SPACESHIP_BULLET;
extern SDL_Surface *FAT_SHIELD;
extern SDL_Surface *SPEED_ICON;
extern SDL_Surface *WEAPON_ICON;

// två ljudeffekter.
extern audiere::SoundEffectPtr sShootSound;
extern audiere::SoundEffectPtr sExplosionSound;
extern audiere::SoundEffectPtr sBabyAouch;
// musik.
extern audiere::OutputStreamPtr sMusic;
extern audiere::OutputStreamPtr sDarth;

bool LoadResources();
void DeleteResources();

#endif
#ifndef __RES_H__
#define __RES_H__

struct SDL_Surface;
#include "audiere.h"

// Skriv s�h�r f�r alla bilder.
extern SDL_Surface *SHIP_SURFACE;
extern SDL_Surface *FACE_SURFACE;
extern SDL_Surface *BOSS_SURFACE;
extern SDL_Surface *BG_SURFACE;
extern SDL_Surface *BULLET_SURFACE;
extern SDL_Surface *BIGBULLET_SURFACE;
extern SDL_Surface *GAME_OVER_SURFACE;
extern SDL_Surface *UFO_SURFACE;
extern SDL_Surface *TIO;
extern SDL_Surface *NIO;
extern SDL_Surface *�TTA;
extern SDL_Surface *SJU;
extern SDL_Surface *SEX;
extern SDL_Surface *FEM;
extern SDL_Surface *FYRA;
extern SDL_Surface *TRE;
extern SDL_Surface *TV�;
extern SDL_Surface *ETT;
extern SDL_Surface *HIGH_SCORE_SURFACE;
extern SDL_Surface *LIFE_PU_SURFACE;
extern SDL_Surface *SHIELD_PU_SURFACE;
extern SDL_Surface *WEAPON_PU_SURFACE;
extern SDL_Surface *SPEED_PU_SURFACE;
extern SDL_Surface *WIDESHOT_PU_SURFACE;

extern SDL_Surface *START_SURFACE;
extern SDL_Surface *GAME_BUTTON_SURFACE;
extern SDL_Surface *INSTR_BUTTON_SURFACE;
extern SDL_Surface *HIGH_SCORE_BUTTON_SURFACE;
extern SDL_Surface *QUIT_BUTTON_SURFACE;

extern SDL_Surface *INSTRUCTION_SURFACE;
extern SDL_Surface *BACK_BUTTON;

extern SDL_Surface *ENEMY_BULLET;
extern SDL_Surface *SPACESHIP_BULLET;
extern SDL_Surface *GREEN_BULLET;
extern SDL_Surface *FIRE_BOMB;
extern SDL_Surface *ROUND_BULLET;
extern SDL_Surface *FAT_SHIELD;
extern SDL_Surface *SPEED_ICON;
extern SDL_Surface *WEAPON_ICON;
extern SDL_Surface *WIDESHOT_ICON;

// ljudeffekter.
extern audiere::SoundEffectPtr sShootSound;
extern audiere::SoundEffectPtr sExplosionSound;
extern audiere::SoundEffectPtr sBabyAouch;
extern audiere::SoundEffectPtr sHeart;
extern audiere::SoundEffectPtr sSplitShot;
extern audiere::SoundEffectPtr sWallShot;
extern audiere::SoundEffectPtr sBossFire;
extern audiere::SoundEffectPtr sLostLife;
// musik.
extern audiere::OutputStreamPtr sMusic;
extern audiere::OutputStreamPtr sDarth;
extern audiere::OutputStreamPtr sStartmusic;
extern audiere::OutputStreamPtr sInstrmusic;

bool LoadResources();
void DeleteResources();

#endif
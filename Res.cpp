#include "Res.h"
#include "SDL.h"
#include "Graphics.h"
#include "audiere.h"
#include <stdio.h>

// Skriv såhär för alla bilder.
SDL_Surface *SHIP_SURFACE = 0;
SDL_Surface *FACE_SURFACE = 0;
SDL_Surface *BG_SURFACE = 0;
SDL_Surface *BIGBULLET_SURFACE = 0;
SDL_Surface *BULLET_SURFACE = 0;
SDL_Surface *GAME_OVER_SURFACE = 0;
SDL_Surface *UFO_SURFACE = 0;
SDL_Surface *BOSS_SURFACE = 0;
SDL_Surface *TIO = 0;
SDL_Surface *NIO = 0;
SDL_Surface *ÅTTA = 0;
SDL_Surface *SJU = 0;
SDL_Surface *SEX = 0;
SDL_Surface *FEM = 0;
SDL_Surface *FYRA = 0;
SDL_Surface *TRE = 0;
SDL_Surface *TVÅ = 0;
SDL_Surface *ETT = 0;
SDL_Surface *HIGH_SCORE_SURFACE = 0;

SDL_Surface *LIFE_PU_SURFACE = 0;
SDL_Surface *SHIELD_PU_SURFACE = 0;
SDL_Surface *WEAPON_PU_SURFACE = 0;
SDL_Surface *SPEED_PU_SURFACE = 0;
SDL_Surface *WIDESHOT_PU_SURFACE = 0;

SDL_Surface *START_SURFACE = 0;
SDL_Surface *GAME_BUTTON_SURFACE = 0;
SDL_Surface *INSTR_BUTTON_SURFACE = 0;
SDL_Surface *HIGH_SCORE_BUTTON_SURFACE = 0;
SDL_Surface *QUIT_BUTTON_SURFACE = 0;

SDL_Surface *INSTRUCTION_SURFACE = 0;
SDL_Surface *BACK_BUTTON = 0;

SDL_Surface *ENEMY_BULLET = 0;
SDL_Surface *GREEN_BULLET = 0;
SDL_Surface *SPACESHIP_BULLET = 0;
SDL_Surface *FIRE_BOMB = 0;
SDL_Surface *ROUND_BULLET = 0;
SDL_Surface *FAT_SHIELD = 0;
SDL_Surface *SPEED_ICON = 0;
SDL_Surface *WEAPON_ICON = 0;
SDL_Surface *WIDESHOT_ICON = 0;

// ljudeffekter.
audiere::SoundEffectPtr sShootSound = 0;
audiere::SoundEffectPtr sExplosionSound = 0;
audiere::SoundEffectPtr sBabyAouch = 0;
audiere::SoundEffectPtr sHeart = 0;
audiere::SoundEffectPtr sSplitShot = 0;
audiere::SoundEffectPtr sWallShot = 0;
audiere::SoundEffectPtr sBossFire = 0;
audiere::SoundEffectPtr sLostLife = 0;
// musik.
audiere::OutputStreamPtr sMusic = 0;
audiere::OutputStreamPtr sDarth = 0;
audiere::OutputStreamPtr sStartmusic = 0;
audiere::OutputStreamPtr sInstrmusic = 0;


bool LoadResources() {
	// Skriv såhär för alla bilder.

	BOSS_SURFACE = SDL_LoadBMP("assets/Spaceboss2.1.bmp");
	FACE_SURFACE = SDL_LoadBMP("assets/zombie_enemy.bmp");

	SHIP_SURFACE = SDL_LoadBMP("assets/Spaceship_2.bmp");
	UFO_SURFACE = SDL_LoadBMP("assets/ufo.bmp");

	// Gör färgen rosa transparent.
	SDL_SetColorKey(FACE_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(BOSS_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(SHIP_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(UFO_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	
	BG_SURFACE = SDL_LoadBMP("assets/Gamescreen.bmp");

	GAME_OVER_SURFACE = SDL_LoadBMP("assets/GameoverScreen.bmp");
	HIGH_SCORE_SURFACE = SDL_LoadBMP("assets/HighScoreScreen.bmp");

	TIO = SDL_LoadBMP("assets/liv10.bmp");
	NIO = SDL_LoadBMP("assets/liv9.bmp");
	ÅTTA = SDL_LoadBMP("assets/liv8.bmp");
	SJU = SDL_LoadBMP("assets/liv7.bmp");
	SEX = SDL_LoadBMP("assets/liv6.bmp");
	FEM = SDL_LoadBMP("assets/liv5.bmp");
	FYRA = SDL_LoadBMP("assets/liv4.bmp");
	TRE = SDL_LoadBMP("assets/liv3.bmp");
	TVÅ = SDL_LoadBMP("assets/liv2.bmp");
	ETT = SDL_LoadBMP("assets/liv1.bmp");

	LIFE_PU_SURFACE = SDL_LoadBMP("assets/PULife.bmp");
	SHIELD_PU_SURFACE = SDL_LoadBMP("assets/PUShield.bmp");
	WEAPON_PU_SURFACE = SDL_LoadBMP("assets/PUWeapon.bmp");
	SPEED_PU_SURFACE = SDL_LoadBMP("assets/PUSpeed.bmp");
	WIDESHOT_PU_SURFACE = SDL_LoadBMP("assets/PUWideshot.bmp");
	SDL_SetColorKey(SPEED_PU_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(LIFE_PU_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(SHIELD_PU_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(WEAPON_PU_SURFACE, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(WIDESHOT_PU_SURFACE, SDL_TRUE, RGB(255, 0, 255));

	START_SURFACE = SDL_LoadBMP("assets/Startscreen.bmp");

	GAME_BUTTON_SURFACE = SDL_LoadBMP("assets/new_game_pressed.bmp");
	INSTR_BUTTON_SURFACE = SDL_LoadBMP("assets/instructions_pressed.bmp");
	HIGH_SCORE_BUTTON_SURFACE = SDL_LoadBMP("assets/high_scores_pressed.bmp");
	QUIT_BUTTON_SURFACE = SDL_LoadBMP("assets/quit_pressed.bmp");

	INSTRUCTION_SURFACE = SDL_LoadBMP("assets/InstructionScreenNEW.bmp");
	BACK_BUTTON = SDL_LoadBMP("assets/knapp_instr.bmp");

	ENEMY_BULLET = SDL_LoadBMP("assets/Enemy_Bullet.bmp");
	SPACESHIP_BULLET = SDL_LoadBMP("assets/Spaceship_Bullet.bmp");
	GREEN_BULLET = SDL_LoadBMP("assets/GreenBullet.bmp");
	FIRE_BOMB = SDL_LoadBMP("assets/FireBomb.bmp");
	ROUND_BULLET = SDL_LoadBMP("assets/RoundBullet.bmp");
	
	FAT_SHIELD = SDL_LoadBMP("assets/FATShield.bmp");
	SDL_SetColorKey(ENEMY_BULLET, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(SPACESHIP_BULLET, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(GREEN_BULLET, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(FIRE_BOMB, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(ROUND_BULLET, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(FAT_SHIELD, SDL_TRUE, RGB(255, 0, 255));
	SPEED_ICON = SDL_LoadBMP("assets/SpeedIcon.bmp");
	WEAPON_ICON = SDL_LoadBMP("assets/WeaponIcon.bmp");
	WIDESHOT_ICON = SDL_LoadBMP("assets/WideshotIcon.bmp");
	SDL_SetColorKey(WEAPON_ICON, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(WIDESHOT_ICON, SDL_TRUE, RGB(255, 0, 255));
	SDL_SetColorKey(SPEED_ICON, SDL_TRUE, RGB(255, 0, 255));

	// audio device.
	audiere::AudioDevicePtr sAudioDevice;
	// audiere.
	sAudioDevice = audiere::OpenDevice();
	// ljudeffekter.
	sShootSound = audiere::OpenSoundEffect(sAudioDevice, "assets/shoot.wav", audiere::SINGLE);
	sExplosionSound = audiere::OpenSoundEffect(sAudioDevice, "assets/explosion.wav", audiere::SINGLE);
	sBabyAouch = audiere::OpenSoundEffect(sAudioDevice, "assets/babyaouch.wav", audiere::SINGLE);
	sHeart = audiere::OpenSoundEffect(sAudioDevice, "assets/ambient_alarm1.wav", audiere::SINGLE);
	sSplitShot = audiere::OpenSoundEffect(sAudioDevice, "assets/laser9.wav", audiere::SINGLE);
	sWallShot = audiere::OpenSoundEffect(sAudioDevice, "assets/laser5.wav", audiere::SINGLE);
	sBossFire = audiere::OpenSoundEffect(sAudioDevice, "assets/laser4.wav", audiere::SINGLE);
	sLostLife = audiere::OpenSoundEffect(sAudioDevice, "assets/FX293.wav", audiere::SINGLE);
	// musik.
	sMusic = audiere::OpenSound(sAudioDevice, "assets/music.mp3", false);
	sDarth = audiere::OpenSound(sAudioDevice, "assets/gameover.mp3", false);
	sStartmusic = audiere::OpenSound(sAudioDevice, "assets/The_Hero.mp3", false);
	sInstrmusic = audiere::OpenSound(sAudioDevice, "assets/Pixel.mp3", false);

	return true;
}

void DeleteResources() {
	// Skriv såhär för alla bilder.
	SDL_FreeSurface(FACE_SURFACE);
	SDL_FreeSurface(BG_SURFACE);
	SDL_FreeSurface(SHIP_SURFACE);
	//SDL_FreeSurface(BIGBULLET_SURFACE);
	SDL_FreeSurface(GAME_OVER_SURFACE);
	SDL_FreeSurface(UFO_SURFACE);
	SDL_FreeSurface(BOSS_SURFACE);
	SDL_FreeSurface(TIO);
	SDL_FreeSurface(NIO);
	SDL_FreeSurface(ÅTTA);
	SDL_FreeSurface(SJU);
	SDL_FreeSurface(SEX);
	SDL_FreeSurface(FEM);
	SDL_FreeSurface(FYRA);
	SDL_FreeSurface(TRE);
	SDL_FreeSurface(TVÅ);
	SDL_FreeSurface(ETT);
	//SDL_FreeSurface(BULLET_SURFACE);
	SDL_FreeSurface(HIGH_SCORE_SURFACE);
	SDL_FreeSurface(LIFE_PU_SURFACE);
	SDL_FreeSurface(SHIELD_PU_SURFACE);
	SDL_FreeSurface(WEAPON_PU_SURFACE);
	SDL_FreeSurface(SPEED_PU_SURFACE);
	SDL_FreeSurface(WIDESHOT_PU_SURFACE);
	SDL_FreeSurface(START_SURFACE);
	SDL_FreeSurface(GAME_BUTTON_SURFACE);
	SDL_FreeSurface(INSTR_BUTTON_SURFACE);
	SDL_FreeSurface(HIGH_SCORE_BUTTON_SURFACE);
	SDL_FreeSurface(QUIT_BUTTON_SURFACE);
	SDL_FreeSurface(INSTRUCTION_SURFACE);
	SDL_FreeSurface(BACK_BUTTON);
	SDL_FreeSurface(ENEMY_BULLET);
	SDL_FreeSurface(SPACESHIP_BULLET);
	SDL_FreeSurface(GREEN_BULLET);
	SDL_FreeSurface(FIRE_BOMB);
	SDL_FreeSurface(ROUND_BULLET);
	SDL_FreeSurface(FAT_SHIELD);
	SDL_FreeSurface(SPEED_ICON);
	SDL_FreeSurface(WEAPON_ICON);
	SDL_FreeSurface(WIDESHOT_ICON);
}

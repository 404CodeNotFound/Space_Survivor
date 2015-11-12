#ifndef __RES_H__
#define __RES_H__

struct SDL_Surface;

extern SDL_Surface *EN_BILD;
extern SDL_Surface *EN_ANNAN_BILD;
// Skriv såhär för alla bilder.
extern SDL_Surface *FACE_SURFACE;
extern SDL_Surface *BG_SURFACE;
extern SDL_Surface *BULLET_SURFACE;
extern SDL_Surface *BIGBULLET_SURFACE;

bool LoadResources();
void DeleteResources();

#endif
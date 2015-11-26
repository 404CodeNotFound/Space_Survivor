#include "Graphics.h"
#include "SDL.h"

Graphics::Graphics(SDL_Surface *surface, int width, int height) {
	mSurface = surface;
	mWidth = width;
	mHeight = height;
}

void Graphics::Clear(unsigned int color) {
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = mWidth;
	r.h = mHeight;
	SDL_FillRect(mSurface, &r, color);
}

void Graphics::DrawImage(SDL_Surface *surface, int x, int y) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = 0;
	r.h = 0;
	SDL_BlitSurface(surface, 0, mSurface, &r);
}

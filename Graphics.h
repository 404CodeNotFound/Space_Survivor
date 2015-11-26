#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

struct SDL_Surface;

#define RGB(r, g, b) ((r) << 16) + ((g) << 8) + (b)

class Graphics {
private:
	SDL_Surface *mSurface;
	int mWidth;
	int mHeight;

public:
	Graphics(SDL_Surface *surface, int width, int height);
	void Clear(unsigned int color);
	void DrawImage(SDL_Surface *surface, int x, int y);
	void DrawImage(SDL_Surface *surface, int x, int y, int srcX, int srcY, int w, int h);
};

#endif
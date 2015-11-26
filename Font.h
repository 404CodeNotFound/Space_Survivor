#ifndef __FONT_H__
#define __FONT_H__

struct SDL_Surface;
class Graphics;

class Font {
private:
	SDL_Surface *mSurface;
	int mCelWidth;
	int mCelHeight;
	int mChars[256];

public:
	Font(char *filename);
	~Font();
	void WriteString(Graphics *g, const char *txt, int x, int y);
};

#endif

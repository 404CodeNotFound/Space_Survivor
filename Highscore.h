#ifndef __HIGH_SCORE_H__
#define __HIGH_SCORE_H__

#include "Screen.h"
#include <vector>
#include <string>


struct SDL_Surface;
class Font;


class Highscore : public Screen {
private:
	
	SDL_Surface *mHighscoreSurface;
	Font *mMyFont;

	struct HighscoreEntry {
		std::string mName;
		int mPoints;
	};

	std::vector<HighscoreEntry> Bestofthebest;
	std::vector<HighscoreEntry>::iterator hit;

	FILE *file;
	
	float mBGX;
	int counter;
	bool ready;
	bool wehaveawinner;
	bool releasekeys;
	std::string winnername;
	int mScore;


public:
	Highscore(int score);
	~Highscore();

	virtual void KeyDown(SDL_Keycode keyCode);
	virtual void KeyUp(SDL_Keycode keyCode);
	virtual void Update();
	virtual void Draw(Graphics *g);
	void CreateHighscore();
	
};

#endif


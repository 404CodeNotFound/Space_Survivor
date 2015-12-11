#include "Highscore.h"
#include "GameApp.h"
#include "Graphics.h"
#include "Res.h"
#include "Gamescreen.h"
#include "Startscreen.h"
#include "audiere.h"
#include "Font.h"
#include "stdio.h"


////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Highscore::Highscore(int score) {

	ready = false;
	wehaveawinner = false;
	releasekeys = false;
	mReturn = false;
	mHighscoreSurface = HIGH_SCORE_SURFACE;
	mMyFont = new Font("assets/font_fire.bmp");
	mScore = score;
	printf("Score:, %d", mScore);

	mBGX = 0.0f;
	counter = 0;
	file = fopen("assets/min_fil.txt", "r");
	if (file == nullptr) {
		CreateHighscore();
		fopen("assets/min_fil.txt", "r");
	}
	for (int i = 0; i < 10; ++i) {
		int points;
		char name [10];
		fscanf(file, "%d%s", &points, name);
		HighscoreEntry tmp;
		tmp.mName = name;
		tmp.mPoints = points;
		Bestofthebest.push_back(tmp);
	}
	fclose(file);

	if (mScore > (Bestofthebest.at(9)).mPoints) {
		wehaveawinner = true;
		printf("We have a winner!");
		std::vector<HighscoreEntry>::iterator it;
		for (it = Bestofthebest.begin(); it < Bestofthebest.end(); it++) {
			if (it->mPoints < mScore) {
				hit = it;
				printf("Found place on list!");
				break;
			}
		}
	}
	else {
		ready = true;
	}
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
Highscore::~Highscore() {
	file = fopen("assets/min_fil.txt", "w");
	for (int i = 0; i < 10; ++i) {
			int points = (Bestofthebest.at(i).mPoints);
			printf("What int:, %d\n", points);
			fprintf(file, "%d %s\n", points, (Bestofthebest.at(i)).mName.c_str());
			printf("Till fil:, %d %s\n", points, (Bestofthebest.at(i)).mName.c_str());
	}
	fclose(file);
	delete mMyFont;
	
	printf("Highscore destroyed\n");
}


////////////////////////////////////////////////////////////////////////////////
// Anropas 100 gånger per sekund. Utför all logik här. 
////////////////////////////////////////////////////////////////////////////////
void Highscore::Update() {
	if (!ready && wehaveawinner) {
		releasekeys = true;
	}
	else if (ready){
		releasekeys = false;
		if (counter == 800) {
			GameApp()->SetScreen(new Startscreen());
		}
		counter = counter + 1;
	}
	// Press left key to go to menu
	if (mReturn) {
		GameApp()->SetScreen(new Startscreen());
	}
}

////////////////////////////////////////////////////////////////////////////////
// Utför all utritning här.
////////////////////////////////////////////////////////////////////////////////
void Highscore::Draw(Graphics *g) {
	g->DrawImage(mHighscoreSurface, (int)mBGX, 0);

	if (ready) {
		for (int i = 0; i < 10; i++) {
			int points = (Bestofthebest.at(i).mPoints);
			char tmp[10];
			sprintf(tmp, "%d", points);
			mMyFont->WriteString(g, (Bestofthebest.at(i)).mName.c_str(), 32, 205 + i*24);
			mMyFont->WriteString(g, tmp, 500, 205 + i*24);
		}
	}
	else if (!ready && wehaveawinner) {
		mMyFont->WriteString(g, "PLEASE ENTER YOUR NAME:", 32, 305);
		mMyFont->WriteString(g, winnername.c_str(), 32, 325);
	}
}
//////////////////////7
void Highscore::KeyDown(SDL_Keycode keyCode) {
	if(releasekeys) {
		if (keyCode == SDLK_a) {
			if (winnername.length() < 11)
				winnername = winnername + 'A';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_b) {
			if (winnername.length() < 11)
				winnername = winnername + 'B';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_c) {
			if (winnername.length() < 11)
				winnername = winnername + 'C';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_d) {
			if (winnername.length() < 11)
				winnername = winnername + 'D';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_e) {
			if (winnername.length() < 11)
				winnername = winnername + 'E';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_f) {
			if (winnername.length() < 11)
				winnername = winnername + 'F';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_g) {
			if (winnername.length() < 11)
				winnername = winnername + 'G';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_h) {
			if (winnername.length() < 11)
				winnername = winnername + 'H';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_i) {
			if (winnername.length() < 11)
				winnername = winnername + 'I';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_j) {
			if (winnername.length() < 11)
				winnername = winnername + 'J';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_k) {
			if (winnername.length() < 11)
				winnername = winnername + 'K';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_l) {
			if (winnername.length() < 11)
				winnername = winnername + 'L';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_m) {
			if (winnername.length() < 11)
				winnername = winnername + 'M';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_n) {
			if (winnername.length() < 11)
				winnername = winnername + 'N';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_o) {
			if (winnername.length() < 11)
				winnername = winnername + 'O';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_p) {
			if (winnername.length() < 11)
				winnername = winnername + 'P';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_q) {
			if (winnername.length() < 11)
				winnername = winnername + 'Q';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_r) {
			if (winnername.length() < 11)
				winnername = winnername + 'R';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_s) {
			if (winnername.length() < 11)
				winnername = winnername + 'S';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_t) {
			if (winnername.length() < 11)
				winnername = winnername + 'T';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_u) {
			if (winnername.length() < 11)
				winnername = winnername + 'U';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_v) {
			if (winnername.length() < 11)
				winnername = winnername + 'V';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_w) {
			if (winnername.length() < 11)
				winnername = winnername + 'W';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_x) {
			if (winnername.length() < 11)
				winnername = winnername + 'X';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_y) {
			if (winnername.length() < 11)
				winnername = winnername + 'Y';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_z) {
			if (winnername.length() < 11)
				winnername = winnername + 'Z';
			else
				winnername = winnername;
		}
		else if (keyCode == SDLK_BACKSPACE) {
			if (winnername.length() > 0) {
				int x = winnername.length()-1;
				winnername.erase(x, 1);
			}
		}
		else if (keyCode == SDLK_RETURN) {
			HighscoreEntry tmpw;
			tmpw.mName = winnername;
			tmpw.mPoints = mScore;
			Bestofthebest.insert(hit, tmpw);
			ready = true;
		}
	}
}

void Highscore::KeyUp(SDL_Keycode keyCode) {
	if (keyCode == SDLK_LEFT) {
		mReturn = true;
	}
}
//////////////////////////////
void Highscore::CreateHighscore() {
	file = fopen("assets/min_fil.txt", "w");
	fprintf(file, "%d %s\n", 210, "KENNETH");
	fprintf(file, "%d %s\n", 200, "NOOK");
	fprintf(file, "%d %s\n", 190, "REBECCA");
	fprintf(file, "%d %s\n", 180, "ALI");
	fprintf(file, "%d %s\n", 170, "KENNETH");
	fprintf(file, "%d %s\n", 160, "KENNETH");
	fprintf(file, "%d %s\n", 150, "JENNIE");
	fprintf(file, "%d %s\n", 130, "MOPZ");
	fprintf(file, "%d %s\n", 120, "PIPPO");
	fprintf(file, "%d %s\n", 100, "BOBA");
	fclose(file);
}
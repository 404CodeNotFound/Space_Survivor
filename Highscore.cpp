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

	//Läs in bakgrundsbild
	ready = false;
	wehaveawinner = false;
	releasekeys = false;
	mHighscoreSurface = HIGH_SCORE_SURFACE;
	mMyFont = new Font("assets/font_fire.bmp");
	mScore = score;
	printf("Score:, %d", mScore);
	//audiere

	//Bakgrundens position

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

	/*for (int i = 0; i < 10; ++i) {
		printf("%s %d\n", (Bestofthebest.at(i)).mName.c_str(), (Bestofthebest.at(i)).mPoints);
	}
	int tio = (Bestofthebest.at(9)).mPoints;
	printf("Tian:, %d", tio);*/
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
	delete mMyFont;;
	// audiere.
	
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
			mMyFont->WriteString(g, (Bestofthebest.at(i)).mName.c_str(), 32, 305 + i*24);
			mMyFont->WriteString(g, tmp, 500, 305 + i*24);
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
			winnername = winnername + 'A';
		}
		else if (keyCode == SDLK_b) {
			winnername = winnername + 'B';
		}
		else if (keyCode == SDLK_c) {
			winnername = winnername + 'C';
		}
		else if (keyCode == SDLK_d) {
			winnername = winnername + 'D';
		}
		else if (keyCode == SDLK_e) {
			winnername = winnername + 'E';
		}
		else if (keyCode == SDLK_f) {
			winnername = winnername + 'F';
		}
		else if (keyCode == SDLK_g) {
			winnername = winnername + 'G';
		}
		else if (keyCode == SDLK_h) {
			winnername = winnername + 'H';
		}
		else if (keyCode == SDLK_i) {
			winnername = winnername + 'I';
		}
		else if (keyCode == SDLK_j) {
			winnername = winnername + 'J';
		}
		else if (keyCode == SDLK_k) {
			winnername = winnername + 'K';
		}
		else if (keyCode == SDLK_l) {
			winnername = winnername + 'L';
		}
		else if (keyCode == SDLK_m) {
			winnername = winnername + 'M';
		}
		else if (keyCode == SDLK_n) {
			winnername = winnername + 'N';
		}
		else if (keyCode == SDLK_o) {
			winnername = winnername + 'O';
		}
		else if (keyCode == SDLK_p) {
			winnername = winnername + 'P';
		}
		else if (keyCode == SDLK_q) {
			winnername = winnername + 'Q';
		}
		else if (keyCode == SDLK_r) {
			winnername = winnername + 'R';
		}
		else if (keyCode == SDLK_s) {
			winnername = winnername + 'S';
		}
		else if (keyCode == SDLK_t) {
			winnername = winnername + 'T';
		}
		else if (keyCode == SDLK_u) {
			winnername = winnername + 'U';
		}
		else if (keyCode == SDLK_v) {
			winnername = winnername + 'V';
		}
		else if (keyCode == SDLK_w) {
			winnername = winnername + 'W';
		}
		else if (keyCode == SDLK_x) {
			winnername = winnername + 'X';
		}
		else if (keyCode == SDLK_y) {
			winnername = winnername + 'Y';
		}
		else if (keyCode == SDLK_z) {
			winnername = winnername + 'Z';
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
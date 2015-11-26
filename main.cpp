#include "MyGameApp.h"
#include <stdio.h>

int main(int argc, char ** args) {
	// Skapa en instans av spelet.
	MyGameApp *game;
	game = new MyGameApp();
	// Kör spelet, återvänder inte förrän körningen nått sitt slut.
	game->Run();
	// Frigör.
	delete game;

	return 0;
}
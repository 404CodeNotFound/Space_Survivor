#include "MyGameApp.h"
#include <stdio.h>

int main(int argc, char ** args) {
	// Skapa en instans av spelet.
	MyGameApp *game;
	game = new MyGameApp();
	// K�r spelet, �terv�nder inte f�rr�n k�rningen n�tt sitt slut.
	game->Run();
	// Frig�r.
	delete game;

	return 0;
}
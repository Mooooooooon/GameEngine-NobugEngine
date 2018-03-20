#include "Engine.h"


int main() {
	NobugEngine game;
	if (game.Initialize()) {
		game.Start();
	}


	
	return 0;
}
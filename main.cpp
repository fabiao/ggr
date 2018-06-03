#include "util.h"
#include "game.h"
#include <allegro.h>

int main() {
	Game game;
	game.init();
	game.Intro();
	while(true) {
		game.Title();
		while(!key[KEY_ESC] && !game.GAME_OVER) {
			game.checkGame();
			if(game.GAME_OVER) break;
			if(game.L_B)   game.layer_back();
			if(game.L_0)   game.layer_0();
			if(game.L_1)   game.layer_1();
			if(game.L_S)   game.layer_s();
			if(game.L_H)   game.layer_h();
			if(game.L_OSD) game.layer_OSD(50);
			game.Player();
			game.Enemies();
			game.Collision();
			if(game.DEBUG) game.debug(game.VSCR,50); // Debug
			game.Scroll();
			game.checkTimer();
			// Print all to screen
			game.rePaint(game.MFPS);
		}
		clear_keybuf();
		wait(500);
	}
	return 0;
}
END_OF_MAIN();
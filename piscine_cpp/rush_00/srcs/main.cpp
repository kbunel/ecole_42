
#include "../includes/ft_retro.h"
#include "../includes/Game.class.hpp"
#include "../includes/Menu.class.hpp"

int			main() {
	Game g;
	Menu m;



	std::srand(std::time(0));
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);
	getmaxyx(stdscr, Game::height, Game::width);
	start_color();
	init_pair(WALL, COLOR_YELLOW, COLOR_BLACK);
	init_pair(PLAYER, COLOR_BLUE, COLOR_BLACK);
	init_pair(ASTEROID, COLOR_WHITE, COLOR_BLACK);
	init_pair(ENEMY, COLOR_RED, COLOR_BLACK);
	while (!m.isStop())
	{
		if (g.isPause() || !g.isRunning())
			m.loop(g);
		else
			g.loop();
	}
	endwin();
}

#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "ft_retro.h"
#include "Wall.class.hpp"
#include "Player.class.hpp"
#include "Map.class.hpp"
#include "Enemy.class.hpp"
#include "Console.class.hpp"
#include "Asteroid.class.hpp"

class Game {

	private:

		void 		initWall( void );
		void 		initEnemies( void );
		void 		initCarte( void );
		void 		initAsteroids( void );
		void		activateEnemies( void );
		void		clear( void );
		int 		enemiesFrequency;
		int 		usq;
		int			ust;
		int			enemyShoot;
		int			frame;
		bool 		stop;
		bool 		running;
		bool		pause;
		Player* 	player;
		Enemy 		*enemies;
		Asteroid 	*asteroids;
		Wall 		*wallsH;
		Wall 		*wallsB;

	public:
		
		Game( void );
		Game(Game const & game);
		~Game();

		void 		input();
		void 		loop();
		void 		run();
		void 		aff();
		int 		getWidth();
		int 		getHeight();
		bool 		isRunning();
		bool 		isPause();
		void		setPause(bool p);
		void 		endGame();
		int 		getScore();

		static void error(std::string err);

		static int 					width;
		static int 					height;
		static Map*  				map;
		static std::string  		mapChar;
		static Console*				console;
		static bool**				carte;

		Player const &				getPlayer( void );

		Game & 		operator=(Game const & src);

};

#endif

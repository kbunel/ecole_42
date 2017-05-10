#ifndef CONSOLE_H
#define CONSOLE_H

#include "ft_retro.h"

class Console {
	
	public:

		Console( void );
		Console( const Console & console);
		~Console( void );

		void				loop( int life );
		void				addScore( int points );
		void				addLevel( void );
		void				display( void );
		int					getScore();
		void				setLevel( int level );
		void				setScore( int score );

	private:

		int					life;
		int					score;
		int					level;

		Console &			operator=( Console const & rhs );
};

#endif

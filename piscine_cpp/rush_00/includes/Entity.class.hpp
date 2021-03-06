#ifndef ENTITY_H
#define ENTITY_H

#include "ft_retro.h"

class Entity {

	public:

		Entity( void );
		Entity( int x1, int x2, int y1, int y2, int life, char dispChar );
		Entity( Entity const & src );
		~Entity( void );
		Entity &			operator=( Entity const & rhs );

		void				loop( void );
		void				clear( void );
		void				display( void );
		bool				checkColision( void );
		void				init( int x1, int x2, int y1, int y2, int life, char dispChar);
		void				init( int x, int y, int life, std::string file);

		void				setType( int type );
		int					getType( void ) const;
		int					getLife( void ) const;
		int					getX1( void ) const;
		int					getX2( void ) const;
		int					getY1( void ) const;
		int					getY2( void ) const;
		std::string**		getDispChars( void ) const;
		void 				deleteDispChars();
		void				generateDispChars(char dispChar);
		void 				generateRenderDesign(std::string design);
	protected:

		int					type;				
		int					life;
		int					x1;
		int					x2;
		int					y1;
		int					y2;
		std::string			**dispChars;

	private:

};

#endif

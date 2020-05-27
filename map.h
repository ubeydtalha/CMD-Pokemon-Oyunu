


#ifndef ss
#define ss

#include <string>
#include "pokemon.h"
#include "hero.h"
class map{


		
	public:
		int x;
		int y;
	    int ** mapx;
	    char ** mapc;
	    int ** mapp;
	    int noPokemon[2];
	    char walking;
	    int heroXX,heroYY;
	 
		map();
		map(int x,int y,pokemon * pk);
		
		//Finish Const
		void mapFillBorder(pokemon * pk);
		void mapStringForm();
		char mapPrinter(int x,int y,char letter,int heroX,int heroY);
		bool mapAttackPrinter(hero hero, pokemon otherPokemon);
		int * findRate(pokemon * pk,int rate);
		friend void fightString();
};
 void fightString();
#endif

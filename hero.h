
#include <stdlib.h> 
#include <iostream>
#include "pokemon.h"
#ifndef sss
#define sss

#include <string>
class hero{
	public: 
		char * name;
		int corX,corY;
		int pokeball;
		int hpc;
		int ccc;
		pokemon havePokemonCount[3];
		char walking;
		//const
		hero();
		hero(char * name,int x,int y);
		//
		bool walk(char walking,int **code,int mapSize);
		bool catchPokemon(pokemon otherPokemon);
	
};

#endif

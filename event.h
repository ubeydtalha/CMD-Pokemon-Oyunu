#include "map.h"
#include "hero.h"
#include "pokemon.h"

#ifndef event
#define event




	
pokemon& createPokemons();

void run();
bool pokemonFound(int **code,int x,int y);

int choose(hero hero);

void update(map harita,hero hero,pokemon * pk);

void banner();

#endif

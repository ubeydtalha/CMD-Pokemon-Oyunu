#include <iostream>
#include <string>
#include <sstream>
#ifndef Pokemon
#define Pokemon

using namespace std;
class pokemon{
	
	public:
		int id;
		string  pname;
		char  name [10] ;
		int cn[10];
		int hp;
		int exp;
		int level;
		int damage;
		int defense;
		int rate;

	pokemon();
	pokemon& operator=(const pokemon& other);
	
	bool operator!=(const int x);
	
	pokemon& operator-(const pokemon& other);
		
	void attack(pokemon mine,pokemon otherPokemon,int round);
	
	void namer(int * c,int len);

};


#endif

#include <iostream>
#include "pokemon.h"
#include <string>
#include <iostream>
#include <time.h>  
#include <stdlib.h> 
#include <sstream>
#include <stdio.h>
#include <cstring>
using namespace std;





pokemon::pokemon(){
			id=-1;
			pname=" ";
			hp=-1;
			exp=-1;
			level=-1;
			damage=-1;
			defense=-1;
			rate=-1;
			
		}



void pokemon::attack(pokemon mine,pokemon otherPokemon,int round){
	
	if(otherPokemon.damage%defense>0)	hp-=(otherPokemon.damage%defense);	
		else hp--;
}

pokemon& pokemon::operator=(const pokemon& other)
	{
		
		
			
//		cout<<other.pname<<endl;
//		
//		stringstream ss;
//		ss<<other.pname;
		
//	for(int i =0 ; i< strlen(other.name);i++){
//		cn[i]=(int)other.name[i];
	//	cout<<(char) cn[i];	
	//}
//		other.pname.copy(name,other.pname.length());
		
//	namer(cn,strlen(other.name));
		pname=other.pname;
		defense=other.defense;
		damage=other.damage;
		hp=	other.hp;
		id=other.id;
		rate=other.rate;
		
		return *this;
	}
	
	
	void pokemon::namer(int * c,int len){
			for(int i =0 ; i< len;i++){
				name[i]=(char) c[i];
			}
			for(int x=len;x<10+len;x++){
				name[x]='\0';
			}
	}
	
	pokemon& pokemon::operator-(const pokemon& other){
			hp=hp-(other.damage%defense);
			return *this;
	}
	
	bool pokemon::operator!=(const int x){
		
		if(id<0) return false;
		return true;
	}

#include <iostream>
#include "event.h"
#include <string>
#include <iostream>
#include <time.h>  
#include <stdlib.h>  
#include <windows.h>
#include "map.h"
#include "hero.h"
#include <fstream>
#include "pokemon.h"
using namespace std;

bool control=false;

pokemon& createPokemons(){
	int	n=13;	
	ifstream poke; 
    poke.open("pokemons.txt", ios::in); 
   pokemon * p= new pokemon[13];
	for(int i=0;i<n;i++){
		if(poke.is_open()){
		poke>>p[i].id>>p[i].pname>>p[i].hp>>p[i].damage>>p[i].defense>>p[i].level>>p[i].exp>>p[i].rate;
		}
	}
	poke.close();
	return *p;
}

bool pokemonFound(int **code,int x,int y){
	if(code[x][y] == 204){
		
		cout<<"  Rate 1 pokemon found";
		control = true;
		return true;
	}
	if(code[x][y] == 202){
		
		cout<<"  Rate 2 pokemon found";
		control = true;
		return true;
		
	}
	if(code[x][y] == 203){
		
		cout<<"   Rate 3 pokemon found";
		control = true;
		return true;
		
	}
	
	control = false;
	return false;
}

int choose(hero hero){
	int select;
	control = true;
	
		
}


void update(map harita,hero hero,pokemon * pk){

if(!hero.walk(harita.mapPrinter(harita.x,harita.y,hero.name[0],hero.corX,hero.corY),harita.mapx,harita.x)){
	if(control){
	
		if(GetAsyncKeyState(VK_NUMPAD4)|| GetAsyncKeyState(65)){
			cout<<"Attack\n";
			system("cls");	
			
			
			bool kontrol=harita.mapAttackPrinter(hero,pk[harita.mapp[hero.corX][hero.corY]-1]);  
			
			if(kontrol){
				harita.mapc[hero.corX][hero.corY]=100;
				harita.mapx[hero.corX][hero.corY]=100;
			}
			kontrol=true;
		}
		
		
		if(GetAsyncKeyState(VK_NUMPAD2)|| GetAsyncKeyState(83)){
			cout<<"Catch to Pokemon\n";
			system("cls");
			bool kontrol;
			try {
				 kontrol=hero.catchPokemon(pk[harita.mapp[hero.corX][hero.corY]-1]);
			}
			catch ( const char* s){
				cout<<s;
			}
			
			if(kontrol){
				harita.mapc[hero.corX][hero.corY]=99;
				harita.mapx[hero.corX][hero.corY]=100;
			}
			
			
		}
	}
	if(harita.mapx[hero.corX][hero.corY]==333){
		
		hero.pokeball++;
		harita.mapx[hero.corX][hero.corY]=100;
	}
	system("pause\n");
}

 system("cls");	
 Sleep(0.001); 
	update(harita,hero,pk);
}



void run(){
	banner();
cout<<"Wellcome to Console Pokemon Game"<<endl;
	cout<<"Can you choose your pokemon"<<endl;
	pokemon * pk= &createPokemons();
		map harita(15,15,pk);pokemon zero;
	hero hero("Ash",harita.noPokemon[0],harita.noPokemon[1]);
	cout<<"1-"<<pk[1].pname<<" 2-"<<pk[11].pname<<" 3-"<<pk[5].pname;
	int choo;
	cin>>choo;
	switch(choo){
		case 1:
			hero.havePokemonCount[0]=pk[1];
			hero.havePokemonCount[1]=zero;
			hero.havePokemonCount[2]=zero;
			break;
		case 2:
			hero.havePokemonCount[0]=pk[11];
			hero.havePokemonCount[1]=zero;
			hero.havePokemonCount[2]=zero;
			break;
		case 3:
			hero.havePokemonCount[0]=pk[5];
			hero.havePokemonCount[1]=zero;
			hero.havePokemonCount[2]=zero;
			break;
	}	
	cout<<"Your pokemon is "<<hero.havePokemonCount[0].pname<<endl;
		 Sleep(1000); 
	cout<<"Loading";
		for(int i =0;i<1;i++){

		Sleep(10); 
		cout<<".";
		Sleep(100); 
		cout<<".";
		Sleep(100); 
		cout<<".";
		Sleep(100); 
		cout<<".";
		Sleep(100); 
		cout<<".";
	}	
	system("cls");
	update(harita,hero,pk);
}

void banner(){

cout<<"  _ __   ___  | | _____ _ __ ___    ___   _ ___     "<<endl;
cout<<" | '_   / _   | |/ / _ ||'_ ` _    / _   | '_  <    "<<endl;
cout<<" | |_) | (_)  |  _<  __/| | | | | | (_) || | | |    "<<endl;
cout<<" | .__/  ___/ |_| |_  __|_| |_| |   ___/ |_| |_|    "<<endl;
cout<<" |_|                                         	   "<<endl;                                
//  _ __   ___ | | _____ _ __ ___   ___  _ __  
// | '_ \ / _ \| |/ / _ \ '_ ` _ \ / _ \| '_ \ 
// | |_) | (_) |   <  __/ | | | | | (_) | | | | 
// | .__/ \___/|_|\_\___|_| |_| |_|\___/|_| |_|
// |_|                                         
}

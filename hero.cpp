#include <iostream>
#include <string>
#include "hero.h"
#include <stdlib.h> 
#include <windows.h>
#include <time.h>  
#include "pokemon.h"
using namespace std;

	hero::hero(){
		
		name ="Ash";
		pokeball=3;
	}
	hero::hero(char * name,int x,int y){
		this->name = name;
		corX=x;
		corY=y;
		pokeball=3;
	
	}


	
	
	bool hero::walk(char walking, int **code, int mapSize){
			
		if(GetAsyncKeyState(VK_LEFT)&& code[corX][corY-1]!=(201)){
			corY--;	
			Sleep(10);
			return true;
		}
		else if((GetAsyncKeyState(VK_UP)&& code[corX-1][corY]!=(201))){
			corX--;	Sleep(10);
			return true;
		}
		else if((GetAsyncKeyState(VK_DOWN)&& code[corX+1][corY]!=(201))){
			corX++;		Sleep(10);
			return true;
		}
		if(GetAsyncKeyState(VK_RIGHT)&& code[corX][corY+1]!=(201)){
			corY++;	Sleep(10);
			return true;
		}
	
	}


	bool hero::catchPokemon(pokemon otherPokemon){
		char cs='Y';
		cout<<"You found "<<otherPokemon.pname<<endl;

		int x=pokeball;
	for(int i=0;i<x ;i++){	int q=0;
		cout<<"You have "<<pokeball<<" pokeball"<<endl;
		cout <<"Do you want to continue?\n"<<"Y-Yes N-No"<<endl;
		cin>>cs;
		if(cs=='N' ||cs=='n') break;
		else if(cs=='Y' ||cs=='y'){
		pokeball--;
		char * yaz="Catching is trying...";
		for(q;q<21;q++){
			cout<<*yaz;
			Sleep(600);
		yaz++;
		}
		
		srand (time(NULL));
		
		int random = rand();
		
		if(otherPokemon.rate==1 &&  random%23==0){
			int u;
			cout<<"You have new pokemon where do you want to put its"<<endl;
			cout<<"1- 2- 3-"<<endl;
			
			cin>>u;
			if(u>3 || u<0) throw "Unable number\n";
				try {
				havePokemonCount[u]=otherPokemon;
				}	catch (const char* wer) {
				cout<<wer;
					}
			throw "Success.You catched.\n";break;
			return true;
			
			}
		if(otherPokemon.rate==2 &&  random%37==0){
				int u;
			cout<<"You have new pokemon where do you want to put its"<<endl;
			cout<<"1- 2- 3-"<<endl;
			
			cin>>u;
			
			havePokemonCount[u]=otherPokemon;
					throw "Success.You catched \n";break;
				return true;
			}
		if(otherPokemon.rate==3 &&  random%61==0){
			int u;
			cout<<"You have new pokemon where do you want to put its"<<endl;
			cout<<"1- 2- 3-"<<endl;
			
			cin>>u;
			
			havePokemonCount[u]=otherPokemon;
				throw "Success.You catched\n ";break;
			return true;
			}
			
			}
		}	
		
		
		if(pokeball==0)throw "Unfortunataly.You don't have pokeball\n";
		else throw "You could not catch pokemon\n";
		return false;
	}

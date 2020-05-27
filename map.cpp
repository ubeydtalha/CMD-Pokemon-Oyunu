#include <iostream>
#include "map.h"
#include "event.h"
#include <string>
#include <time.h>  
#include <stdlib.h>  
#include <windows.h> 
#include "pokemon.h"
#include <conio.h>


using namespace std;



map::map(){
			x=0;
			y=0;
		}
map::map(int x,int y,pokemon * pk){
			this->x=x;
			this->y=y;
			mapc = new char*[x];
			mapx = new int*[x];
			mapp = new int*[x];
				for(int i=0;i<x;i++){
					mapc[i]=new char[y];
					mapx[i]=new int[y];
					mapp[i] = new int[y];
				}
			mapFillBorder(pk);
			mapStringForm();
		}
void map::mapFillBorder(pokemon * pk){
srand (time(NULL));
int pc=14;
int cnt=0;int cnt2=0;int cnt3=0;	int *rp=new int[6]; int *rp2=new int[6]; int *rp3=new int[6];
					int count=0;int count2=0;int count3=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			
			if(i==0 || j==0 || i== x-1 || j==y-1){
					mapx[i][j]=201;
					mapp[i][j]=14;
			}
			else{
				
				int random= rand() +100;
				
				mapx[i][j]=100;
			    mapp[i][j]=14;
			 if(random %5 == 0){
					mapx[i][j]=204;
				
					 if(cnt<1)for(int q =0 ; q<pc;q++ )
					{
						if(pk[q].rate==1) 
						{
						rp[count]=pk[q].id;
					//	cout<<rp[count]<<endl;
						count++;
						}	cnt++;	
					} 
				
				
					mapp[i][j]=rp[random%count];
					
				}
				else if(random %7 == 0){
					mapx[i][j]=202; //
					
					 if(cnt2<1)for(int q =0 ; q<pc;q++ )
					{
						if(pk[q].rate==2) 
						{
						rp2[count2]=pk[q].id;
//						cout<<rp2[count2]<<endl;
						count2++;
						}	cnt2++;	
					} 
				mapp[i][j]=rp2[random%count2];
				}
				else if(random %13 == 0){
					mapx[i][j]=203; //
					if(cnt3<1)for(int q =0 ; q<pc;q++ )
					{
						if(pk[q].rate==3) 
						{
						rp3[count3]=pk[q].id;
//					
						count3++;
						}	cnt3++;	
					} 
				mapp[i][j]=rp3[random&count3];
				}
				else if(random %11 == 0) {
					mapx[i][j]=201;
				}
				else if(random%17==0){
					mapx[i][j]=333;
				}
				else if(mapp[i][j]>pc || mapp[i][j]<0) mapp[i][j]=14;
				else{mapp[i][j]=14;
						mapx[i][j]=100;
				}
				
			}
		}
	}
}

 void map::mapStringForm(){
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(mapx[i][j]==201){
				mapc[i][j]='*';
				}
			else if(mapx[i][j]>99 || mapx[i][j]<105){
				mapc[i][j]=' ';
				if(mapx[i][j]==100){
					noPokemon[0]=i;
					noPokemon[1]=j;
					}
				}	
			else if(mapx[i][j]==202){
				mapc[i][j]='_';
			}
			else if(mapx[i][j]==203){
				mapc[i][j]='^';
			}
		}
	}	
}

char map::mapPrinter(int x, int y,char letter,int heroX,int heroY){
		bool pokemonFoundControl;
		int selected;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
		
		if(i==heroX && j==heroY)	cout<<letter;
	 	else {
				cout<<mapc[i][j];
				
				
			 }
		}
		if(i==((x/2)-1)){
			//	cout<<"  ______________________";
				
		}
		if(i==(x/2)){
					pokemonFoundControl = pokemonFound(mapx,heroX,heroY);
				}
		if(i==((x/2)+1)&&pokemonFoundControl){
		
				cout<<"   What do you want to do?";
		}
		if(i==((x/2)+2) && pokemonFoundControl ){
			cout<<"  A-Fight S-Catch  Arrow Keys-Leave";
		
		}
		if(i==((x/2)+3)){
				
				//cout<<"  ______________________";
				
		}
		cout<<"\n";
	}
	walking = 'Q';
	return walking;	
}

bool map::mapAttackPrinter(hero hero, pokemon otherPokemon){
	fightString();
	
	cout<<"Which pokemon do you want to use\n"<<endl;
	int i=0; int choose=0;
	
	while(hero.havePokemonCount[i]!=1){i++;
		cout<<i<<"-"<<hero.havePokemonCount[i-1].pname<<endl;
		
	}
	
	cin>>choose;    //Buraya exception yazýlacak
	cout<<"Will you attack "<<otherPokemon.pname<<endl;
	choose--;
	int y;
	int round=1;
	while(!(hero.havePokemonCount[choose].hp<=0 || otherPokemon.hp<=0)){
		system("cls");
		cout<<round<<". round"<<endl;
		cout<<"-----------------------"<<otherPokemon.pname<<endl;
		cout<<"  #       #   ###       "<<"HP:"<<otherPokemon.hp<<endl;
		cout<<"   #     #    #         "<<endl;
		cout<<"    #   #     ###       "<<endl;
		cout<<"     # #        #       "<<endl;
		cout<<"      #       ###       "<<endl;
		cout<<"HP:"<<hero.havePokemonCount[choose].hp<<endl;
		cout<<hero.havePokemonCount[choose].pname<<"-----------------------"<<endl;
		round++;
		if(round&1){
		cout<<"Attack"<<endl;
		hero.havePokemonCount[choose].attack(hero.havePokemonCount[choose],otherPokemon,round);
		}
		else {
		cout<<"Defense"<<endl;
		otherPokemon.attack(hero.havePokemonCount[choose],otherPokemon,round);
		}
		cin>>y;
	}
	if(hero.havePokemonCount[choose].hp<=0 ) {
		cout<<"You Lose.Please wait few minute for heal to your pokemon";
		return false;
		
	}
	else if(otherPokemon.hp<=0){
		
		cout<<"Congratulations... You win."<<endl;
		cout<<"You gained "<<otherPokemon.rate<<" exp."<<endl;
		
		
		hero.havePokemonCount[choose].exp+=otherPokemon.rate;
		return true;
	}
//	 cout<<"Pres arrow key pls"<<endl;
//	 int const ch = getch();
//		 if(ch != (VK_RBUTTON || VK_LBUTTON || VK_UP || VK_DOWN)){
//		 	throw "Error you have not pressed arrow key";
//		 }
	
}



int * map::findRate(pokemon * pk,int rate){
		int pc=13;
		int * rp1;
		int * rp2;
		int * rp3;
		for(int i =0 ; i<pc;i++ )
		{
			if(pk[i].rate==1) {
				*rp1=pk[i].id;
				rp1++;
			}
			else if(pk[i].rate==2) {
				*rp2=pk[i].id;
				rp2++;
			}
			else if(pk[i].rate==3) {
				*rp3=pk[i].id;
				rp3++;
			}
			
		}
		
		if(rate==1) return rp1;
	    if(rate == 2) return rp2;
		if(rate== 3)return rp3;

	}
	
	void fightString(){
	cout<<"   __________________________   \n";
	cout<<"|-| ##### #  #### #  # ##### |-|\n";
	cout<<"|-| #     # #     #  #   #   |-|\n";
	cout<<"|-| ##### # # ### ####   #   |-|\n";
	cout<<"|-| #     # #   # #  #   #   |-|\n";
	cout<<"|-| #     #  #### #  #   #   |-|\n";
	cout<<"|-|__________________________|-|\n";
	cout<<"________________________________\n";
	
	}

#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
using namespace std;

class player {
	public: 
	char player_name[100];
    char player_sign;	
    int player_win; 
	};
	
	
 int game_turn(char x[][3],player plr_1, player plr_2){
 int play_again=1;
 plr_1.player_win=0;
 plr_2.player_win=0; 
char num;
char y[3][3]={{'_','_','_'},
              {'_','_','_'},
              {'_','_','_'}};

char symbol;
int g=9;
 while (g>0) {
 
 system("cls");
  
 cout<<"\n player1   name: "<<plr_1.player_name<<"\t\t player2  name: "<<plr_2.player_name;
 cout<< "\n\t  sign: "<<plr_1.player_sign<< "\t\t\t sign: "<<plr_2.player_sign;
 	
cout<<"\n\n\n\n\t\t\t "<<x[0][0]<<"\t"<<x[0][1] <<"\t"<<x[0][2];
cout<<"\n\n\t\t\t "<<y[0][0]<<"\t"<<y[0][1] <<"\t"<<y[0][2];

cout<<"\n\n\n\n\t\t\t "<<x[1][0]<<"\t"<<x[1][1] <<"\t"<<x[1][2];
cout<<"\n\n\t\t\t "<<y[1][0]<<"\t"<<y[1][1] <<"\t"<<y[1][2];

cout<<"\n\n\n\n\t\t\t "<<x[2][0]<<"\t"<<x[2][1] <<"\t"<<x[2][2];
cout<<"\n\n\t\t\t "<<y[2][0]<<"\t"<<y[2][1] <<"\t"<<y[2][2]<<"\n";


if(g%2!=0){
symbol=plr_1.player_sign;
cout<<"\n\t\tplayer1: ";}
else{
symbol=plr_2.player_sign;
cout<<"\n\t\tplayer2: ";}


if ( plr_1.player_win==1){
	cout<<"\n\n\t\t\t"<< plr_1.player_name << " win";
     return play_again=0;}

else if ( plr_2.player_win==1){
		cout<<"\n\n\t\t\t"<< plr_2.player_name << " win";
      return play_again=0;}
else{

up1: cin>>num;



if((isalpha(num))||((num!='1')&&(num!='2')&&(num!='3')&&(num!='4')&&(num!='5')&&(num!='6')&&(num!='7')&&(num!='8')&&(num!='9'))){
	cout<<"error must enter no. between (1-9)";
	goto up1;
}

for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		if(x[i][j]==num)
		 
		 if(y[i][j]=='_')
		y[i][j]=symbol;
	
	else{
	
		cout<<"error choose empty no. ";
		goto up1;}
	
	}
}


g--;

if((y[0][0]!='_')&&(y[0][0]==y[0][1])&&((y[0][0]==y[0][2]))){
if(y[0][0]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
}

else if((y[0][0]!='_')&&(y[0][0]==y[1][0])&&((y[0][0]==y[2][0]))){
if(y[0][0]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
	
}

else if((y[0][1]!='_')&&(y[0][1]==y[1][1])&&((y[0][1]==y[2][1]))){
if(y[0][1]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
	
}


else if((y[0][2]!='_')&&(y[0][2]==y[1][2])&&((y[0][0]==y[2][2]))){
if(y[0][2]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
	
}


else if((y[1][0]!='_')&&(y[1][0]==y[1][1])&&((y[1][0]==y[1][2]))){
if(y[1][0]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
}
	else if((y[2][0]!='_')&&(y[2][0]==y[2][1])&&((y[2][0]==y[2][2]))){
if(y[2][0]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
	
}

else if((y[0][0]!='_')&&(y[0][0]==y[1][1])&&((y[0][0]==y[2][2]))){
if(y[0][0]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;
	
}

else if((y[0][2]!='_')&&(y[0][2]==y[1][1])&&((y[0][2]==y[2][0]))){
if(y[0][2]==plr_1.player_sign)
plr_1.player_win=1;
else
plr_2.player_win=1;}
}
}

cout<<"\n\n\t\t No one win\n";

 return play_again=0;
}



	void game_st(player plr_1, player plr_2, int play_again){

up0:  system("cls");
char qu, play;
	system("color 5f");
		  //welcome screen;
		cout<<"\n"<<"\t\t"<<"  *  *  *  *  *  *  *  *  *  *  *  *  *  *"<<"\n";
  cout<<"\t\t"<<"  *  *  * "<<" Welcome in X-O game "<<" *  *  *  *\n";
 cout<<"\t\t"<<"  *  *  *  *  *  *  *  *  *  *  *  *  *  *"<<"\n";
  cout<<"\n\t"<<"  "<<"player1_name:"<<"\t";
  cin>> plr_1.player_name;
  cout<<"\n choose sign X or O "<<"\t";


up:  cin>> plr_1.player_sign ;
  if (( plr_1.player_sign == 'x') || ( plr_1.player_sign == 'X'))
  plr_2.player_sign='O';
   
   else if ( (plr_1.player_sign == 'o')||( plr_1.player_sign == 'O'))
  plr_2.player_sign='X';

 else {
 cout <<" error enter x or o \n";
 goto up;
 
}
  cout<<"\n\t"<<"  "<<"player2_name:"<<"\t";
   cin>> plr_2.player_name;

char x[3][3]={ {'1','2','3'},
              {'4','5','6'},
			  {'7','8','9'}}; 

play_again=game_turn(x, plr_1, plr_2);

play= play_again;
if (play==0){
cout<<"\n\n\t\tplay again: \n\t\t\t\t 1:yes\t 0:no\n";

 cin >>qu;
while((qu!='0')&&(qu!='1')){
cout<<"\n\t enter 0 or 1\n";

cin>>qu;}

if(qu=='1'){
	 play_again=1;
	goto up0;
	 }

else if(qu=='0')
exit(0); 


}

}


int main(){

int play_again=1;	
  player p1;
  player p2;
  
game_st(p1,p2,play_again);

return 0;	
} 





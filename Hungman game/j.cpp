#include<iostream>
#include<string>
#include<cstring>
#include<ctype.h>
#include<cstdlib>
#include<time.h>
#include<stdlib.h>

using namespace std;

//function for searshing of letter.
void s_char(char arr[],int n,char var,int & score,int & chance,char arr2[], int & comp){
 int y=score;

	for(int l=0;l<n;l++){

//condition for the repeated letter.
		if((var==arr2[l])||(var== (char) toupper (arr2[l]))||(var== (char) tolower (arr2[l]))){
		
	cout<<" you entered this letter before try again"<<"\n";
	y=3000;
break;

}
// condition for true letter. 
else if((var==arr[l])||(var== (char) toupper (arr[l]))||(var== (char) tolower (arr[l]))){
score++;
comp++;
arr2[l]=arr[l];
 cout<<"excellant"<<"\n"<<var<<" is letter no. "<<l+1<<"\n";
 	cout<<"\t\t\t\t\t\t\t\t - \n";
 }
}

//condition for wrong letter.
while(y==score){
		chance--;
			score--;
		if(chance>0){
		
	cout<<"wrong try again"<<"\n";
	cout<<"you have"<<chance<<" chance"<<"\n";
	cout<<"\t\t\t\t\t\t\t\t "<<var<<"\n";}
else
break;
	}

	
}

//main_level that contains 2 level. 
int main_level(string array[],int n,int level, char name[] ){
	int chance=5;
	
	int score=0;
	char cn[100];
	char found_char[100];
	int help =3;
	int play;
//	srand((unsigned)time(0));
		for(int i=0;i<n;i++){
//country index = c_index .
//countery length = c_l .
 srand((unsigned)time(0));
	int c_index= rand()%n;
	int c_l=array[c_index].length();
	cout<<"\n country contains:"<<c_l<<" letter "<<"\n";

strcpy(cn,array[c_index].c_str());
cout<<" guss the contry"<<"\n"<<"you have "<<chance<<" chance";
cout<<"\n";
	char found_char[100]={0};
char g_c[2];
if(level==1)
cout<<"you can ask help three time if you want help enter star (*) \n";

   cout<<"\n"<<"enter one letter"<<"\n\n";

int comp=0;
 cout<<"\t\t\t\t\t\t\t wrong letter \n";
		while (chance>0){
 fo2:
 	cout<<"\n";
 for(int i=0;i<c_l;i++){
	if(found_char[i]==0)
	cout<<" _ ";

	else
	cout<<found_char[i];
		
		}

 cout<<"\n";
	 cin>>g_c;
	 while ((isdigit(g_c[0]))||(g_c[1]!=0)){
	 	cout<<"you must enter one letter \n";
	 	cin>>g_c;
	 	if((g_c[1]==0)&&(isalpha(g_c[0])))
	 	break;
	 }
	 
//easy_level.
if(level==1){

	if(g_c[0]=='*'){

	if(help>0){
	
	for(int i=0;i<c_l;i++)
	if(cn[i]!=found_char[i]){
		found_char[i]=cn[i];
		comp++;
		break;
		}

	help--;

		if(comp!=c_l)
	goto fo2;


}
	else
	cout<<" sorry you asked help 3 time,you can't ask help again\n";
}
}
if(((level==1)&&(g_c[0] !='*'))||(level==2))
 s_char(cn,c_l,g_c[0],score,chance,found_char,comp);
 
   
 //condition for complete the true letters for the country. 
  if(comp==c_l){
        cout<<"\n\ncongratulation you found the country"<<"\n";
		cout<<"the country is "<<cn;
		cout<<"\n-----------------------";
	
		break;
	  }

}
   if (chance==0){

   cout<<"\n   Game Over "<<name<<"\n";
   cout<<"your score: "<<score<<"\n the country was "<<cn;
cout<<"\n\ndo you want to play again\n1-Yes\n2-No";
cin>>play;
while((play!=1)&&(play!=2)){
	cout<<"you must enter 1 to play again or 2 to exit \n ";
	cin>>play;
	if((play==1)||(play==2))
	break;
	if(isalpha('play'))
	exit(0);
}
//condition for continue the playing.
if(play==1){

cout<<"Enter the no.of level"<<"\n1- Easy\n2- Hard"<<"\n";
cin>>level;
chance=5;
help=3;
play=0;
score=0;
}

}
 if(play==2)

exit(0);
}
return 0;
}
int main(){
system("color 5f");

	//array used as a library for countries.
string countries[]={"Egypt","Iraq","Djibouti","Syria","Qatar","Yemen",
"Argentina","Palestine","Brazil","Italy","Iceland","Panama","Turkey","Tunisia"
,"Mauritania","Jordan","Taiwan","Algeria","Japan","Switzerland","France",
"Cameroon","Britain","Nigeria","Mexico","America","Morocco","Lebanon","Canada",
"Belgium","Bahrain","Germany","Australia","Indonesia","Comoros","Somalia",
"Kuwait","Ethiopia","Sudan"};

  //welcome screen;
  char name[100];
  cout<<"\n"<<"\t\t"<<"  *  *  *  *  *  *  *  *  *  *  *  *  *  *"<<"\n";
  cout<<"\t\t"<<"  *  *  * "<<" Welcome in hungman game "<<"*  *  *\n";
 cout<<"\t\t"<<"  *  *  *  *  *  *  *  *  *  *  *  *  *  *"<<"\n";
  cout<<"\n\t"<<"  "<<"Enter yor name:"<<"\n"<<endl;
  cin>>name;
  cout<<"\n\t\t\t"<<"Hello "<<name<<"\n"<<endl;

  int n=sizeof(countries)/sizeof(countries[0]);
  cout<<"Enter the no.of level"<<"\n1- Easy\n2- hard"<<"\n";
 int level,x;

cin>>level;
while((level!=1)&&(level!=2)){
	cout<<"you must enter 1 or 2 to \n ";
	cin>>level;
	if((level==1)||(level==2))
	break;
	if(isalpha('level'))
	exit(0);
}


 main_level(countries,n,level,name);


return 0;
}


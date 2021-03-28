#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int k(char array1[3][3],int m,int lol);
int win_check(char array1[3][3]);
void display_board(char array1[3][3]);

void main (void){

int count=1,n=0,i,j,win,menu,signal1=0;
char a[3][3];
a[0][0]='1';
a[0][1]='2';
a[0][2]='3';
a[1][0]='4';
a[1][1]='5';
a[1][2]='6';
a[2][0]='7';
a[2][1]='8';
a[2][2]='9';

printf("\t\t\t WELCOME TO OUR TIC GAME!\n\n Main Menu \n 1-Human vs Human\n 2-Human vs Computer \n 3-Computer vs Human \n");
scanf("%d",&menu);

display_board(a);

while(count<10){
	if(menu==2 && count%2==0){
		n=k(a,count,menu);
		printf("Computer turn: %d \n",n);
	}
	else if(menu==3 && count%2==1){
		n=k(a,count,menu);
		printf("Computer turn: %d \n",n);
	}
	else{
		puts(count%2?"Player A":"Player B");
		printf("Enter the corresponding number to choose a square: ");
		scanf("%d",&n);
	}
	signal1=0;
	do{
		signal1=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(a[i][j]=='0'+n){
					
					signal1=1;
					if(count%2==1){ 
						a[i][j]='X';}
					else{
						a[i][j]='O';}	
				}
			}
		}
		if(signal1==0){
			printf("Invalid Value.Enter another value: ");
			scanf("%d",&n);
			
		}
	}while(signal1!=1);
	
	
	display_board(a);
	
	
	win=win_check(a);
	if(win==1){
		if(menu==2 && count%2==0){
		printf("Computer won \n");
		break;
	}
	else if(menu==3 && count%2==1){
		
		printf("Computer won \n");
		break;
	}
	else{
		puts(count%2?"Player A win":"Player B win");
		break;
	}
	}
	count++;
	
}
if(win!=1){
	puts(" Game Draw ;P ");
	
}
puts("\t Game Over!");
}
void display_board(char array1[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		
			
		
			if (j!=2){
				printf(" \t%c",'|');
			}
		}
		printf("\n");
		for (j=0;j<3;j++){
			printf("%4c",array1[i][j]);

			if (j!=2){
				printf("\t%c",'|');
			}
		}
		printf("\n");
		for (j=0;j<12;j++){
			if(i!=2)
				printf("%2c",'_');
			}
		printf("\n");
	}	
}
int win_check(char array1[3][3]){
int result=0,i,j;
for(i=0;i<3;i++){
	if(array1[i][0]==array1[i][1] && array1[i][1]==array1[i][2]){
		result=1;
	}
} 
for(j=0;j<3;j++){
	if(array1[0][j]==array1[1][j] && array1[1][j]==array1[2][j]){
		result=1;
	}
}
if(array1[0][0]==array1[1][1] && array1[1][1]==array1[2][2]){
		result=1;
	}
if(array1[0][2]==array1[1][1] && array1[1][1]==array1[2][0]){
		result=1;
	}

return result;
}
int k(char array1[3][3],int m,int lol){
	unsigned int i,j,k,z,choice,signal=0,fl=0,w=0;
	char c[]={'1','2'};
	if(lol==3){
		c[0]='O';
		c[1]='X';
	}
	if(lol==2){
		c[0]='X';
		c[1]='O';
	}
	for(k=0;k<2;k++){
		for(i=0;i<3;i++){
			if(array1[i][0]==c[k] && array1[i][1]==c[k] &&  array1[i][2]!='X' && array1[i][2]!='O'){
				z=3*(i+1);
				fl=1;}
			if(array1[i][1]==c[k] && array1[i][2]==c[k] &&  array1[i][0]!='X' && array1[i][0]!='O'){
				z=3*i+1;
				fl=1;}
			if(array1[i][0]==c[k] && array1[i][2]==c[k] &&  array1[i][1]!='X' && array1[i][1]!='O'){
				z=3*i+2;
				fl=1;}
			}
		for(j=0;j<3;j++){
			if(array1[0][j]==c[k] && array1[1][j]==c[k] &&  array1[2][j]!='X' && array1[2][j]!='O'){
				z=array1[2][j]-'0';
				fl=1;}
			if(array1[1][j]==c[k] && array1[2][j]==c[k] &&  array1[0][j]!='X' && array1[0][j]!='O'){
				z=array1[0][j]-'0';
				fl=1;}
			if(array1[0][j]==c[k] && array1[2][j]==c[k] &&  array1[1][j]!='X' && array1[1][j]!='O'){
				z=array1[1][j]-'0';
				fl=1;}
			}
			if(array1[0][0]==c[k] && array1[1][1]==c[k] &&  array1[2][2]!='X' && array1[2][2]!='O'){
				z=9;
				fl=1;}
			if(array1[1][1]==c[k] && array1[2][2]==c[k] &&  array1[0][0]!='X' && array1[0][0]!='O'){
				z=1;
				fl=1;}
			if(array1[0][0]==c[k] && array1[2][2]==c[k] &&  array1[1][1]!='X' && array1[1][1]!='O'){
				z=5;
				fl=1;}
				
			if(array1[0][2]==c[k] && array1[1][1]==c[k] &&  array1[2][0]!='X' && array1[2][0]!='O'){
				z=7;
				fl=1;}
			if(array1[2][0]==c[k] && array1[1][1]==c[k] &&  array1[0][2]!='X' && array1[0][2]!='O'){
				z=3;
				fl=1;}
			if(array1[0][2]==c[k] && array1[2][0]==c[k] &&  array1[1][1]!='X' && array1[1][1]!='O'){
				z=5;
				fl=1;}	
				
		
	}
	
	
	if(fl==0){
		srand(time (NULL));	
		z=1 + ( rand() %9);
		signal=0;
		do{
			signal=0;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(array1[i][j]=='0'+z){
						signal=1;
						}		
					}
				}
			
			if(signal==0){
				z=1 + ( rand() %9);
			}
		}while(signal==0);
	}
	choice=(int)z;
    return choice;
}
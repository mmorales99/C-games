#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main(){
	
	int score=0;
	
	int randy = rand() % 20;
	int randx = rand() % 40;
	int contComida=0;
	int maxComida=1;
	
	char barra = 179;
	char barraAlta = 238;
	
	char comida = 237;
	char jugador = 254;
	
	int x,y;
	int dimx=40,dimy=20;
	char mundo[dimy][dimx];
	
	char mundoComida[dimy][dimx];
	char mundoSnake[dimy][dimx];
	
	
	printf("\t\t\t            ___\n");
	printf("\t  SCORE :  %d\t           %cTAB%c Pausa", score,barra,barra);
	printf("\n\t\t\t            %c%c%c\n", barraAlta,barraAlta,barraAlta);
	
	mundo[0][0]= 218;
	mundo[0][39]= 191;
	mundo[19][0]= 192;
	mundo[19][39]= 217;
	
	for(x=1;x<dimx-1;x++){
		mundo[0][x]= '-';
	}
	for(x=1;x<dimx-1;x++){
		mundo[19][x]= '-';
	}
	for(y=1;y<dimy-1;y++){
		for(x=0;x<dimx;x++){
			if(x==0 || x==39){
				mundo[y][x]= 179;
			}else{
				mundo[y][x]=' ';
			}
		}
	}
	if(contComida!=maxComida){
		mundo[randy][randx]=comida;
		contComida++;
	}	
	printf("\t");
	for(y=0;y<dimy;y++){
		/*for(x=0;x<dimx;x++){
			printf("%c",mundoComida[y][x]);
		}
		printf("\r\t");*/
		for(x=0;x<dimx;x++){
			if(x<dimx-1 && x>0 && y>0 && y<dimy-1 && mundoComida[y][x]==comida){
				mundo[y][x]=mundoComida[y][x];	
			}
			if(x<dimx-1 && x>0 && y>0 && y<dimy-1 && mundoComida[y][x]==jugador){
				mundo[y][x]=mundoComida[y][x];	
			}
			printf("%c",mundo[y][x]);
		}
		printf("\n\t");
	}
	
	
	
	
	getchar();
	system("cls");
	contComida--;
	main();
	}

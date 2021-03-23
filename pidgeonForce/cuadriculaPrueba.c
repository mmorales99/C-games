#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

/*
int main(){
	char z='O';
	
	time_t start_t, end_t;
	double diff_t;
		
	int nivel=1;
	int metros;
	int contMetros =0;
	int victory=0;
	int k=1;
	int obstaculoTotal=0;
	int obstaculoMax=600;
	int coordy=79;
	int coordx=20; // caracteres máximos de la pantalla de juego
	int x,y; // contadores auxiliares
	int i=78;  // caracteres totales horizontales, utilizado para el menu de pausa y la pantalla de inicio
	int c=0;	// contador de vueltas para la generacion del menu de pausa y la pantlla de inicio
	int vidas =3; // numero de golpes que puedes recivir antes de morir
	int score =0;	// puntuacion, segun el tiempo y los enemigos derrotados.
	int count;	// cntador auxiliar
	int misilMax=5;
	int misilTotal=0;
	int enemigoTotal=0;
	int enemigoActual=0;
	int scoreTiempo=0;
	int balaCd=0;
	int misilCd=0;
	int r = rand() % 12;
	
	char keyPress;
	char nombreSoldado[10];
	char str[3];
	char mundo[coordx][coordy];
	char player= '{';
	char misil ='*';
	char bala ='=';
	char obstaculo='O';
	char enemigo='E';
	char caja='H';
	char recargaVida='V';
	char recargaMisil='R';
	char direccionJuego = 'r';
	
	c=0;
	k=1;
	x=0;
	y=0;
	
	while(x!=coordx){
		while(y!=coordy){
			mundo[x][y]= ' ';
			if(y==0 || y==5){
				mundo[x][y]= z;
			}
			y++;
		}
		x++;
		y=0;
	}
	x=0;
	y=0;
	
	while(k){
		
		while(x!=coordx){
			while(y!=coordy){
				printf("%c",mundo[x][y]);
				y++;
			}
			printf("\n");
			x++;
			y=0;
		}
		x=0;
		y=0;
		printf("Presiona intro");
		getchar();
		y=coordy-1;
		while(x!=coordx){
			while(y>=0){
				if(mundo[x][y]==z){
			 			mundo[x][y+1]=mundo[x][y];
			 			mundo[x][y]=' ';
				}
				y--;
			}
			y=coordy-1;
			x++;
		}
		x=0;
		y=0;
		while(x!=coordx){
			while(y!=coordy){
				if(y==0){
					mundo[x][y]= z;
				}
				y++;
			}
			x++;
			y=0;
		}
		
		x=0;
		y=0;
		while(x!=coordx){
			while(y!=coordy){
				printf("%c",mundo[x][y]);
				y++;
			}
			printf("\n");
			y=0;
			x++;
		}
	}
	system("PAUSE");
	
}
	
*/



/*
int main(){
	char z='O';//carqacter auxiliar, remover para implementar en el juego final 
	
	int coordy=20;	// caracteres máximos de la pantalla de juego. es lo acho
	int coordx=78;  // caracteres máximos de la pantalla de juego, es el altontn
	int x,y; // contadores auxiliares
	
	char mundo[coordy][coordx];	//mundo de dimensiones n m
		
	
//	c=0;
//	k=1;
//	x=0;
//	y=0;

	for(y=0; y<coordy; y++){
		for(x=0;x<coordx;x++){	
			if((y>0 && y<coordy-1)){
				mundo[y][0]='|';
			}
			if(((y!=0 || y<coordy) && (x!=0)) || (y==0 && x==0) || (y==coordy-1 && x==0)){
				mundo[y][x]=' ';
			}
			if((y==0 || y==coordy-1) && (x>0 && x<coordx) ){
				mundo[y][x]='-';
			}
		}
	}
	
	for(y=0;y<coordy;y++){
		for(x=0;x<coordx;x++){
			printf("%c",mundo[y][x]);
		}
		printf("\n");
	}
	getchar();
	
	
	for(y=1;y<coordy-1;y++){
		mundo[y][1]='Q';
		mundo[y][10]='Q';
	}
	
	
	for(y=0;y<coordy;y++){
		for(x=0;x<coordx;x++){
			printf("%c",mundo[y][x]);
		}
		printf("\n");
	}
	getchar();
	while(1){
		for(y=1;y<coordy-1;y++){
			mundo[y][1]='Q';
			mundo[y][10]='Q';
		}
		
		
		
		x=coordx-1;
		while(y!=coordy){
			while(x>0){
				if(mundo[y][x]=='Q'){
			 			mundo[y][x+1]=mundo[y][x];
			 			//mundo[y][x]=' ';
				}
				x--;
			}
			x=coordy-1;
			y++;
		}
		x=0;
		y=0;
		
		for(y=0;y<coordy;y++){
			for(x=0;x<coordx;x++){
				printf("%c",mundo[y][x]);
			}
			printf("\n");
		}	
	}
	
	
	
	
	
	
	
	system("PAUSE");
}*/

/*

time_t start_t, end_t;	//variables de tiempo, que sirve para el calculo de la puntuacion
	double diff_t;	//contador para la puntuacion en fucion del tiempo
		
	int nivel=1;	//nivel actual en el que te encuentras, da la longitud y la puntuacion
	int metros;	//duracion de un nivel en ciclos, da tambien la puntuacion.
	int contMetros =0;	//cuenta las vueltas que se dan al cilo del juego, sirve para poner final aun nivel.
	int victory=0;	//contador para orzar la salida cuando se pierde.
	int k=1;	//fuerza la reproducion del juego cada vez que se pierde
	int obstaculoTotal=0;  //contador de obstculos, para evitar sobre pasar el maximo de obstaculos, evita la sobre poblacion de obstaculos.	
	int obstaculoMax=600; //cantidad maxima en superficie que pueden aparecer obstaculos
	int coordy=78;	// caracteres máximos de la pantalla de juego. es lo acho
	int coordx=20;  // caracteres máximos de la pantalla de juego, es el alto
	int x,y; // contadores auxiliares
	int i=78;  // caracteres totales horizontales, utilizado para el menu de pausa y la pantalla de inicio
	int c=0;	// contador de vueltas para la generacion del menu de pausa y la pantlla de inicio
	int vidas =3; // numero de golpes que puedes recivir antes de morir
	int score =0;	// puntuacion, segun el tiempo y los enemigos derrotados.
	int count;	// cntador auxiliar
	int misilMax=5;				//maximo de misiles que puede tener el jugarodr. si se excede da mas puntuacion
	int misilTotal=0;			//misiles que tiene el jugador , en cada momento.
	int enemigoMax=20;			//enemigos maximos, controla la sobre aparcion de enemigos.
	int enemigoTotal=0;		//contador para limitar la cantidad de enemigos en pantalla
	int scoreTiempo=0;			//La puntuacion va en funcion del tiempo que te mantengas vivo , mates nemigo y recojas objetos. si exceden el total maximo tienes un bonus. este contador  es para el tiempo.
	int balaCd=0;				//cooldown, o enfriamiento de las balas, tiempo entre balas
	int misilCd=0;				//cooldown, o enfriamiento de los misiles, tiempo entre misiles
	int r = rand() % 12; 		//genera un numero aleatorio para la generacion de objetos aleatorios, componente de rng. dota de proceduralidad¿?
	
	char keyPress;				//recoge la tecla pulsada para el movimiento del jugardor
	char nombreSoldado[10];		//dota al jugarodr de un nombre. fatal que si el jugador no da un nombre, se le asigne uno aleatorio.
	char str[3];				//recoje datos
	char mundo[coordx][coordy];	//mundo de dimensiones n m
	char player= '{';		//objeto jugador, puede moverse por la cuadricula de juego, puede disparar, tiene tres vidas y puede recojer objetos.
	char misil ='*';		//objeto de jugador, puede destuir obstaculos, enemigos y cajas en area, sonb limitados y pueden recargarse.
	char bala ='=';			//objeto de jugador, puede eliminar enemigos, romper cajas y recoger objetos lejanos 
	char obstaculo='O';		//objeto destruible solo con misiles. no suelta nada, y puede quitar vidas.
	char enemigo='E';		//objeto destuible que quita vidas. puede soltar vidas o misiles, en menor proporcion a las cajas.
	char caja='H'; 			//objeto del mundo, es destruible, y puede soltar vidas o misiles.
	char recargaVida='V';   //no esta habilitada, de momento
	char recargaMisil='R';	//no esta habilitada, de momento
	char direccionJuego = 'r';    // esta variable no es significativa, solo indica el movimiento del mundo. se puede eliminar o comentar.
*/






/*
int main(){
	
	
	char z='O';
	
	time_t start_t, end_t;
	double diff_t;
		
	int nivel=1;
	int metros;
	int contMetros =0;
	int victory=0;
	int k=1;
	int obstaculoTotal=0;
	int obstaculoMax=600;
	int coordy=79;
	int coordx=20; // caracteres máximos de la pantalla de juego
	int x,y; // contadores auxiliares
	int i=78;  // caracteres totales horizontales, utilizado para el menu de pausa y la pantalla de inicio
	int c=0;	// contador de vueltas para la generacion del menu de pausa y la pantlla de inicio
	int vidas =3; // numero de golpes que puedes recivir antes de morir
	int score =0;	// puntuacion, segun el tiempo y los enemigos derrotados.
	int count;	// cntador auxiliar
	int misilMax=5;
	int misilTotal=0;
	int enemigoTotal=0;
	int enemigoActual=0;
	int scoreTiempo=0;
	int balaCd=0;
	int misilCd=0;
	int r = rand() % 12;
	
	char keyPress;
	char nombreSoldado[10];
	char str[3];
	char mundo[coordx][coordy];
	char player= '{';
	char misil ='*';
	char bala ='=';
	char obstaculo='O';
	char enemigo='E';
	char caja='H';
	char recargaVida='V';
	char recargaMisil='R';
	char direccionJuego = 'r';
	
	
	score=0;
		z=0;	
	// genera una matriz de dimensiones iguales a los desplazamientos.
		for(x=0; x<coordx; x++){
			for(y=0; y<coordy; y++){
				if((x==0 && y==0) || (x==0 && y==coordy)){
					mundo[y][x]=' ';
				}
				if((y!=0 && x==0) || (y!=coordy && x==0)){
					mundo[y][x]='|';
				}
				if((y!=0 && x!=0) || (y!=coordy && x!=0)){
					mundo[y][x]=' ';
				}
			}
			mundo[0][0]=' ';
			mundo[20][0]=' ';
			mundo[0][x]='-';
			mundo[20][x]='-';	
		}
		mundo[coordy/2][coordx - 10]= player;
		
		while(k){
			victory=1;
			metros = nivel*500;
			misilTotal=2;
			printf("\n\n\n\n\n\t\t\t\t N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\t\tLoading mundo");
			Sleep(750);
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\t\tLoading mundo.");
			Sleep(750);
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\t\tLoading mundo..");
			Sleep(750);
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\t\tLoading mundo...");
			Sleep(500);
			system("cls");
			time(&start_t);	
			//muestra en pantalla el juego.
			while(victory){
				system("cls");
				printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
				printf("<\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
				for (y = 0; y <= coordy; y ++) {
			            for (x = 0; x < coordx; x ++) {
			                printf("%c",mundo[y][x]);
			            }
					printf("\n");
				}
				printf("\t\t\t\t|  %d  /  %d  |m",contMetros, metros);
				
				//enemies, obstacles and aids.
				
				// para desplazar correctamente las columnas, comprobar y primero. coordenadas de x tratar a la inversa.
				for(x=0;x<coordx;x++){
					for(y=1;y<coordy;y++){
						if(mundo[y][x+1]!=player||mundo[y][x+1]!=misil){
							if(x==0){
								mundo[y][x]='|';
							}
							if((x+1)!=coordx){
								mundo[y][z+1]=mundo[y][z];
							}else{
								mundo[y][z]=' ';
							}
						}else{
							if(mundo[y][x+1]==player){
								mundo[y][x]=player;
							}else if(mundo[y][x+1]==player && mundo[y][x]==obstaculo){
								mundo[y][x]=player;
								mundo[y+1][x+1]=' ';
								mundo[y+1][x]=' ';
								mundo[y+1][x-1]=' ';
								mundo[y-1][x+1]=' ';
								mundo[y-1][x]=' ';
								mundo[y-1][x-1]=' ';
							}
						}
					}
				}
				z++;
				
				for(y=1;y<coordy;y++){
					r = rand() % 12;
					if(r==0 || r==1 || r==2 || r==3 || r==7||r==8){
						mundo[y][1]=' ';
					}
					if(r==5 || r==6 || r==4){
						if(obstaculoTotal<obstaculoMax){
						mundo[y][1]=obstaculo;
						obstaculoTotal++;
						}
					}
					if(r== 9 || r==10){
						mundo[y][1]=enemigo;
					}
					if(r==11){
						mundo[y][1]=caja;
					}
				}
				
					
				
				/*GUNS!!!*/
			/*
				for(x = 0; x<coordx;x++){
					for(y=0;y<coordy;y++){
						if (mundo[y][x] == bala && mundo[y][x-1] != obstaculo) {
		                    if((x-1)!=0){
								mundo[y][x] = ' ';
		                        mundo[y][x-1] = bala;
		                        for(y=0;y<coordy;y++){
		                        	if(mundo[y][1]==bala){
										mundo[y][1]=' ';
									}
								}
							}
						}else if(mundo[y][x] == bala && mundo[y][x-1] == obstaculo){
							mundo[y][x]=' ';
						}
						if (mundo[y][x] == misil && mundo[y][x-1] != obstaculo) {
							if((x-1)!=0){
								mundo[y][x] = ' ';
		                        mundo[y][x-1] = misil;
		                        for(y=0;y<coordy;y++){
		                        	if(mundo[y][1]==misil){
										mundo[y][1]=' ';
									}
								}
							}
						}else if(mundo[y][x]==misil && mundo[y][x-1]==obstaculo){
							mundo[y-1][x-1]=' ';
							mundo[y-1][x]=' ';
							mundo[y-1][x+1]=' ';
							mundo[y][x-1]=' ';
							mundo[y][x]=' ';
							mundo[y][x+1]=' ';
							mundo[y+1][x+1]=' ';
							mundo[y+1][x]=' ';
							mundo[y+1][x-1]=' ';
						}
					}
				}
			//control de teclas.
				if(kbhit()){
			        keyPress = getch();
			    }
			    else {
			        keyPress = ' ';
			    }
			    if(keyPress=='m' && misilCd > 15 && misilTotal!=0){
					misilTotal--;
					for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( mundo[y][x] == player) {
		                 		mundo[y][x-2] = misil;
			                    misilCd=0;
			                }
			            }
					}
				}
			    if(keyPress=='b' && balaCd > 2){
					for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( mundo[y][x] == player) {
		                 		mundo[y][x-2] = bala;
			                    balaCd=0;
			                }
			            }
					}
				}
			    if (keyPress == 'a') {
			        for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( mundo[y][x] == player) {
		                 		if(x!=1){
								mundo[y][x-1] = player;
			                    mundo[y][x] = ' ';
								}
			                }
			            }
					}
			    }
			    if (keyPress == 'd') {
			        for(y = coordy - 1 ;y > 0;y--){
						for (x = coordx - 1 ; x > 0; x--) {
			                if ( mundo[y][x] == player) {
			                    if((x+2)!=coordx){
									mundo[y][x+1] = player;
			                    	mundo[y][x] = ' ';
								}
			                }
			            }
					}
			    }
			    if (keyPress == 'w') {
			        for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( mundo[y][x] == player) {
		                 		if(y!=1){
								mundo[y-1][x] = player;
			                    mundo[y][x] = ' ';
								}
			                }
			            }
					}
			    }
			    if (keyPress == 's') {
			        for(y = coordy - 1 ;y > 0;y--){
						for (x = coordx - 1 ; x > 0; x--) {
			                if ( mundo[y][x] == player) {
			                    if((y+1)!=coordy){
									mundo[y+1][x] = player;
			                    	mundo[y][x] = ' ';
								}
			                }
			            }
					}
			    }
				if (keyPress == '	') {
			        Sleep(150);
			        fflush(stdin);
					system("cls");
					c=0;
					i=78;
					printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
					printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
					do{
						if(i==78){
							printf(" ");
						}
						if(i!=1 || i!=78){
							printf("-");
						}
						if(i==1 && c==0){
							i=19;
							c=1;
							while(i!=0){
								if(i!=10){
									printf("\n|");
								}
								if(i==12){
									printf("\n|");
									printf("\t\t\t\t\t\t\t%c",player);
								}
								i--;
							}
						printf("\n");
						i=79;
						}
					i--;
					}while(i);
					getch();	
					system("cls");		
			    }
			    if(vidas==0){
					victory=0;
				}
				if(contMetros == metros){
					continue;
				}
				contMetros++;
				time(&end_t);
				score = difftime(end_t, start_t);			
				balaCd++;
				misilCd++;
			    Sleep(60);
			    
				}
				if(victory==0){
					break;
				}	
				nivel++;
			}
	}
	*/	
	
	
	
	/*
	
	
	c=0;
	k=1;
	x=0;
	y=0;
	
	while(x!=coordx){
		while(y!=coordy){
			mundo[x][y]= ' ';
			if(y==0 || y==5){
				mundo[x][y]= z;
			}
			y++;
		}
		x++;
		y=0;
	}
	x=0;
	y=0;
	
	while(k){
		
		while(x!=coordx){
			while(y!=coordy){
				printf("%c",mundo[x][y]);
				y++;
			}
			printf("\n");
			x++;
			y=0;
		}
		x=0;
		y=0;
		printf("Presiona intro");
		getchar();
		y=coordy-1;
		while(x!=coordx){
			while(y>=0){
				if(mundo[x][y]==z){
			 			mundo[x][y+1]=mundo[x][y];
			 			mundo[x][y]=' ';
				}
				y--;
			}
			y=coordy-1;
			x++;
		}
		x=0;
		y=0;
		while(x!=coordx){
			while(y!=coordy){
				if(y==0){
					mundo[x][y]= z;
				}
				y++;
			}
			x++;
			y=0;
		}
		
		x=0;
		y=0;
		while(x!=coordx){
			while(y!=coordy){
				printf("%c",mundo[x][y]);
				y++;
			}
			printf("\n");
			y=0;
			x++;
		}
	}
	system("PAUSE");
	
}
*/


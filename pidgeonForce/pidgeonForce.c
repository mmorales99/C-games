#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

char relleno = 219;	

void pantalla_completa(){
	keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
	}
	
int main(){
	
	time_t start_t, end_t;
	double diff_t;
		
	int nivel=1;
	int metros;
	int contMetros =0;
	int victory=0;
	int k=1;
	int obstaculoTotal=0;
	int obstaculoMax=500;
	int coordx=78, coordy=20; // caracteres máximos de la pantalla de juego
	int x,y, z; // contadores auxiliares
	int i=78;  // caracteres totales horizontales, utilizado para el menu de pausa y la pantalla de inicio
	int c=0;	// contador de vueltas para la generacion del menu de pausa y la pantlla de inicio
	int vidas =3; // numero de golpes que puedes recivir antes de morir
	int score =0;	// puntuacion, segun el tiempo y los enemigos derrotados.
	int count;	// cntador auxiliar
	int misilMax=5;
	int misilTotal=0;
	int enemigoTotal=0;
	int enemigoMax=50;
	int cajaTotal=0;
	int cajaMax=5;
	int scoreTiempo=0;
	int balaCd=0;
	int misilCd=0;
	int r = rand() % 12;
	
	char keyPress;
	char nombreSoldado[10];
	char str[3];
	char world[coordy][coordx];
	
	//flechass de direccion
	char arriba=24;
	char abajo=25;
	char izquierda=27;
	char derecha=26;

	char player= '{';
	char misil =207;
	char bala ='=';
	char obstaculo='O';
	char enemigo='E';
	char caja='H';
	char nuke='N';
	char recargaVida='V';
	char recargaMisil='R';
	char direccionJuego = 'r';
	
	printf("\n\n\n\n\tQUIERES JUGAR A PANTALLA COMPLTEA?\n\n\t[SI / NO] :  ");
	gets(str);
	if(str[0]=='s' || str[0]=='S'){
		pantalla_completa();
	}
	system("CLS");
	system("COLOR 0a");
	printf("\n\n\n\t\tYA SOLDIER, WHAT'S YA NAME??\n\n\n\t     >>  ");
	gets(nombreSoldado);
	
	//returns your name in mayus.
	
	count=strlen(nombreSoldado);
	while(count>=0){
		if(nombreSoldado[count]>='a' && nombreSoldado[count]<='z'){
			nombreSoldado[count] = nombreSoldado[count] + ('A'-'a');
		}
		count--;
	}
	
	Sleep(2000);
	printf("\n\n\n\t    HELLO %s , AND FEEL AS WELCOME TO PIDGEONFORCE!!",nombreSoldado);
	Sleep(2900);
	system("CLS");
	char animacion[3];
	printf("\n\n\n\t    DO YOU WANT TO SEE THE HISTORY ? [SI / NO] :");
	gets(animacion);
	if(animacion[0]=='n' || animacion[0]=='N'){
		system("CLS");
		Sleep(400);
		Beep(975,100);
		Beep(975,150);
		printf("\n\n- Hello, little duck.\n\n\n");
		printf("- You have grown very fast. \n\n- But by now, you have became a high rank soldier inside the pidgeons army.\n\n");
		printf("- So, you have been sent to L.1. during the D day.\n\n");
		printf("- Your orders are so simply.\n\n- Survive and try to deploy the troops behind the enemy.\n\n\n");
		printf("- Good Luck.\n\n\n- Herr General, Over and out.\n\n");
		Beep(975,150);
		Beep(720, 150);
		printf("\n    Press any key to continue.\t");
		getch();
	}else if(animacion[0]=='s' || animacion[0]=='S'){
		system("cls");
			
		Beep(725,75 );
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |    NO   IMAGE    |\n");
		printf("\t\t\t        |--  ---  ---  --- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |    CONNECTING    |\n");
		printf("\t\t\t        |--  ---  ---  --- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   --   --   --   |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  ---  ---  ---  -|\n");
		printf("\t\t\t        |     CONNECTING   |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-  ---  ---  ---  |\n");
		printf("\t\t\t        |      CONNECTING  |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | --   --   --   --|\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   ---  ---  ---|\n");
		printf("\t\t\t        |       CONNECTING |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t         ------------------\n");														  
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t         ------------------\n");
		Beep(975,100);
		Beep(975,150);
		Sleep(700);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(500);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   | O    O   |   |\n");
		printf("\t\t\t        |   |    uu    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    uu    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(200);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |   O    O |   |\n");
		printf("\t\t\t        |   |    uu    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(900);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O __ O  |   |\n");
		printf("\t\t\t        |   |   |  |   |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(1000);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |   |__|   |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(1000);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     Q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- Hello, little duck.\n\n\n");
		Sleep(2500);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     Q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- You have grown very fast.\n\n\n");
		Sleep(2000);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     Q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- But by now, you have became a high rank soldier\n\n\t\t       on pidgeon's army.\n\n\n");
		Sleep(2500);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     Q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    --So, you have been sent to L.1. during the D day.\n\n\n");
		Sleep(2000);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     Q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- Your orders are so simply. Survive and try to\n\n\t\t       deploy the troops behind the enemy.\n\n\n");
		Sleep(2800);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- ...\n\n\n");
		Sleep(2500);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     Q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- Good Luck.\n\n\n");
		Sleep(2500);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(500);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  _    _  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  _    _  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |     q    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		printf("\n\n\t\t    -- Herr General, Over and out.\n\n\n");
		Sleep(1800);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		Beep(975,150);
		Beep(720, 150);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |    NO   IMAGE    |\n");
		printf("\t\t\t        |--  ---  ---  --- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   --   --   --   |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  ---  ---  ---  -|\n");
		printf("\t\t\t        |   NO   IMAGE     |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-  ---  ---  ---  |\n");
		printf("\t\t\t        |  NO   IMAGE      |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | --   --   --   --|\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   ---  ---  ---|\n");
		printf("\t\t\t        | NO   IMAGE       |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t         ------------------\n");
		Sleep(400);	  
		system("CLS");
	}
	system("CLS");
	Sleep(500);
	printf("\n\n");
	printf("\t\t\t         ------------------\n");
	printf("\t\t\t        |   ____________   |\n");
	printf("\t\t\t        |  /  TUTORIAL  \\  |\n");
	printf("\t\t\t        | |--------------| |\n");
	printf("\t\t\t        |   |  O    O  |   |\n");
	printf("\t\t\t        |   |     q    |   |\n");
	printf("\t\t\t        |    \\________/    |\n");
	printf("\t\t\t        |                  |\n");
	printf("\t\t\t         ------------------\n");
	printf("\n\n\t\t    -- You are the '{' on the right and bad guys are\n\n\t\t       on the left.\t\t       \n\n\t\t       Use [W][A][S][D] to move you around.\n\n\t\t       [B] and [M] shoots.\n\n\t\t       Also you have 3 lives each level.");
	Sleep(400);														  
	printf("\n\n\t\t\t Press enter to continue.");
	fflush(stdin);
	getchar();	
	fflush(stdin);
	//init world.
	system("cls");
	
	int juego(){
		
		
		
		
		time_t t;
			
		score=0;
		vidas=3;
		
		srand(time(&t));
		
		while(k){
			
			srand(time(&t));
			
			obstaculoTotal=0;
			cajaTotal=0;
		
			// genera una matriz de dimensiones iguales a los desplazamientos.	
			for(x=0; x<coordx; x++){
			for(y=0; y<coordy; y++){
				if((x==0 && y==0) || (x==0 && y==coordy)){
					world[y][x]=' ';
				}
				if((y!=0 && x==0) || (y!=coordy && x==0)){
					world[y][x]='|';
				}
				if((y!=0 && x!=0) || (y!=coordy && x!=0)){
					world[y][x]=' ';
				}
			}
			world[0][0]=' ';
			world[20][0]=' ';
			world[0][x]='-';
			world[20][x]='-';	
			}
			world[coordy/2][coordx - 10]= player;
			
			char esquinaIA=218;
			char esquinaDA=191;
			char esquinaIB=192;
			char esquinaDB=217;
			char lado=179;
			char suelo=196;
			char barra=254;
			char espacio=' ';
				
			if(vidas>0){
				victory=1;
			}
			if(vidas<=0){
				break;
			}
			metros = nivel*500;
			contMetros=0;
			misilTotal=2;
			printf("\n\n\n\n\n\t\t\t    N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\n\n\n\n\t\t\t    Loading world");
			printf("\n\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIA,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDA);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",lado,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,lado);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIB,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDB);
			Sleep(750);
			system("cls");
			printf("\n\n\n\n\n\t\t\t    N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\n\n\n\n\t\t\t    Loading world.");
			printf("\n\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIA,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDA);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",lado,barra,barra,barra,barra,barra,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,lado);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIB,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDB);
			Sleep(750);
			system("cls");
			printf("\n\n\n\n\n\t\t\t    N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\n\n\n\n\t\t\t    Loading world..");
			printf("\n\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIA,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDA);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",lado,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,espacio,espacio,espacio,espacio,espacio,espacio,espacio,espacio,lado);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIB,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDB);
			Sleep(750);
			system("cls");
			printf("\n\n\n\n\n\t\t\t    N I V E L   %d\n\n\n\n",nivel);
			printf("\n\n\t\t    SOLDIER :  %s\t\tLIVES :  %d",nombreSoldado,vidas);
			printf("\n\n\n\n\n\n\t\t\t    Loading world...");
			printf("\n\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIA,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDA);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",lado,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,barra,lado);
			printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",esquinaIB,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,suelo,esquinaDB);
			Sleep(500);
			system("cls");
			time(&start_t);	
			//muestra en pantalla el juego.
			while(victory){
				system("cls");
				printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
				printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
				for (y = 0; y <= coordy; y ++) {
			            for (x = 0; x < coordx; x ++) {
			                printf("%c",world[y][x]);
			            }
					printf("\n");
				}
				printf("\t\t\t\t|  %d  /  %d  |m",contMetros, metros);
			
			
				for(x=0; x<coordx; x++){
					for(y=0; y<coordy; y++){
						if((x==0 && y==0) || (x==0 && y==coordy)){
							world[y][x]=' ';
						}
						if((y!=0 && x==0) || (y!=coordy && x==0)){
							world[y][x]='|';
						}
					}
					world[0][0]=' ';
					world[20][0]=' ';
					world[0][x]='-';
					world[20][x]='-';	
				}
				
				
				//enemies, obstacles and aids.
				if(contMetros%2==0)
				for(y=1;y<coordy;y++){
					r = rand() % 12;
					if(r==0 || r==1 || r==2 || r==3 || r==7||r==8){
						world[y][1]=' ';
					}
					if(r==5 || r==6 || r==4){
						if(obstaculoTotal<obstaculoMax){
						world[y][1]=obstaculo;
						obstaculoTotal++;
						}
					}
					if(r== 9 || r==10){
						if(enemigoTotal<enemigoMax){
						world[y][1]=enemigo;
						enemigoTotal++;
						}
					}
					if(r==11){
						if(cajaTotal<cajaMax){
/*	En pruebas	*/		world[y][1]=caja;
						cajaTotal++;
						}
					}
				}
				if(contMetros%3==0)
					for(x=coordx-1;x>0;x--){
						for(y=1;y<coordy;y++){
							if(world[y][x]==obstaculo){
								if(world[y][x+1]==misil){
									obstaculoTotal--;
									Beep(700,200);
									if(world[y][x-1]=caja){cajaTotal--;}
									if(world[y][x-2]=caja){cajaTotal--;}
									if(world[y][x-3]=caja){cajaTotal--;}
									if(world[y][x-4]=caja){cajaTotal--;}
									if(world[y][x-5]=caja){cajaTotal--;}
									if(world[y][x-6]=caja){cajaTotal--;}
									if(world[y][x-7]=caja){cajaTotal--;}
									if(world[y][x-8]=caja){cajaTotal--;}
									if(world[y][x-9]=caja){cajaTotal--;}
									if(world[y-1][x-2]=caja){cajaTotal--;}
									if(world[y+1][x-2]=caja){cajaTotal--;}
									if(world[y-1][x-3]=caja){cajaTotal--;}
									if(world[y+1][x-3]=caja){cajaTotal--;}
									if(world[y-1][x-4]=caja){cajaTotal--;}
									if(world[y+1][x-4]=caja){cajaTotal--;}
									if(world[y-1][x-5]=caja){cajaTotal--;}
									if(world[y+1][x-5]=caja){cajaTotal--;}
									if(world[y-1][x-6]=caja){cajaTotal--;}
									if(world[y+1][x-6]=caja){cajaTotal--;}
									if(world[y-1][x-7]=caja){cajaTotal--;}
									if(world[y+1][x-7]=caja){cajaTotal--;}
									if(world[y-1][x-8]=caja){cajaTotal--;}
									if(world[y+1][x-8]=caja){cajaTotal--;}
									if(world[y-1][x-9]=caja){cajaTotal--;}
									if(world[y+1][x-9]=caja){cajaTotal--;}
									if(world[y-2][x-3]=caja){cajaTotal--;}
									if(world[y+2][x-3]=caja){cajaTotal--;}
									if(world[y-2][x-4]=caja){cajaTotal--;}
									if(world[y+2][x-4]=caja){cajaTotal--;}
									if(world[y-2][x-5]=caja){cajaTotal--;}
									if(world[y+2][x-5]=caja){cajaTotal--;}
									if(world[y-2][x-6]=caja){cajaTotal--;}
									if(world[y+2][x-6]=caja){cajaTotal--;}
									if(world[y-2][x-7]=caja){cajaTotal--;}
									if(world[y+2][x-7]=caja){cajaTotal--;}
									if(world[y-2][x-8]=caja){cajaTotal--;}
									if(world[y+2][x-8]=caja){cajaTotal--;}
									if(world[y-3][x-5]=caja){cajaTotal--;}
									if(world[y+3][x-5]=caja){cajaTotal--;}
									if(world[y-3][x-6]=caja){cajaTotal--;}
									if(world[y+3][x-6]=caja){cajaTotal--;}
									if(world[y-3][x-7]=caja){cajaTotal--;}
									if(world[y+3][x-7]=caja){cajaTotal--;}
									
									
									if(world[y][x-1]=enemigo){enemigoTotal--;}
									if(world[y][x-2]=enemigo){enemigoTotal--;}
									if(world[y][x-3]=enemigo){enemigoTotal--;}
									if(world[y][x-4]=enemigo){enemigoTotal--;}
									if(world[y][x-5]=enemigo){enemigoTotal--;}
									if(world[y][x-6]=enemigo){enemigoTotal--;}
									if(world[y][x-7]=enemigo){enemigoTotal--;}
									if(world[y][x-8]=enemigo){enemigoTotal--;}
									if(world[y][x-9]=enemigo){enemigoTotal--;}
									if(world[y-1][x-2]=enemigo){enemigoTotal--;}
									if(world[y+1][x-2]=enemigo){enemigoTotal--;}
									if(world[y-1][x-3]=enemigo){enemigoTotal--;}
									if(world[y+1][x-3]=enemigo){enemigoTotal--;}
									if(world[y-1][x-4]=enemigo){enemigoTotal--;}
									if(world[y+1][x-4]=enemigo){enemigoTotal--;}
									if(world[y-1][x-5]=enemigo){enemigoTotal--;}
									if(world[y+1][x-5]=enemigo){enemigoTotal--;}
									if(world[y-1][x-6]=enemigo){enemigoTotal--;}
									if(world[y+1][x-6]=enemigo){enemigoTotal--;}
									if(world[y-1][x-7]=enemigo){enemigoTotal--;}
									if(world[y+1][x-7]=enemigo){enemigoTotal--;}
									if(world[y-1][x-8]=enemigo){enemigoTotal--;}
									if(world[y+1][x-8]=enemigo){enemigoTotal--;}
									if(world[y-1][x-9]=enemigo){enemigoTotal--;}
									if(world[y+1][x-9]=enemigo){enemigoTotal--;}
									if(world[y-2][x-3]=enemigo){enemigoTotal--;}
									if(world[y+2][x-3]=enemigo){enemigoTotal--;}
									if(world[y-2][x-4]=enemigo){enemigoTotal--;}
									if(world[y+2][x-4]=enemigo){enemigoTotal--;}
									if(world[y-2][x-5]=enemigo){enemigoTotal--;}
									if(world[y+2][x-5]=enemigo){enemigoTotal--;}
									if(world[y-2][x-6]=enemigo){enemigoTotal--;}
									if(world[y+2][x-6]=enemigo){enemigoTotal--;}
									if(world[y-2][x-7]=enemigo){enemigoTotal--;}
									if(world[y+2][x-7]=enemigo){enemigoTotal--;}
									if(world[y-2][x-8]=enemigo){enemigoTotal--;}
									if(world[y+2][x-8]=enemigo){enemigoTotal--;}
									if(world[y-3][x-5]=enemigo){enemigoTotal--;}
									if(world[y+3][x-5]=enemigo){enemigoTotal--;}
									if(world[y-3][x-6]=enemigo){enemigoTotal--;}
									if(world[y+3][x-6]=enemigo){enemigoTotal--;}
									if(world[y-3][x-7]=enemigo){enemigoTotal--;}
									if(world[y+3][x-7]=enemigo){enemigoTotal--;}
									
									
									if(world[y][x-1]=obstaculo){obstaculoTotal--;}
									if(world[y][x-2]=obstaculo){obstaculoTotal--;}
									if(world[y][x-3]=obstaculo){obstaculoTotal--;}
									if(world[y][x-4]=obstaculo){obstaculoTotal--;}
									if(world[y][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y][x-7]=obstaculo){obstaculoTotal--;}
									if(world[y][x-8]=obstaculo){obstaculoTotal--;}
									if(world[y][x-9]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-2]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-2]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-3]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-3]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-4]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-4]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-7]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-7]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-8]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-8]=obstaculo){obstaculoTotal--;}
									if(world[y-1][x-9]=obstaculo){obstaculoTotal--;}
									if(world[y+1][x-9]=obstaculo){obstaculoTotal--;}
									if(world[y-2][x-3]=obstaculo){obstaculoTotal--;}
									if(world[y+2][x-3]=obstaculo){obstaculoTotal--;}
									if(world[y-2][x-4]=obstaculo){obstaculoTotal--;}
									if(world[y+2][x-4]=obstaculo){obstaculoTotal--;}
									if(world[y-2][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y+2][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y-2][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y+2][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y-2][x-7]=obstaculo){obstaculoTotal--;}
									if(world[y+2][x-7]=obstaculo){obstaculoTotal--;}
									if(world[y-2][x-8]=obstaculo){obstaculoTotal--;}
									if(world[y+2][x-8]=obstaculo){obstaculoTotal--;}
									if(world[y-3][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y+3][x-5]=obstaculo){obstaculoTotal--;}
									if(world[y-3][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y+3][x-6]=obstaculo){obstaculoTotal--;}
									if(world[y-3][x-7]=obstaculo){obstaculoTotal--;}
									if(world[y+3][x-7]=obstaculo){obstaculoTotal--;}
									world[y][x]=' ';
									world[y][x-1]=' ';
									world[y][x-2]=' ';
									world[y][x-3]=' ';
									world[y][x-4]=' ';
									world[y][x-5]=' ';
									world[y][x-6]=' ';
									world[y][x-7]=' ';
									world[y][x-8]=' ';
									world[y][x-9]=' ';
									world[y+1][x-1]=' ';
									world[y-1][x-1]=' ';
									world[y+1][x-2]=' ';
									world[y-1][x-2]=' ';
									world[y+1][x-3]=' ';
									world[y-1][x-3]=' ';
									world[y+1][x-4]=' ';
									world[y-1][x-4]=' ';
									world[y+1][x-5]=' ';
									world[y-1][x-5]=' ';
									world[y+1][x-6]=' ';
									world[y-1][x-6]=' ';
									world[y+1][x-7]=' ';
									world[y-1][x-7]=' ';
									world[y+1][x-8]=' ';
									world[y-1][x-8]=' ';
									world[y+1][x-9]=' ';
									world[y-1][x-9]=' ';
									world[y+2][x-3]=' ';
									world[y-2][x-3]=' ';
									world[y+2][x-4]=' ';
									world[y-2][x-4]=' ';
									world[y+2][x-5]=' ';
									world[y-2][x-5]=' ';
									world[y+2][x-6]=' ';
									world[y-2][x-6]=' ';
									world[y+2][x-7]=' ';
									world[y-2][x-7]=' ';
									world[y+2][x-8]=' ';
									world[y-2][x-8]=' ';
									world[y+3][x-5]=' ';
									world[y-3][x-5]=' ';
									world[y+3][x-6]=' ';
									world[y-3][x-6]=' ';
									world[y+3][x-7]=' ';
									world[y-3][x-7]=' ';
								}
								if(world[y][x+1]==player){
									Beep(700,200);
									vidas--;
									world[y][x]=' ';
									world[y+1][x]=' ';
									world[y+2][x]=' ';
									world[y+3][x]=' ';
									world[y-1][x]=' ';
									world[y-2][x]=' ';
									world[y-3][x]=' ';
									world[y+1][x-1]=' ';
									world[y+2][x-1]=' ';
									world[y+3][x-1]=' ';
									world[y-1][x-1]=' ';
									world[y-2][x-1]=' ';
									world[y-3][x-1]=' ';
									world[y+1][x-2]=' ';
									world[y+2][x-2]=' ';
									world[y+3][x-2]=' ';
									world[y-1][x-2]=' ';
									world[y-2][x-2]=' ';
									world[y-3][x-2]=' ';
									world[y][x-1]=' ';
									world[y][x-2]=' ';
									world[y][x-3]=' ';
									world[y][x+3]=player;
								}
								world[y][x+1]=world[y][x];
								world[y][x]=' ';
	      						if(world[y][coordx-1]==obstaculo){
									world[y][coordx-1]=' ';
									obstaculoTotal--;
								}
								
							}
							if(world[y][x]==enemigo){
								if(world[y][x+1]==player){
									Beep(690,180);
									vidas--;
									enemigoTotal--;
									world[y][x]=' ';
									world[y+1][x]=' ';
									world[y+2][x]=' ';
									world[y+3][x]=' ';
									world[y-1][x]=' ';
									world[y-2][x]=' ';
									world[y-3][x]=' ';
									world[y+1][x+1]=' ';
									world[y+2][x+1]=' ';
									world[y+3][x+1]=' ';
									world[y-1][x+1]=' ';
									world[y-2][x+1]=' ';
									world[y-3][x+1]=' ';
									world[y+1][x+2]=' ';
									world[y+2][x+2]=' ';
									world[y+3][x+2]=' ';
									world[y-1][x+2]=' ';
									world[y-2][x+2]=' ';
									world[y-3][x+2]=' ';
									world[y][x-1]=' ';
									world[y][x-2]=' ';
									world[y][x-3]=' ';
									world[y][x+3]=player;
								}
								if(world[y][x+1]==bala || world[y][x+2]==bala || world[y][x]==bala){
									enemigoTotal--;
									Beep(700,200);
									world[y][x]=' ';
									world[y+1][x]=' ';
									world[y+2][x]=' ';
									world[y+3][x]=' ';
									world[y-1][x]=' ';
									world[y-2][x]=' ';
									world[y-3][x]=' ';
									world[y+1][x+1]=' ';
									world[y+2][x+1]=' ';
									world[y+3][x+1]=' ';
									world[y-1][x+1]=' ';
									world[y-2][x+1]=' ';
									world[y-3][x+1]=' ';
									world[y+1][x+2]=' ';
									world[y+2][x+2]=' ';
									world[y+3][x+2]=' ';
									world[y-1][x+2]=' ';
									world[y-2][x+2]=' ';
									world[y-3][x+2]=' ';
									world[y][x-1]=' ';
									world[y][x-2]=' ';
									world[y][x-3]=' ';
								}
								world[y][x+1]=world[y][x];
								world[y][x]=' ';
			                    if(world[y][coordx-1]==enemigo){
									world[y][coordx-1]=' ';
									enemigoTotal--;
								}
							}
							if(world[y][x]==caja)
							
							{ 
								if(world[y][x]==caja && (world[y][x+1]== player || world[y][x+1]==bala || world[y][x+1]==misil)){
									misilTotal++;
									vidas++;
									cajaTotal--;
								}
							}
								/*if(world[y][x]==caja && (world[y][x+1]==bala || world[y][x+2]==bala || world[y][x]==bala || world[y][x+1]==misil || world[y][x]==misil || world[y][x+2]==misil)){
									int f = rand()% 100;
									f = rand()% 100;
									if(f <=45){
										world[y][x+1]==recargaVida;
									}
									if(f > 45 && r <=90){
										world[y][x+1]==recargaMisil;
									}
									if(f > 90){
										world[y][x+1]==nuke;
									}
								}
								if( world[y][x]==caja && world[y][x+2]==player ){
									int f = rand()% 100;
									f = rand()% 100;
									if(f <=45){
										vidas++;
										for(y=0;y<coordy;y++){
											for(x=0;x<coordx;x++){
												if(world[y][x]==player){
													world[y][x+3]='+';
													world[y][x+4]='1';
													world[y][x+5]=' ';
													world[y][x+6]='V';
													world[y][x+7]='I';
													world[y][x+8]='D';
													world[y][x+9]='A';
												}
											}
										}
										Sleep(100);
									}
									if(f > 45 && r <=90){
										misilTotal++;
										for(y=0;y<coordy;y++){
											for(x=0;x<coordx;x++){
												if(world[y][x]==player){
													world[y][x+3]='+';
													world[y][x+4]='1';
													world[y][x+5]=' ';
													world[y][x+6]='M';
													world[y][x+7]='I';
													world[y][x+8]='S';
													world[y][x+9]='I';
													world[y][x+10]='L';
												}
											}
										}	
									}
									if(f > 90){
										for(y=0;y<coordy;y++){
											for(x=0;x<coordx;x++){
												if(world[y][x]==obstaculo){
													world[y][x]=' ';
													obstaculoTotal=0;
												}
												if(world[y][x]==enemigo){
													world[y][x]=' ';
													enemigoTotal=0;
												}
											}
										}
									}
									world[y][x]=' ';
									world[y+1][x]=' ';
									world[y+2][x]=' ';
									world[y+3][x]=' ';
									world[y-1][x]=' ';
									world[y-2][x]=' ';
									world[y-3][x]=' ';
									world[y+1][x+1]=' ';
									world[y+2][x+1]=' ';
									world[y+3][x+1]=' ';
									world[y-1][x+1]=' ';
									world[y-2][x+1]=' ';
									world[y-3][x+1]=' ';
									world[y+1][x+2]=' ';
									world[y+2][x+2]=' ';
									world[y+3][x+2]=' ';
									world[y-1][x+2]=' ';
									world[y-2][x+2]=' ';
									world[y-3][x+2]=' ';
									world[y][x-1]=' ';
									world[y][x-2]=' ';
									world[y][x-3]=' ';
									world[y][x+3]=player;
								}
								world[y][x+1]=world[y][x];
								world[y][x]=' ';
			                    if(world[y][coordx-1]==caja){
									world[y][coordx-1]=' ';
									cajaTotal--;
								}
							}*/
							/*if(world[y][x]==nuke){
								if(world[y][x]==nuke && world[y][x+1]==player){
									for(y=0;y<coordy;y++){
										for(x=0;x<coordx;x++){
											if(world[y][x]==obstaculo){
												world[y][x]=' ';
												obstaculoTotal=0;
											}
											if(world[y][x]==enemigo){
												world[y][x]=' ';
												enemigoTotal=0;
											}
										}
									}
								}
								world[y][x+1]=world[y][x];
								world[y][x]=' ';
								if(world[y][coordx-1]==nuke){
									world[y][coordx-1]=' ';
								}
							}
							if(world[y][x]==recargaVida){
								if(world[y][x]==recargaVida && world[y][x+1]==player){
									vidas++;
									for(y=0;y<coordy;y++){
										for(x=0;x<coordx;x++){
											if(world[y][x]==player){
												world[y][x+3]='+';
												world[y][x+4]='1';
												world[y][x+5]=' ';
												world[y][x+6]='V';
												world[y][x+7]='I';
												world[y][x+8]='D';
												world[y][x+9]='A';
											}
										}
									}
								}
								world[y][x+1]=world[y][x];
								world[y][x]=' ';
								if(world[y][coordx-1]==recargaVida){
									world[y][coordx-1]=' ';
								}
							}
							if(world[y][x]==recargaMisil){
								if(world[y][x]==recargaMisil && world[y][x+1]==player){
									misilTotal++;
									for(y=0;y<coordy;y++){
										for(x=0;x<coordx;x++){
											if(world[y][x]==player){
												world[y][x+3]='+';
												world[y][x+4]='1';
												world[y][x+5]=' ';
												world[y][x+6]='M';
												world[y][x+7]='I';
												world[y][x+8]='S';
												world[y][x+9]='I';
												world[y][x+10]='L';
											}
										}
									}
								}
								world[y][x+1]=world[y][x];
								world[y][x]=' ';
								if(world[y][coordx-1]==recargaMisil){
									world[y][coordx-1]=' ';
								}
							}*/
							if(world[y][x]==' '){
							}
						}
					}
				
				for(y=0;y<coordy;y++){
					for(x=0;x<coordx;x++){
						if(world[y][x]==player){
							world[y][x+3]=' ';
							world[y][x+4]=' ';
							world[y][x+5]=' ';
							world[y][x+6]=' ';
							world[y][x+7]=' ';
							world[y][x+8]=' ';
							world[y][x+9]=' ';
							world[y][x+10]=' ';
						}
					}
				}
				
				
				/*GUNS!!!*/
				for(x = 0; x<coordx;x++){
					for(y=0;y<coordy;y++){
						if (world[y][x] == bala && world[y][x-1] != obstaculo) {
		                    if((x-1)!=0){
								world[y][x] = ' ';
		                        world[y][x-1] = bala;
		                        for(y=0;y<coordy;y++){
		                        	if(world[y][1]==bala){
										world[y][1]=' ';
									}
								}
							}
						}else if(world[y][x] == bala && world[y][x-1] == obstaculo){
							world[y][x]=' ';
						}
						if (world[y][x] == misil && world[y][x-1] != obstaculo) {
							if((x-1)!=0){
								world[y][x] = ' ';
		                        world[y][x-1] = misil;
		                        for(y=0;y<coordy;y++){
		                        	if(world[y][1]==misil){
										world[y][1]=' ';
									}
								}
							}
						}else if(world[y][x]==misil && world[y][x-1]==obstaculo){
							world[y-1][x-1]=' ';
							world[y-1][x]=' ';
							world[y-1][x+1]=' ';
							world[y][x-1]=' ';
							world[y][x]=' ';
							world[y][x+1]=' ';
							world[y+1][x+1]=' ';
							world[y+1][x]=' ';
							world[y+1][x-1]=' ';
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
			    if(( keyPress=='m' )&& misilCd > 10 && misilTotal>0){
					Beep(850,230);
					misilTotal--;
					for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( world[y][x] == player) {
		                 		world[y][x-2] = misil;
			                    misilCd=0;
			                }
			            }
					}
				}
			    if(( keyPress=='b' ) && balaCd > 2){
					Beep(915,200);
					for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( world[y][x] == player) {
		                 		world[y][x-2] = bala;
			                    balaCd=0;
			                }
			            }
					}
				}
			    if (keyPress == 'a') {
			        for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( world[y][x] == player) {
		                 		if(x!=1){
								world[y][x-1] = player;
			                    world[y][x] = ' ';
								}
			                }
			            }
					}
			    }
			    if (keyPress == 'd') {
			        for(y = coordy - 1 ;y > 0;y--){
						for (x = coordx - 1 ; x > 0; x--) {
			                if ( world[y][x] == player) {
			                    if((x+2)!=coordx){
									world[y][x+1] = player;
			                    	world[y][x] = ' ';
								}
			                }
			            }
					}
			    }
			    if (keyPress == 'w') {
			        for(y=0;y<coordy;y++){
						for (x = 0; x < coordx; x++) {
			                if ( world[y][x] == player) {
		                 		if(y!=1){
									world[y-1][x] = player;
			                    	world[y][x] = ' ';
								}
			                }
			            }
					}
			    }
			    if (keyPress == 's') {
			        for(y = coordy - 1 ;y > 0;y--){
						for (x = coordx - 1 ; x > 0; x--) {
			                if ( world[y][x] == player) {
			                    if((y+1)!=coordy){
									world[y+1][x] = player;
			                    	world[y][x] = ' ';
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
				
				
				contMetros++;
				time(&end_t);
				score = difftime(end_t, start_t);			
				balaCd++;
				misilCd++;
				if(vidas==0){
					victory=0;
					break;
				}
				if(contMetros==metros){
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                                       {\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(1200);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("||\n");
						printf("||\n");
						printf("||                                      {\n");
						printf("||\n");
						printf("||\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\\\n");
						printf("| |\n");
						printf("| |\n");
						printf("| |                                     {\n");
						printf("| |\n");
						printf("| |\n");
						printf("|/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|_\n");
						printf("| \\\n");
						printf("|_ |\n");
						printf("|  |\n");
						printf("|  |                                    {\n");
						printf("|  |\n");
						printf("|\\ |\n");
						printf("|_/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|__\n");
						printf("|  \\\n");
						printf("|__ |\n");
						printf("|   |\n");
						printf("|   |                                   {\n");
						printf("|\\  |\n");
						printf("|_\\ |\n");
						printf("|__/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|___\n");
						printf("|   \\\n");
						printf("|___ |\n");
						printf("|    |\n");
						printf("|    |                                  {\n");
						printf("| \\  |\n");
						printf("|__\\ |\n");
						printf("|___/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|____\n");
						printf("|    \\\n");
						printf("|____ |\n");
						printf("|     |\n");
						printf("|\\    |                                 {\n");
						printf("|  \\  |\n");
						printf("|___\\ |\n");
						printf("|____/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|_____\n");
						printf("|     \\\n");
						printf("|_____ |\n");
						printf("|\\     |\n");
						printf("| \\    |                                {\n");
						printf("|   \\  |\n");
						printf("|____\\ |\n");
						printf("|_____/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|______\n");
						printf("|      \\\n");
						printf("| _____ |\n");
						printf("| \\     |\n");
						printf("|  \\    |                               {\n");
						printf("|    \\  |\n");
						printf("| ____\\ |\n");
						printf("|______/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|_______\n");
						printf("|       \\\n");
						printf("|  _____ |\n");
						printf("|  \\     |\n");
						printf("||  \\    |                              {\n");
						printf("||    \\  |\n");
						printf("|  ____\\ |\n");
						printf("|_______/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|________\n");
						printf("|_       \\\n");
						printf("|   _____ |\n");
						printf("|_  \\     |\n");
						printf("| |  \\    |                             {\n");
						printf("|_|    \\  |\n");
						printf("|   ____\\ |\n");
						printf("|________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|_________\n");
						printf("|__       \\\n");
						printf("|    _____ |\n");
						printf("|__  \\     |\n");
						printf("|  |  \\    |                            {\n");
						printf("|__|    \\  |\n");
						printf("|    ____\\ |\n");
						printf("|_________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|__________\n");
						printf("|___       \\\n");
						printf("|     _____ |\n");
						printf("|___  \\     |\n");
						printf("|   |  \\    |                           {\n");
						printf("|___|    \\  |\n");
						printf("|     ____\\ |\n");
						printf("|__________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|___________\n");
						printf("| ___       \\\n");
						printf("||     _____ |\n");
						printf("||___  \\     |\n");
						printf("|    |  \\    |                          {\n");
						printf("| ___|    \\  |\n");
						printf("|      ____\\ |\n");
						printf("|___________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|____________\n");
						printf("|  ___       \\\n");
						printf("| |     _____ |\n");
						printf("| |___  \\     |\n");
						printf("|     |  \\    |                         {\n");
						printf("|  ___|    \\  |\n");
						printf("|       ____\\ |\n");
						printf("|____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
						system("cls");
						printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("| ____________\n");
						printf("|/  ___       \\\n");
						printf("|| |     _____ |\n");
						printf("|| |___  \\     |\n");
						printf("||     |  \\    |                        {\n");
						printf("||  ___|    \\  |\n");
						printf("||       ____\\ |\n");
						printf("|\\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("cls");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|  ____________\n");
						printf("| /  ___       \\\n");
						printf("| | |     _____ |\n");
						printf("| | |___  \\     |\n");
						printf("| |     |  \\    |                       {\n");
						printf("| |  ___|    \\  |\n");
						printf("| |       ____\\ |\n");
						printf("| \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|   ____________\n");
						printf("|  /  ___       \\\n");
						printf("|  | |     _____ |\n");
						printf("|  | |___  \\     |\n");
						printf("|  |     |  \\    |                      {\n");
						printf("|  |  ___|    \\  |\n");
						printf("|  |       ____\\ |\n");
						printf("|  \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|    ____________\n");
						printf("|   /  ___       \\\n");
						printf("|   | |     _____ |\n");
						printf("|   | |___  \\     |\n");
						printf("|   |     |  \\    |                     {\n");
						printf("|   |  ___|    \\  |\n");
						printf("|   |       ____\\ |\n");
						printf("|   \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|     ____________\n");
						printf("|    /  ___       \\\n");
						printf("|    | |     _____ |\n");
						printf("|    | |___  \\     |\n");
						printf("|    |     |  \\    |                    {\n");
						printf("|    |  ___|    \\  |\n");
						printf("|    |       ____\\ |\n");
						printf("|    \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|      ____________\n");
						printf("|     /  ___       \\\n");
						printf("|     | |     _____ |\n");
						printf("|     | |___  \\     |\n");
						printf("|     |     |  \\    |                   {\n");
						printf("|     |  ___|    \\  |\n");
						printf("|     |       ____\\ |\n");
						printf("|     \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|       ____________\n");
						printf("|      /  ___       \\\n");
						printf("|      | |     _____ |\n");
						printf("|      | |___  \\     |\n");
						printf("|      |     |  \\    |                  {\n");
						printf("|      |  ___|    \\  |\n");
						printf("|      |       ____\\ |\n");
						printf("|      \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|        ____________\n");
						printf("|       /  ___       \\\n");
						printf("|       | |     _____ |\n");
						printf("|       | |___  \\     |\n");
						printf("|       |     |  \\    |                 {\n");
						printf("|       |  ___|    \\  |\n");
						printf("|       |       ____\\ |\n");
						printf("|       \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|         ____________\n");
						printf("|        /  ___       \\\n");
						printf("|        | |     _____ |\n");
						printf("|        | |___  \\     |\n");
						printf("|        |     |  \\    |                {\n");
						printf("|        |  ___|    \\  |\n");
						printf("|        |       ____\\ |\n");
						printf("|        \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|          ____________\n");
						printf("|         /  ___       \\\n");
						printf("|         | |     _____ |\n");
						printf("|         | |___  \\     |\n");
						printf("|         |     |  \\    |               {\n");
						printf("|         |  ___|    \\  |\n");
						printf("|         |       ____\\ |\n");
						printf("|         \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|           ____________\n");
						printf("|          /  ___       \\\n");
						printf("|          | |     _____ |\n");
						printf("|          | |___  \\     |\n");
						printf("|          |     |  \\    |              {\n");
						printf("|          |  ___|    \\  |\n");
						printf("|          |       ____\\ |\n");
						printf("|          \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|            ____________\n");
						printf("|           /  ___       \\\n");
						printf("|           | |     _____ |\n");
						printf("|           | |___  \\     |\n");
						printf("|           |     |  \\    |             {\n");
						printf("|           |  ___|    \\  |\n");
						printf("|           |       ____\\ |\n");
						printf("|           \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|             ____________\n");
						printf("|            /  ___       \\\n");
						printf("|            | |     _____ |\n");
						printf("|            | |___  \\     |\n");
						printf("|            |     |  \\    |            {\n");
						printf("|            |  ___|    \\  |\n");
						printf("|            |       ____\\ |\n");
						printf("|            \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|              ____________\n");
						printf("|             /  ___       \\\n");
						printf("|             | |     _____ |\n");
						printf("|             | |___  \\     |\n");
						printf("|             |     |  \\    |           {\n");
						printf("|             |  ___|    \\  |\n");
						printf("|             |       ____\\ |\n");
						printf("|             \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|               ____________\n");
						printf("|              /  ___       \\\n");
						printf("|              | |     _____ |\n");
						printf("|              | |___  \\     |\n");
						printf("|              |     |  \\    |          {\n");
						printf("|              |  ___|    \\  |\n");
						printf("|              |       ____\\ |\n");
						printf("|              \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                ____________\n");
						printf("|               /  ___       \\\n");
						printf("|               | |     _____ |\n");
						printf("|               | |___  \\     |\n");
						printf("|               |     |  \\    |         {\n");
						printf("|               |  ___|    \\  |\n");
						printf("|               |       ____\\ |\n");
						printf("|               \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                 ____________\n");
						printf("|                /  ___       \\\n");
						printf("|                | |     _____ |\n");
						printf("|                | |___  \\     |\n");
						printf("|                |     |  \\    |        {\n");
						printf("|                |  ___|    \\  |\n");
						printf("|                |       ____\\ |\n");
						printf("|                \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                  ____________\n");
						printf("|                 /  ___       \\\n");
						printf("|                 | |     _____ |\n");
						printf("|                 | |___  \\     |\n");
						printf("|                 |     |  \\    |       {\n");
						printf("|                 |  ___|    \\  |\n");
						printf("|                 |       ____\\ |\n");
						printf("|                 \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                   ____________\n");
						printf("|                  /  ___       \\\n");
						printf("|                  | |     _____ |\n");
						printf("|                  | |___  \\     |\n");
						printf("|                  |     |  \\    |      {\n");
						printf("|                  |  ___|    \\  |\n");
						printf("|                  |       ____\\ |\n");
						printf("|                  \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                    ____________\n");
						printf("|                   /  ___       \\\n");
						printf("|                   | |     _____ |\n");
						printf("|                   | |___  \\     |\n");
						printf("|                   |     |  \\    |     {\n");
						printf("|                   |  ___|    \\  |\n");
						printf("|                   |       ____\\ |\n");
						printf("|                   \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                     ____________\n");
						printf("|                    /  ___       \\\n");
						printf("|                    | |     _____ |\n");
						printf("|                    | |___  \\     |\n");
						printf("|                    |     |  \\    |    {\n");
						printf("|                    |  ___|    \\  |\n");
						printf("|                    |       ____\\ |\n");
						printf("|                    \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                      ____________\n");
						printf("|                     /  ___       \\\n");
						printf("|                     | |     _____ |\n");
						printf("|                     | |___  \\     |\n");
						printf("|                     |     |  \\    |   {\n");
						printf("|                     |  ___|    \\  |\n");
						printf("|                     |       ____\\ |\n");
						printf("|                     \\____________/\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					
						Sleep(400);
					    system("CLS");
					    printf("\n   SOLDIER :  %s   \tSCORE :  %d",nombreSoldado,score);
						printf("\tLIVES :  %d   \tMISILS :  %d\n\n",vidas,misilTotal);
						printf(" -----------------------------------------------------------------------------\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|\n");
						printf("|                      ____________                                 \n");
						printf("|                     /  ___       \\                               \n");
						printf("|                     | |     _____ |                               \n");
						printf("|                     | |___  \\     |                              \n");
						printf("|                     |     |  \\    |   {                          \n");
						printf("|                     |  ___|    \\  |                              \n");
						printf("|                     |       ____\\ |                              \n");
						printf("|                     \\____________/                               \n");
						printf("|                                        \n");
						printf("|                                        \n");
						printf("|                                        \n");
						printf("|                                        \n");
						printf("|                                        \n");
						printf(" -----------------------------------------------------------------------------\n");
					    printf("                              | %d - %d | m",metros,metros);
					    Beep(990,100);
						Beep(990,75);
						Beep(780,50);
						Beep(990,100);
						Beep(990,75);
						Beep(780,50);
						Beep(990,75);
						Beep(780,50);
						Beep(820,100);
						Beep(930,100);
						Beep(990,200);
						Beep(990,100);
						Beep(990,75);
						Beep(780,50);
						Beep(990,75);
						Beep(780,50);
						Beep(820,100);
						Beep(930,100);
						Beep(990,200);
						Beep(990,100);
						Beep(990,75);
						Beep(780,50);
						Beep(990,75);
						Beep(780,50);
						Beep(820,100);
						Beep(930,100);
						Beep(990,200);
						system("cls");
						Beep(725,75 );
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |  --   --   --   -|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    | ---  ---  ---  --|\n");
						printf("\t\t\t    |    NO   IMAGE    |\n");
						printf("\t\t\t    |--  ---  ---  --- |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |-   --   --   --  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |  --   --   --   -|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    | ---  ---  ---  --|\n");
						printf("\t\t\t    |    CONNECTING    |\n");
						printf("\t\t\t    |--  ---  ---  --- |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |-   --   --   --  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   --   --   --   |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |  ---  ---  ---  -|\n");
						printf("\t\t\t    |     CONNECTING   |\n");
						printf("\t\t\t    |---  ---  ---  ---|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |--   --   --   -- |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |-   --   --   --  |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |-  ---  ---  ---  |\n");
						printf("\t\t\t    |      CONNECTING  |\n");
						printf("\t\t\t    |---  ---  ---  ---|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    | --   --   --   --|\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |--   --   --   -- |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |--   ---  ---  ---|\n");
						printf("\t\t\t    |       CONNECTING |\n");
						printf("\t\t\t    | ---  ---  ---  --|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |  --   --   --   -|\n");
						printf("\t\t\t     ------------------\n");														  
						Sleep(400);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t     ------------------\n");
						Beep(975,100);
						Beep(975,150);
						Sleep(700);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    __    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(500);
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   | O    O   |   |\n");
						printf("\t\t\t    |   |    uu    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    uu    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(200);
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |   O    O |   |\n");
						printf("\t\t\t    |   |    uu    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    __    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    __    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(600);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |   |__|   |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(500);
						system("CLS");
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |   |__|   |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |     q    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						printf("\n\n\t\t    -- Well done soldier!! Mision Acomplished\n\n\n");
						Sleep(1800);
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    \\/    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(900);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |     q    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						printf("\n\n\t\t    -- Herr General, Over and out.\n\n\n");
						Sleep(1800);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    __    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						Beep(975,150);
						Beep(720, 150);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   ____________   |\n");
						printf("\t\t\t    |  /     pF     \\  |\n");
						printf("\t\t\t    | |--------------| |\n");
						printf("\t\t\t    |   |  O    O  |   |\n");
						printf("\t\t\t    |   |    __    |   |\n");
						printf("\t\t\t    |    \\________/    |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |  --   --   --   -|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    | ---  ---  ---  --|\n");
						printf("\t\t\t    |    NO   IMAGE    |\n");
						printf("\t\t\t    |--  ---  ---  --- |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |-   --   --   --  |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |   --   --   --   |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |  ---  ---  ---  -|\n");
						printf("\t\t\t    |   NO   IMAGE     |\n");
						printf("\t\t\t    |---  ---  ---  ---|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |--   --   --   -- |\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |-   --   --   --  |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |-  ---  ---  ---  |\n");
						printf("\t\t\t    |  NO   IMAGE      |\n");
						printf("\t\t\t    |---  ---  ---  ---|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    | --   --   --   --|\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |--   --   --   -- |\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |--   ---  ---  ---|\n");
						printf("\t\t\t    | NO   IMAGE       |\n");
						printf("\t\t\t    | ---  ---  ---  --|\n");
						printf("\t\t\t    |                  |\n");
						printf("\t\t\t    |  --   --   --   -|\n");
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\t     ------------------\n");
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t    |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
						printf("\t\t\t     ------------------\n");
						Sleep(400);														  
						system("CLS");
						break;
				}
			
				Sleep(100);    
			}
			
			system("cls");				
			nivel++;
		}
		system("CLS");
		printf("\n\n\n\t%s ha puntuado : %d",nombreSoldado, score);
		Sleep(1200);
		system("CLS");
		char relleno = 219;		
		Beep(725,75 );
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |    NO   IMAGE    |\n");
		printf("\t\t\t        |--  ---  ---  --- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |    CONNECTING    |\n");
		printf("\t\t\t        |--  ---  ---  --- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   --   --   --   |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  ---  ---  ---  -|\n");
		printf("\t\t\t        |     CONNECTING   |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-  ---  ---  ---  |\n");
		printf("\t\t\t        |      CONNECTING  |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | --   --   --   --|\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   ---  ---  ---|\n");
		printf("\t\t\t        |       CONNECTING |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t         ------------------\n");														  
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t         ------------------\n");
		Beep(975,100);
		Beep(975,150);
		Sleep(700);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(500);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   | O    O   |   |\n");
		printf("\t\t\t        |   |    uu    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    uu    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(200);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |   O    O |   |\n");
		printf("\t\t\t        |   |    uu    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O    O  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(900);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  O __ O  |   |\n");
		printf("\t\t\t        |   |   |  |   |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(950);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  _    _  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(1000);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  _    _  |   |\n");
		printf("\t\t\t        |   |    __  | |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(520);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  _    _  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\_______|/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(520);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   ____________   |\n");
		printf("\t\t\t        |  /     pF     \\  |\n");
		printf("\t\t\t        | |--------------| |\n");
		printf("\t\t\t        |   |  _    _  |   |\n");
		printf("\t\t\t        |   |    __    |   |\n");
		printf("\t\t\t        |    \\________/    |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(1000);
		system("cls");
		Beep(975,150);
		Beep(720, 150);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |          ______  |\n");
		printf("\t\t\t        |   ___   |        |\n");
		printf("\t\t\t        |  |   |  |____    |\n");
		printf("\t\t\t        |  |___|  |        |\n");
		printf("\t\t\t        |  |      |        |\n");
		printf("\t\t\t        |  |      |        |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |    NO   IMAGE    |\n");
		printf("\t\t\t        |--  ---  ---  --- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |   --   --   --   |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  ---  ---  ---  -|\n");
		printf("\t\t\t        |   NO   IMAGE     |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |-   --   --   --  |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |-  ---  ---  ---  |\n");
		printf("\t\t\t        |  NO   IMAGE      |\n");
		printf("\t\t\t        |---  ---  ---  ---|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        | --   --   --   --|\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |--   --   --   -- |\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |--   ---  ---  ---|\n");
		printf("\t\t\t        | NO   IMAGE       |\n");
		printf("\t\t\t        | ---  ---  ---  --|\n");
		printf("\t\t\t        |                  |\n");
		printf("\t\t\t        |  --   --   --   -|\n");
		printf("\t\t\t         ------------------\n");
		Sleep(400);														  
		system("CLS");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t         ------------------\n");
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t        |%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|\n",relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno,relleno);
		printf("\t\t\t         ------------------\n");
		Sleep(400);	  
		system("CLS");
		char wanto[3];
		printf("\n\n\n\t\tDO YOU WANT TO PLAY AGAIN?\n\n\n\t[ SI / NO ] : ");
		gets(wanto);
		if(wanto[0]=='S' || wanto[0]=='s'){
			system("CLS");
			printf("\n\n\n\t\tYA SOLDIER, WHAT'S YA NAME??\n\n\n\t     >>  ");
			gets(nombreSoldado);
			count=strlen(nombreSoldado);
			while(count>=0){
				if(nombreSoldado[count]>='a' && nombreSoldado[count]<='z'){
					nombreSoldado[count] = nombreSoldado[count] + ('A'-'a');
				}
				count--;
			}
			Sleep(2000);
			printf("\n\n\n\t    HELLO %s , AND FEEL AS WELCOME TO PIDGEONFORCE!!",nombreSoldado);
			Sleep(2900);
			system("CLS");
			juego();
		}
	}
	juego();
	system("CLS");
	printf("\n\n\n\n\n\tA game made in ANSCII C by Manuel Morales Amat.");
	printf("\n\n\tBy C0D3_BR0k3r for 4LivesGames...");
	printf("\n\tVer. : 1.01");
}

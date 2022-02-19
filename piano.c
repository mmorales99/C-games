#include <windows.h>
#include <conio.h>

#define MAX_LONG 1*1000 // 30 segundos en milisegundos
#define LOWEST_NOTE 5
#define ESPACE ' '
#define ESCAPE 27

int main(){
    char martillo = 0;
    char nota = 0;
    while(1){
        int freq = LOWEST_NOTE;
        if(kbhit()){
            switch(nota = getch()){
                case ESPACE:
                    martillo = martillo > 0 ? 0 : 1;
                    break;
                case ESCAPE:
                    exit(0);
                default:
                    freq*=nota;
                    Beep(freq,martillo?150:350);
                    break;
            }
        }
    }
}

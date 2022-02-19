#include <windows.h>
#include <conio.h>

#define MAX_LONG 30*1000 // 30 segundos en milisegundos
#define LOWEST_NOTE 100
#define ESPACE ' '
#define ESCAPE 27

int main(){
    char martillo = 0;
    char nota = 0;
    while(true){
        int freq = LOWEST_NOTE;
        if(kbhit()){
            switch(nota = getch()){
                case ESPACE:
                    martillo = martillo > 0 ? 0 : 1;
                    breaK;
                case ESCAPE:
                    exit(0);
                default:
                    freq*=nota;
                    beep(freq,martillo?MAX_LONG/2:MAX_LONG);
                    break;
            }
        }
    }
}
/*
 *  Plik: e4.c
 *  Opis: Program rysujący ramkę ze znaków ASCII, 
 *        współrzędne ramki pobrane na starcie programu.
 */

#include <stdio.h>

#define TOP 220    // ▄
#define SIDE 219   // █
#define BOTTOM 223 // ▀

#define WIDTH 10
#define HEIGHT 5

int main() 
{ 
    int x, y;

    printf("\nPodaj wspolrzedne ramki:\n");

    do 
    {
        printf("x: ");
        fflush(stdin);
    } 
    while (scanf("%d", &x) != 1);

    do 
    {
        printf("y: ");
        fflush(stdin);
    } 
    while (scanf("%d", &y) != 1);

    printf("---------------------------\n");

    for (int _y=0; _y<y; _y++) putchar('\n');
    
    for (int r=1; r<=HEIGHT; r++)
    {
        for (int _x=0; _x<x; _x++) printf("   ");

        for (int c=1; c<=WIDTH; c++)
        {
            if (r == 1)                    putchar(TOP);
            else if (r == HEIGHT)          putchar(BOTTOM);
            else if (c == 1 || c == WIDTH) putchar(SIDE);
            else                           putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
/*
 *  Plik: e2.c
 *  Opis: Program wypisujący tabelę znaków ASCII (kody 32..255) w wierszach po 16 znaków.
 */

#include <stdio.h>

#define ROWS 13
#define COLUMNS 16

int main() 
{
    int code = 32;

    printf("\n----------ASCII TABLE----------\n");

    for (int r=0; r<ROWS; r++)
    {
        for (int c=0; c<COLUMNS; c++)
        {
            printf("%c ", code);
            code++;
        }
        putchar('\n');
    }
    
    printf("-------------------------------\n");

    return 0;
}
/*
 *  Plik: e5.c
 *  Opis: Program wyświetlający tabliczkę mnożenia (z nagłówkami).
 */

#include <stdio.h>

#define COLUMNS 5
#define ROWS 2
#define SUBROWS 10

int main() 
{
    int head = 1;
    
    putchar('\n');

    for (int r=0; r<ROWS; r++)
    {
        for (int sr=0; sr<=SUBROWS; sr++)
        {        
            for (int c=0; c<COLUMNS; c++, head++)
            {
                if (sr == 0) printf("      %dx     ", head);
                else printf("%2d x %2d = %3d", head, sr, head * sr);
                putchar('\t');
            }
            head -= COLUMNS;
            putchar('\n');
        }
        head += COLUMNS;
        putchar('\n');
    }

    return 0;
}
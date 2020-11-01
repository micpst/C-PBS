/*
 *  Plik: e6.c
 *  Opis: Program, który wczytuje 4 liczby rzeczywiste z klawiatury, a następnie sprawdza, 
 *        czy wśród nich jest więcej liczb dodatnich (>=0) czy ujemnych (<0).
 */

#include <stdio.h>

int main() 
{
    int pos, neg;
    float tmp;

    pos = 0;
    neg = 0;

    printf("\nWpisz 4 liczby:\n");  

    for (int i=1; i<=4; i++)
    {
        do 
        {
            printf("#%d: ", i);
            fflush(stdin);
        } 
        while (scanf("%f", &tmp) != 1);

        if (tmp >= 0) pos++;
        else neg++;
    }

    printf("----------------------------------------\n");
    if (neg > pos) printf("Liczb ujemnych jest wiecej niz dodatnich\n");
    else if (neg < pos) printf("Liczb ujemnych jest mniej niz dodatnich\n");
    else printf("Liczb ujemnych jest tyle samo co dodatnich\n");

    printf("----------------------------------------\n");
    printf(">> Liczb dodatnich: %d\n", pos);
    printf(">> Liczb ujemnych: %d\n", neg);

    return 0;
}
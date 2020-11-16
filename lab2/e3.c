/*
 *  Plik: e3.c
 *  Opis: Program sumujący N podanych przez użytkownika liczb, 
 *        gdzie N jest pobierane na starcie programu.
 */

#include <stdio.h>

int main() 
{
    float tmp, sum;
    int N;

    printf("\nIle liczb chcesz wprowadzic: ");
    scanf("%d", &N);

    printf("Podaj %d liczby\n", N);
    printf("-----------------\n");

    for (int i=1; i<=N; i++)
    {
        do 
        {
            printf("#%d: ", i);
            fflush(stdin);
        } 
        while (scanf("%f", &tmp) != 1);

        sum += tmp;
    }
    
    printf("-----------------\n");
    printf("Suma podanych liczb wynosi: %f\n", sum);

    return 0;
}
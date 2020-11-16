/*
 *  Plik: e1.c
 *  Opis: Program losujący liczby z przedziału 1..6, aż do momentu trafienia 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int random;

    srand(time(0));

    do
    {
       random = rand() % 6 + 1;
       printf("Wylosowana liczba: %d\n", random);
    } 
    while (random != 6);
    
    return 0;
}
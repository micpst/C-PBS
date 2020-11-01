/*
 *  Plik: e2.c
 *  Opis: Program wypisujący funkcją printf tą samą zmienną 
 *        typu int w formacie zmiennoprzecinkowym i napisowym.
 */

#include <stdio.h>

int main() 
{
    int number;

    printf("\n");

    do 
    {
        printf("Podaj liczbe calkowita: ");
        fflush(stdin);
    } 
    while (scanf("%d", &number) != 1);
    
    printf("------------------\n");
    printf("Wpisana liczba: %d\n", number);
    printf("Format = float: %f\n", (float) number); 
    printf("Format = char: %c\n", number);

    return 0;
}
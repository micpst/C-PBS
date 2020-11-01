/*
 *  Plik: e1.c
 *  Opis: Program pobierający liczbę całkowitą i sprawdzający 
 *        czy bit 5 i 11 ma wartość 1.
 */

#include <stdio.h>

int main() 
{
    int b4, b10, num;

    printf("\n");

    do 
    {
        printf("Podaj liczbe calkowita: ");
        fflush(stdin);
    } 
    while (scanf("%d", &num) != 1);
    
    b4  = (num & (1 <<  4)) ? 1 : 0;
    b10 = (num & (1 << 10)) ? 1 : 0;

    printf("-------------------\n");
    printf("Liczba %d:\n", num);
    printf("b4 = %d\n", b4);
    printf("b10 = %d\n", b10);

    if (b4 && b10) 
    {
        printf("-------------------\n");
        printf("Oba bity sa ustawione\n");
    }

    return 0;
}
/*
 *  Plik: e5.c
 *  Opis: Program sprawdzający czy podany z klawiatury znak to duża litera.
 */

#include <stdio.h>

int main() 
{
    printf("\nPodaj litere: ");
    int letter = getchar();

    if (letter >= 'A' && letter <= 'Z') printf("%c jest wielka litera\n", letter);
    else printf("%c nie jest wielka litera\n", letter);

    return 0;
}
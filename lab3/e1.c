/*
 *  Plik: e1.c
 *  Opis: Napisz program, który będzie wyświetlał na ekranie postać binarną liczby dziesiętnej
 *        podanej przez użytkownika. Zakładamy, że zmienna, w której będzie przechowywana ta liczba 
 *        jest typu integer. Program należy zbudować z funkcji. Zadaniem pierwszej z nich będzie 
 *        komunikacja z użytkownikiem (wraz ze sprawdzeniem poprawności wprowadzonej przez niego wartości), 
 *        a drugiej znalezienie reprezentacji binarnej tej wartości. Uwaga, funkcje nie mogą bezpośrednio
 *        odwoływać się do zmiennych globalnych.
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int get_int(char *msg);
void print_bin(int n);

int main() 
{ 
    putchar('\n');
    int num = get_int("Podaj liczbe: ");
    print_bin(num);
    
    return 0;
}

int get_int(char *msg)
{
    char str[12];
    char *end = NULL;
    int n;

    while (1)
    {
        printf("%s", msg);
        fgets(str, 12, stdin);
        fflush(stdin);

        str[strcspn(str, "\n")] = '\0';
        n = (int) strtol(str, &end, 10);

        if (errno == 0 && str && *end != 0 || str == end) printf("Blad - nie podano liczby\n");
        else if (errno == ERANGE && n == LONG_MIN)        printf("Blad - wystapilo niedopelnienie\n");
        else if (errno == ERANGE && n == LONG_MAX)        printf("Blad - wystapilo przepelnienie\n");
        else break;
    }

    return n;
}

void print_bin(int n)
{
    printf("---------------------------------------\n");
    printf("Postac binarna liczby %d: \n", n);

    for (int i=31; i>=0; i--)
    {
        printf("%d", (n & (1 << i)) ? 1 : 0);
        if (i % 4 == 0) putchar(' ');
    }

    printf("\n---------------------------------------\n");
}
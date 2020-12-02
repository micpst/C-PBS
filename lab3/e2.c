/*
 *  Plik: e2.c
 *  Opis: Zmodyfikuj program 1 tak aby zrealizować prosty kalkulator realizujący
 *        operacje bitowe and, or, xor, negacja. Program pobiera parametry bezpośrednio 
 *        z linii komend (parametry wywołania programu), są to 2 liczby całkowite 
 *        i operator, wyświetla argumenty oraz wynik w postaci binarnej.
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

void print_bin(int n);
void print_result(int n, ...);
int parse_int(char *str);

int main(int argc, char *argv[]) 
{
    if (argc != 4)
    {
        printf("\nPodano za malo parametrow.\n");
        printf("Wymagano: 3\n");
        printf("Podano: %d\n", argc - 1);
        return 1;
    }

    int num1 = parse_int(argv[1]),
        num2 = parse_int(argv[2]);

    char operator = *argv[3];

    switch(operator)
    {
        case '&': { print_result(3, num1, num2, num1 & num2);  break; }
        case '|': { print_result(3, num1, num2, num1 | num2);  break; }
        case '^': { print_result(3, num1, num2, num1 ^ num2);  break; }
        case '~': { print_result(4, num1, ~num1, num2, ~num2); break; }
        
        default: printf("\nWprowadzono niepoprawny operator logiczny.\n");
    }

    return 0;
}

int parse_int(char *str)
{
    char *end = NULL;
    int n = (int) strtol(str, &end, 10);

    if (errno == 0 && str && *end != 0 || str == end) { printf("Blad - nie podano liczby\n");        exit(1); }
    else if (errno == ERANGE && n == LONG_MIN)        { printf("Blad - wystapilo niedopelnienie\n"); exit(1); }
    else if (errno == ERANGE && n == LONG_MAX)        { printf("Blad - wystapilo przepelnienie\n");  exit(1); }
    
    return n;
}

void print_bin(int n)
{
    for (int i=31; i>=0; i--)
    {
        printf("%d", (n & (1 << i)) ? 1 : 0);
        if (i % 4 == 0) putchar(' ');
    }                         
}

void print_result(int n, ...)
{
    int val;
    va_list args;
    
    va_start(args, n);

    for (int i=0; i<n; i++) 
    {
        val = va_arg(args, int);   
        printf("\n%11d : ", val);
        print_bin(val);
    }

    putchar('\n');    
    va_end(args);
}
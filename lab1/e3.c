/*
 *  Plik: e3.c
 *  Opis: Program kalkulator – interfejs: 
 *        > pobranie liczb poddawanych obliczeniom (zmienny przecinek), 
 *        > pobranie operatora (+-/*),
 *        > wyświetlenie całej operacji z wynikiem.
 */

#include <stdio.h>

int main() 
{
    float num1, num2, result;
    char operator;

    printf("\n--------------KALKULATOR--------------\n");
    printf("Podaj 2 liczby zmiennoprzecinkowe:\n");

    do 
    {
        printf("#1: ");
        fflush(stdin);
    } 
    while (scanf("%f", &num1) != 1);

    do 
    {
        printf("#2: ");
        fflush(stdin);
    } 
    while (scanf("%f", &num2) != 1);

    do 
    {
        printf("Podaj operator (+-/*): ");
        fflush(stdin);
    } 
    while (scanf("%[+-/*]s", &operator) != 1);
    
    switch (operator) 
    {
        case '+': { result = num1 + num2; break; }
        case '-': { result = num1 - num2; break; }
        case '*': { result = num1 * num2; break; }
        case '/': { result = num1 / num2; break; }
        default: 
        {
            printf("Nie mozna wykonac obliczenia\n");
            return 0;
        }
    }

    printf("--------------------------------------\n");
    printf("Wynik operacji: %f %c %f = %f\n", num1, operator, num2, result);

    return 0;
}
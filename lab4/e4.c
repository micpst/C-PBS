/*
 *  Plik: e4.c
 *  Opis: Napisz 3 funkcje biorące jako parametr liczbę zmiennoprzecinkową 
 *        i zwracające wynik obliczeń z użyciem następujących funkcji bibliotecznych 
 *        (sqrt, sin, exp – math.h) oraz łańcuch napisowy reprezentujący rodzaj wykonywanych 
 *        obliczeń. Następnie napisz funkcję oblicz przyjmującą jako parametr wskaźnik na 
 *        dowolną z powyższych funkcji + liczbę zmiennoprzecinkową, zwracającą wynik odpowiednich 
 *        obliczeń, wywołaj funkcję oblicz dla wszystkich 3 przypadków, wypisz wynik obliczeń, 
 *        oraz łańcuch napisowy reprezentujący rodzaj obliczeń.
 */

#include <math.h>
#include <stdio.h>

char * square(float x);
char * sinus(float x);
char * exponential(float x);
char * calculate(char * (*func)(float), float x);

int main()
{  
    float n = 0;
    printf("\nPodaj liczbe: ");
    scanf("%f", &n);

    printf("%s\n", calculate(square, n));
    printf("%s\n", calculate(sinus, n));
    printf("%s\n", calculate(exponential, n));

    return 0;
}

char * square(float x)
{
    static char result[2][10] = { "sqrt" };
    float y = sqrt(x);

    snprintf(result[1], sizeof(result[1])-1, "%f", y);
    return (char *) result;
}

char * sinus(float x)
{
    static char result[2][10] = { "sin" };
    float y = sin(x);

    snprintf(result[1], sizeof(result[1])-1, "%f", y);
    return (char *) result;
}

char * exponential(float x)
{
    static char result[2][10] = { "exp" };
    float y = exp(x);

    snprintf(result[1], sizeof(result[1])-1, "%f", y);
    return (char *) result;
}

char * calculate(char * (*func)(float), float x)
{
    char * res = func(x);

    static char pattern[29];
    snprintf(pattern, sizeof(pattern)-1, "%-4s (%f) = %10s", res, x, res+10);

    return (char *) pattern;
}
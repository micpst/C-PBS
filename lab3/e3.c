/*
 *  Plik: e3.c
 *  Opis: Zdefiniuj funkcję silnia, która dla danej liczby naturalnej oblicza wartość n!,
 *        przeanalizuj wpływ typu zmiennych na otrzymany wynik (kilka wersji funkcji).
 */

#include <stdio.h>

int       factorial_int(int n);
long long factorial_long(int n);
float     factorial_float(int n);
double    factorial_double(int n);

int main() 
{
    int in;

    printf("\nPodaj liczbe: ");
    scanf("%d", &in);

    printf("!%d : (int)       [%d B] %d\n",   in, sizeof(int),       factorial_int   (in)); // max !12
    printf("!%d : (long long) [%d B] %lld\n", in, sizeof(long long), factorial_long  (in)); // max !20
    printf("!%d : (float)     [%d B] %f\n",   in, sizeof(float),     factorial_float (in)); // max !13
    printf("!%d : (double)    [%d B] %lf\n",  in, sizeof(double),    factorial_double(in)); // max !20

    return 0;
}

int factorial_int(int n)
{
    int val = 1;
    for (int i=1; i<=n; i++) val *= i;
    return val;
}

long long factorial_long(int n)
{
    long long val = 1;
    for (int i=1; i<=n; i++) val *= i;
    return val;
}

float factorial_float(int n)
{
    float val = 1;
    for (int i=1; i<=n; i++) val *= i;
    return val;
}

double factorial_double(int n)
{
    double val = 1;
    for (int i=1; i<=n; i++) val *= i;
    return val;
}
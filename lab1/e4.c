/*
 *  Plik: e4.c
 *  Opis: Program obliczający wartość maksymalną i minimalną z 3 liczb - interfejs: 
 *        > pobranie 3 liczb, 
 *        > wyświetlenie wyniku.
 */

#include <stdio.h>

int main() 
{
    float num, min, max;

    printf("\nPodaj 3 liczby:\n");
    
    for (int i=1; i<=3; i++)
    {
        do 
        {
            printf("#%d: ", i);
            fflush(stdin);
        } 
        while (scanf("%f", &num) != 1);

        if (i == 1) 
        {
            min = num;
            max = num;
            continue;
        }

        min = (num < min) ? num : min;
        max = (num > max) ? num : max;
    }
    
    printf("----------------------\n");
    printf("Najmniejsza liczba: %f\n", min);
    printf("Najwieksza liczba: %f\n", max);

    return 0;
}
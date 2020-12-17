/*
 *  Plik: e2.c
 *  Opis: Uporządkować rosnąco ciąg n liczb całkowitych używając notacji wskaźnikowej 
 *        (stała tablica zadeklarowana w programie, sortowanie bąbelkowe).
 */

#include <stdio.h>

void sort(int *arr, size_t len) 
{
    for (int i = len - 1; i > 0; arr -= i, i--)
    {
        for (int *end = arr + i; arr != end; arr++)
        {
            if (*arr > *(arr + 1))
            {
                int tmp = *(arr + 1);
                *(arr + 1) = *arr;
                *arr = tmp;         
            }
        }
    }
}

int main() 
{   
    int array[] = { 13, 2, 32, 78, 12 };
    size_t length = sizeof (array) / sizeof (int);

    printf("\n[IN]  Tablica : ");
    for (int i = 0; i < length; i++) printf("%2d ", array[i]);

    sort(array, length);

    printf("\n[OUT] Tablica : ");
    for (int i = 0; i < length; i++) printf("%2d ", array[i]);
    putchar('\n');

    return 0;
}
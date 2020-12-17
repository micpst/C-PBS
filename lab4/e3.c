/*
 *  Plik: e3.c
 *  Opis: Napisać funkcję sklej, która dostaje dwa łańcuchy napisowe a i b
 *        i dopisuje do napisu a napis b (używając wskaźników). 
 */

#include <stdio.h>
#include <string.h>

void concat(char *s1, char *s2)
{
    while (*s1) s1++;
    while (*s2)
    {
        *s1 = *s2;
        *s1++;
        *s2++;
    }
}

int main()
{ 
    char a[100] = "",
         b[50]  = "";

    printf("\nWpisz tekst #1 [max 50 znakow]: ");
    fgets(a, sizeof(a)/2 + 1, stdin); // 50 znaków + '\0' = bufor : 51
    fflush(stdin);

    printf("Wpisz tekst #2 [max 49 znakow]: ");
    fgets(b, sizeof(b), stdin); // 49 znaków + '\0' = bufor : 50
    fflush(stdin);
   
    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';

    concat(a, b);

    printf("-------------------------\n");
    printf("Out: %s\n", a);

    return 0;
}
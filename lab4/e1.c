/*
 *  Plik: e1.c
 *  Opis: Wskaźnik wskazuje na tekst, napisz funkcję, która policzy liczbę wystąpień 
 *        (histogram) małych liter oraz cyfr w podanym tekscie, nagłówek funkcji: 
 *        zlicz_wystapienia(char *tekst, int *litery, int *cyfry), parametry litery 
 *        i cyfry są wskaźnikami do tablic, w których mają być umieszczone wyniki zliczania. 
 *        Napisz drugą funkcję, która dostaje jako parametr uzyskane wcześniej tablice oraz 
 *        wybrany znak (litera, cyfra) zwracającą ilość wystąpień wybranego znaku.
 */

#include <stdio.h>
#include <string.h>

void countld(char *txt, char *ltr, char *dgt);
int countc(char *ltr, char *dgt, char c);

int main() 
{
    char str [100] = "", 
         ltrs[100] = "",
         dgts[100] = "";

    printf("\nWpisz tekst [max 99 znakow]: ");
    fgets(str, sizeof(str), stdin);
    fflush(stdin);

    str[strcspn(str, "\n")] = '\0';

    countld(str, ltrs, dgts);

    printf("----------------\n");
    printf("Histogram:      \n");
    printf("male litery : %d\n", strlen(ltrs));
    printf("cyfry       : %d\n", strlen(dgts));
    printf("----------------\n");

    printf("\nPodaj znak: ");
    int code = fgetc(stdin);
    fflush(stdin);

    printf("Znak '%c' wystepuje %d razy\n", code, countc(ltrs, dgts, code));

    return 0;
}

void countld(char *txt, char *ltr, char *dgt)
{
    while (*txt)
    {
        if (*txt >= '0' && *txt <= '9')
        {
            *dgt = *txt;
            dgt++;
        }
        else if (*txt >= 'a' && *txt <= 'z')
        {
            *ltr = *txt;
            ltr++;
        }
        txt++;
    }
}

int countc(char *ltr, char *dgt, char c)
{
    int n = 0;
    char *t = "";

    if      (c >= '0' && c <= '9') t = dgt;
    else if (c >= 'a' && c <= 'z') t = ltr;

    while (*t)
    {
        if (*t == c) n++;
        t++;
    }
    
    return n;
}
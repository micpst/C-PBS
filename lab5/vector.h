/*
 *  Plik: vector.h
 *  Opis: Implementacja wektora.
 * 
 *        vector:
 *        +------+------+---------+
 *        | size | used | data... |
 *        +------+------+---------+
 * 
 *        Wektor sklada się z trzech pol:
 *        > size - maksymalna pojemnosc wektora,
 *        > used - ilosc elementow w wektorze,
 *        > data - tablica elementow.
 * 
 *        Wektor zostaje zainicjowany za pomoca metody vector_create(), 
 *        alokuje tym samym odpowiednia ilosc pamieci dla potencjalnych 
 *        danych. Za kazdym razem, kiedy wektor sie zapelni, nastepuje 
 *        proba alokacji wiekszej ilosci pamieci.
 * 
 *        Charakterystyka rozmiaru wektora:
 *        size ^
 *          30 |            ######
 *          20 |      ######
 *          10 |######
 *             +-----+-----+-----+-->
 *           0      10    20    30  used
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"
#include "student.h"

#define VECTOR_INIT_SIZE 10
#define VECTOR_GROWTH_FACTOR 10

typedef struct
{
    uint32  size;
    uint32  used;
    Student data[];
} Vector;

/* Tworzy nowy wektor - alokuje pamiec i ustawia domyslne wartosci dla pol */
Vector * vector_create();

/* Zwalnia pamiec zaalokowana dla wektora */
void vector_destroy(Vector *v);

/* Dodaje nowego studenta do wektora */
void vector_add(Vector **v, Student s);

/* Usuwa studenta z wektora */
void vector_remove(Vector **v, uint32 idx);

/* Zmienia wartosc istniejacego studenta w wektorze */
void vector_set(Vector *v, uint32 idx, Student s);

/* Zwraca wskaznik na studenta w wektorze */
Student * vector_get(Vector *v, uint32 idx);

/* Zwraca wskaznik na pierwszego studenta w wektorze */
Student * vector_begin(Vector *v);

/* Zwraca wskaznik do ostatniego adresu wektora*/
Student * vector_end(Vector *v);

/* Zwraca aktualny rozmiar wektora */
uint32 vector_size(Vector *v);

/* Zwraca aktualna ilosc elementow w wektorze*/
uint32 vector_used(Vector *v);

#endif
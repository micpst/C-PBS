/*
 *  Plik: student.h
 *  Opis: Implementacja struktury studenta.
 *          
 *        Student:
 *        +------+---------+--------------------+------------------------------+
 *        | roll | surname |       birthday     |            grades            |
 *        +------+---------+-----+-------+------+------+---------+-------------+                       
 *                         | day | month | year | math | physics | programming |
 *                         +-----+-------+------+------+---------+-------------+
 * 
 *        Student sklada sie z trzech pol:
 *        > roll     - numer indeksu studenta,
 *        > surname  - nazwisko studenta,
 *        > birthday - data urodzin studenta (dzien, miesiac, rok),
 *        > grades   - oceny z 3 przedmiotow (matematyka, fizyka, programowanie).
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "types.h"

#define STUDENT_MAX_SURNAME 20
#define STUDENT_MIN_YEAR 1900
#define STUDENT_MAX_YEAR 9999

typedef struct
{
    uint8  day;
    uint8  month;
    uint16 year;
} Date;

typedef struct
{
    uint8 math;
    uint8 physics;
    uint8 programming; 
} Book;

typedef struct
{
    uint32 roll;
    char   surname[STUDENT_MAX_SURNAME];
    Date   birthday;
    Book   grades;  
} Student;

/* Inicjuje wszystkie pola studenta */
void student_init(Student *s);

/* Wyswietla wartosci wszystkich pol studenta */
void student_print_details(Student *s);

/* Waliduje nazwisko studenta */
boolean student_validate_surname(Student *s);

/* Waliduje date urodzin studenta */
boolean student_validate_birthday(Student *s);

/* Waliduje wszystkie oceny studenta */
boolean student_validate_grades(Student *s);

/* Zwraca srednia wszystkich ocen studenta */
float student_get_avarage(Student *s);

#endif
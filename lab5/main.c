/*
 *  Plik: main.c
 *  Opis: Program przechowuje dane studentow, pozwala na:
 *        1) dodawanie studentow,
 *        2) edytowanie studentow,
 *        3) usuwanie studentow,
 *        4) posortowanie studentow alfabetycznie.
 *        5) wyszukiwanie studenta:
 *          > wedlug nazwiska,
 *          > wedlug najwyzszej sredniej ocen,
 *          > wedlug najwyzszej oceny z przedmiotu.   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli.h"
#include "types.h"
#include "vector.h"
#include "student.h"

// Komendy:
void add(Vector **v);
void rm(Vector **v);
void edit(Vector *v);
void show(Vector *v);
void find(Vector *v);
void sort(Vector *v);
void help();

int main()
{
    Vector *db = vector_create();
    boolean run = true;

    while (run)
    {
        char command[5] = "";
        cli_get_string(">> ", command, sizeof (command));

        if      (!strcmp(command, "add"))  add(&db);
        else if (!strcmp(command, "rm"))   rm(&db);
        else if (!strcmp(command, "edit")) edit(db);
        else if (!strcmp(command, "show")) show(db);
        else if (!strcmp(command, "find")) find(db);
        else if (!strcmp(command, "sort")) sort(db);
        else if (!strcmp(command, "help")) help();
        else if (!strcmp(command, "quit")) run = false;
        else if (*command) printf("Nie znaleziono komendy\n");
    }

    vector_destroy(db); 
    return 0;
}

void help()
{
    printf("               Komendy              \n");
    printf("+----------------------------------+\n");
    printf("| add  - dodaje nowych studentow   |\n");
    printf("| rm   - usuwa studenta            |\n");
    printf("| edit - edytuje dane studenta     |\n");
    printf("| show - wyswietla liste studentow |\n");
    printf("| find - wyszukuje studenta        |\n");
    printf("| sort - sortuje liste studentow   |\n");
    printf("| quit - wyjscie z programu        |\n");
    printf("+----------------------------------+\n");
}

void add(Vector **v)
{
    uint32 n = cli_get_number("Liczba nowych studentow : ");

    printf("\nWprowadz dane dla %d studentow", n);
    printf("\n------------------------------\n");

    for (uint32 i = 1; i <= n; i++)
    { 
        Student s;
        student_init(&s);

        printf("\n[%d/%d] Student #%d:\n", i, n, s.roll);
        
        do 
        {
            cli_get_string("Podaj nazwisko : ", s.surname, STUDENT_MAX_SURNAME);
        }
        while (!student_validate_surname(&s));

        do
        {
            printf("Podaj date urodzenia :\n");       
            s.birthday.day   = cli_get_number("dzien   : ");
            s.birthday.month = cli_get_number("miesiac : ");
            s.birthday.year  = cli_get_number("rok     : ");
        } 
        while (!student_validate_birthday(&s));

        do
        {
            printf("Podaj oceny z przedmiotow :\n");
            s.grades.math        = cli_get_number("matematyka    : ");
            s.grades.physics     = cli_get_number("fizyka        : ");
            s.grades.programming = cli_get_number("programowanie : ");
        } 
        while (!student_validate_grades(&s));

        vector_add(v, s);
        student_print_details(&s);
        printf("Student #%d zostal dodany\n", s.roll);
    }
}

void rm(Vector **v)
{
    if (vector_used(*v) > 0)
    {
        uint32 roll = cli_get_number("Numer indeksu studenta : ");
        Student *s = vector_begin(*v);
        Student *end = vector_end(*v);

        for (; s != end; s++) 
        {
            if (s->roll == roll) 
            {
                uint32 idx = (s - vector_begin(*v));
                vector_remove(v, idx);
                printf("Student #%d zostal usuniety\n", roll);
                return;
            }
        }

        if (s == end)
        {
            printf("Nie znaleziono studenta #%d\n", roll);
        }   
    }
    else
    {
        printf("Lista studentow jest pusta\n");
    } 
}

void edit(Vector *v)
{
    if (vector_used(v) > 0)
    {
        uint32 roll = cli_get_number("Numer indeksu studenta : ");
        Student *s = vector_begin(v);
        Student *end = vector_end(v);

        for (; s != end; s++)
        {
            if (s->roll == roll) 
            {
                printf("Student nr indeksu : %d\n", s->roll);
                printf("Dane:\n");
                printf("[1] Nazwisko : %s\n", s->surname);
                printf("[2] Data urodzenia : %02d/%02d/%4d\n", 
                        s->birthday.day, 
                        s->birthday.month, 
                        s->birthday.year);
                printf("[3] Oceny : %d %d %d\n",
                        s->grades.math, 
                        s->grades.physics, 
                        s->grades.programming);

                switch (cli_get_number(": "))
                {
                    case 1:
                        do 
                        {
                            cli_get_string("Edytuj nazwisko : ", s->surname, STUDENT_MAX_SURNAME);
                        } 
                        while (!student_validate_surname(s));
                        printf("Student #%d nowe nazwisko -> %s\n", s->roll, s->surname);
                        break;
                    case 2:
                        do
                        {
                            printf("Edytuj date urodzenia :\n");       
                            s->birthday.day   = cli_get_number("dzien   : ");
                            s->birthday.month = cli_get_number("miesiac : ");
                            s->birthday.year  = cli_get_number("rok     : ");
                        } 
                        while (!student_validate_birthday(s));
                        printf("Student #%d nowa data urodzenia -> %02d/%02d/%4d\n", 
                                s->roll, 
                                s->birthday.day, 
                                s->birthday.month, 
                                s->birthday.year);
                        break;
                    case 3:
                        do
                        {
                            printf("Edytuj oceny z przedmiotow :\n");
                            s->grades.math        = cli_get_number("matematyka    : ");
                            s->grades.physics     = cli_get_number("fizyka        : ");
                            s->grades.programming = cli_get_number("programowanie : ");
                        } 
                        while (!student_validate_grades(s));
                        printf("Student #%d nowe oceny -> %d %d %d\n", 
                                s->roll, 
                                s->grades.math, 
                                s->grades.physics, 
                                s->grades.programming);
                }
                return;
            }
        }
        if (s == end) 
        {
            printf("Nie znaleziono studenta\n");
        }
    }
    else
    {
        printf("Lista studentow jest pusta\n");
    }
}

void show(Vector *v)
{
    printf("                      Lista studentow                      \n");
    printf("+------------+---------------------+--------------+-------+\n");
    printf("| Nr indeksu |       Nazwisko      | Data urodzin | Oceny |\n");
    printf("+------------+---------------------+--------------+-------+\n");
    
    if (vector_used(v) > 0)
    {
        Student *s = vector_begin(v);
        Student *end = vector_end(v);
        
        for (; s != end; s++) 
        {
            printf("| %010d | %-19s |  %02d/%02d/%4d  | %d %d %d |\n",
                    s->roll, s->surname,
                    s->birthday.day, s->birthday.month, s->birthday.year,
                    s->grades.math, s->grades.physics, s->grades.programming);
        }
        printf("+------------+---------------------+--------------+-------+\n");
    }
    else
    {
        printf("|               Lista studentow jest pusta                |\n");
        printf("+---------------------------------------------------------+\n");
    }
}

void find_by_surname(Vector *v)
{ 
    char query[STUDENT_MAX_SURNAME] = "";
    cli_get_string("Nazwisko studenta : ", query, sizeof (query));

    Student *s = vector_begin(v);
    Student *end = vector_end(v);

    for (; s != end; s++) 
    {
        if (!strcmp(s->surname, query) || strstr(s->surname, query)) 
        {
            student_print_details(s);
            break;
        }
    }
    if (s == end) 
    {
        printf("Nie znaleziono studenta\n");
    }
}

void find_by_grade(Vector *v)
{
    printf("Lista przedmiotow:\n");
    printf("[1] matematyka\n");
    printf("[2] fizyka\n");
    printf("[3] programowanie\n");

    uint8 offset = cli_get_number(": ") - 1;
    if (offset < 0 || offset > 2) 
    {
        printf("Nie wybrano zadnego przedmiotu\n");
        return;
    }

    Student *s = vector_begin(v);
    Student *end = vector_end(v);
    Student *save = s;

    for (; s != end; s++) 
    {
        if (*((uint8 *) &s->grades + offset) > *((uint8 *) &save->grades + offset)) 
            save = s;
    }
    student_print_details(save);
}

void find_by_avg(Vector *v)
{
    Student *s = vector_begin(v);
    Student *end = vector_end(v);
    Student *save = s;

    for (; s != end; s++) 
    {
        if (student_get_avarage(s) > student_get_avarage(save)) 
            save = s;
    }
    student_print_details(save);
}

void find(Vector *v)
{
    if (vector_used(v) > 0)
    {
        printf("Wyszukaj studenta po:\n");
        printf("[1] nazwisku\n");
        printf("[2] ocenie z przedmiotu\n");
        printf("[3] najwyzszej sredniej ocen\n");

        switch (cli_get_number(": "))
        {
            case 1: find_by_surname(v); break;
            case 2: find_by_grade(v); break;
            case 3: find_by_avg(v);
        }
    }
    else
    {
        printf("Lista studentow jest pusta\n");
    }
}

int abc_cmp(const void *s1, const void *s2)
{
    return stricmp(((Student *) s1)->surname, ((Student *) s2)->surname);
}

void sort(Vector *v)
{
    qsort(vector_begin(v), vector_used(v), sizeof (Student), abc_cmp);
    show(v);
}
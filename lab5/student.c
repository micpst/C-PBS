#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "types.h"
#include "student.h"

void student_init(Student *s)
{
    s->roll = time(0);
    *(s->surname) = '\0';
    s->birthday.day = 1;
    s->birthday.month = 1;
    s->birthday.year = 1900;
    s->grades.math = 2;
    s->grades.physics = 2;
    s->grades.programming = 2;
}

boolean student_validate_surname(Student *s)
{
    char *ltr = s->surname;
    char *end = s->surname + strlen(s->surname);

    if (!*ltr) 
    {
        return false;
    }

    for (; ltr != end ; ltr++)
    {
        if (!isalpha(*ltr) && *ltr != ' ')
        {
            return false;
        }
    }

    return true;
}

boolean student_validate_birthday(Student *s)
{
    if (s->birthday.day < 1 || s->birthday.day > 31) 
    {
        return false;
    }     

    if (s->birthday.month < 1 || s->birthday.month > 12) 
    {
        return false;
    }

    if (s->birthday.year < STUDENT_MIN_YEAR || 
        s->birthday.year > STUDENT_MAX_YEAR) 
    {
        return false;
    }

    if (s->birthday.month == 2)
    {
        if (((s->birthday.year % 4 == 0) && 
             (s->birthday.year % 100 != 0)) ||
             (s->birthday.year % 400 == 0))
        {
            return s->birthday.day <= 29;
        }

        return s->birthday.day <= 28;
    }

    if (s->birthday.month == 4 || s->birthday.month == 6 ||
        s->birthday.month == 9 || s->birthday.month == 11)
    {
        return s->birthday.day <= 30;
    }

    return true;
}

boolean student_validate_grades(Student *s)
{
    if (s->grades.math < 2 || s->grades.math > 5) return false;
    if (s->grades.physics < 2 || s->grades.physics > 5) return false;
    if (s->grades.programming < 2 || s->grades.programming > 5) return false;
    return true;
}

float student_get_avarage(Student *s)
{
    return (s->grades.math + s->grades.physics + s->grades.programming) / 3.;
}

void student_print_details(Student *s)
{
    printf("+------------------------------------+\n");
    printf("| Informacje ogolne                  |\n");
    printf("+------------------------------------+\n");
    printf("| Nr indeku    : %-010d          |\n", s->roll);
    printf("| Nazwisko     : %-19s |\n", s->surname);
    printf("| Data urodzin : %02d/%02d/%4d          |\n", 
            s->birthday.day, s->birthday.month, s->birthday.year);
    printf("+------------------------------------+\n");
    printf("| Oceny                              |\n");
    printf("+------------------------------------+\n");
    printf("| matematyka    : %d                  |\n", s->grades.math);
    printf("| fizyka        : %d                  |\n", s->grades.physics);
    printf("| programowanie : %d                  |\n", s->grades.programming);
    printf("+------------------------------------+\n");
    printf("| Srednia       : %1.2f               |\n", student_get_avarage(s));
    printf("+------------------------------------+\n");
}
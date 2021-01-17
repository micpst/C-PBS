#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "vector.h"
#include "student.h"

Vector * vector_create() 
{
    Vector *v = malloc(sizeof (Vector) + VECTOR_INIT_SIZE * sizeof (Student));

    if (v == NULL)
    {
        printf("Nie mozna zaalokowac pamieci dla wektora\n");
        printf("Wyjscie z programu\n");
        exit(1);
    }

    v->size = VECTOR_INIT_SIZE;
    v->used = 0;
    memset(v->data, 0, v->size * sizeof (Student));
    
    return v;
}

void vector_destroy(Vector *v)
{
    if (v != NULL) 
    {
        free(v);
    }
}

void vector_resize(Vector **v, uint32 size)
{
    int gap = size - (*v)->size;
    Vector *tmp = realloc(*v, sizeof (Vector) + size * sizeof (Student));
    
    if (tmp == NULL)
    {
        printf("Nie mozna zaalokowac pamieci dla wektora\n");
        printf("Wyjscie z programu\n");
        exit(1);
    }

    *v = tmp;
    (*v)->size = size;
    
    if (gap > 0)
    {
        memset((*v)->data + (*v)->used, 0, gap * sizeof (Student));
    }
}

void vector_add(Vector **v, Student s) 
{
    if ((*v)->used == (*v)->size)
    {
        uint32 size = (*v)->size + VECTOR_GROWTH_FACTOR;
        vector_resize(v, size);
    }

    *((*v)->data + (*v)->used) = s;
    (*v)->used++;
}

void vector_remove(Vector **v, uint32 idx)
{
    if (idx < (*v)->used)
    {
        (*v)->used--;
        memcpy((*v)->data + idx, (*v)->data + idx + 1, ((*v)->used - idx) * sizeof (Student));
        memset((*v)->data + (*v)->used, 0, sizeof (Student));

        if (((*v)->size - (*v)->used) >= VECTOR_GROWTH_FACTOR)
        {
            uint32 size = (*v)->size - VECTOR_GROWTH_FACTOR;
            vector_resize(v, size);
        }
    }
}

void vector_set(Vector *v, uint32 idx, Student s)
{
    if (idx < v->used) 
    {
        *(v->data + idx) = s;
    }  
}

Student * vector_get(Vector *v, uint32 idx)
{
    if (idx < v->used) 
    {
        return v->data + idx;
    }   
    return NULL;
}

Student * vector_begin(Vector *v)
{
    return v->data;
}

Student * vector_end(Vector *v)
{
    return v->data + v->used;
}

uint32 vector_size(Vector *v)
{
    return v->size;
}

uint32 vector_used(Vector *v)
{
    return v->used;
}
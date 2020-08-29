#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tour.h"

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

int main()
{
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for(; strcmp(fgets(name, 80, stdin), "\n") != 0; i = next) {
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }
    display(start);
}
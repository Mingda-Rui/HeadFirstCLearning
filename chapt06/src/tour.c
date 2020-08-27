#include <stdio.h>
#include "tour.h"

void display(island *start)
{
    island *i = start;

    for (; i != NULL; i = i->next) {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    char *my_env[] = {"JUICE=peach and apple", NULL};
    // execle("diner_info", "diner_info", "4", NULL, my_env);
    execle("./build/diner_info", "diner_info", "4", NULL, my_env);
    puts("Dude - the diner_info code must be busted");
    puts(strerror(errno));
}
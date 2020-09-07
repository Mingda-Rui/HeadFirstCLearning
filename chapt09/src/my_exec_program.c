#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *my_env[] = {"JUICE=peach and apple", NULL};
    execle("/Users/ruimingda/Code/HeadFirstCLearning/chapt09/build/diner_info", "/Users/ruimingda/Code/HeadFirstCLearning/chapt09/build/diner_info", "4", NULL, my_env);
    puts("Dude - the diner_info code must be busted");
}
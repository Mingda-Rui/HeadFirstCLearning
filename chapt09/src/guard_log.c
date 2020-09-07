#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
    time_t t;
    time (&t);
    return asctime(localtime (&t));
}

/* Master Control Program utility.
    Records guard patrol check-ins. */
int main()
{
    char comment[80];
    char cmd[120];

    fgets(comment, 80, stdin);
    // sprintf will print the charactes to a string.
    // The formatted string will be stored in the cmd array.
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

    system(cmd);
    return 0;
}
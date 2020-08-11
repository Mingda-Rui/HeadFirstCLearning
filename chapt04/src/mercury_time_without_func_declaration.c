#include <stdio.h>

/* compiler will throw the following warning if compiling the code */
// ./src/mercury_time_without_func_declaration.c:8:17: warning: implicit declaration of function 'hours_in_an_earth_day' is invalid in C99
//       [-Wimplicit-function-declaration]
//     int hours = hours_in_an_earth_day();
                ^
1 warning generated.

float mercury_day_in_earth_days();

int main()
{
    float length_of_day = mercury_day_in_earth_days();
    int hours = hours_in_an_earth_day();
    float day = length_of_day * hours;

    printf("A day on Mercury is %f hours\n", day);
    return 0;
}

float mercury_day_in_earth_days()
{
    return 58.65;
}

int hours_in_an_earth_day()
{
    return 24;
}
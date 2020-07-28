#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    // size_t is an integer used 
    // for storing the sizes of things.
    size_t len = strlen(s);
    char *t = s + len - 1;
    while (t >= s) {
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}

int main()
{
    char test[] = "12345";
    print_reverse(test);
}
#include <stdio.h>
#include <stdlib.h>

void fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    printf("msg occupies %lu bytes\n", sizeof(msg));
}

// char quote[] = "Cookies make you fat";
// fortune_cookie(quote);

int main()
{
    char quote[] = "Cookies make you fat";
    fortune_cookie(quote);
}
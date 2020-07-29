#include <stdio.h>

int main()
{
    char cards[] = "JQK";
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);
    return 0;

    /* error: array initializer must be an initializer list or string literal */
    // char *test = "JDK";
    // char test2[] = *test;
    // test2[0] = "A";
    // puts(test2);
}
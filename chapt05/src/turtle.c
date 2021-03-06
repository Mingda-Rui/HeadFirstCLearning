#include <stdio.h>

typedef struct {
    const char *name;
    const char *species;
    int age;
} turtle;

void happy_birthday(turtle t)
{
    t.age = t.age + 1;
    printf("Happy Birtday %s! You are now %i years old!\n",
        t.name, t.age);
}

void happy_birthday_to_same_turtle(turtle *t)
{
    (*t).age = (*t).age + 1;
    // or use this:
    // t -> age = t -> age + 1;
    // This means: The age field in the struct that t poitns to.
    printf("Happy Birthday %s! You are now %i years old!\n",
        (*t).name, (*t).age);
}

int main()
{
    turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
    happy_birthday(myrtle);
    printf("%s's age is now %i\n", myrtle.name, myrtle.age);
    happy_birthday_to_same_turtle(&myrtle);
    printf("%s's age is now %i\n", myrtle.name, myrtle.age);
    return 0;
}
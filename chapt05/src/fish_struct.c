#include <stdio.h>

struct exercise;
struct meal;
struct preferences;
struct fish;
void label(struct fish a);

struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char *ingredients;
    float weight;
};

struct preferences {
    struct meal food;
    struct exercise exercise;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

// This is the data that will be recorded for one of the fish:
/*
    Name: Snappy
    Species: Piranha
    Food ingredients: meat
    Food weight: 0.2 lbs
    Exercies description: swim in the jacuzzi
    Exericse duration 7.5 hours
*/

int main()
{
    // Question 0: How would you write this data in C?
    struct fish snappy = {"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jscuzzi", 7.5}}};
    label(snappy);
}

// Question 1: Complete the code of the label() function so it produces output like this:
/*
    Name: Snappy
    Species: Piranha
    4 years old, 69 teeth
    Feed with 0.20 lbs of meat and allow to swim in the jscuzzi for 7.50 hours
*/
void label(struct fish a)
{
    printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n", 
        a.name, a.species, a.teeth, a.age);
    printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n",
        a.care.food.weight, a.care.food.ingredients, 
        a.care.exercise.description, a.care.exercise.duration);
}
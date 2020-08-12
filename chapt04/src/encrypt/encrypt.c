#include "encrypt.h"

void encrypt(char *message)
{
    while (*message) {
        *message = *message ^ 31; // This means you'll XOR each character with the number 31.
        message++;
    }
}
#include <stdio.h>

int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("data=[");
    // %79[^\n] is just a way of saying, "Give me every 
    // character up to the end of the line."
    // Or, according to StackOverflow, The format "%79[^\n]" says all the characters up to 79 characters max that are no '\n'.

    // The scanf() function returns the nuber of
    // values it was able to read.
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if (started)
            printf(",\n");
        else
            started = 1;

        if (latitude < -90 || latitude > 90) {
            printf("Invalid latitude: %f\n", latitude);
            return 2;
        }
            
        if (longitude < -180 || longitude > 180) {
            printf("Invalid longitude: %f\n", longitude);
            return 2;
        }
        printf("{latitude: %f, logitude: %f, info: '%s}", latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}
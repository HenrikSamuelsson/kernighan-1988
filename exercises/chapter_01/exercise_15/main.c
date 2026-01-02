#include <stdio.h>
#include <stdlib.h>

float to_celsius(int fahrenheit);

int main(void)
{
    const int fahrenheit_min = 0;
    const int fahrenheit_max = 300;
    const int step = 20;

    int fahrenheit = fahrenheit_min;

    printf(" F      C  \n");
    printf("---   -----\n");

    while (fahrenheit <= fahrenheit_max)
    {
        printf("%3d   %5.1f\n", fahrenheit, to_celsius(fahrenheit));
        fahrenheit = fahrenheit + step;
    }

    return EXIT_SUCCESS;
}

float to_celsius(int fahrenheit)
{
    return (5.0f / 9.0f) * (fahrenheit - 32.0f);
}

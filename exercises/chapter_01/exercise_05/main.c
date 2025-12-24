#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int fahrenheit_min = 0;
    const int fahrenheit_max = 300;
    const int step = 20;

    int fahrenheit = fahrenheit_max;
    float celsius;

    printf(" F      C  \n");
    printf("---   -----\n");

    while (fahrenheit >= fahrenheit_min)
    {
        celsius = (5.0f / 9.0f) * ((float)fahrenheit - 32.0f);
        printf("%3d   %5.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit - step;
    }

    return EXIT_SUCCESS;
}

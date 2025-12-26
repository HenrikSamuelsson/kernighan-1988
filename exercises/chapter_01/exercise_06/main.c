#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    int expr;

    while ((c = getchar()) != EOF)
    {
        expr = (c != EOF);
        printf("c = %d  (c != EOF) = %d\n", c, expr);
    }
    printf("c = %d  (c != EOF) = %d\n", c, (c != EOF));

    return EXIT_SUCCESS;
}

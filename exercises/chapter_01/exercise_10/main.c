#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    while (EOF != (c = getchar()))
    {
        if ('\t' == c)
        {
            putchar('\\');
            putchar('t');
        }
        else if ('\b' == c)
        {
            putchar('\\');
            putchar('b');
        }
        else if ('\\' == c)
        {
            putchar('\\');
        }
        else
        {
            putchar(c);
        }
    }

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int last_char_was_blank = 0;
    int current_char;

    while ((current_char = getchar()) != EOF)
    {
        if (' ' == current_char)
        {
            last_char_was_blank = 1;
        }
        else
        {
            if (1 == last_char_was_blank)
            {
                putchar(' ');
                last_char_was_blank = 0;
            }
            putchar(current_char);
        }
    }

    /* Handle the special case that the very last char is a blank. */
    if (1 == last_char_was_blank)
    {
        putchar(' ');
    }

    return EXIT_SUCCESS;
}
